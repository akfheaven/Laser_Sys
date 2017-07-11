#pragma once
#include "afxcmn.h"
#include "Resource.h"

#define WM_USER_EDIT_CHIP_ID WM_USER + 1002

class CListCtrlEdit : public CEdit
{
	// ������������̬����ʱCRuntimeClass
	DECLARE_DYNAMIC(CListCtrlEdit)
	// ������ 2012-11-16 ��
public:
	DECLARE_MESSAGE_MAP()
	// �����󣺿ؼ�����Ϣ���壬��Ҫ��CWndΪ����
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	// ������ 2012-11-16 ��
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

