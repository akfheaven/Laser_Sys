
// Laser_server_mfcView.cpp : CLaser_server_mfcView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// CLaser_server_mfcView ����/����

CLaser_server_mfcView::CLaser_server_mfcView()
{
	// TODO: �ڴ˴���ӹ������

}

CLaser_server_mfcView::~CLaser_server_mfcView()
{
}

BOOL CLaser_server_mfcView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CLaser_server_mfcView ����

void CLaser_server_mfcView::OnDraw(CDC* /*pDC*/)
{
	CLaser_server_mfcDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CLaser_server_mfcView ���

#ifdef _DEBUG
void CLaser_server_mfcView::AssertValid() const
{
	CView::AssertValid();
}

void CLaser_server_mfcView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLaser_server_mfcDoc* CLaser_server_mfcView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLaser_server_mfcDoc)));
	return (CLaser_server_mfcDoc*)m_pDocument;
}
#endif //_DEBUG


// CLaser_server_mfcView ��Ϣ�������

char* num = "0";
int CLaser_server_mfcView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	CRect rect_button(40, 10, 200, 60);  //�����ؼ�λ���Լ���С�Ľṹ

	btn.Create(_T("TEST_BUTTON"), WS_CHILD | WS_VISIBLE | WS_BORDER, rect_button, this, IDU_TEST_BTN);

	btn.ShowWindow(SW_SHOWNORMAL);

	return 0;
}
void CLaser_server_mfcView::OnBtnDown()
{
		MessageBox(_T("hhh"));
}
