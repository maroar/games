#include "Constants.h"
#include "Game.h"
#include <SFML/Graphics.hpp>

namespace DungeonFight
{
    int Game::run()
    {
        sf::RenderWindow window(sf::VideoMode(200, 200), strDungeonFight);
        sf::CircleShape shape(100.f);
        shape.setFillColor(sf::Color::Green);

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear();
            window.draw(shape);
            window.display();
        }

        return EXIT_SUCCESS;
    }
}
