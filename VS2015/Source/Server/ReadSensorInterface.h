//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Laser_sys
//  @ File Name : ReadSensorInterface.h
//  @ Date : 2018/1/3
//  @ Author : akfheaven
//
//


#if !defined(_READSENSORINTERFACE_H)
#define _READSENSORINTERFACE_H


class ReadSensorInterface {
public:
	virtual bool RecieveData(char* data, int& len, int& channel) = 0;
};

#endif  //_READSENSORINTERFACE_H