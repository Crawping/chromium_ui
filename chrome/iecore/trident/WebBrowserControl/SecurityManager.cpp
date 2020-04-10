// DocHostUIHandler.cpp: implementation of the CWebBrowserEx class.
//
//////////////////////////////////////////////////////////////////////

#include "chrome/iecore/trident/stdafx.h"
#include "SecurityManager.h"
#include "chrome/iecore/trident/webbrowserhost/IEBrowserWnd.h"

STDMETHODIMP_(ULONG)CSecurityManager::AddRef(THIS)
{
	return 1;
}

STDMETHODIMP_(ULONG)CSecurityManager::Release(THIS)
{
	return 1;
}

STDMETHODIMP CSecurityManager::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
	*ppvObj = NULL;

	if( IsEqualIID(riid, IID_IUnknown) )
		*ppvObj = this;
	else if( IsEqualIID(riid, IID_IInternetSecurityManager) )
		*ppvObj = (IInternetSecurityManager *)this;
	else if( IsEqualIID(riid, IID_IHttpSecurity) )
		*ppvObj = (IHttpSecurity *)this;
	else
	{
		*ppvObj = 0;
		return E_NOINTERFACE;
	}

	return S_OK;	
}


STDMETHODIMP CSecurityManager::ProcessUrlAction(LPCWSTR pwszUrl,DWORD dwAction,BYTE *pPolicy,DWORD cbPolicy,BYTE *pContext,DWORD cbContext,DWORD dwFlags,DWORD dwReserved)
{	
  //URLACTION�ο���http://msdn.microsoft.com/en-us/library/ms537178.aspx
	//URLACTION_HTML_MIXED_CONTENT ���������ʾ
	//URLACTION_SCRIPT_PASTE  ����Լ�������б�̷���
  //URLACTION_AUTOMATIC_ACTIVEX_UI:Determines whether to display the Information Bar for ActiveX control installations rather than the ActiveX control prompt. ��װActivex����Inforamation Bar
  //bug:http://pap.cpipec.com �޷���װActivex�ؼ�����Ϊ��װ�ؼ��ᴥ��Navigate�¼���Ȼ��ҳ��ͻ���ת����½ҳ
  //���ﲻ������Ļ�����ͨ��CSecurityManager::ProcessUrlActionEx2Internal����ӿ�ȥ��ȡע����е�FeatureControl������
	if(dwAction == URLACTION_HTML_MIXED_CONTENT||dwAction==URLACTION_SCRIPT_PASTE ||dwAction==URLACTION_AUTOMATIC_ACTIVEX_UI)
	{
		if(pwszUrl && pPolicy && (cbPolicy >= sizeof(DWORD)))
		{
			*(DWORD*)pPolicy = URLPOLICY_ALLOW;
			return S_OK;
		}
	}
	return INET_E_DEFAULT_ACTION;
}


STDMETHODIMP CSecurityManager::GetWindow(REFGUID rguidReason,HWND *phwnd)
{
		*phwnd = m_pIEBrowserWnd->m_hWnd;
		return S_OK;
}

STDMETHODIMP CSecurityManager::OnSecurityProblem(DWORD dwProblem)
{
// 	switch (dwProblem) {
// 	case ERROR_HTTP_REDIRECT_NEEDS_CONFIRMATION:
// 	case ERROR_INTERNET_CLIENT_AUTH_CERT_NEEDED:
// 		return S_FALSE;
// 	case ERROR_INTERNET_SEC_CERT_REV_FAILED:
// 		return S_OK;
// 	case ERROR_INTERNET_SEC_CERT_ERRORS:
// 	case ERROR_INTERNET_INVALID_CA:
// 	case ERROR_INTERNET_SEC_CERT_CN_INVALID:
// 	case ERROR_INTERNET_SEC_CERT_DATE_INVALID:
// 	case ERROR_INTERNET_SEC_CERT_NO_REV:
// 		return S_OK;
// 	}
	return S_FALSE;
}