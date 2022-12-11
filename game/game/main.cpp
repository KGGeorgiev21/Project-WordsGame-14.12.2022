#include "precompile.hpp"
#include "game.hpp"
#define _WIN32_WINNT 0x0500
#include <windows.h>

void hideConsole()
{
    HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, SW_HIDE);
}

int main()
{
    hideConsole();
    gameClass game(720, 1280, "Test");
    game.initWindow();
    return 0;
}