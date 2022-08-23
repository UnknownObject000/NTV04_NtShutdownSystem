
// NTV_04_NtShutdownSystemDlg.h: 头文件
//

#pragma once


// CNTV04NtShutdownSystemDlg 对话框
class CNTV04NtShutdownSystemDlg : public CDialogEx
{
// 构造
public:
	CNTV04NtShutdownSystemDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NTV_04_NTSHUTDOWNSYSTEM_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedEweShutdown();
	afx_msg void OnBnClickedEwePpoweroff();
	afx_msg void OnBnClickedEweReboot();
	afx_msg void OnBnClickedNssShutdown();
	afx_msg void OnBnClickedNssPoweroff();
	afx_msg void OnBnClickedNssReboot();
	afx_msg void OnClose();
};
