#include "Constants.h"
#include "Game.h"

namespace DungeonFight
{

Game::Game(int width, int hight)
    : window_(std::make_shared<sf::RenderWindow>(
                  sf::VideoMode(width, hight), strDungeonFight))
{
}

int Game::run()
{
    Screen screen(600, 600);

    while (window_->isOpen())
    {
        sf::Event event;
        while (window_->pollEvent(event))
        {
            handleEvent(event);
        }

        render(screen);
    }

    return EXIT_SUCCESS;
}

void Game::render(Screen& screen)
{
    sf::RectangleShape base(sf::Vector2f(screen.getWidth(), screen.getHight()));
    base.setFillColor(sf::Color::White);

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    window_->clear();
    window_->draw(base);
    //window_->draw(shape);
    screen.draw(*window_);
    window_->display();
}

void Game::handleEvent(const sf::Event &event)
{
    switch (event.type)
    {
    case sf::Event::Closed:
        window_->close();
        break;

    case sf::Event::GainedFocus:
        break;

    case sf::Event::KeyPressed:
        if (event.key.code == sf::Keyboard::Up)
        {
            //p1.move(0, -1 * pstep);
        }
        else if (event.key.code == sf::Keyboard::Down)
        {
            //p1.move(0, pstep);
        }
        else if (event.key.code == sf::Keyboard::W)
        {
            //p2.move(0, -1 * pstep);
        }
        else if (event.key.code == sf::Keyboard::S)
        {
            //p2.move(0, pstep);
        }
        break;

    case sf::Event::KeyReleased:
        break;

    case sf::Event::LostFocus:
        break;

    case sf::Event::TextEntered:
        if (event.text.unicode < 128)
        {
            char pkey = static_cast<char>(event.text.unicode);
            if (pkey == 'q')
                return ;
        }
        break;

    default:
        break;
    }
}
}
