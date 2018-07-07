#ifndef __DRAWABLE_H_INCLUDED__
#define __DRAWABLE_H_INCLUDED__

#include <SFML/Graphics.hpp>

namespace DungeonFight
{
//
class Drawable
{
public:
    virtual void draw(sf::RenderWindow& window) = 0;
};
}

#endif
