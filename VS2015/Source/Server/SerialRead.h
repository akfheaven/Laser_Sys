//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Laser_sys
//  @ File Name : SerialRead.h
//  @ Date : 2018/1/3
//  @ Author : akfheaven
//
//


#if !defined(_SERIALREAD_H)
#define _SERIALREAD_H

#include "ReadSensorInterface.h"

class SerialRead : public ReadSensorInterface {
public:
	void Init(char* port, int bautRate);
	bool RecieveData(char* data, int& len, char* channel);
	void close();
};

#endif  //_SERIALREAD_H
