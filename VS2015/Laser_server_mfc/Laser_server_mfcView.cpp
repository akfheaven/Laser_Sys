
// Laser_server_mfcView.cpp : CLaser_server_mfcView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Laser_server_mfc.h"
#endif

#include "Laser_server_mfcDoc.h"
#include "Laser_server_mfcView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLaser_server_mfcView

IMPLEMENT_DYNCREATE(CLaser_server_mfcView, CView)

BEGIN_MESSAGE_MAP(CLaser_server_mfcView, CView)
	ON_WM_CREATE()
	ON_COMMAND(IDU_TEST_BTN, OnBtnDown)
END_MESSAGE_MAP()

// CLaser_server_mfcView 构造/析构

CLaser_server_mfcView::CLaser_server_mfcView()
{
	// TODO: 在此处添加构造代码

}

CLaser_server_mfcView::~CLaser_server_mfcView()
{
}

BOOL CLaser_server_mfcView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CLaser_server_mfcView 绘制

void CLaser_server_mfcView::OnDraw(CDC* /*pDC*/)
{
	CLaser_server_mfcDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CLaser_server_mfcView 诊断

#ifdef _DEBUG
void CLaser_server_mfcView::AssertValid() const
{
	CView::AssertValid();
}

void CLaser_server_mfcView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLaser_server_mfcDoc* CLaser_server_mfcView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLaser_server_mfcDoc)));
	return (CLaser_server_mfcDoc*)m_pDocument;
}
#endif //_DEBUG


// CLaser_server_mfcView 消息处理程序

char* num = "0";
int CLaser_server_mfcView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	CRect rect_button(40, 10, 200, 60);  //描述控件位置以及大小的结构

	btn.Create(_T("TEST_BUTTON"), WS_CHILD | WS_VISIBLE | WS_BORDER, rect_button, this, IDU_TEST_BTN);

	btn.ShowWindow(SW_SHOWNORMAL);

	return 0;
}
void CLaser_server_mfcView::OnBtnDown()
{
		MessageBox(_T("hhh"));
}
