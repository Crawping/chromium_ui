
#pragma once
#include <DbgHelp.h>
#include <string>
/*todo:�ο� http://blog.csdn.net/pkrobbie/article/details/6636310
1��dump�Ĵ�С����������� �ο�http://www.debuginfo.com/tools/minidumpwizard.html
2��dump�����û��Զ�������
*/
typedef enum _WG_DUMPTYPE
{
	SMALL_DUMP = MiniDumpNormal,
	BIG_DUMP = MiniDumpNormal | MiniDumpWithUnloadedModules |MiniDumpWithProcessThreadData|MiniDumpWithIndirectlyReferencedMemory,
	FULL_DUMP = MiniDumpWithFullMemory,

}WG_DUMPTYPE;

class CExceptionHandler
{
public:
	CExceptionHandler();
	virtual ~CExceptionHandler();

public:
	void SetExceptionHandler();
	//try_catch 3�μ�Ϊ����
	static LONG CatchException(PEXCEPTION_POINTERS ExceptionInfo);
	//����
	static LONG WINAPI ExceptionFilter(PEXCEPTION_POINTERS ExceptionInfo);

private:
	static void InitDumpFile( std::wstring &szFile);
	static void GetTime(int nDays, PTSTR szTime, int nLen);
	static void CreateDumpFile(LPCTSTR szDumpFile,PEXCEPTION_POINTERS pExceptionInfo,
		PMINIDUMP_USER_STREAM_INFORMATION pUserStreamParam=NULL,WG_DUMPTYPE type =BIG_DUMP );
	static PMINIDUMP_USER_STREAM_INFORMATION InitUserStreamData();
};
