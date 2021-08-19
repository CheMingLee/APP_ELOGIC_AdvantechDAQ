
// APP_ELOGIC_AdvantechDAQDlg.h : header file
//

#pragma once


typedef void (*Def_Set_DevNum)(int iAiDevNum, int iDioDevNum);
typedef double (*Def_Read_AI)(int iChanel);
typedef int (*Def_Read_DI)(int iDI_pin);
typedef bool (*Def_Write_DO)(int iDO_pin, int iOutData);

// CAPP_ELOGIC_AdvantechDAQDlg dialog
class CAPP_ELOGIC_AdvantechDAQDlg : public CDialog
{
// Construction
public:
	CAPP_ELOGIC_AdvantechDAQDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_APP_ELOGIC_ADVANTECHDAQ_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	HINSTANCE m_hinstLib;
	Def_Set_DevNum m_Set_DevNum;
	Def_Read_AI m_Read_AI;
	Def_Read_DI m_Read_DI;
	Def_Write_DO m_Write_DO;
	int m_iAiDevNum;
	int m_iDioDevNum;
	int m_iAiChanel;
	int m_iDiPin;
	int m_iDoPin;
	int m_iDoData;
	afx_msg void OnBnClickedButtonSetDevnum();
	afx_msg void OnBnClickedButtonReadAi();
	afx_msg void OnBnClickedButtonReadDi();
	afx_msg void OnBnClickedButtonWriteDo();
	afx_msg void OnDestroy();
};
