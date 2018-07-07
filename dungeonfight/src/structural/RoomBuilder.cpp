#include "RoomBuilder.h"

namespace DungeonFight
{
//
RoomBuilder::RoomBuilder(int width, int hight) : Room(width, hight)
{}

void RoomBuilder::draw(sf::RenderWindow& window)
{
    sf::RectangleShape base(sf::Vector2f(getWidth(), getHight()));
    base.setFillColor(sf::Color::Green);

    window.draw(base);
}
}
