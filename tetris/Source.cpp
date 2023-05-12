#include <SFML/Graphics.hpp>
#include"header.h"
#include<random>
#include<Windows.h>
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
            gameDrawer.setFillColor(sf::Color(0, 0, 0, 0));
            gameDrawer.setSize(sf::Vector2f(430.f, 80.f));
            gameDrawer.setPosition(sf::Vector2f(745, 500.f));
            gameDrawer.setOutlineColor(sf::Color(255, 255, 255, 255));
            gameDrawer.setOutlineThickness(2);
            window.draw(gameDrawer);
            text.setString("Enter Your Name");
            text.setCharacterSize(65);
            text.setFillColor(sf::Color::White);
            text.setPosition(sf::Vector2f(650.f, 400.f));
            window.draw(text);

            text.setString(name);
            text.setCharacterSize(65);
            text.setFillColor(sf::Color::White);
            text.setPosition(sf::Vector2f(780.f, 500.f));
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