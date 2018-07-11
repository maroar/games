#include "StatusBar.h"

namespace DungeonFight
{
StatusBar::StatusBar(int width, int hight) : width_(width), hight_(hight)
{}
//
int StatusBar::getWidth() const
{
    return width_;
}
//
void StatusBar::setWidth(int value)
{
    width_ = value;
}
//
int StatusBar::getHight() const
{
    return hight_;
}
//
void StatusBar::setHight(int value)
{
    hight_ = value;
}
//
void StatusBar::draw(sf::RenderWindow& window)
{
    sf::RectangleShape base(sf::Vector2f(getWidth(), getHight()));
    base.setFillColor(sf::Color::Red);

    window.draw(base);
}
}
