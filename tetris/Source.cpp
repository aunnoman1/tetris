#include <SFML/Graphics.hpp>
#include"header.h"
#include<random>
int main()
{
    sf::Font font;
    if (!font.loadFromFile("DragonHunter.otf"))
    {
        cout << "error";
    }
    srand(time(0));
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(desktop, "TETRIS");
    Game game;
    sf::Time elapsed;
    sf::Clock clock;
    sf::RectangleShape wellBoundary(sf::Vector2f(400.f, 800.f));
    sf::RectangleShape wellfiller(sf::Vector2f(40.f, 40.f));
    sf::RectangleShape shapemaker(sf::Vector2f(40.f, 40.f));
    sf::RectangleShape gameDrawer(sf::Vector2f(0.f, 0.f));
    sf::Text text;
    text.setFont(font);
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
                if (event.key.code == sf::Keyboard::Up)
                {
                    game.rotateShape(shapemaker, window);
                }
            }
        }

        window.clear();
        game.drawGame(wellBoundary,window,wellfiller,shapemaker, gameDrawer, text);



        game.fixShape();

        if (elapsed >= game.getInterval())
        {
            game.dropShape(shapemaker,window);
            clock.restart();
        }
        window.display();

    }

    return 0;
}