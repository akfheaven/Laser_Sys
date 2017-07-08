
// Laser_server_mfcView.h : CLaser_server_mfcView 类的接口
//

#pragma once
#include "afxwin.h"


class CLaser_server_mfcView : public CView
{
protected: // 仅从序列化创建
	CLaser_server_mfcView();
	DECLARE_DYNCREATE(CLaser_server_mfcView)

// 特性
public:
	CLaser_server_mfcDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CLaser_server_mfcView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
protected:
	CButton btn;
private:
	void OnBtnDown();
};

#ifndef _DEBUG  // Laser_server_mfcView.cpp 中的调试版本
inline CLaser_server_mfcDoc* CLaser_server_mfcView::GetDocument() const
   { return reinterpret_cast<CLaser_server_mfcDoc*>(m_pDocument); }
#endif

