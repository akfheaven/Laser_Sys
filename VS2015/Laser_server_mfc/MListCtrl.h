#pragma once
#include "afxcmn.h"
#include "Resource.h"

#define WM_USER_EDIT_CHIP_ID WM_USER + 1002

class CListCtrlEdit : public CEdit
{
	// 大气象：声明动态运行时CRuntimeClass
	DECLARE_DYNAMIC(CListCtrlEdit)
	// 大气象 2012-11-16 ↓
public:
	DECLARE_MESSAGE_MAP()
	// 大气象：控件中消息定义，需要以CWnd为参数
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	// 大气象 2012-11-16 ↑
public:
	CListCtrlEdit(void);
	~CListCtrlEdit(void);
};

class CMListCtrl :
	public CListCtrl
{
	DECLARE_DYNAMIC(CMListCtrl)
public:
	CMListCtrl();
	~CMListCtrl();
	BOOL    RegisterWindowClass(HINSTANCE hInstance = NULL);
	DECLARE_MESSAGE_MAP()
//	afx_msg void OnPaint();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg LRESULT OnEditEnd(WPARAM wParam, LPARAM lParam = FALSE);

	void ShowEdit(bool bShow, int nItem, int nSubItem, CRect rcCtrl);
	int nItem;
	int nSubItem;
	CListCtrlEdit m_Edit;
};

