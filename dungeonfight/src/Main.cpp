#include "DungeonFightConfig.h"
#include "Game.h"
#include <iostream>

/*!
 * \brief main
 * \return
 */
int main(int argc, char* argv[])
{
    std::cout << "Dungeon Fight"
              << " Version "
              << DUNGEONFIGHT_VERSION_MAJOR
              << "."
              << DUNGEONFIGHT_VERSION_MINOR
              << std::endl;

    DungeonFight::Game game;

    return game.run();
}
