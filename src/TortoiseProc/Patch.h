#pragma once

#include "csmtp.h"

#define REG_SMTP_SERVER _T("Software\\TortoiseGit\\EMAIL\\SMTPSERVER")
#define REG_SMTP_PORT _T("Software\\TortoiseGit\\EMAIL\\PORT")
#define REG_SMTP_ISAUTH _T("Software\\TortoiseGit\\EMAIL\\ISAUTH")
#define REG_SMTP_USER _T("Software\\TortoiseGit\\EMAIL\\USER")
#define REG_SMTP_PASSWORD _T("Software\\TortoiseGit\\EMAIL\\PASSWORD")

class CPatch
{
protected:
	void AddRecipient(CSmtp &mail, CString &tolist, bool isCC= FALSE);
	void GetNameAddress(CString &in, CString &name,CString &address);
public:
	CPatch();
	~CPatch(void);
	int Parser(CString &pathfile);
	int Send(CString &pathfile,CString &To, CString &CC,bool bAttachment);

	CString m_Author;
	CString m_Date;
	CString m_Subject;
	CString m_PathFile;
	std::vector<BYTE> m_Body;
	CString m_strBody;
	void ConvertToArray(CString &to, CStringArray &Array);
};
