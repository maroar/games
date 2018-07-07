#ifndef __MENU_H_INCLUDED__
#define __MENU_H_INCLUDED__

#include "Drawable.h"
#include <memory>

namespace DungeonFight
{
//
class StatusBar : public Drawable
{
    int width_;
    int hight_;
public:
    StatusBar(int width, int hight);
    int getWidth() const;
    void setWidth(int value);
    int getHight() const;
    void setHight(int value);
    virtual void draw(sf::RenderWindow& window) override;
};
}

#endif
