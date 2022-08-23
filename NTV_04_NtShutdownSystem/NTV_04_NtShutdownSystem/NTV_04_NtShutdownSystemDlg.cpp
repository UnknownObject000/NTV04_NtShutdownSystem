
// NTV_04_NtShutdownSystemDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "NTV_04_NtShutdownSystem.h"
#include "NTV_04_NtShutdownSystemDlg.h"
#include "afxdialogex.h"
#include "NtShutdownSystem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CNTV04NtShutdownSystemDlg 对话框



CNTV04NtShutdownSystemDlg::CNTV04NtShutdownSystemDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_NTV_04_NTSHUTDOWNSYSTEM_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNTV04NtShutdownSystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CNTV04NtShutdownSystemDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CNTV04NtShutdownSystemDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CNTV04NtShutdownSystemDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDB_EWE_SHUTDOWN, &CNTV04NtShutdownSystemDlg::OnBnClickedEweShutdown)
	ON_BN_CLICKED(IDB_EWE_PPOWEROFF, &CNTV04NtShutdownSystemDlg::OnBnClickedEwePpoweroff)
	ON_BN_CLICKED(IDB_EWE_REBOOT, &CNTV04NtShutdownSystemDlg::OnBnClickedEweReboot)
	ON_BN_CLICKED(IDB_NSS_SHUTDOWN, &CNTV04NtShutdownSystemDlg::OnBnClickedNssShutdown)
	ON_BN_CLICKED(IDB_NSS_POWEROFF, &CNTV04NtShutdownSystemDlg::OnBnClickedNssPoweroff)
	ON_BN_CLICKED(IDB_NSS_REBOOT, &CNTV04NtShutdownSystemDlg::OnBnClickedNssReboot)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CNTV04NtShutdownSystemDlg 消息处理程序

BOOL CNTV04NtShutdownSystemDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CNTV04NtShutdownSystemDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CNTV04NtShutdownSystemDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CNTV04NtShutdownSystemDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CNTV04NtShutdownSystemDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void CNTV04NtShutdownSystemDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CNTV04NtShutdownSystemDlg::OnBnClickedEweShutdown()
{
	// TODO: 在此添加控件通知处理程序代码
	GetShutdownPrivilege();
	ExitWindowsEx(EWX_SHUTDOWN, SHTDN_REASON_MAJOR_APPLICATION);
}


void CNTV04NtShutdownSystemDlg::OnBnClickedEwePpoweroff()
{
	// TODO: 在此添加控件通知处理程序代码
	GetShutdownPrivilege();
	ExitWindowsEx(EWX_POWEROFF, SHTDN_REASON_MAJOR_APPLICATION);
}


void CNTV04NtShutdownSystemDlg::OnBnClickedEweReboot()
{
	// TODO: 在此添加控件通知处理程序代码
	GetShutdownPrivilege();
	ExitWindowsEx(EWX_REBOOT, SHTDN_REASON_MAJOR_APPLICATION);
}


void CNTV04NtShutdownSystemDlg::OnBnClickedNssShutdown()
{
	// TODO: 在此添加控件通知处理程序代码
	GetShutdownPrivilege();
	NtShutdownSystem(ShutdownNoReboot);
}


void CNTV04NtShutdownSystemDlg::OnBnClickedNssPoweroff()
{
	// TODO: 在此添加控件通知处理程序代码
	GetShutdownPrivilege();
	NtShutdownSystem(ShutdownPowerOff);
}


void CNTV04NtShutdownSystemDlg::OnBnClickedNssReboot()
{
	// TODO: 在此添加控件通知处理程序代码
	GetShutdownPrivilege();
	NtShutdownSystem(ShutdownReboot);
}


void CNTV04NtShutdownSystemDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	exit(0);
	CDialogEx::OnClose();
}
