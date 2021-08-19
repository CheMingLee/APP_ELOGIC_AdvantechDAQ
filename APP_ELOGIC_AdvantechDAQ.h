
// APP_ELOGIC_AdvantechDAQ.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CAPP_ELOGIC_AdvantechDAQApp:
// See APP_ELOGIC_AdvantechDAQ.cpp for the implementation of this class
//

class CAPP_ELOGIC_AdvantechDAQApp : public CWinAppEx
{
public:
	CAPP_ELOGIC_AdvantechDAQApp();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CAPP_ELOGIC_AdvantechDAQApp theApp;