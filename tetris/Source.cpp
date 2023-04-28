#include <SFML/Graphics.hpp>
#include"header.h"
#include<random>
int main()
{
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(desktop, "TETRIS");
    int well[20][10] = { 0 };
    bool settled = false;
    tetrimino** shapes=new tetrimino*[7];
    shapes[0] = new square;
    shapes[1] = new square;
    shapes[2] = new square;
    shapes[3] = new square;
    shapes[4] = new square;
    shapes[5] = new square;
    shapes[6] = new square;
    sf::Time interval = sf::milliseconds(1000);
    sf::Time elapsed;
    sf::Clock clock;
    int currentShape = rand() % 7;
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
        }

        window.clear();
        shapes[currentShape]->draw(shapemaker, window);
        //if (elapsed >= interval)
        //{
        //    settled = shapes[currentShape]->drop(well, shapemaker, window);
        //    clock.restart();
        //}
        wellBoundary.setFillColor(sf::Color(12, 12, 12));
        wellBoundary.setOutlineThickness(2);
        wellBoundary.setOutlineColor(sf::Color(255, 255, 255));
        wellBoundary.setPosition(sf::Vector2f(500.f, 100.f));
        wellfiller.setFillColor(sf::Color(12, 12, 12));
        window.draw(wellBoundary);

        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (well[i][j] == 0)
                {
                    wellfiller.setFillColor(sf::Color(12, 12, 12));
                    wellfiller.setOutlineThickness(-1);
                    wellfiller.setOutlineColor(sf::Color(46, 46, 46));
                    wellfiller.setPosition(sf::Vector2f((500 + 40 * j), (100 + 40 * i)));
                    window.draw(wellfiller);
                }
                else
                {
                    wellfiller.setFillColor((shapes[well[i][j] - 1])->getColour());
                    wellfiller.setOutlineThickness(-3);
                    wellfiller.setOutlineColor((shapes[well[i][j] - 1])->getOuterColour());
                    wellfiller.setPosition(sf::Vector2f((500 + 40 * j), (100 + 40 * i)));
                    window.draw(wellfiller);
                }

            }
        }
        window.display();
    }

    return 0;
}