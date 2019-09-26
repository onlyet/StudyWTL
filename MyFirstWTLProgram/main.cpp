#include "stdafx.h"
#include "MyWindow.h"

CAppModule _Module;

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPWSTR lpCmdLine, int nCmdShow)
{
    _Module.Init(NULL, hInstance);

    CMyWindow wndMain;
    MSG msg;

    if (NULL == wndMain.CreateEx())
        return 1;

    wndMain.ShowWindow(nCmdShow);
    wndMain.UpdateWindow();

    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    _Module.Term();
    return msg.wParam;
}