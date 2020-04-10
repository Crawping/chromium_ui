#pragma  once
#include "chrome/iecore/trident/preheader.h"
#include <WinInet.h>
#include <MsHTML.h>
/*
  1���Զ���UA
  2��fixed IE11��ʧMSIE 11.0;compatibale;
    һ�������Headerͷ�е�UA
      ������վ��IE11�� ��ʾ��֧��,�����Ǽ���Request Headerͷ�е�UA  http://211.158.18.211/seeyon/index.jsp 
      bugzilla��ie11��ʧЧ��https://bugzilla.mozilla.org/show_bug.cgi?id=902515
    ����jsͨ��navigator.userAgent����ȡ�ͻ���UA
      �е���վ������js�����֧��������ġ�
    bug:�����ſ��޷���ⰲװ��flash
    bug:http://note.youdao.com/ �����¼û�е���
*/

typedef HRESULT (WINAPI *pfnObtainUserAgentString)(DWORD dwOption, LPSTR pcszUAOut, DWORD *cbSize);
typedef BOOL (WINAPI *pfnHttpAddRequestHeadersA)(HINTERNET hConnect, LPCSTR lpszHeaders, DWORD dwHeadersLength, DWORD dwModifiers);
typedef HRESULT (WINAPI *pfnNavigator_get_userAgent)( IOmNavigator* pThis,BSTR *p);

class CUserAgentHelper
{
public:
	CUserAgentHelper();
	~CUserAgentHelper();


	static pfnObtainUserAgentString RealObtainUserAgentString;
	static pfnHttpAddRequestHeadersA RealHttpAddRequestHeadersA;
  static pfnNavigator_get_userAgent RealNavigator_get_userAgent;
	static HRESULT WINAPI HookedObtainUserAgentString(DWORD dwOption, LPSTR pcszUAOut, DWORD *cbSize);
	static BOOL WINAPI HookedHttpAddRequestHeadersA(HINTERNET hConnect, LPCSTR lpszHeaders, DWORD dwHeadersLength, DWORD dwModifiers);
  static HRESULT WINAPI HookedNavigator_get_userAgent( IOmNavigator* pThis,BSTR *p);

	static CUserAgentHelper& GetInstance()
	{
		static CUserAgentHelper instance;
		return instance;
	}
	static void StartAPIHook();
  static void StartNavigatorHook();
private:
	HRESULT ProxyObtainUserAgentString(DWORD dwOption, LPSTR pcszUAOut, DWORD *cbSize);
	BOOL  ProxyHttpAddRequestHeadersA(HINTERNET hConnect, LPCSTR lpszHeaders, DWORD dwHeadersLength, DWORD dwModifiers);
  HRESULT ProxyNavigator_get_userAgent( IOmNavigator* pThis,BSTR *p);
  //
  BOOL MakeBrowserAgent(LPCTSTR lpszOriginalAgent, LPTSTR lpszBrowserAgent, DWORD dwSize);
  BOOL AddMSIE11(LPCTSTR lpszOriginalAgent, LPTSTR lpszBrowserAgent, DWORD dwSize);
  BOOL GetBrowserAgentFromOriginal(LPCTSTR lpszOriginalAgent, LPTSTR lpszBrowserAgent, DWORD dwSize);
};