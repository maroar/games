#include "Screen.h"
#include "Constants.h"

namespace DungeonFight
{
//
Screen::Screen(int width, int hight) : width_(width), hight_(hight)
{
    const int sliceOfScreen = hight_ / intNumberOfScreenSlices;
    statusBar_ = std::make_shared<StatusBar>(width_, sliceOfScreen);
    currentRoom_ =
            std::make_shared<RoomBuilder>(width_, hight - sliceOfScreen);
    message_ = std::make_shared<Message>(width_, sliceOfScreen/2);
}
//
int Screen::getWidth() const
{
    return width_;
}
//
void Screen::setWidth(int value)
{
    width_ = value;
}
//
int Screen::getHight() const
{
    return hight_;
}
//
void Screen::setHight(int value)
{
    hight_ = value;
}
//
void Screen::draw(sf::RenderWindow& window)
{
    currentRoom_->draw(window);
    statusBar_->draw(window);
    message_->draw(window);
}
}
