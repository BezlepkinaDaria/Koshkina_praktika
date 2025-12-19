#include "Game.h"
#include <iostream>
#include <locale.h> 

int main() {
    setlocale(LC_ALL, "Russian");

    Game game;
    game.run();

    return 0;
}