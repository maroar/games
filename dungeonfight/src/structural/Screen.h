#ifndef __SCREEN_H_INCLUDED__
#define __SCREEN_H_INCLUDED__

#include "Drawable.h"
#include "StatusBar.h"
#include "Message.h"
#include "RoomBuilder.h"
#include <memory>

namespace DungeonFight
{
//
class Screen : public Drawable
{
    int width_;
    int hight_;
    std::shared_ptr<StatusBar> statusBar_;
    std::shared_ptr<RoomBuilder> currentRoom_;
    std::shared_ptr<Message> message_;
public:
    Screen(int width, int hight);
    int getWidth() const;
    void setWidth(int value);
    int getHight() const;
    void setHight(int value);
    virtual void draw(sf::RenderWindow& window) override;
};
}

#endif
