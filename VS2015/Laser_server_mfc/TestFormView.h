#pragma once



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
public:
	afx_msg void OnBnClickedButton();
};


