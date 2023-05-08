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
void square::rotateShape(Well&)
{}
bool square::isSettled(Well& well)
{
	if (well.cellCheck(mainRow + 2,mainCol) == true && well.cellCheck(mainRow + 2,mainCol + 1) == true)
	{
		return false;
	}
	return true;

}
void square::drop(Well& well, sf::RectangleShape &shapedrawer, sf::RenderWindow &window) //false = shape is not settled, true= shape is settled
{
	if (mainRow<18&& well.cellCheck(mainRow + 2,mainCol) == true && well.cellCheck(mainRow + 2,mainCol + 1) == true)
	{
		mainY += 40;
		mainRow++;
		draw(shapedrawer, window);
	}
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
	mainRow = 0;
	mainCol = 4;
	rotation = 0;
	mainX = 500 + mainCol * 40;
	mainY = 100 + mainRow * 40;
}
void square::moveRight(sf::RectangleShape& shapedrawer, sf::RenderWindow& window, Well& well)
{
	if (mainCol < 8 && well.cellCheck(mainRow, mainCol + 2) == true && well.cellCheck(mainRow + 1, mainCol + 2) == true)
	{
		mainCol++;
		mainX += 40;
		draw(shapedrawer,window);
	}
}
void square::moveLeft(sf::RectangleShape& shapedrawer, sf::RenderWindow& window, Well& well)
{
	if (mainCol > 0 && well.cellCheck(mainRow, mainCol - 1) == true && well.cellCheck(mainRow + 1, mainCol -1) == true)
	{
		mainCol--;
		mainX -= 40;
		draw(shapedrawer, window);
	}
}
void square::updateWell(Well& well)
{
	well.setCell(1, mainRow, mainCol);
	well.setCell(1, mainRow, mainCol+1);
	well.setCell(1, mainRow+1, mainCol);
	well.setCell(1, mainRow+1, mainCol+1);

}