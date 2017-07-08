
// Laser_server_mfc.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "Laser_server_mfc.h"
#include "MainFrm.h"

#include "Laser_server_mfcDoc.h"
#include "Laser_server_mfcView.h"
#include "TestFormView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


// CLaser_server_mfcApp

BEGIN_MESSAGE_MAP(CLaser_server_mfcApp, CWinApp)
	//ON_COMMAND(ID_APP_ABOUT, &CLaser_server_mfcApp::OnAppAbout)
	// �����ļ��ı�׼�ĵ�����
	ON_COMMAND(ID_FILE_NEW, &CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinApp::OnFileOpen)
END_MESSAGE_MAP()


// CLaser_server_mfcApp ����

CLaser_server_mfcApp::CLaser_server_mfcApp()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// ���Ӧ�ó��������ù�����������ʱ֧��(/clr)�����ģ���: 
	//     1) �����д˸������ã�������������������֧�ֲ�������������
	//     2) ��������Ŀ�У������밴������˳���� System.Windows.Forms ������á�
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO: ������Ӧ�ó��� ID �ַ����滻ΪΨһ�� ID �ַ�����������ַ�����ʽ
	//Ϊ CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("Laser_server_mfc.AppID.NoVersion"));

	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}

// Ψһ��һ�� CLaser_server_mfcApp ����

CLaser_server_mfcApp theApp;


// CLaser_server_mfcApp ��ʼ��

BOOL CLaser_server_mfcApp::InitInstance()
{
	{
		CSingleDocTemplate* pNewDocTemplate = new CSingleDocTemplate(
			IDR_TESTFORMVIEW_TMPL,
			RUNTIME_CLASS(CLaser_server_mfcDoc),
			RUNTIME_CLASS(CMainFrame),
			RUNTIME_CLASS(TestFormView));
		AddDocTemplate(pNewDocTemplate);
	}

	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()��  ���򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	// ��ʼ�� OLE ��
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction(FALSE);

	// ʹ�� RichEdit �ؼ���Ҫ AfxInitRichEdit2()	
	// AfxInitRichEdit2();

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));
	LoadStdProfileSettings(4);  // ���ر�׼ INI �ļ�ѡ��(���� MRU)


	// ע��Ӧ�ó�����ĵ�ģ�塣  �ĵ�ģ��
	// �������ĵ�����ܴ��ں���ͼ֮�������
	//CSingleDocTemplate* pDocTemplate;
	//pDocTemplate = new CSingleDocTemplate(
	//	IDR_MAINFRAME,
	//	RUNTIME_CLASS(CLaser_server_mfcDoc),
	//	RUNTIME_CLASS(CMainFrame),       // �� SDI ��ܴ���
	//	RUNTIME_CLASS(CLaser_server_mfcView));
	//if (!pDocTemplate)
	//	return FALSE;
	//AddDocTemplate(pDocTemplate);


	//pDocTemplate = new CSingleDocTemplate(
	//	IDD_FORMVIEW,
	//	RUNTIME_CLASS(CLaser_server_mfcDoc),
	//	RUNTIME_CLASS(CMainFrame),       // �� SDI ��ܴ���
	//	RUNTIME_CLASS(TestFormView));
	//if (!pDocTemplate)
	//	return FALSE;
	//AddDocTemplate(pDocTemplate);

	

	// ������׼ shell ���DDE�����ļ�������������
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);



	// ��������������ָ�������  ���
	// �� /RegServer��/Register��/Unregserver �� /Unregister ����Ӧ�ó����򷵻� FALSE��
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	m_pMainWnd->SetWindowTextW(_T("2333"));

	// Ψһ��һ�������ѳ�ʼ���������ʾ����������и���
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

int CLaser_server_mfcApp::ExitInstance()
{
	//TODO: �����������ӵĸ�����Դ
	AfxOleTerm(FALSE);

	return CWinApp::ExitInstance();
}

// CLaser_server_mfcApp ��Ϣ�������






// �������жԻ����Ӧ�ó�������
void CLaser_server_mfcApp::OnAppAbout()
{
	
	//aboutDlg.DoModal();
	if (!aboutDlg.m_hWnd) {
		aboutDlg.Create(IDD_ABOUTBOX);
	}
	aboutDlg.ShowWindow(SW_SHOW);
}

// CLaser_server_mfcApp ��Ϣ�������





//void CAboutDlg::OnAppAbout()
//{
//	// TODO: �ڴ���������������
//	CAboutDlg aboutDlg;
//	aboutDlg.DoModal();
//}
