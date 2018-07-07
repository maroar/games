#ifndef __ROOM_H_INCLUDED__
#define __ROOM_H_INCLUDED__

#include "Room.h"

namespace DungeonFight
{
//
class Room
{
    int width_;
    int hight_;
    //list<std::shared_ptr<Door>> doors_;
public:
    Room(int width, int hight);
    int getWidth() const;
    void setWidth(int value);
    int getHight() const;
    void setHight(int value);
};
}

#endif
