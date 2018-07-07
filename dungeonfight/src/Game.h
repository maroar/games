#ifndef __GAME_H_INCLUDED__
#define __GAME_H_INCLUDED__

#include "Screen.h"
#include <SFML/Graphics.hpp>
#include <memory>

namespace DungeonFight
{
//
class Game
{
    std::shared_ptr<sf::RenderWindow> window_;
public:
    Game(int width, int hight);
    int run();
    void render(Screen& screen);
    void handleEvent(const sf::Event &event);
};
}

#endif
