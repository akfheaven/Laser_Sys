
// Laser_server_mfcView.h : CLaser_server_mfcView ��Ľӿ�
//

#pragma once
#include "afxwin.h"


class CLaser_server_mfcView : public CView
{
protected: // �������л�����
	CLaser_server_mfcView();
	DECLARE_DYNCREATE(CLaser_server_mfcView)

// ����
public:
	CLaser_server_mfcDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CLaser_server_mfcView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
protected:
	CButton btn;
private:
	void OnBtnDown();
};

#ifndef _DEBUG  // Laser_server_mfcView.cpp �еĵ��԰汾
inline CLaser_server_mfcDoc* CLaser_server_mfcView::GetDocument() const
   { return reinterpret_cast<CLaser_server_mfcDoc*>(m_pDocument); }
#endif

