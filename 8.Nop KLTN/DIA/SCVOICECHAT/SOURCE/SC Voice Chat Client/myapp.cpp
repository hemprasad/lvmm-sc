// myapp.cpp: implementation of the myapp class.
//
//////////////////////////////////////////////////////////////////////
#include <afxwin.h>
#include "myapp.h"
#include "resource.h"
#include "Display.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// Chuong trinh cua nhom co su dung cac nguon tham khao sau day :
//	-Giao dien va chuong trinh voice chat chua ma hoa lay tu trang web  http://www.codeproject.com/KB/IP/voicechat2.aspx
//	-Source code cua AES 128 bit lay tu trang web http://www.efgh.com/software/rijndael.htm
//	-Source code cua ZUC lay tu file tai lieu  http://www.gsmworld.com/documents/EEA3_EIA3_ZUC_v1_5.pdf
//////////////////////////////////////////////////////////////////////
BOOL myapp::InitInstance()
{
Display dlg(IDD_DIALOG1);
m_pMainWnd=&dlg;
dlg.DoModal();

return FALSE;

}


myapp a;