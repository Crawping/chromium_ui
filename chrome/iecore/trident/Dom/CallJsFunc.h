// WebPage.h: interface for the CWebPage class.
//
#pragma once
#include <atlbase.h>
#include <Mshtml.h>

/*
c++����js����ĺ�����js�������߶�����C++�����Ӧ�ľ���IDispatch������external,navigator,onbeforeunload
1��pDoc->get_Script(&spDisp)�ӿڣ��������onbeforeunload����    �������ԣ���QQ�ռ䲥��������Mute���ԡ�Activex��������ʵ����IDispatch��ͨ��QueryInterface,Ȼ��Ϳ����޸�����
2��IHTMLWindow exeScript
3��js������c++�����������IDispatch����ֱ�ӵ���Invoke��DISPID_VALUE���������GetIDsOfNames
4��js����Ҳ��IDispatch������ͨ��GetIDsOfNames��ȡDISPID��Ȼ��Invoke(DISPID����
5��js�������������Ƿ����Ļ����Ͷ�ӦIDispatch����

c++ע��ȫ�ֶ���ҳ��
	c++ͨ��IDispatchEx������ҳ�����һ��object���󣨸�external���ƣ����ű�ʹ��

js����c++,����external,navigator�����Ǽ̳е�IDispatch)
	ͨ��IDispatch�ӿ�

IE11Ҳ֧���޸�ֻ�����ԡ�����
navigator.__defineGetter__('appName',function(){return "Internet Explore"})
document.__defineGetter__('referrer',function(){return "Internet Explore"})
*/
class CWebPage  
{
public:
	CWebPage();
	virtual ~CWebPage();


	bool GetJScript(IHTMLDocument2* pDoc,CComPtr<IDispatch>& spDisp);
	bool GetJScripts(IHTMLDocument2* pDoc,CComPtr<IHTMLElementCollection>& spColl);
};
