#ifndef __STAGE_H_INCLUDED__
#define __STAGE_H_INCLUDED__

#include "ngraph.hpp"
#include "Room.h"
#include <memory>

namespace DungeonFight 
{
//
class Stage
{
    NGraph::tGraph<std::shared_ptr<Room>> rooms_;
};
}

#endif 
