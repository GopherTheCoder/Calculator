
// CalculatorDlg.h: 头文件
//

#pragma once

#include "Processor.h"

// CCalculatorDlg 对话框
class CCalculatorDlg : public CDialogEx
{
// 构造
public:
	CCalculatorDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
	Processor processor;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString editContent;
	afx_msg void OnBnClickedButtonNum1();
	afx_msg void OnBnClickedButtonNum2();
	afx_msg void OnBnClickedButtonNum3();
	afx_msg void OnBnClickedButtonNum4();
	afx_msg void OnBnClickedButtonNum5();
	afx_msg void OnBnClickedButtonNum6();
	afx_msg void OnBnClickedButtonNum7();
	afx_msg void OnBnClickedButtonNum8();
	afx_msg void OnBnClickedButtonNum9();
	afx_msg void OnBnClickedButtonNum0();
	afx_msg void OnBnClickedButtonBackspace();
	afx_msg void OnBnClickedButtonDivision();
	afx_msg void OnBnClickedButtonMultiply();
	afx_msg void OnBnClickedButtonMinus();
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonDot();
	afx_msg void OnBnClickedButtonLeftBracket();
	afx_msg void OnBnClickedButtonRightBracket();
	afx_msg void OnBnClickedButtonC();
	CString displayContent;
	afx_msg void OnBnClickedButtonEqual();
	CEdit edit;
	CEdit display;
	afx_msg void OnBnClickedButtonInverse();
	afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
	afx_msg void OnChangeEdit();
//	afx_msg void OnSetFocus(CWnd* pOldWnd);
//	afx_msg void OnKillfocusEdit();
//	afx_msg void OnUpdateEdit();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};
