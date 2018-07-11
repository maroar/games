#ifndef __MESSAGE_H_INCLUDED__
#define __MESSAGE_H_INCLUDED__

#include "Drawable.h"
#include <string>

namespace DungeonFight
{
//
class Message : public Drawable
{
    int width_;
    int hight_;
    std::string message;
public:
    Message(int width, int hight);
    int getWidth() const;
    void setWidth(int value);
    int getHight() const;
    void setHight(int value);
    virtual void draw(sf::RenderWindow& window);
};
}

#endif
