#include "createwindow.h"
#include "cppgame.h"
/*ignore errors even copilot and chatgpt couldnt fix them well that aint that important*/
/*btw i didn upload somefiles due to bugs and blah blah happens*/
HWND CreateWindowManager::hwnd = nullptr;
HDC CreateWindowManager::hdc = nullptr;


HWND CreateWindowManager::getHwnd() {
    return hwnd;
}

// event handelr eg closing window
LRESULT CALLBACK CreateWindowManager::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            //set bg color
            HBRUSH brush = CreateSolidBrush(CppGame::getWindowColor());
            FillRect(hdc, &ps.rcPaint, brush);
            DeleteObject(brush);

            // set text color 
            SetTextColor(hdc, CppGame::getTextColor());
            TextOut(hdc, CppGame::getTextX(), CppGame::getTextY(), CppGame::getDisplayText().c_str(), CppGame::getDisplayText().length());

            EndPaint(hwnd, &ps);
        } break;
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

// function for creating window
void CreateWindowManager::createWindow(const std::string& title, int width, int height, int x, int y) {
    const char CLASS_NAME[] = "CppGameWindowClass";

    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = GetModuleHandle(nullptr);
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    hwnd = CreateWindowEx(
        0,
        CLASS_NAME,
        title.c_str(),
        WS_OVERLAPPEDWINDOW,
        x, y, width, height,
        nullptr, nullptr, GetModuleHandle(nullptr), nullptr
    );

    if (hwnd == nullptr) {
        return;
    }

    ShowWindow(hwnd, SW_SHOW);
    hdc = GetDC(hwnd);
}

// Function to refresh/ckground
void CreateWindowManager::invalidateWindow() {
    InvalidateRect(hwnd, nullptr, TRUE);
}
