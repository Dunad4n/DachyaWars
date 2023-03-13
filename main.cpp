#include <iostream>
#include "Game.h"

int main() {
    game::Game *game = new game::Game();
    game->run();
    delete game;
    return 0;
}
