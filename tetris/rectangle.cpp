#include"header.h"

rectangle::rectangle()
{

	rotation = 0;
	MainX = 0;
}

bool rectangle::drop(int well[][10], sf::RectangleShape &shapedrawer, sf::RenderWindow &window)
{
	MainX += 50;
	return true;
}
void rectangle::draw()
{

}
void rectangle::rotateShape()
{}
void rectangle::resetLocation()
{}