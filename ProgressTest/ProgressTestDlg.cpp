
// ProgressTestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ProgressTest.h"
#include "ProgressTestDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CProgressTestDlg �Ի���




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


// CProgressTestDlg ��Ϣ�������

BOOL CProgressTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_strText=_T("0%");
	m_intText=0;
	UpdateData(FALSE);
    m_ctrlProgress.SetRange(0,100);//���ý������ķ�Χ
    m_ctrlProgress.SetStep(10);//���ý�������ÿһ��������
    m_ctrlProgress.SetPos(0);//���ý������ĵ�ǰλ��


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CProgressTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CProgressTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CProgressTestDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(FALSE);
	int nLower=0;
	int nUpper=0;
	m_ctrlProgress.GetRange(nLower,nUpper);//��ȡ��������λ�÷�Χ�����ֵ����Сֵ
	if(m_ctrlProgress.GetPos()==nUpper)
	{
		m_ctrlProgress.SetPos(nLower);
    }
    m_ctrlProgress.StepIt();//��ÿһ�������������ӽ������ĵ�ǰλ��
	int nPos=(m_ctrlProgress.GetPos()-nLower)*100/(nUpper-nLower);//��ȡ�������ĵ�ǰλ��
	m_strText.Format(_T("%d%%"),nPos);
	m_intText=nPos;
	m_intText2=nPos;
	UpdateData(FALSE);
}


void CProgressTestDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_ctrlProgress.SetPos(m_intText);//���ý������ĵ�ǰλ��
	m_strText.Format(_T("%d%%"),m_intText);
	m_intText2=m_intText;
	UpdateData(FALSE);
}


void CProgressTestDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
	exit(0);
}


void CProgressTestDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
	exit(0);
}


void CProgressTestDlg::OnEnChangeEdit2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
}


void CProgressTestDlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
}


void CProgressTestDlg::OnEnChangeEdit3()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_ctrlProgress.SetPos(m_intText2);//���ý������ĵ�ǰλ��
	UpdateData(FALSE);
	m_strText.Format(_T("%d%%"),m_intText2);
	m_intText=m_intText2;
	UpdateData(FALSE);
}
