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
	//DDX_Control(pDX, IDC_CUSTOM2, mCustomListCtrl);
	DDX_Control(pDX, IDC_LIST4, mCustomListCtrl);
}

BEGIN_MESSAGE_MAP(TestFormView, CFormView)
//	ON_WM_CONTEXTMENU()
ON_WM_CREATE()
ON_BN_CLICKED(IDC_BUTTON, &TestFormView::OnBnClickedButton)
ON_WM_TIMER()
ON_MESSAGE(WM_USER_EDIT_CHIP_ID, &TestFormView::OnEditChipID)
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


//void TestFormView::OnContextMenu(CWnd* /*pWnd*/, CPoint point)
//{
//	// TODO: 在此处添加消息处理程序代码
//	CMenu menu;
//	menu.LoadMenuW(IDR_TESTFORMVIEW_TMPL);
//
//	CMenu* pMenu = menu.GetSubMenu(0);
//	//ClientToScreen(&point);
//
//	pMenu->TrackPopupMenu(TPM_LEFTALIGN|TPM_LEFTBUTTON, point.x, point.y,GetParent());
//
//
//
//}


LRESULT TestFormView::OnEditChipID(WPARAM setID, LPARAM row)
{
	CString str;
	str.Format(_T("%d\n"), setID);
	int genID = listMapGenID[row];
	server->setGenIdMapRealID(genID, setID);
	return LRESULT(0);
}

void TestFormView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	//TODO
	
	//LONG lStyle;
	//lStyle = GetWindowLong(mCustomListCtrl.m_hWnd, GWL_STYLE);// 获取当前窗口style 
	//lStyle &= ~LVS_TYPEMASK; // 清除显示方式位 
	//lStyle |= LVS_REPORT; // 设置style 
	//SetWindowLong(mCustomListCtrl.m_hWnd, GWL_STYLE, lStyle);// 设置style 

	//
	//if (!mCustomListCtrl.m_hWnd) {

	//	mCustomListCtrl.Create(WS_VISIBLE | WS_BORDER | LVS_EX_GRIDLINES, CRect(0, 0, 250, 400), this, IDC_CUSTOM2);
	//	
	//	DWORD dwStyle = mCustomListCtrl.GetExtendedStyle();
	//	dwStyle |= LVS_EX_FULLROWSELECT;// 选中某行使整行高亮（只适用与report 风格的listctrl ） 
	//	dwStyle |= LVS_EX_GRIDLINES;// 网格线（只适用与report 风格的listctrl ） 
	//	dwStyle |= LVS_EX_CHECKBOXES;//item 前生成checkbox 控件 
	//	mCustomListCtrl.SetExtendedStyle(dwStyle); // 设置扩展风格
	//}

	mCustomListCtrl.InsertColumn(0, _T("chip-id"), LVCFMT_CENTER, 80);
	mCustomListCtrl.InsertColumn(1, _T("Qw"), LVCFMT_LEFT, QWidth);
	mCustomListCtrl.InsertColumn(2, _T("Qx"), LVCFMT_LEFT, QWidth);
	mCustomListCtrl.InsertColumn(3, _T("Qy"), LVCFMT_LEFT, QWidth);
	mCustomListCtrl.InsertColumn(4, _T("Qz"), LVCFMT_LEFT, QWidth);

	this->SetTimer(1, 200, NULL);//50hz
}


int TestFormView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFormView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	//Fuck u

	for (int i = 0; i <= MAX_TRACKER_NUM; i++) {
		listMapGenID[i] = -1;
	}
	
	server = new LayserServer();

	server->Start(8999);
	
	
	return 0;
}


void TestFormView::OnBnClickedButton()
{
	// TODO: 在此添加控件通知处理程序代码

}

int id = 0;
void TestFormView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	vector<Tracker*>* trackers = server->GetTrackers();
	int i = 0;
	for (i = 0; i < trackers->size(); i++) {
		Tracker* var = (*trackers)[i];
		if (var == NULL)continue;

		if (i >= preListSize) {
			mCustomListCtrl.InsertItem(i, CString());
		}
		listMapGenID[i] = var->GenId;

		int row = i;
		int realID = var->ReadId;
		if (realID != -1) {
			tempString.Format(_T("%d"), var->ReadId);
		}
		else {
			tempString.SetString(_T("UnSet"));
		}
		mCustomListCtrl.SetItemText(row, 0, tempString.GetString());
		tempString.Format(_T("%.5f"), var->Qw);
		mCustomListCtrl.SetItemText(row, 1, tempString.GetString());
		tempString.Format(_T("%.5f"), var->Qx);
		mCustomListCtrl.SetItemText(row, 2, tempString.GetString());
		tempString.Format(_T("%.5f"), var->Qy);
		mCustomListCtrl.SetItemText(row, 3, tempString.GetString());
		tempString.Format(_T("%.5f"), var->Qz);
		mCustomListCtrl.SetItemText(row, 4, tempString.GetString());
	}

	for (i = trackers->size(); i < preListSize; i++) {
		mCustomListCtrl.DeleteItem(i);
		listMapGenID[i] = -1;
	}

	preListSize = mCustomListCtrl.GetItemCount();
	
	CFormView::OnTimer(nIDEvent);
}
