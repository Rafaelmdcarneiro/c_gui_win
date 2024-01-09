#include <Windows.h>

LRESULT WinProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_PAINT:
            HDC hDc = GetDC(hWnd);
            RECT rect = {
                150,
                150,
                500,
                500
            };
            HBRUSH hBr = CreateSolidBrush(RGB(0,0,255));
            FillRect(hDc, &rect, hBr);
            DeleteObject(hBr);
            ReleaseDC(hWnd, hDc);
            return 0;

        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;

        default:
            return DefWindowProcA(hWnd, uMsg, wParam, lParam);
    }

    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE a, PSTR b, int nCmdShow) {
    WNDCLASSA class = {
        0,
        WinProc,
        0,
        0,
        hInstance,
        NULL,
        NULL,
        NULL,
        NULL,
        "NirsClass"
    };

    RegisterClassA(&class);

    HWND windowHandle = CreateWindowA("NirsClass", "Hello", WS_CAPTION | WS_POPUP | WS_SYSMENU, 100, 100, 1000, 1000, NULL, NULL, hInstance, NULL);

    ShowWindow(windowHandle, nCmdShow);

    MSG msg;

    for (;;) {
        if (GetMessageA(&msg, NULL, 0, 0) == 0) {
            break;
        }

        DispatchMessageA(&msg);
    }

    return 0;
}
