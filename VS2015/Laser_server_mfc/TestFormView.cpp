// TestFormView.cpp : 实现文件
//

#include "stdafx.h"
#include "Laser_server_mfc.h"
#include "TestFormView.h"


// TestFormView

IMPLEMENT_DYNCREATE(TestFormView, CFormView)

TestFormView::TestFormView()
	: CFormView(IDD_FORMVIEW)
{

}

TestFormView::~TestFormView()
{
}

void TestFormView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(TestFormView, CFormView)
	ON_BN_CLICKED(IDC_BUTTON, &TestFormView::OnBnClickedButton)
END_MESSAGE_MAP()


// TestFormView 诊断

#ifdef _DEBUG
void TestFormView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void TestFormView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// TestFormView 消息处理程序


void TestFormView::OnBnClickedButton()
{
	MessageBox(_T("hhh"));
	// TODO: 在此添加控件通知处理程序代码
}
