#ifndef CPPGAME_H
#define CPPGAME_H

#include <string>
#include <windows.h>

class CppGame {
public:
    static void createWindow(const std::string& title, int width, int height, int x, int y);
    static void setWindowColor(COLORREF color);
    static void printText(const std::string& text, int x, int y, COLORREF color);

    // getters :clown:
    static COLORREF getWindowColor();
    static COLORREF getTextColor();
    static int getTextX();
    static int getTextY();
    static std::string getDisplayText();

private:
    // static variables for handling window settings ig
    static COLORREF bgColor;
    static std::string displayText;
    static int textX, textY;
    static COLORREF textColor;
};

#endif // CPPGAME_H
