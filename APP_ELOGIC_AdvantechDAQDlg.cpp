
// APP_ELOGIC_AdvantechDAQDlg.cpp : implementation file
//

#include "stdafx.h"
#include "APP_ELOGIC_AdvantechDAQ.h"
#include "APP_ELOGIC_AdvantechDAQDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CAPP_ELOGIC_AdvantechDAQDlg dialog
CAPP_ELOGIC_AdvantechDAQDlg::CAPP_ELOGIC_AdvantechDAQDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAPP_ELOGIC_AdvantechDAQDlg::IDD, pParent)
	, m_iAiDevNum(0)
	, m_iDioDevNum(0)
	, m_iAiChanel(0)
	, m_iDiPin(0)
	, m_iDoPin(0)
	, m_iDoData(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAPP_ELOGIC_AdvantechDAQDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAPP_ELOGIC_AdvantechDAQDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON_SET_DEVNUM, &CAPP_ELOGIC_AdvantechDAQDlg::OnBnClickedButtonSetDevnum)
	ON_BN_CLICKED(IDC_BUTTON_READ_AI, &CAPP_ELOGIC_AdvantechDAQDlg::OnBnClickedButtonReadAi)
	ON_BN_CLICKED(IDC_BUTTON_READ_DI, &CAPP_ELOGIC_AdvantechDAQDlg::OnBnClickedButtonReadDi)
	ON_BN_CLICKED(IDC_BUTTON_WRITE_DO, &CAPP_ELOGIC_AdvantechDAQDlg::OnBnClickedButtonWriteDo)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CAPP_ELOGIC_AdvantechDAQDlg message handlers

BOOL CAPP_ELOGIC_AdvantechDAQDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	m_hinstLib = LoadLibrary("ELOGIC_AdvantechDAQ.dll");
	m_Set_DevNum = (Def_Set_DevNum)GetProcAddress(m_hinstLib, "Set_DevNum");
	m_Read_AI = (Def_Read_AI)GetProcAddress(m_hinstLib, "Read_AI");
	m_Read_DI = (Def_Read_DI)GetProcAddress(m_hinstLib, "Read_DI");
	m_Write_DO = (Def_Write_DO)GetProcAddress(m_hinstLib, "Write_DO");

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CAPP_ELOGIC_AdvantechDAQDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CAPP_ELOGIC_AdvantechDAQDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CAPP_ELOGIC_AdvantechDAQDlg::OnDestroy()
{
	CDialog::OnDestroy();

	FreeLibrary(m_hinstLib);
}

void CAPP_ELOGIC_AdvantechDAQDlg::OnBnClickedButtonSetDevnum()
{
	if(!UpdateData(TRUE))
		return;

	m_Set_DevNum(m_iAiDevNum, m_iDioDevNum);
}

void CAPP_ELOGIC_AdvantechDAQDlg::OnBnClickedButtonReadAi()
{
	if(!UpdateData(TRUE))
		return;

	double dScaledData;
	CString strData;
	
	dScaledData	= m_Read_AI(m_iAiChanel);
	strData.Format("%f", dScaledData);
	GetDlgItem(IDC_STATIC_AI)->SetWindowTextA(strData);
}

void CAPP_ELOGIC_AdvantechDAQDlg::OnBnClickedButtonReadDi()
{
	if(!UpdateData(TRUE))
		return;

	int iDiData;
	CString strData;

	iDiData = m_Read_DI(m_iDiPin);
	strData.Format("%d", iDiData);
	GetDlgItem(IDC_STATIC_DI)->SetWindowTextA(strData);
}

void CAPP_ELOGIC_AdvantechDAQDlg::OnBnClickedButtonWriteDo()
{
	if(!UpdateData(TRUE))
		return;

	CString strData;

	if(m_Write_DO(m_iDoPin, m_iDoData))
		strData = "true";
	else
		strData = "false";
	GetDlgItem(IDC_STATIC_DO)->SetWindowTextA(strData);
}
