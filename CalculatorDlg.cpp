
// CalculatorDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCalculatorDlg 对话框



CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
	, editContent(_T(""))
	, displayContent(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	processor = Processor();
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT, editContent);
	DDX_Text(pDX, IDC_EDIT_Display, displayContent);
	DDX_Control(pDX, IDC_EDIT, edit);
	DDX_Control(pDX, IDC_EDIT_Display, display);
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_Num1, &CCalculatorDlg::OnBnClickedButtonNum1)
	ON_BN_CLICKED(IDC_BUTTON_Num2, &CCalculatorDlg::OnBnClickedButtonNum2)
	ON_BN_CLICKED(IDC_BUTTON_Num3, &CCalculatorDlg::OnBnClickedButtonNum3)
	ON_BN_CLICKED(IDC_BUTTON_Num4, &CCalculatorDlg::OnBnClickedButtonNum4)
	ON_BN_CLICKED(IDC_BUTTON_Num5, &CCalculatorDlg::OnBnClickedButtonNum5)
	ON_BN_CLICKED(IDC_BUTTON_Num6, &CCalculatorDlg::OnBnClickedButtonNum6)
	ON_BN_CLICKED(IDC_BUTTON_Num7, &CCalculatorDlg::OnBnClickedButtonNum7)
	ON_BN_CLICKED(IDC_BUTTON_Num8, &CCalculatorDlg::OnBnClickedButtonNum8)
	ON_BN_CLICKED(IDC_BUTTON_Num9, &CCalculatorDlg::OnBnClickedButtonNum9)
	ON_BN_CLICKED(IDC_BUTTON_Num0, &CCalculatorDlg::OnBnClickedButtonNum0)
	ON_BN_CLICKED(IDC_BUTTON_Backspace, &CCalculatorDlg::OnBnClickedButtonBackspace)
	ON_BN_CLICKED(IDC_BUTTON_Division, &CCalculatorDlg::OnBnClickedButtonDivision)
	ON_BN_CLICKED(IDC_BUTTON_Multiply, &CCalculatorDlg::OnBnClickedButtonMultiply)
	ON_BN_CLICKED(IDC_BUTTON_Minus, &CCalculatorDlg::OnBnClickedButtonMinus)
	ON_BN_CLICKED(IDC_BUTTON_Add, &CCalculatorDlg::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_Dot, &CCalculatorDlg::OnBnClickedButtonDot)
	ON_BN_CLICKED(IDC_BUTTON_Left_Bracket, &CCalculatorDlg::OnBnClickedButtonLeftBracket)
	ON_BN_CLICKED(IDC_BUTTON_Right_Bracket, &CCalculatorDlg::OnBnClickedButtonRightBracket)
	ON_BN_CLICKED(IDC_BUTTON_C, &CCalculatorDlg::OnBnClickedButtonC)
	ON_BN_CLICKED(IDC_BUTTON_Equal, &CCalculatorDlg::OnBnClickedButtonEqual)
	ON_BN_CLICKED(IDC_BUTTON_Inverse, &CCalculatorDlg::OnBnClickedButtonInverse)
	ON_WM_GETMINMAXINFO()
	ON_EN_CHANGE(IDC_EDIT, &CCalculatorDlg::OnChangeEdit)
END_MESSAGE_MAP()


// CCalculatorDlg 消息处理程序

BOOL CCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	//ShowWindow(SW_MAXIMIZE);

	//ShowWindow(SW_MINIMIZE);

	// TODO: 在此添加额外的初始化代码
	CFont editFont;
	editFont.CreatePointFont(300, _T("微软雅黑"));
	edit.SetFont(&editFont);
	editContent = "0";
	UpdateData(FALSE);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCalculatorDlg::OnPaint()
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
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CCalculatorDlg::OnBnClickedButtonEqual()
{
	displayContent = editContent;
	double res;
	if (processor.Calculate(displayContent, res))
		editContent.Format(_T("%g"), res);
	else
		editContent = "ERROR!";

	UpdateData(FALSE);
}

void CCalculatorDlg::OnBnClickedButtonNum1()
{
	if (editContent == "0" || editContent == "ERROR!" || editContent == "inf")
		editContent.Empty();
	editContent.AppendChar('1');
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonNum2()
{
	if (editContent == "0" || editContent == "ERROR!" || editContent == "inf")
		editContent.Empty();
	editContent.AppendChar('2');
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonNum3()
{
	if (editContent == "0" || editContent == "ERROR!" || editContent == "inf")
		editContent.Empty();
	editContent.AppendChar('3');
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonNum4()
{
	if (editContent == "0" || editContent == "ERROR!" || editContent == "inf")
		editContent.Empty();
	editContent.AppendChar('4');
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonNum5()
{
	if (editContent == "0" || editContent == "ERROR!" || editContent == "inf")
		editContent.Empty();
	editContent.AppendChar('5');
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonNum6()
{
	if (editContent == "0" || editContent == "ERROR!" || editContent == "inf")
		editContent.Empty();
	editContent.AppendChar('6');
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonNum7()
{
	if (editContent == "0" || editContent == "ERROR!" || editContent == "inf")
		editContent.Empty();
	editContent.AppendChar('7');
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonNum8()
{
	if (editContent == "0" || editContent == "ERROR!" || editContent == "inf")
		editContent.Empty();
	editContent.AppendChar('8');
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonNum9()
{
	if (editContent == "0" || editContent == "ERROR!" || editContent == "inf")
		editContent.Empty();
	editContent.AppendChar('9');
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonNum0()
{
	if (editContent == "0" || editContent == "ERROR!" || editContent == "inf")
		editContent.Empty();
	editContent.AppendChar('0');
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonBackspace()
{
	editContent.Delete(editContent.GetLength() - 1);
	if (editContent.IsEmpty())
		editContent = "0";
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonDivision()
{
	editContent.AppendChar('/');
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonMultiply()
{
	editContent.AppendChar('*');
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonMinus()
{
	editContent.AppendChar('-');
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonAdd()
{
	editContent.AppendChar('+');
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonDot()
{
	editContent.AppendChar('.');
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonLeftBracket()
{
	if (editContent == "0" || editContent == "ERROR!" || editContent == "inf")
		editContent.Empty();
	editContent.AppendChar('(');
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonRightBracket()
{
	if (editContent == "0" || editContent == "ERROR!" || editContent == "inf")
		editContent.Empty();
	editContent.AppendChar(')');
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonC()
{
	displayContent.Empty();
	editContent = "0";
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonInverse()
{
	editContent.AppendChar(')');
	editContent.Insert(0, '(');
	editContent.Insert(0, '/');
	editContent.Insert(0, '1');
	UpdateData(FALSE);
}


void CCalculatorDlg::OnGetMinMaxInfo(MINMAXINFO* lpMMI)
{
	lpMMI->ptMinTrackSize.x = 282;
	lpMMI->ptMinTrackSize.y = 588;

	CDialogEx::OnGetMinMaxInfo(lpMMI);
}


void CCalculatorDlg::OnChangeEdit()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	UpdateData(TRUE);
	if (editContent.IsEmpty())
		editContent = "0";
	UpdateData(FALSE);
}

