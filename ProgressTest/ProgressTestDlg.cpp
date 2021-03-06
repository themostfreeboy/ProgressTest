
// ProgressTestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ProgressTest.h"
#include "ProgressTestDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CProgressTestDlg 对话框




CProgressTestDlg::CProgressTestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CProgressTestDlg::IDD, pParent)
	, m_strText(_T(""))
	, m_intText(0)
	, m_intText2(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CProgressTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS1, m_ctrlProgress);
	DDX_Text(pDX, IDC_EDIT1, m_strText);
	DDX_Text(pDX, IDC_EDIT2, m_intText);
	DDX_Text(pDX, IDC_EDIT3, m_intText2);
}

BEGIN_MESSAGE_MAP(CProgressTestDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CProgressTestDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CProgressTestDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDOK, &CProgressTestDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CProgressTestDlg::OnBnClickedCancel)
	ON_EN_CHANGE(IDC_EDIT2, &CProgressTestDlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT1, &CProgressTestDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT3, &CProgressTestDlg::OnEnChangeEdit3)
END_MESSAGE_MAP()


// CProgressTestDlg 消息处理程序

BOOL CProgressTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_strText=_T("0%");
	m_intText=0;
	UpdateData(FALSE);
    m_ctrlProgress.SetRange(0,100);//设置进度条的范围
    m_ctrlProgress.SetStep(10);//设置进度条的每一步的增量
    m_ctrlProgress.SetPos(0);//设置进度条的当前位置


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CProgressTestDlg::OnPaint()
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
HCURSOR CProgressTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CProgressTestDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(FALSE);
	int nLower=0;
	int nUpper=0;
	m_ctrlProgress.GetRange(nLower,nUpper);//获取进度条的位置范围的最大值和最小值
	if(m_ctrlProgress.GetPos()==nUpper)
	{
		m_ctrlProgress.SetPos(nLower);
    }
    m_ctrlProgress.StepIt();//用每一步的增量来增加进度条的当前位置
	int nPos=(m_ctrlProgress.GetPos()-nLower)*100/(nUpper-nLower);//获取进度条的当前位置
	m_strText.Format(_T("%d%%"),nPos);
	m_intText=nPos;
	m_intText2=nPos;
	UpdateData(FALSE);
}


void CProgressTestDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_ctrlProgress.SetPos(m_intText);//设置进度条的当前位置
	m_strText.Format(_T("%d%%"),m_intText);
	m_intText2=m_intText;
	UpdateData(FALSE);
}


void CProgressTestDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	exit(0);
}


void CProgressTestDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
	exit(0);
}


void CProgressTestDlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
}


void CProgressTestDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
}


void CProgressTestDlg::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_ctrlProgress.SetPos(m_intText2);//设置进度条的当前位置
	UpdateData(FALSE);
	m_strText.Format(_T("%d%%"),m_intText2);
	m_intText=m_intText2;
	UpdateData(FALSE);
}
