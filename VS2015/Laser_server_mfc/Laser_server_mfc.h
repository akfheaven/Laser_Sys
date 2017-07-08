
// Laser_server_mfc.h : Laser_server_mfc 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持


};


// CLaser_server_mfcApp:
// 有关此类的实现，请参阅 Laser_server_mfc.cpp
//

class CLaser_server_mfcApp : public CWinApp
{
public:
	CLaser_server_mfcApp();

	CAboutDlg aboutDlg;
// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CLaser_server_mfcApp theApp;
