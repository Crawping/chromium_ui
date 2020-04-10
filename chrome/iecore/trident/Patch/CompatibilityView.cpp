#include "chrome/iecore/trident/stdafx.h"
#include "CompatibilityView.h"
#include "chrome/iecore/third_party/detours/src/detours.h"
#include "CompatibilityViewRule.h"


extern BOOL _bIE8;
extern BOOL _bIE9;
extern BOOL _bIE10;
extern BOOL _bIE11;

pfnGetUrlCacheEntryInfoA CIECompatibilityView::RealGetUrlCacheEntryInfoA =NULL;
pfnGetUrlCacheEntryInfoW CIECompatibilityView::RealGetUrlCacheEntryInfoW=NULL;

CIECompatibilityView::CIECompatibilityView()
{

}

CIECompatibilityView::~CIECompatibilityView()
{

}

BOOL CIECompatibilityView::GetCompatViewListVersion(DWORD* pVerHigh, DWORD* pVerLow)
{
	DWORD dwType = REG_DWORD;
	DWORD dwVerHigh = 0;
	DWORD cbTempSize = sizeof(dwVerHigh);
	if(ERROR_SUCCESS == SHGetValue(HKEY_CURRENT_USER, _T("Software\\Microsoft\\Internet Explorer\\BrowserEmulation"), _T("IECompatVersionHigh"), &dwType, &dwVerHigh, &cbTempSize))
	{
		dwType = REG_DWORD;
		DWORD dwVerLow = 0;
		cbTempSize = sizeof(dwVerLow);
		if (ERROR_SUCCESS == SHGetValue(HKEY_CURRENT_USER, _T("Software\\Microsoft\\Internet Explorer\\BrowserEmulation"), _T("IECompatVersionLow"), &dwType, &dwVerLow, &cbTempSize))
		{
			*pVerHigh = dwVerHigh;
			*pVerLow = dwVerLow;
			return TRUE;
		}
	}
	return FALSE;
}
BOOL WINAPI CIECompatibilityView::HookedGetUrlCacheEntryInfoA(LPCSTR lpszUrlName, LPINTERNET_CACHE_ENTRY_INFOA lpCacheEntryInfo, LPDWORD lpcbCacheEntryInfo)
{
	return CIECompatibilityView::GetInstance().ProxyGetUrlCacheEntryInfoA(lpszUrlName,lpCacheEntryInfo,lpcbCacheEntryInfo);
}
BOOL  CIECompatibilityView::ProxyGetUrlCacheEntryInfoA(LPCSTR lpszUrlName, LPINTERNET_CACHE_ENTRY_INFOA lpCacheEntryInfo, LPDWORD lpcbCacheEntryInfo)
{
	BOOL bRet = RealGetUrlCacheEntryInfoA(lpszUrlName, lpCacheEntryInfo, lpcbCacheEntryInfo);

	if( strncmp(lpszUrlName, "iecompat:", 9) ) //ֻ����������б��ѯ��ַ
		return bRet;

	static DWORD s_dwCVVerHigh = 0;
	static DWORD s_dwCVVerLow = 0;
	static BOOL s_bGetCompatVer = FALSE;
	if (!s_bGetCompatVer)
	{
		s_bGetCompatVer = TRUE;
		GetCompatViewListVersion(&s_dwCVVerHigh, &s_dwCVVerLow); //��ȡ΢������б���ͼ�İ汾��

		if( 0==s_dwCVVerHigh && 0==s_dwCVVerLow )
			return FALSE;
	}

	if( FALSE == bRet && lpCacheEntryInfo && lpcbCacheEntryInfo /*&& GetLastError() == ERROR_FILE_NOT_FOUND*/ )
	{
		BOOL bIEXMode = FALSE;
		bIEXMode = CIECompatibilityViewData::GetInstance().MatchBlackList(lpszUrlName + 9);
    if(bIEXMode==FALSE)
      bIEXMode = CIECompatibilityViewData::GetInstance().MatchSelfBlackList(lpszUrlName + 9);
		if( bIEXMode )
		{
			//��д���ݽṹ
			size_t nStrLen = lstrlenA(lpszUrlName);
			memset(lpCacheEntryInfo, 0, *lpcbCacheEntryInfo); //����
			lpCacheEntryInfo->dwStructSize = sizeof(INTERNET_CACHE_ENTRY_INFOA);
			lpCacheEntryInfo->lpszSourceUrlName = (CHAR*)(((BYTE*)lpCacheEntryInfo) + lpCacheEntryInfo->dwStructSize);
			strncpy_s(lpCacheEntryInfo->lpszSourceUrlName, nStrLen + 1, lpszUrlName,_TRUNCATE);
			lpCacheEntryInfo->CacheEntryType = 9;
			lpCacheEntryInfo->lpHeaderInfo = lpCacheEntryInfo->lpszSourceUrlName + nStrLen + 1; //1���ַ�����β
			lpCacheEntryInfo->dwHeaderInfoSize = *lpcbCacheEntryInfo - (lpCacheEntryInfo->dwStructSize + nStrLen + 1);

			//��дheadinfo
			HeadInfo* pHeadInfo = (HeadInfo*)lpCacheEntryInfo->lpHeaderInfo;
			pHeadInfo->dwVerLow = s_dwCVVerLow;
			pHeadInfo->dwVerHigh = s_dwCVVerHigh;
			bRet = TRUE;
		}
	}

	if( bRet ){
		static BOOL fExcept = FALSE;
		if( !fExcept ){
			//dz@2012.05.17�޸�  __try catch��Ŀ�ģ�һ���˺�����δ��������������ʹ�������ڶ�IE�����򣬱���ʹ�ô����µı���  ��������IE�汾�жϴ����µı�������
			__try{
				if( _bIE8 )
        {
					static pfnCoInternetSetBrowserEmulationMode CoInternetSetBrowserEmulationMode=NULL;
					if( NULL==CoInternetSetBrowserEmulationMode )
						CoInternetSetBrowserEmulationMode = (pfnCoInternetSetBrowserEmulationMode)::GetProcAddress(GetModuleHandle(_T("urlmon.dll")),(LPCSTR)450 );
					if( CoInternetSetBrowserEmulationMode )
						CoInternetSetBrowserEmulationMode( 7 );
				}
				else if( _bIE9 || _bIE10 || _bIE11)
        {
					EmulationMode em = {0};
					em.dwCurMode = 7;
					em.dwBrowserMode = 0x201;
					//�ֲ���̬�����̰߳�ȫ
					static pfnCoInternetSetBrowserEmulationState CoInternetSetBrowserEmulationState=NULL;
					if( NULL==CoInternetSetBrowserEmulationState )
						CoInternetSetBrowserEmulationState = (pfnCoInternetSetBrowserEmulationState)::GetProcAddress(GetModuleHandle(_T("urlmon.dll")),(LPCSTR)450 );
					if( CoInternetSetBrowserEmulationState )
						CoInternetSetBrowserEmulationState( &em );
				}
			}
			__except( EXCEPTION_EXECUTE_HANDLER )
			{	fExcept=TRUE;	}
		}
	}

	return bRet;
}
BOOL WINAPI CIECompatibilityView::HookedGetUrlCacheEntryInfoW(LPCWSTR lpszUrlName, LPINTERNET_CACHE_ENTRY_INFOW lpCacheEntryInfo, LPDWORD lpcbCacheEntryInfo)
{
	return CIECompatibilityView::GetInstance().ProxyGetUrlCacheEntryInfoW(lpszUrlName,lpCacheEntryInfo,lpcbCacheEntryInfo);
}
BOOL  CIECompatibilityView::ProxyGetUrlCacheEntryInfoW(LPCWSTR lpszUrlName, LPINTERNET_CACHE_ENTRY_INFOW lpCacheEntryInfo, LPDWORD lpcbCacheEntryInfo)
{
	USES_CONVERSION;

	BOOL bRet = RealGetUrlCacheEntryInfoW(lpszUrlName, lpCacheEntryInfo, lpcbCacheEntryInfo);

	if( wcsncmp(lpszUrlName, L"iecompat:", 9) ) //ֻ����������б��ѯ��ַ
		return bRet;

	static DWORD s_dwCVVerHigh = 0;
	static DWORD s_dwCVVerLow = 0;
	static BOOL s_bGetCompatVer = FALSE;
	if (!s_bGetCompatVer)
	{
		s_bGetCompatVer = TRUE;
		GetCompatViewListVersion(&s_dwCVVerHigh, &s_dwCVVerLow); //��ȡ΢������б���ͼ�İ汾��

		if( 0==s_dwCVVerHigh && 0==s_dwCVVerLow )
			return FALSE;
	}

	if( FALSE == bRet && lpCacheEntryInfo && lpcbCacheEntryInfo /*&& GetLastError() == ERROR_FILE_NOT_FOUND*/ )
	{
		//��ѯ�������б�
		BOOL bIEXMode = FALSE;
		bIEXMode = CIECompatibilityViewData::GetInstance().MatchBlackList(W2A(lpszUrlName + 9));
    if(bIEXMode==FALSE)
      bIEXMode = CIECompatibilityViewData::GetInstance().MatchSelfBlackList(W2A(lpszUrlName + 9));
		if( bIEXMode)
		{
			//��д���ݽṹ
			size_t nStrLen = wcslen(lpszUrlName);
			memset(lpCacheEntryInfo, 0, *lpcbCacheEntryInfo); //����
			lpCacheEntryInfo->dwStructSize = sizeof(INTERNET_CACHE_ENTRY_INFOW);
			lpCacheEntryInfo->lpszSourceUrlName = (WCHAR*)(((BYTE*)lpCacheEntryInfo) + lpCacheEntryInfo->dwStructSize);
			wcsncpy_s(lpCacheEntryInfo->lpszSourceUrlName, nStrLen + 1, lpszUrlName,_TRUNCATE);
			lpCacheEntryInfo->CacheEntryType = 9;
			lpCacheEntryInfo->lpHeaderInfo = lpCacheEntryInfo->lpszSourceUrlName + nStrLen + 1; //1���ַ�����β
			lpCacheEntryInfo->dwHeaderInfoSize = *lpcbCacheEntryInfo - (lpCacheEntryInfo->dwStructSize + nStrLen + 1);

			//��дheadinfo
			HeadInfo* pHeadInfo = (HeadInfo*)lpCacheEntryInfo->lpHeaderInfo;
			pHeadInfo->dwVerLow = s_dwCVVerLow;
			pHeadInfo->dwVerHigh = s_dwCVVerHigh;

			bRet = TRUE;
		}
	}

	if( bRet )
	{
		static BOOL fExcept = FALSE;
		if( !fExcept ){
			//dz@2012.05.17�޸�   __try catch��Ŀ�ģ�һ���˺�����δ��������������ʹ�������ڶ�IE�����򣬱���ʹ�ô����µı���  ��������IE�汾�жϴ����µı�������
			__try{
				if( _bIE8 )
        {
					static pfnCoInternetSetBrowserEmulationMode CoInternetSetBrowserEmulationMode=NULL;
					if( NULL==CoInternetSetBrowserEmulationMode )
						CoInternetSetBrowserEmulationMode = (pfnCoInternetSetBrowserEmulationMode)::GetProcAddress(GetModuleHandle(_T("urlmon.dll")),(LPCSTR)450 );
					if( CoInternetSetBrowserEmulationMode )
						CoInternetSetBrowserEmulationMode( 7 );
				}
				else if( _bIE9 || _bIE10 || _bIE11)
        {
					EmulationMode em = {0};
					em.dwCurMode = 7;
					em.dwBrowserMode = 0x201;
					//�ֲ���̬�����̰߳�ȫ
					static pfnCoInternetSetBrowserEmulationState CoInternetSetBrowserEmulationState=NULL;
					if( NULL==CoInternetSetBrowserEmulationState )
						CoInternetSetBrowserEmulationState = (pfnCoInternetSetBrowserEmulationState)::GetProcAddress(GetModuleHandle(_T("urlmon.dll")),(LPCSTR)450 );
					if( CoInternetSetBrowserEmulationState )
						CoInternetSetBrowserEmulationState( &em );
				}
			}
			__except( EXCEPTION_EXECUTE_HANDLER )
			{
				fExcept=TRUE;
			}
		}
	}

	return bRet;
}
void  CIECompatibilityView::StartAPIHook()
{
  if(_bIE8 || _bIE9 || _bIE10 || _bIE11)
  {
    HMODULE wininet = GetModuleHandle(_T("wininet.dll"));
    if (!wininet)
      wininet = LoadLibrary(_T("wininet.dll"));
    if( wininet ) {
      RealGetUrlCacheEntryInfoA = (pfnGetUrlCacheEntryInfoA)GetProcAddress(wininet, "GetUrlCacheEntryInfoA");
      if( RealGetUrlCacheEntryInfoA )
        DetourAttach(&(PVOID&)RealGetUrlCacheEntryInfoA,HookedGetUrlCacheEntryInfoA);
      RealGetUrlCacheEntryInfoW = (pfnGetUrlCacheEntryInfoW)GetProcAddress(wininet, "GetUrlCacheEntryInfoW");
      if( RealGetUrlCacheEntryInfoW )
        DetourAttach(&(PVOID&)RealGetUrlCacheEntryInfoW, HookedGetUrlCacheEntryInfoW);
    }
  }
}
