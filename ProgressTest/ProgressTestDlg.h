
// ProgressTestDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"


// CProgressTestDlg 对话框
class CProgressTestDlg : public CDialogEx
{
// 构造
public:
	CProgressTestDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_PROGRESSTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CProgressCtrl m_ctrlProgress;
	afx_msg void OnBnClickedButton1();
	CString m_strText;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	int m_intText;
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit1();
	int m_intText2;
	afx_msg void OnEnChangeEdit3();
};
