
// ProgressTestDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"


// CProgressTestDlg �Ի���
class CProgressTestDlg : public CDialogEx
{
// ����
public:
	CProgressTestDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_PROGRESSTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
