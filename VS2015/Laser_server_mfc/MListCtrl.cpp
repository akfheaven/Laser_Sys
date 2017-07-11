#include "stdafx.h"
#include "MListCtrl.h"

#define WM_USER_EDIT_END WM_USER + 1001


IMPLEMENT_DYNAMIC(CListCtrlEdit, CEdit)

BEGIN_MESSAGE_MAP(CListCtrlEdit, CEdit)
	ON_WM_KILLFOCUS()
END_MESSAGE_MAP()
void CListCtrlEdit::OnKillFocus(CWnd* pNewWnd)
{
	CEdit::OnKillFocus(pNewWnd);
	// 向父窗口发消息
	CWnd* pParent = this->GetParent();
	::PostMessage(pParent->GetSafeHwnd(), WM_USER_EDIT_END, 0, 0);
}
CListCtrlEdit::CListCtrlEdit(void)
{
}
CListCtrlEdit::~CListCtrlEdit(void)
{
}


IMPLEMENT_DYNAMIC(CMListCtrl, CListCtrl)
CMListCtrl::CMListCtrl()
{
	//RegisterWindowClass();
}


CMListCtrl::~CMListCtrl()
{
}

BOOL CMListCtrl::RegisterWindowClass(HINSTANCE hInstance)
{
	WNDCLASS wndcls;
	HINSTANCE hInst = AfxGetInstanceHandle();
	TCHAR* CLASSNAME = _T("CMListCtrl");
	if (!(::GetClassInfo(hInst, CLASSNAME, &wndcls)))
	{
		// otherwise we need to register a new class  
		wndcls.style = CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW;
		wndcls.lpfnWndProc = ::DefWindowProc;
		wndcls.cbClsExtra = wndcls.cbWndExtra = 0;
		wndcls.hInstance = hInst;
		wndcls.hIcon = NULL;
		wndcls.hCursor = AfxGetApp()->LoadStandardCursor(IDC_ARROW);
		wndcls.hbrBackground = (HBRUSH)(COLOR_3DFACE + 1);
		wndcls.lpszMenuName = NULL;
		wndcls.lpszClassName = CLASSNAME;

		if (!AfxRegisterClass(&wndcls))
		{
			AfxThrowResourceException();
			return FALSE;
		}
	}
	return TRUE;
	return 0;
}
BEGIN_MESSAGE_MAP(CMListCtrl, CListCtrl)
//	ON_WM_PAINT()
ON_WM_LBUTTONDBLCLK()
ON_MESSAGE(WM_USER_EDIT_END, CMListCtrl::OnEditEnd)
END_MESSAGE_MAP()


//void CMListCtrl::OnPaint()
//{
//	//CListCtrl::OnPaint();
//	CPaintDC dc(this); // device context for painting
//					   // TODO: 在此处添加消息处理程序代码
//					   // 不为绘图消息调用 CWnd::OnPaint()
//	dc.DrawText(L"test123", CRect(0, 0, 100, 100), DT_LEFT);
//}


void CMListCtrl::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//m_Edit.Create(ES_AUTOHSCROLL | WS_CHILD | ES_LEFT | ES_WANTRETURN | WS_BORDER, CRect(0, 0, 40, 20), this, IDC_EDIT);
	//m_Edit.ShowWindow(SW_SHOW);

	LVHITTESTINFO lvhti;    // 大气象：保存ListCtrl行列信息的结构
	lvhti.pt = point;
	nItem = CListCtrl::SubItemHitTest(&lvhti);
	if (nItem == -1) return;
	nSubItem = lvhti.iSubItem;

	CRect rect;
	CListCtrl::GetSubItemRect(nItem, nSubItem, LVIR_LABEL, rect);
	ShowEdit(TRUE, nItem, nSubItem, rect);
	CListCtrl::OnLButtonDblClk(nFlags, point);
}

LRESULT CMListCtrl::OnEditEnd(WPARAM wParam, LPARAM lParam)
{
	CString strText;
	m_Edit.GetWindowText(strText);
	CListCtrl::SetItemText(nItem, nSubItem, strText);
	m_Edit.ShowWindow(SW_HIDE);

	if (nSubItem == 0) {
		int id = _wtoi(strText.GetBuffer());
		::PostMessage(this->GetParent()->GetSafeHwnd(), WM_USER_EDIT_CHIP_ID, id, nItem);
	}

	return LRESULT(0);
}

void CMListCtrl::ShowEdit(bool bShow, int nItem, int nSubItem, CRect rcCtrl)
{
	if (m_Edit.m_hWnd == NULL)
	{
		m_Edit.Create(ES_AUTOHSCROLL | WS_CHILD | ES_LEFT | ES_WANTRETURN | WS_BORDER, CRect(0, 0, 0, 0), this, IDC_EDIT);
		m_Edit.ShowWindow(SW_HIDE);
		CFont tpFont;
		tpFont.CreateStockObject(DEFAULT_GUI_FONT);
		m_Edit.SetFont(&tpFont);
		tpFont.DeleteObject();
	}
	if (bShow == TRUE)
	{
		CString strItem = CListCtrl::GetItemText(nItem, nSubItem);
		rcCtrl.top -= 2;    // 大气象：防止上边框被遮挡
		m_Edit.MoveWindow(&rcCtrl);
		m_Edit.ShowWindow(SW_SHOW);
		m_Edit.SetWindowText(strItem);
		m_Edit.SetFocus();
		m_Edit.SetSel(-1);
	}
	else
		m_Edit.ShowWindow(SW_HIDE);
}
