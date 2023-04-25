#include <SFML/Graphics.hpp>
#include"header.h"
int main()
{
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    cout << desktop.height << desktop.width;
    sf::RenderWindow window(desktop, "TETRIS");
    int well[20][10] = { 0 };
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }

    return 0;
}