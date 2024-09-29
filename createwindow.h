#ifndef CREATEWINDOW_H
#define CREATEWINDOW_H

#include <string>
#include <windows.h>

class CreateWindowManager {
public:
    static void createWindow(const std::string& title, int width, int height, int x, int y);
    static void invalidateWindow();
    
  
    static HWND getHwnd();

private:
    static HWND hwnd;
    static HDC hdc;
    static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
};

#endif // CREATEWINDOW_H
