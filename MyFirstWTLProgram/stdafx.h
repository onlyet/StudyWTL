#define STRICT
#define WIN32_LEAN_AND_MEAN
#define _WTL_USE_CSTRING

#include <atlbase.h>       // 基本的ATL类
#include <atlapp.h>        // 基本的WTL类
extern CAppModule _Module; // WTL 派生的CComModule版本
#include <atlwin.h>        // ATL 窗口类
#include <atlframe.h>      // WTL 主框架窗口类
#include <atlmisc.h>       // WTL 实用工具类，例如：CString
#include <atlcrack.h>      // WTL 增强的消息宏
