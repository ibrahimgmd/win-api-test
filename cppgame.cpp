#include "cppgame.h"
#include "createwindow.h"

// static variabels
COLORREF CppGame::bgColor = RGB(255, 255, 255); // default white bg if any errors or bugs occur
std::string CppGame::displayText = "";
int CppGame::textX = 0, CppGame::textY = 0;
COLORREF CppGame::textColor = RGB(0, 0, 0);     // defualt black text if any bugs occur

void CppGame::createWindow(const std::string& title, int width, int height, int x, int y) {
    CreateWindowManager::createWindow(title, width, height, x, y);
}

void CppGame::setWindowColor(COLORREF color) {
    bgColor = color;
    CreateWindowManager::invalidateWindow();
}

void CppGame::printText(const std::string& text, int x, int y, COLORREF color) {
    displayText = text;
    textX = x;
    textY = y;
    textColor = color;
    CreateWindowManager::invalidateWindow();
}

// that getter things idk
COLORREF CppGame::getWindowColor() { return bgColor; }
COLORREF CppGame::getTextColor() { return textColor; }
int CppGame::getTextX() { return textX; }
int CppGame::getTextY() { return textY; }
std::string CppGame::getDisplayText() { return displayText; }
