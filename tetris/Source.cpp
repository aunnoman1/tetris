#include <SFML/Graphics.hpp>
#include"header.h"
int main()
{
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    cout << desktop.height << desktop.width;
    sf::RenderWindow window(desktop, "TETRIS");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        sf::RectangleShape lWell(sf::Vector2f(150.f, 2.f));
        window.display();
    }

    return 0;
}