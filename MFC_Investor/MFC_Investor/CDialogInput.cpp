// CDialogInput.cpp: 实现文件
//

#include "stdafx.h"
#include "MFC_Investor.h"
#include "CDialogInput.h"
#include "afxdialogex.h"


// CDialogInput 对话框

IMPLEMENT_DYNAMIC(CDialogInput, CDialog)

CDialogInput::CDialogInput(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_INPUT, pParent)
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

}

CDialogInput::~CDialogInput()
{
}

void CDialogInput::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	DDX_Control(pDX, IDC_EDIT2, m_edit2);
}


BEGIN_MESSAGE_MAP(CDialogInput, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CDialogInput::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDialogInput::OnBnClickedButton2)
END_MESSAGE_MAP()


// CDialogInput 消息处理程序


void CDialogInput::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	MessageBox(L"递交成功", L"递交成功", 0);
}


void CDialogInput::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_edit1.SetWindowTextW(L"");
	m_edit2.SetWindowTextW(L"");
}
