#include <SFML/Graphics.hpp>
#include"header.h"
#include<random>
#include<fstream>
#include<windows.h>
int main()
{
    sf::Font font;
    if (!font.loadFromFile("DragonHunter.otf"))
    {
        cout << "error";
    }
    bool filesExist;


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
    bool nameEntered = false;
    string name="";
    text.setFont(font);
    while (window.isOpen() && nameEntered == false)
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::TextEntered)
            {
                if (event.text.unicode == 8 && name.size() > 0)
                    name.erase(name.size() - 1, 1);
                else if (event.text.unicode < 123 && event.text.unicode >64  && name.size() < 8)
                    name += static_cast<char>(event.text.unicode);

            }
            window.clear();
            game.drawUser(window, gameDrawer, text, name);
            window.draw(text);

            

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Enter && name.size() > 0)
                {
                    nameEntered = true;
                }
            }
            window.display();
        }
    }
    game.setname(name);
    while (window.isOpen() && game.gameRunning())
    {
        elapsed = clock.getElapsedTime();
 
        sf::Event event;
        window.clear();
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
                 else if (event.key.code == sf::Keyboard::Down)
                {
                    game.dropShape(shapemaker, window);
                }
                 else if (event.key.code == sf::Keyboard::Left)
                {
                    game.moveLeft(shapemaker, window);
                }
                 else if (event.key.code == sf::Keyboard::Up)
                {
                    game.rotateShape(shapemaker, window);
                }
            }
        }
        game.drawGame(wellBoundary,window,wellfiller,shapemaker, gameDrawer, text );

        if (elapsed >= game.getInterval() && game.gameRunning() == true)
        {
            if(!game.fixShape())
                game.dropShape(shapemaker,window);
            clock.restart();
        }
        if (game.gameRunning() == false)
        {
            game.drawGameOver(window, gameDrawer, text);
        }
        window.display();
        if (game.gameRunning() == false)
            Sleep(2000);
    }
    game.UpdateLeaderboard();
    while (window.isOpen())
    {
        sf::Event event;
        window.clear();
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        game.drawGameOverScreen(window, gameDrawer, text);

        window.display();

    }

    return 0;
}