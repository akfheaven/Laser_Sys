// Laser_server_lib.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include <cstdio>
#include "LayserServer.h"
#ifdef MDebug
int main()
{
	puts("[main] server lib test");


	LayserServer *server = new LayserServer();
	
	server->Start(8999);

	while (1);
    return 0;
}

#endif

