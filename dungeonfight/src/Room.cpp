#include "Room.h"

namespace DungeonFight
{
Room::Room(int width, int hight) : width_(width), hight_(hight)
{
}

int Room::getWidth() const
{
    return width_;
}

void Room::setWidth(int value)
{
    width_ = value;
}

int Room::getHight() const
{
    return hight_;
}

void Room::setHight(int value)
{
    hight_ = value;
}
}
