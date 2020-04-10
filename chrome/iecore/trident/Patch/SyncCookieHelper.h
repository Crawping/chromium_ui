
/*
cookieͬ����
InternetSetCookieW
InternetSetCookieExW
RealInternetSetCookieA
InternetSetCookieExA

��document.cookie��
InternetGetCookieExA
InternetGetCookieExW

InternetSetStatusCallbackA
HttpSendRequestExA
HttpSendRequestExW

���������⣺HTTP Requset Header��cookieû��Я��
1��˫���л�  cookie��ʧ����˳�
2��wan.360.cn�޷���¼  OnBeforeNavigate
3��yunpan.360.cn�޷���¼
4��һЩhttps��վ�޷���¼
5��302��ת�޷���cookie
*/
#pragma once
#include "chrome/iecore/trident/preheader.h"
#include <WinInet.h>
typedef HINTERNET (WINAPI *pfnHttpOpenRequestA)(HINTERNET hConnect,LPCSTR lpszVerb,LPCSTR lpszObjectName,LPCSTR lpszVersion,LPCSTR lpszReferrer,LPCSTR FAR * lplpszAcceptTypes,DWORD dwFlags,DWORD_PTR dwContext);
typedef HINTERNET (WINAPI *pfnHttpOpenRequestW)(HINTERNET hConnect,LPCWSTR lpszVerb,LPCWSTR lpszObjectName,LPCWSTR lpszVersion,LPCWSTR lpszReferrer,LPCWSTR FAR * lplpszAcceptTypes,DWORD dwFlags,DWORD_PTR dwContext) ;
typedef BOOL (WINAPI *pfnInternetSetCookieA)(LPCSTR lpszUrl,LPCSTR lpszCookieName,LPCSTR lpszCookieData) ;
typedef BOOL (WINAPI *pfnInternetSetCookieW)(LPCWSTR lpszUrl,LPCWSTR lpszCookieName,LPCWSTR lpszCookieData);
typedef DWORD (WINAPI *pfnInternetSetCookieExA)(LPCSTR lpszUrl,LPCSTR lpszCookieName,LPCSTR lpszCookieData,DWORD dwFlags,DWORD_PTR dwReserved);
typedef DWORD (WINAPI *pfnInternetSetCookieExW)(LPCWSTR lpszUrl,LPCWSTR lpszCookieName,LPCWSTR lpszCookieData,DWORD dwFlags,DWORD_PTR dwReserved) ;
typedef BOOL (WINAPI *pfnInternetGetCookieExA)(LPCSTR lpszUrl,LPCSTR lpszCookieName,LPSTR lpszCookieData,LPDWORD pcchCookieData,DWORD dwFlags,LPVOID dwReserved) ;
//add to support IE11
typedef BOOL (WINAPI *pfnInternetGetCookieExW)(LPCWSTR lpszUrl, LPCWSTR lpszCookieName, LPWSTR lpszCookieData, LPDWORD pcchCookieData, DWORD dwFlags, LPVOID dwReserved) ;
typedef INTERNET_STATUS_CALLBACK (WINAPI *pfnInternetSetStatusCallbackA)(HINTERNET hInternet,INTERNET_STATUS_CALLBACK lpfnInternetCallback) ;


class CSyncCookieHelper
{
public:
	CSyncCookieHelper();
	~CSyncCookieHelper();

	static CSyncCookieHelper& GetInstance()
	{
		static CSyncCookieHelper instance;
		return instance;
	}

	static void StartAPIHook();

	static pfnInternetSetCookieA RealInternetSetCookieA;
	static pfnInternetSetCookieW RealInternetSetCookieW;
	static pfnInternetSetCookieExA RealInternetSetCookieExA;
	static pfnInternetSetCookieExW RealInternetSetCookieExW;
	static pfnInternetGetCookieExA RealInternetGetCookieExA;
	static pfnInternetGetCookieExW RealInternetGetCookieExW;
	//������cookieαװ �������HTTP Request Header��cookie
	static pfnHttpOpenRequestA RealHttpOpenRequestA;
	static pfnHttpOpenRequestW RealHttpOpenRequestW;
	static pfnInternetSetStatusCallbackA RealInternetSetStatusCallbackA;

	static HINTERNET WINAPI HookedHttpOpenRequestA(HINTERNET hConnect,LPCSTR lpszVerb,LPCSTR lpszObjectName,LPCSTR lpszVersion,LPCSTR lpszReferrer,LPCSTR FAR * lplpszAcceptTypes,DWORD dwFlags,DWORD_PTR dwContext)
	{
		return CSyncCookieHelper::GetInstance().ProxyHttpOpenRequestA(hConnect,lpszVerb,lpszObjectName,lpszVersion,lpszReferrer,lplpszAcceptTypes,dwFlags,dwContext);
	}
	static HINTERNET WINAPI HookedHttpOpenRequestW(HINTERNET hConnect,LPCWSTR lpszVerb,LPCWSTR lpszObjectName,LPCWSTR lpszVersion,LPCWSTR lpszReferrer,LPCWSTR FAR * lplpszAcceptTypes,DWORD dwFlags,DWORD_PTR dwContext)
	{
		return CSyncCookieHelper::GetInstance().ProxyHttpOpenRequestW(hConnect,lpszVerb,lpszObjectName,lpszVersion,lpszReferrer,lplpszAcceptTypes,dwFlags,dwContext);
	}
	static BOOL WINAPI HookedInternetSetCookieA(LPCSTR lpszUrl,LPCSTR lpszCookieName,LPCSTR lpszCookieData) 
	{
		return CSyncCookieHelper::GetInstance().ProxyInternetSetCookieA(lpszUrl,lpszCookieName,lpszCookieData);
	}
	static BOOL WINAPI HookedInternetSetCookieW(LPCWSTR lpszUrl,LPCWSTR lpszCookieName,LPCWSTR lpszCookieData)
	{
		return CSyncCookieHelper::GetInstance().ProxyInternetSetCookieW(lpszUrl,lpszCookieName,lpszCookieData);
	}
	static DWORD WINAPI HookedInternetSetCookieExA(LPCSTR lpszUrl,LPCSTR lpszCookieName,LPCSTR lpszCookieData,DWORD dwFlags,DWORD_PTR dwReserved)
	{
		return CSyncCookieHelper::GetInstance().ProxyInternetSetCookieExA( lpszUrl, lpszCookieName, lpszCookieData, dwFlags, dwReserved);
	}
	static DWORD WINAPI HookedInternetSetCookieExW(LPCWSTR lpszUrl,LPCWSTR lpszCookieName,LPCWSTR lpszCookieData,DWORD dwFlags,DWORD_PTR dwReserved) 
	{
		return CSyncCookieHelper::GetInstance().ProxyInternetSetCookieExW( lpszUrl, lpszCookieName, lpszCookieData, dwFlags, dwReserved);
	}
	static BOOL WINAPI HookedInternetGetCookieExA(LPCSTR lpszUrl,LPCSTR lpszCookieName,LPSTR lpszCookieData,LPDWORD pcchCookieData,DWORD dwFlags,LPVOID dwReserved) 
	{
		return CSyncCookieHelper::GetInstance().ProxyInternetGetCookieExA( lpszUrl, lpszCookieName, lpszCookieData, pcchCookieData, dwFlags, dwReserved) ;
	}
	//add to support IE11
	static BOOL WINAPI HookedInternetGetCookieExW(LPCWSTR lpszUrl, LPCWSTR lpszCookieName, LPWSTR lpszCookieData, LPDWORD pcchCookieData, DWORD dwFlags, LPVOID dwReserved) 
	{
		return CSyncCookieHelper::GetInstance().ProxyInternetGetCookieExW( lpszUrl, lpszCookieName, lpszCookieData, pcchCookieData, dwFlags, dwReserved) ;
	}
	static INTERNET_STATUS_CALLBACK WINAPI HookedInternetSetStatusCallbackA(HINTERNET hInternet,INTERNET_STATUS_CALLBACK lpfnInternetCallback)
	{
		return CSyncCookieHelper::GetInstance().ProxyInternetSetStatusCallbackA( hInternet, lpfnInternetCallback);
	}

private:
	HINTERNET  ProxyHttpOpenRequestA(HINTERNET hConnect,LPCSTR lpszVerb,LPCSTR lpszObjectName,LPCSTR lpszVersion,LPCSTR lpszReferrer,LPCSTR FAR * lplpszAcceptTypes,DWORD dwFlags,DWORD_PTR dwContext);
	HINTERNET  ProxyHttpOpenRequestW(HINTERNET hConnect,LPCWSTR lpszVerb,LPCWSTR lpszObjectName,LPCWSTR lpszVersion,LPCWSTR lpszReferrer,LPCWSTR FAR * lplpszAcceptTypes,DWORD dwFlags,DWORD_PTR dwContext);
	BOOL  ProxyInternetSetCookieA(LPCSTR lpszUrl,LPCSTR lpszCookieName,LPCSTR lpszCookieData) ;
	BOOL  ProxyInternetSetCookieW(LPCWSTR lpszUrl,LPCWSTR lpszCookieName,LPCWSTR lpszCookieData);
	DWORD  ProxyInternetSetCookieExA(LPCSTR lpszUrl,LPCSTR lpszCookieName,LPCSTR lpszCookieData,DWORD dwFlags,DWORD_PTR dwReserved);
	DWORD  ProxyInternetSetCookieExW(LPCWSTR lpszUrl,LPCWSTR lpszCookieName,LPCWSTR lpszCookieData,DWORD dwFlags,DWORD_PTR dwReserved) ;
	BOOL  ProxyInternetGetCookieExA(LPCSTR lpszUrl,LPCSTR lpszCookieName,LPSTR lpszCookieData,LPDWORD pcchCookieData,DWORD dwFlags,LPVOID dwReserved) ;
	//add to support IE11
	BOOL  ProxyInternetGetCookieExW(LPCWSTR lpszUrl, LPCWSTR lpszCookieName, LPWSTR lpszCookieData, LPDWORD pcchCookieData, DWORD dwFlags, LPVOID dwReserved) ;
	INTERNET_STATUS_CALLBACK  ProxyInternetSetStatusCallbackA(HINTERNET hInternet,INTERNET_STATUS_CALLBACK lpfnInternetCallback);
	static void CALLBACK InternetCallbackFunc(HINTERNET hInternet,DWORD_PTR dwContext,DWORD dwInternetStatus,LPVOID lpvStatusInformation,DWORD dwStatusInformationLength);
	static void onCookieReceived(HINTERNET hInternet);
	static void onCookieSent(HINTERNET hInternet);
	static void onResolvingName(HINTERNET hInternet, LPVOID lpvStatusInformation);
	//��ƭIE
	static void CheatIECoookie(HINTERNET hRequest);
	static void CheatIECoookieForRedirect(HINTERNET hRequest) ;

	static void SetChromeCookie(const char* pszUrl,const char* pszCookie,bool request_cookie);
	static bool GetChromeCookie(const char* pszUrl,char* pszCookieData,unsigned long* pcchCookieData,bool request_cookie);
}; 