
// ProgressTest.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CProgressTestApp:
// �йش����ʵ�֣������ ProgressTest.cpp
//

class CProgressTestApp : public CWinApp
{
public:
	CProgressTestApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CProgressTestApp theApp;