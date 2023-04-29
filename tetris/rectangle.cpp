#include"header.h"

rectangle::rectangle()
{

	rotation = 0;
	mainX = 0;
}

bool rectangle::drop(int well[][10], sf::RectangleShape &shapedrawer, sf::RenderWindow &window)
{
	mainX += 50;
	return true;
}
void rectangle::draw()
{

}
void rectangle::rotateShape()
{}
void rectangle::resetLocation()
{}