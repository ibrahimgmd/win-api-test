#include "cppgame.h"
    /*TUTORIOL TIME1!!1! nvm i aint teaching (bro really changed his mind in 1 second)*/
/*aye ppl am gonna remove "cppgame::" thing for everything except printing and ill remove the msg loop thing*/
int main() {
    // creates a window , 600, 500 r actually the size of the window and 100, 150 r x and y
    CppGame::createWindow("CppGame Window", 600, 500, 100, 150);

    // blah get a color picker from google 
    CppGame::setWindowColor(RGB(14, 240, 191));

    // print text with color and position
    CppGame::printText("my back hurts", 60, 70, RGB(240, 14, 14));

    // drawing shapes soon

 

    // ignore this shit
    MSG msg = {};
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
