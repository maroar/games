#ifndef __ROOM_H_INCLUDED__
#define __ROOM_H_INCLUDED__

#include "ngraph.hpp"
#include "Room.h"

namespace DungeonFight
{
    //
    class Room
    {
        int width_;
        //list<std::shared_ptr<Door>> doors_;
    public:
        Room();
        int getWidth();
    };
}

#endif
