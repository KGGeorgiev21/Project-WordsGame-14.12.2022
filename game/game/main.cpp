#include "precompile.hpp"
#include "game.hpp"
#define _WIN32_WINNT 0x0500
#include <windows.h>

void hideConsole()
{
    HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, SW_SHOW);
}

int main()
{
    hideConsole();
    gameClass game(720, 1280, "Main");
    game.initWindow();
    return 0;
}