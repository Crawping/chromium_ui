

//������Ⱦ������������ͼ���ܣ�������IE9&IE10��CoInternetSetBrowserEmulationMode���岻ͬ������ͬ�Ĵ���
//����ʹ��IE�ļ�����ͼ������Ȼ���������Լ�������
//IE9������ṹ��9*DWORD�ռ䣬IE10������ṹ��0x4D*DWORD���ռ䣬����������ǰ�����ṹ�����Ƶ���һ���ڴ�����
//SE��������ṹ��0x50*DWORD���ռ�
#pragma once
#include "chrome/iecore/trident/preheader.h"
#include <WinInet.h>
#pragma pack(2)
typedef struct _tagHeadInfo
{
	DWORD dwVerLow;
	DWORD dwVerHigh;
	DWORD dwAttr;
	DWORD dwFeature;
	DWORD dwReserve;
	short unknown;
}HeadInfo; //sizeof = 26 bytes
#pragma pack()

typedef struct _tagEmulationMode
{
	DWORD dwCurMode;
	DWORD dwBrowserMode;   //������ΪIE7ģʽ��IE9&IE10���Ĳ�����0x201,���岻���
	DWORD dwReserve[0x4E];
}EmulationMode, *PEmulationMode;

//IE8�º���Ϊ��urlmon!CoInternetSetBrowserEmulationMode
typedef HRESULT (__stdcall* pfnCoInternetSetBrowserEmulationMode)(	DWORD dwCurMode	);
//IE9&IE10�º���Ϊ��urlmon!CoInternetSetBrowserEmulationState
typedef HRESULT (__stdcall* pfnCoInternetSetBrowserEmulationState)(	PEmulationMode	);

typedef BOOL (WINAPI *pfnGetUrlCacheEntryInfoA)(LPCSTR lpszUrlName, LPINTERNET_CACHE_ENTRY_INFOA lpCacheEntryInfo, LPDWORD lpcbCacheEntryInfo);
typedef BOOL (WINAPI *pfnGetUrlCacheEntryInfoW)(LPCWSTR lpszUrlName, LPINTERNET_CACHE_ENTRY_INFOW lpCacheEntryInfo, LPDWORD lpcbCacheEntryInfo);

//funtion 
class CIECompatibilityView
{
public:
	CIECompatibilityView();
	~CIECompatibilityView();

	static pfnGetUrlCacheEntryInfoA RealGetUrlCacheEntryInfoA;
	static pfnGetUrlCacheEntryInfoW RealGetUrlCacheEntryInfoW ;
	static BOOL WINAPI HookedGetUrlCacheEntryInfoA(LPCSTR lpszUrlName, LPINTERNET_CACHE_ENTRY_INFOA lpCacheEntryInfo, LPDWORD lpcbCacheEntryInfo);
	static BOOL WINAPI HookedGetUrlCacheEntryInfoW(LPCWSTR lpszUrlName, LPINTERNET_CACHE_ENTRY_INFOW lpCacheEntryInfo, LPDWORD lpcbCacheEntryInfo);
	static CIECompatibilityView& GetInstance()
	{
		static CIECompatibilityView instance;
		return instance;
	}
	static void StartAPIHook();
private:
	BOOL ProxyGetUrlCacheEntryInfoA(LPCSTR lpszUrlName, LPINTERNET_CACHE_ENTRY_INFOA lpCacheEntryInfo, LPDWORD lpcbCacheEntryInfo); 
	BOOL ProxyGetUrlCacheEntryInfoW(LPCWSTR lpszUrlName, LPINTERNET_CACHE_ENTRY_INFOW lpCacheEntryInfo, LPDWORD lpcbCacheEntryInfo);

	BOOL GetCompatViewListVersion(DWORD* pVerHigh, DWORD* pVerLow);
};

