//#pragma once
#include "resource.h"

class CMyWindow : public CFrameWindowImpl<CMyWindow>
{
public:
    DECLARE_FRAME_WND_CLASS(_T("First WTL window"), IDR_MAINFRAME)

    //BEGIN_MSG_MAP(CMyWindow)
    BEGIN_MSG_MAP_EX(CMyWindow)
        MSG_WM_CREATE(OnCreate)
        MSG_WM_DESTROY(OnDestroy)
        MSG_WM_TIMER(OnTimer)
        MSG_WM_ERASEBKGND(OnErasebkgnd)
        CHAIN_MSG_MAP(CFrameWindowImpl<CMyWindow>)
        END_MSG_MAP()

    LRESULT OnCreate(LPCREATESTRUCT lpCreateStruct)
    {
        SetTimer(1, 1000);
        SetMsgHandled(false);   //让CFrameWindowImpl也处理该消息
        return 0;
    }

    void OnDestroy()
    {
        KillTimer(1);
        SetMsgHandled(false);
    }

    void OnTimer(UINT_PTR nTimerId)
    {
        if (1 != nTimerId)
        {
            SetMsgHandled(false);
        }
        else
        {
            RedrawWindow();
        }
    }

    LRESULT OnErasebkgnd(HDC hdc)
    {
        CDCHandle   dc(hdc);
        CRect       rect;
        SYSTEMTIME  st;
        CString     sTime;

        GetClientRect(&rect);

        GetLocalTime(&st);
        sTime.Format(_T("The time is %d:%02d:%02d"), st.wHour, st.wMinute, st.wSecond);

        dc.SaveDC();

        dc.SetBkColor(RGB(66, 66, 66));
        dc.SetTextColor(RGB(0, 0, 0));
        dc.ExtTextOut(0, 0, ETO_OPAQUE, &rect, sTime, sTime.GetLength());

        dc.RestoreDC(-1);

        return 1;
    }
};