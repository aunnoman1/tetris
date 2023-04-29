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
	mainRow = 0;
	mainCol = 4;
	rotation = 0;
	mainX = 500 + mainCol * 40;
	mainY = 100 + mainRow * 40;
	
}
void square::rotateShape()
{}
bool square::drop(int well[][10], sf::RectangleShape &shapedrawer, sf::RenderWindow &window)
{
	if (well[mainRow + 2][mainCol] == 0 && well[mainRow + 2][mainCol + 1] == 0)
	{
		mainY += 40;
		mainRow++;
		draw(shapedrawer, window);
	}
	if (well[mainRow + 2][mainCol] == 0 && well[mainRow + 2][mainCol + 1] == 0)
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
	shapedrawer.setPosition(mainX, mainY);
	window.draw(shapedrawer);
	shapedrawer.setPosition(mainX + 40, mainY);
	window.draw(shapedrawer);
	shapedrawer.setPosition(mainX, mainY+40);
	window.draw(shapedrawer);
	shapedrawer.setPosition(mainX + 40, mainY+40);
	window.draw(shapedrawer);
}
void square::resetLocation()
{
	mainRow = 4;
	mainCol = 0;
	rotation = 0;
	mainX = 500 + mainRow * 40;
	mainY = 100 + mainCol * 40;
}
void square::move(sf::RectangleShape& shapedrawer, sf::RenderWindow& window, bool direction) //true = right, left=false
{
	if (direction == true)
	{
		
	}
}