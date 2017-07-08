//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Laser_sys
//  @ File Name : LayserService.cpp
//  @ Date : 2017/7/4
//  @ Author : 
//
//

#include <cstdio>
#include <winsock2.h>
#include <Ws2tcpip.h>
#include <mswsock.h>
#include <tchar.h>
#include <windows.h>
#include "LayserService.h"


#pragma comment(lib, "ws2_32.lib")
LayserService::~LayserService()
{
	Stop();
}
//#pragma comment(lib, "wsock32.lib")
void LayserService::Start(int pPort) {
	port = pPort;

	//start read and send thread;
	ReadThread = new SimpleThread();
	ReadThread->SetRun(ReadDataRunWarp, this);
	ReadContinueFlag = true;
	ReadThread->Start("Read");

	//share memery data
	//Trackers = new Tracker[MAX_TRACKER_NUM];
	// 创建共享文件句柄  
	HANDLE hMapFile = CreateFileMapping(
		INVALID_HANDLE_VALUE,    // 物理文件句柄  
		NULL,                    // 默认安全级别  
		PAGE_READWRITE,          // 可读可写  
		0,                       // 高位文件大小  
		sizeof(Tracker) * MAX_TRACKER_NUM,                // 地位文件大小  
		_T(TRACERS_SHARE_MEM_NAME)                   // 共享内存名称  
		);


	Trackers = (Tracker*)MapViewOfFile(
		hMapFile,            // 共享内存的句柄  
		FILE_MAP_ALL_ACCESS, // 可读写许可  
		0,
		0,
		sizeof(Tracker) * MAX_TRACKER_NUM
		);
}

void LayserService::Stop() {
	ReadContinueFlag = false;
	ReadThread->Stop();
}

void LayserService::ReadDataRunWarp(void * Owner)
{
	LayserService* service = (LayserService*)(Owner);
	service->ReadDataRun();
}

void LayserService::ReadDataRun()
{

	SOCKET s;
	struct sockaddr_in si_other;
	int slen, recv_len = 0;
	char buf[MAX_BUFFER];
	WSADATA wsa;
	slen = sizeof(si_other);
	//Initialise winsock
	printf("\nInitialising Winsock...");
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("Failed. Error Code : %d", WSAGetLastError());
		return;
	}
	printf("\nUDP Initialised.\n");

	//Create a socket
	if ((s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == INVALID_SOCKET)
	{
		printf("Could not create socket : %d", WSAGetLastError());
	}
	printf("Socket created.\n");

	//Prepare the sockaddr_in structure
	struct sockaddr_in local;
	memset(&local, 0, sizeof(local));
	local.sin_family = AF_INET;
	local.sin_port = htons(port);
	local.sin_addr.s_addr = INADDR_ANY;// inet_addr("127.0.0.1");
	//local.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	//Bind
	if (bind(s, (struct sockaddr *)&local, sizeof(local)) == SOCKET_ERROR)
	{
		printf("Bind failed with error code : %d", WSAGetLastError());
		return;
	}
	puts("UDP Bind done");


	int loop = 1;
	if (setsockopt(s, IPPROTO_IP, IP_MULTICAST_LOOP, (char*)&loop, sizeof(int))) {
		int err = GetLastError();
		printf("setsockopt:%d", err);
		return;
	}
	
	//int optval = 8;
	//setsockopt(s, IPPROTO_IP, IP_MULTICAST_TTL, (char*)&optval, sizeof(int));

	///**加入组播**/
	struct ip_mreq myMreq;
	myMreq.imr_multiaddr.s_addr = inet_addr("234.5.6.7"); //加入的组  
	myMreq.imr_interface.s_addr = INADDR_ANY;// inet_addr("127.0.0.1"); //把本机加入到这个组  
	if (setsockopt(s, IPPROTO_IP, IP_ADD_MEMBERSHIP, (const char*)&myMreq, sizeof(myMreq)) < 0)
	{
		int err = GetLastError();
		printf("setsockopt:%d", err);
		return ;
	}

	puts("Add To Group Brocast");



	// read data
	mavlink_message_t msg;
	mavlink_status_t status;
	mavlink_t_tracker_t readedTracker;
	while (ReadContinueFlag) {
		if ((recv_len = recvfrom(s, buf, MAX_BUFFER, 0, (sockaddr*)&si_other, &slen)) < 0) {
			int err = GetLastError();
			printf("recvfrom:%d\n", err);
		}
		else {
			//printf("len: %d\n", recv_len);
			for (int i = 0; i < recv_len; i++) {
				if (mavlink_parse_char(124, buf[i], &msg, &status)) {
					if (msg.msgid == MAVLINK_MSG_ID_T_TRACKER)
					{
						mavlink_msg_t_tracker_decode(&msg,&readedTracker);
						if (readedTracker.ID >= 0 && readedTracker.ID <= MAX_TRACKER_NUM) {
							Trackers[readedTracker.ID].Qw = readedTracker.Qw;
							Trackers[readedTracker.ID].Qx = readedTracker.Qx;
							Trackers[readedTracker.ID].Qy = readedTracker.Qy;
							Trackers[readedTracker.ID].Qz = readedTracker.Qz;

							Trackers[readedTracker.ID].Px = readedTracker.Px;
							Trackers[readedTracker.ID].Py = readedTracker.Py;
							Trackers[readedTracker.ID].Pz = readedTracker.Pz;
						}
						printf("tracker id: %d | %f	%f	%f	%f\n", readedTracker.ID, readedTracker.Qw, readedTracker.Qx, readedTracker.Qy, readedTracker.Qz);
					}
					//printf("id: %d\n", msg.msgid);
				}
			}
		}
	}

	setsockopt(s, IPPROTO_IP, IP_DROP_MEMBERSHIP, (const char*)&myMreq, sizeof(myMreq));
	closesocket(s);
}

