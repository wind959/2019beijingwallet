// CDialogpasswordTools.cpp: 实现文件
//

#include "stdafx.h"
#include "MFC_Investor.h"
#include "CDialogpasswordTools.h"
#include "afxdialogex.h"


// CDialogpasswordTools 对话框

IMPLEMENT_DYNAMIC(CDialogpasswordTools, CDialogEx)

CDialogpasswordTools::CDialogpasswordTools(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_tools, pParent)
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

}

CDialogpasswordTools::~CDialogpasswordTools()
{
}

void CDialogpasswordTools::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE1, m_tree1);
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	DDX_Control(pDX, IDC_LIST2, m_list);
	DDX_Control(pDX, IDC_EDIT2, m_edit2);
	DDX_Control(pDX, IDC_EDIT4, m_edit4);
	DDX_Control(pDX, IDC_SLIDER1, m_slider);
}


BEGIN_MESSAGE_MAP(CDialogpasswordTools, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDialogpasswordTools::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDialogpasswordTools::OnBnClickedButton2)
END_MESSAGE_MAP()


// CDialogpasswordTools 消息处理程序

#include <iostream>
#include <ctime>
using namespace std;

string CDialogpasswordTools::randstr(string strCharElem, int nOutStrLen)
{
	string strRet;
	strRet.insert(0, nOutStrLen, '\0');





	int iRand = 0;
	for (int i = 0; i < nOutStrLen; ++i)
	{
		iRand = rand() % strCharElem.length();
		strRet[i] = strCharElem[iRand];
	}
	return strRet;
}


void CDialogpasswordTools::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	//mypass;
	m_edit1.GetWindowTextW(mypass);
	MessageBox(L"私钥打碎成功", L"私钥打碎", 0);

	//m_edit1.GetWindowTextW(laststr);
	m_list.ResetContent();
	srand((unsigned)time(0));
	for (int i = 0; i < 10; i++) {

		string mystr = randstr("abcdefghigklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890", 16);
		m_list.AddString((CStringW)(char*)mystr.c_str());
		mystr = "";
		//m_list.AddString(_T( mystr.c_str() ));
	}

}


void CDialogpasswordTools::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_edit2.SetWindowTextW(mypass);
	MessageBox(L"私钥恢复成功", L"私钥恢复", 0);



}


BOOL CDialogpasswordTools::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_edit4.SetWindowTextW(L"TRX-password-yincheng");

	m_slider.SetRange(0, 100);  //假如让用户选分钟,限定只能是0至59中的某个数字
	m_slider.SetPos(60);


	//设置树形控件样式

	//m_tree.ModifyStyle(NULL, TVS_HASBUTTONS | TVS_LINESATROOT | TVS_HASLINES);



	//HTREEITEM相当于是一个结点的句柄
	HTREEITEM hRoot1;
	HTREEITEM hRoot2;
	HTREEITEM hChild1;
	HTREEITEM hChild2;


	hRoot1 = m_tree1.InsertItem(L"亲人", TVI_ROOT); //插入根结点



	hChild1 = m_tree1.InsertItem(L"爸爸", hRoot1);
	hChild1 = m_tree1.InsertItem(L"妈妈", hRoot1);
	hChild1 = m_tree1.InsertItem(L"姐姐", hRoot1);
	hChild1 = m_tree1.InsertItem(L"哥哥", hRoot1);
	hChild1 = m_tree1.InsertItem(L"弟弟", hRoot1);
	hChild1 = m_tree1.InsertItem(L"妹妹", hRoot1);



	hRoot2 = m_tree1.InsertItem(L"朋友", TVI_ROOT); //插入根结点
	hChild2 = m_tree1.InsertItem(L"李笑来", hRoot2);
	hChild2 = m_tree1.InsertItem(L"李哭去", hRoot2);
	hChild2 = m_tree1.InsertItem(L"孙宇晨", hRoot2);
	hChild2 = m_tree1.InsertItem(L"帅初", hRoot2);
	hChild2 = m_tree1.InsertItem(L"宝二爷", hRoot2);
	hChild2 = m_tree1.InsertItem(L"郭洪才", hRoot2);


	m_tree1.Expand(hRoot1, TVE_EXPAND);
	m_tree1.Expand(hRoot2, TVE_EXPAND);

	//m_pSelection = nullptr;    // 初始化所选内容

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
