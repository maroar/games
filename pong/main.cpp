#include <iostream>
#include <SFML/Graphics.hpp>

#define h 600
#define w 800

void setInitialPosition(sf::CircleShape& ball, 
                        sf::RectangleShape& p1, 
                        sf::RectangleShape& p2) 
{
    ball.setPosition(w / 2, h / 2);
    p1.setPosition(10, h / 2 - 75);
    p2.setPosition(w - 35, h / 2 - 75);
}

void setInitialColors(sf::CircleShape& ball, 
                      sf::RectangleShape& p1, 
                      sf::RectangleShape& p2) 
{
    ball.setFillColor(sf::Color::White);
    p1.setFillColor(sf::Color::Blue);
    p2.setFillColor(sf::Color::Red);
}

void init(sf::CircleShape& ball, sf::RectangleShape& p1, 
          sf::RectangleShape& p2) 
{
    setInitialPosition(ball, p1, p2);
    setInitialColors(ball, p1, p2);
}

const float step = 2.0;
const float pstep = 2.0;
const float radius = 10.f;

int main(int argc, char** argv)
{
    bool up{true}, right{true};

    sf::RenderWindow window(sf::VideoMode(w, h), "SFML works!");
    window.setVerticalSyncEnabled(true); 
    
    sf::CircleShape ball(radius);

    sf::RectangleShape p1(sf::Vector2f(25, 150));

    sf::RectangleShape p2(sf::Vector2f(25, 150));

    init(ball, p1, p2);

    while (window.isOpen())
    {
    // move ball
        float x, y;
        if (up)
            y = -1 * step;
        else
            y = step;

        if (right)
            x = step;
        else
            x = -1 * step;
        ball.move(x, y);

    // check colision with the bounds
        sf::Vector2f pos(ball.getPosition());
        // colision with right side
        if (pos.x == w - 20.0)
        {
            std::cout << "|" << std::endl;
            right = false;
        }
        // colision with left side
        else if (pos.x == 0)
        {
            std::cout << "|" << std::endl;
            right = true;
        }
        // colision with the roof
        if (pos.y == h - 20.0)
        {
            std::cout << "------------------" << std::endl;
            up = true;
        }
        // colision with the floor
        else if (pos.y == 0)
        {
            std::cout << "------------------" << std::endl;
            up = false;
        }

        if (p1.getGlobalBounds().intersects(ball.getGlobalBounds()))
        {
            if (ball.getGlobalBounds().top < p1.getGlobalBounds().top ||
                ball.getGlobalBounds().top + ball.getRadius() > 
                p1.getGlobalBounds().top + p1.getGlobalBounds().height)
            {
                up = !up;
            }    
            else
                right = !right;
        }
        else if (p2.getGlobalBounds().intersects(ball.getGlobalBounds())) 
        {
            if (ball.getGlobalBounds().top < p2.getGlobalBounds().top ||
                ball.getGlobalBounds().top + ball.getRadius() > 
                p2.getGlobalBounds().top + p2.getGlobalBounds().height)
            {
                up = !up;
            }
            else
                right = !right;
        }

        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::GainedFocus:
                    break;

                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Up) 
                    {
                        p1.move(0, -1 * pstep);
                    } 
                    else if (event.key.code == sf::Keyboard::Down)
                    {
                        p1.move(0, pstep);
                    }
                    else if (event.key.code == sf::Keyboard::W) 
                    {
                        p2.move(0, -1 * pstep);
                    } 
                    else if (event.key.code == sf::Keyboard::S)
                    {
                        p2.move(0, pstep);
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
                            return 0;
                    }
                    break;

                default:
                    break;
            }
        }

        window.clear();
        window.draw(ball);
        window.draw(p1);
        window.draw(p2);
        window.display();
    }

    return 0;
}


