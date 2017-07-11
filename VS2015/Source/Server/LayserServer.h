//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Laser_sys
//  @ File Name : LayserServer.h
//  @ Date : 2017/7/4
//  @ Author : 
//
//


#if !defined(_LAYSERSERVER_H)
#define _LAYSERSERVER_H

#include <vector>
#include <map>
#include "Tracker.h"
#include "SimpleThread.h"
#include "common\mavlink.h"
using namespace std;
//mavlink Test
typedef struct {
	uint32_t time_boot_ms; /*< Timestamp (milliseconds since system boot)*/
	float q1; /*< Quaternion component 1, w (1 in null-rotation)*/
	float q2; /*< Quaternion component 2, x (0 in null-rotation)*/
	float q3; /*< Quaternion component 3, y (0 in null-rotation)*/
	float q4; /*< Quaternion component 4, z (0 in null-rotation)*/
	float rollspeed; /*< Roll angular speed (rad/s)*/
	float pitchspeed; /*< Pitch angular speed (rad/s)*/
	float yawspeed; /*< Yaw angular speed (rad/s)*/
	char name[5];
} mMavlink_attitude_quaternion_t;



class LayserServer {
public:
	LayserServer();
	virtual ~LayserServer();
	void Start(int port);
	void Stop();
	bool setGenIdMapRealID(int GenID, int RealID);
	vector<Tracker*>* GetTrackers();
private:
	// Server Threads
	SimpleThread* ReadThread;
	SimpleThread* SendThread;
	

	static void ReadDataRunWarp(void* Owner);
	static void SendDataRunWarp(void* Owner);

	void ReadDataRun();
	void SendDataRun();

	bool ReadContinueFlag;
	bool SendContinueFlag;


	//UDP
	int port = 8888;//C++11?
	int portSend = 7777;
	static const int MAX_BUFFER = 2048;
	static const int READ_LEN = 2048;
	char decodeBuffer[MAX_BUFFER];
	CRITICAL_SECTION g_cs;
	int readedBufferLen = 0;

	//Decode
	void DecodeMavlink(uint8_t channel, char* data, int len);
	mavlink_message_t DecodeMsg[MAX_TRACKER_NUM + 5];
	mavlink_status_t status;
	mMavlink_attitude_quaternion_t pck;


	//Tacker 
	vector<Tracker*> *Trackers;
	vector<Tracker*> *TrackersCpy;
	CRITICAL_SECTION TrackersCpyLock;
	Tracker ReadTracker[MAX_TRACKER_NUM + 5];
	map<char*, Tracker*> TrackerMap;
	uint8_t MavSendBuffer[MAX_TRACKER_NUM + 5][1024];
	mavlink_message_t EncodeMsg[MAX_TRACKER_NUM + 5];
	mavlink_t_tracker_t ToSendTracker;
	void MulticastTrackerData(SOCKET &s, sockaddr_in &remote);

	//Tracer ID Managememt 
	bool IsGenIDExist[MAX_TRACKER_NUM + 5];
	bool IsRealIDExist[MAX_TRACKER_NUM + 5];
	int NextGenID[MAX_TRACKER_NUM + 5];
	void InitID();
	int GenID();
	int DelID(int id);
	map<char*, int>IpMapGenID;
	double GenIDMapTimeTick[MAX_TRACKER_NUM + 5];
	int GenIDMapRealID[MAX_TRACKER_NUM + 5];
	int RealIDMapGenID[MAX_TRACKER_NUM + 5];
	static const double IP_TIME_OUT;//second
	

};

#endif  //_LAYSERSERVER_H
