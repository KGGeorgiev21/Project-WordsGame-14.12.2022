#include "precompile.hpp"
#include "game.hpp"

int main()
{
    gameClass game(720, 1280, "Test");

    game.initWindow();
    return 0;
}