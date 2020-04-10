#pragma once
#include <MsHTML.h>
#include <ExDisp.h>
/*
ģ��ʵ�ֶ�IE�ں˴��´��ڵ�֧��
����window_open�¼���features��Ӧ���´��ڵ����ԡ�
window_moveto--Window_ResizeBy��Ϊ��֧�ֶ��´���λ�õ��޸ġ�
����URL��
www.ccb.com
http://www.cnbeta.com/articles/267434.htm �����Qzone��ע��ť
*/

typedef HRESULT (__stdcall *Window_Open)(IHTMLWindow2* pThis, BSTR url, BSTR name, BSTR features, VARIANT_BOOL replace, IHTMLWindow2 **pomWindowResult);
typedef HRESULT (__stdcall *Window_MoveTo)(IHTMLWindow2* pThis, long x, long y);
typedef HRESULT (__stdcall *Window_MoveBy)(IHTMLWindow2* pThis, long x, long y);
typedef HRESULT (__stdcall *Window_ResizeTo)(IHTMLWindow2* pThis, long x, long y);
typedef HRESULT (__stdcall *Window_ResizeBy)(IHTMLWindow2* pThis, long x, long y);

enum
{
  WINDOW_POS_MOVETO,
  WINDOW_POS_MOVEBY,
  WINDOW_POS_RESIZETO,
  WINDOW_POS_RESIZEBY,
};

struct POSITIONADJUST
{
  int nType;
  long x;
  long y;
};

class CHtmlWindowHook
{
public:
  CHtmlWindowHook(void);
  virtual ~CHtmlWindowHook(void);
  
  enum WINDOWOPEN_POLICY 
  {
    WINDOWOPEN_SUGGEST = 0,
    WINDOWOPEN_NEWWINDOW,
    WINDOWOPEN_NEWTAB,
    WINDOWOPEN_UNKNOWN = -1,
  };

public:
  static Window_Open orig_window_open;
  static Window_MoveTo orig_window_moveTo;
  static Window_MoveBy orig_window_moveBy;
  static Window_ResizeTo orig_window_resizeTo;
  static Window_ResizeBy orig_window_resizeBy;

  static HRESULT __stdcall Hooked_window_open( IHTMLWindow2* pThis, BSTR url, BSTR name, BSTR features, VARIANT_BOOL replace, IHTMLWindow2 **pomWindowResult );
  static HRESULT __stdcall Hooked_window_moveTo( IHTMLWindow2* pThis, long x, long y );
  static HRESULT __stdcall Hooked_window_moveBy( IHTMLWindow2* pThis, long x, long y );
  static HRESULT __stdcall Hooked_window_resizeTo( IHTMLWindow2* pThis, long x, long y );
  static HRESULT __stdcall Hooked_window_resizeBy( IHTMLWindow2* pThis, long x, long y );

  static void StartAPIHook();

  // ���ie��window.open�򿪵ķ�ʽ
  static WINDOWOPEN_POLICY GetWindowOpenPilicy();
};
