#ifndef __ROOMBUILDER_H_INCLUDED__
#define __ROOMBUILDER_H_INCLUDED__


#include "Drawable.h"
#include "Room.h"
#include <memory>

namespace DungeonFight
{
//
class RoomBuilder : public Room, public Drawable
{
public:
    RoomBuilder(int width, int hight);
    virtual void draw(sf::RenderWindow& window) override;
};
}

#endif
