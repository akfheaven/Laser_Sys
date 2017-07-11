#pragma once
#include "afxcmn.h"
#include "MListCtrl.h"
#include "LayserServer.h"


// TestFormView ������ͼ

class TestFormView : public CFormView
{
	DECLARE_DYNCREATE(TestFormView)

protected:
	TestFormView();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~TestFormView();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FORMVIEW };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private :
	afx_msg LRESULT OnEditChipID(WPARAM wParam, LPARAM lParam = FALSE);
public:
//	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	virtual void OnInitialUpdate();//extend
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnBnClickedButton();
	CMListCtrl mCustomListCtrl;
	CString tempString;
	UINT32 preListSize = 0;
	UINT32 QWidth = 60;
	int listMapGenID[MAX_TRACKER_NUM + 5];
	LayserServer *server;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};


