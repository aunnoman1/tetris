#include"header.h"
square::square()
{
	colour[0] = 255;
	colour[1] = 255;
	colour[2] = 0;
	colour[3] = 255;
	outerColour[0] = 221;
	outerColour[1] = 175;
	outerColour[2] = 14;
	outerColour[3] = 255;
	row = 4;
	col = 0;
	rotation = 0;
	MainX = 500 + row * 40;
	MainY = 100 + col * 40;
	
}
void square::rotateShape()
{}
bool square::drop(int well[][10], sf::RectangleShape &shapedrawer, sf::RenderWindow &window)
{
	if (well[row + 2][col] == 0 && well[row + 2][col + 1] == 0)
	{
		MainY += 50;
		row++;
		draw(shapedrawer, window);
	}
	if (well[row + 2][col] == 0 && well[row + 2][col + 1] == 0)
	{
		return true;
	}
	return false;

}
void square::draw(sf::RectangleShape &shapedrawer,sf::RenderWindow &window)
{
	shapedrawer.setFillColor(sf::Color(colour[0], colour[1], colour[2], colour[3]));
	shapedrawer.setOutlineColor(sf::Color(outerColour[0], outerColour[1], outerColour[2], outerColour[3]));
	shapedrawer.setOutlineThickness(-3);
	shapedrawer.setPosition(MainX, MainY);
	window.draw(shapedrawer);
	shapedrawer.setPosition(MainX + 40, MainY);
	window.draw(shapedrawer);
	shapedrawer.setPosition(MainX, MainY+40);
	window.draw(shapedrawer);
	shapedrawer.setPosition(MainX + 40, MainY+04);
	window.draw(shapedrawer);
}
void square::resetLocation()
{
	row = 4;
	col = 0;
	rotation = 0;
	MainX = 500 + row * 40;
	MainY = 100 + col * 40;
}