#include <SFML/Graphics.hpp>
#include"header.h"
#include<random>
int main()
{
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(desktop, "TETRIS");
    bool settled = false;
    Game game;
    sf::Time interval = sf::milliseconds(1000);
    sf::Time elapsed;
    sf::Clock clock;
    sf::RectangleShape wellBoundary(sf::Vector2f(400.f, 800.f));
    sf::RectangleShape wellfiller(sf::Vector2f(40.f, 40.f));
    sf::RectangleShape shapemaker(sf::Vector2f(40.f, 40.f));
    while (window.isOpen())
    {

        elapsed = clock.getElapsedTime();
 
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Right)
                {
                    game.moveRight(shapemaker, window);
                }
                if (event.key.code == sf::Keyboard::Down)
                {
                    game.dropShape(shapemaker, window);
                }
                if (event.key.code == sf::Keyboard::Left)
                {
                    game.moveLeft(shapemaker, window);
                }
            }
        }

        window.clear();
        game.drawGame(wellBoundary,window,wellfiller,shapemaker);





        if (elapsed >= interval)
        {
            game.dropShape(shapemaker,window);
            clock.restart();
        }
        window.display();
    }

    return 0;
}