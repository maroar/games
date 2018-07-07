#include "Message.h"

namespace DungeonFight
{
Message::Message(int width, int hight) : width_(width), hight_(hight)
{}
//
int Message::getWidth() const
{
    return width_;
}
//
void Message::setWidth(int value)
{
    width_ = value;
}
//
int Message::getHight() const
{
    return hight_;
}
//
void Message::setHight(int value)
{
    hight_ = value;
}
//
void Message::draw(sf::RenderWindow& window)
{
    sf::RectangleShape base(sf::Vector2f(getWidth(), getHight()));
    base.setFillColor(sf::Color::Black);

    window.draw(base);
}
}
