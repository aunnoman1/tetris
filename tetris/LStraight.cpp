#include"header.h"
lStraight::lStraight()
{
	colour[0] = 255;
	colour[1] = 165;
	colour[2] = 0;
	colour[3] = 255;
	outerColour[0] = 76;
	outerColour[1] = 49;
	outerColour[2] = 0;
	outerColour[3] = 255;
	mainRow = 0;
	mainCol = 4;
	rotation = 0;
	mainX = 500 + mainCol * 40;
	mainY = 100 + mainRow * 40;

}
void lStraight::rotateShape(Well& well)
{
	if (rotation == 0 && well.cellCheck(mainRow + 1, mainCol) == true && well.cellCheck(mainRow - 1, mainCol) == true && well.cellCheck(mainRow + 1, mainCol + 1) == true)
	{
		rotation = 1; cout << rotation;
	}
	else if (rotation == 1 && mainCol > 0 && well.cellCheck(mainRow, mainCol + 1) == true && well.cellCheck(mainRow, mainCol - 1) == true && well.cellCheck(mainRow + 1, mainCol - 1) == true)
	{
		rotation = 2; cout << rotation;
	}
	else if (rotation == 2 && well.cellCheck(mainRow + 1, mainCol) == true && well.cellCheck(mainRow - 1, mainCol) == true && well.cellCheck(mainRow - 1, mainCol - 1) == true)
	{
		rotation = 3; cout << rotation;
	}
	else if (rotation == 3 && mainCol < 9 && well.cellCheck(mainRow , mainCol - 1) == true && well.cellCheck(mainRow, mainCol + 1) == true && well.cellCheck(mainRow - 1, mainCol + 1) == true)
	{
		rotation = 0; cout << rotation;
	}
}
bool lStraight::isSettled(Well& well) //returns false if every block under it is empty
{
	if (rotation == 0 && mainRow < 19 && well.cellCheck(mainRow + 1, mainCol - 1) == true && well.cellCheck(mainRow + 1, mainCol) == true && well.cellCheck(mainRow + 1, mainCol + 1) == true)
	{
		return false;
	}
	if (rotation == 1 && mainRow < 18 && well.cellCheck(mainRow + 2, mainCol) == true && well.cellCheck(mainRow + 2, mainCol + 1) == true)
	{
		return false;
	}
	if (rotation == 2 && mainRow < 18 && well.cellCheck(mainRow + 2, mainCol - 1) == true && well.cellCheck(mainRow + 1, mainCol) == true && well.cellCheck(mainRow + 1, mainCol + 1) == true)
	{
		return false;
	}
	if (rotation == 3 && mainRow < 18 && well.cellCheck(mainRow , mainCol - 1) == true && well.cellCheck(mainRow + 2, mainCol) == true)
	{
		return false;
	}
	return true;

}
void lStraight::drop(Well& well, sf::RectangleShape& shapedrawer, sf::RenderWindow& window) //false = shape is not settled, true= shape is settled
{
	if (rotation == 0 && mainRow < 19 && well.cellCheck(mainRow + 1, mainCol - 1) == true && well.cellCheck(mainRow + 1, mainCol) == true && well.cellCheck(mainRow + 1, mainCol + 1) == true)
	{
		mainRow++;
		mainY = mainY + 40;
		draw(shapedrawer, window);
	}
	if (rotation == 1 && mainRow < 18 && well.cellCheck(mainRow + 2, mainCol) == true && well.cellCheck(mainRow + 2, mainCol + 1) == true)
	{
		mainRow++;
		mainY = mainY + 40;
		draw(shapedrawer, window);
	}
	if (rotation == 2 && mainRow < 18 && well.cellCheck(mainRow + 2, mainCol - 1) == true && well.cellCheck(mainRow + 1, mainCol) == true && well.cellCheck(mainRow + 1, mainCol + 1) == true)
	{
		mainRow++;
		mainY = mainY + 40;
		draw(shapedrawer, window);
	}
	if (rotation == 3 && mainRow < 18 && well.cellCheck(mainRow, mainCol - 1) == true && well.cellCheck(mainRow + 2, mainCol) == true)
	{
		mainRow++;
		mainY = mainY + 40;
		draw(shapedrawer, window);
	}
}
void lStraight::draw(sf::RectangleShape& shapedrawer, sf::RenderWindow& window)
{
	shapedrawer.setFillColor(sf::Color(colour[0], colour[1], colour[2], colour[3]));
	shapedrawer.setOutlineColor(sf::Color(outerColour[0], outerColour[1], outerColour[2], outerColour[3]));
	shapedrawer.setOutlineThickness(-3);
	if (rotation == 0)
	{
		shapedrawer.setPosition(mainX, mainY);
		window.draw(shapedrawer);
		shapedrawer.setPosition(mainX - 40, mainY);
		window.draw(shapedrawer);
		shapedrawer.setPosition(mainX + 40, mainY);
		window.draw(shapedrawer);
		shapedrawer.setPosition(mainX + 40, mainY - 40);
		window.draw(shapedrawer);
	}
	if (rotation == 1)
	{
		shapedrawer.setPosition(mainX, mainY);
		window.draw(shapedrawer);
		shapedrawer.setPosition(mainX, mainY - 40);
		window.draw(shapedrawer);
		shapedrawer.setPosition(mainX + 40, mainY + 40);
		window.draw(shapedrawer);
		shapedrawer.setPosition(mainX, mainY + 40);
		window.draw(shapedrawer);
	}
	if (rotation == 2)
	{
		shapedrawer.setPosition(mainX, mainY);
		window.draw(shapedrawer);
		shapedrawer.setPosition(mainX - 40, mainY);
		window.draw(shapedrawer);
		shapedrawer.setPosition(mainX + 40, mainY);
		window.draw(shapedrawer);
		shapedrawer.setPosition(mainX - 40, mainY + 40);
		window.draw(shapedrawer);
	}
	if (rotation == 3)
	{
		shapedrawer.setPosition(mainX, mainY);
		window.draw(shapedrawer);
		shapedrawer.setPosition(mainX, mainY - 40);
		window.draw(shapedrawer);
		shapedrawer.setPosition(mainX, mainY + 40);
		window.draw(shapedrawer);
		shapedrawer.setPosition(mainX - 40, mainY - 40);
		window.draw(shapedrawer);
	}
}
void lStraight::resetLocation()
{
	mainRow = 0;
	mainCol = 4;
	rotation = 0;
	mainX = 500 + mainCol * 40;
	mainY = 100 + mainRow * 40;
}
void lStraight::moveRight(sf::RectangleShape& shapedrawer, sf::RenderWindow& window, Well& well)
{
	if (rotation == 0 && mainCol < 8 && well.cellCheck(mainRow, mainCol + 2) == true && well.cellCheck(mainRow - 1, mainCol) == true)
	{
		mainCol++;
		mainX += 40;
		draw(shapedrawer, window);
	}
	if (rotation == 1 && mainCol < 8 && well.cellCheck(mainRow - 1, mainCol + 1) == true && well.cellCheck(mainRow, mainCol + 1) == true && well.cellCheck(mainRow + 1, mainCol + 2) == true)
	{
		mainCol++;
		mainX += 40;
		draw(shapedrawer, window);
	}
	if (rotation == 2 && mainCol < 8 && well.cellCheck(mainRow, mainCol + 2) == true && well.cellCheck(mainRow + 1, mainCol ) == true)
	{
		mainCol++;
		mainX += 40;
		draw(shapedrawer, window);
	}
	if (rotation == 3 && mainCol < 9 && well.cellCheck(mainRow - 1, mainCol + 1) == true && well.cellCheck(mainRow, mainCol + 1) == true && well.cellCheck(mainRow + 1, mainCol + 1) == true)
	{
		mainCol++;
		mainX += 40;
		draw(shapedrawer, window);
	}
}
void lStraight::moveLeft(sf::RectangleShape& shapedrawer, sf::RenderWindow& window, Well& well)
{
	if (rotation == 0 && mainCol > 1 && well.cellCheck(mainRow, mainCol - 2) == true && well.cellCheck(mainRow - 1, mainCol ) == true)
	{
		mainCol--;
		mainX -= 40;
		draw(shapedrawer, window);
	}
	if (rotation == 1 && mainCol > 0 && well.cellCheck(mainRow - 1, mainCol - 1) == true && well.cellCheck(mainRow, mainCol - 1) == true && well.cellCheck(mainRow + 1, mainCol - 1) == true)
	{
		mainCol--;
		mainX -= 40;
		draw(shapedrawer, window);
	}
	if (rotation == 2 && mainCol > 1 && well.cellCheck(mainRow, mainCol - 2) == true && well.cellCheck(mainRow + 1, mainCol - 2) == true)
	{
		mainCol--;
		mainX -= 40;
		draw(shapedrawer, window);
	}
	if (rotation == 3 && mainCol > 1 && well.cellCheck(mainRow - 1, mainCol - 2) == true && well.cellCheck(mainRow, mainCol - 1) == true && well.cellCheck(mainRow + 1, mainCol - 1) == true)
	{
		mainCol--;
		mainX -= 40;
		draw(shapedrawer, window);
	}
}
void lStraight::updateWell(Well& well)
{
	if (rotation == 0)
	{
		well.setCell(4, mainRow, mainCol);
		well.setCell(4, mainRow, mainCol - 1);
		well.setCell(4, mainRow, mainCol + 1);
		well.setCell(4, mainRow - 1, mainCol + 1);
	}
	if (rotation == 1)
	{
		well.setCell(4, mainRow, mainCol);
		well.setCell(4, mainRow - 1, mainCol);
		well.setCell(4, mainRow + 1, mainCol);
		well.setCell(4, mainRow + 1, mainCol + 1);
	}
	if (rotation == 2)
	{
		well.setCell(4, mainRow, mainCol);
		well.setCell(4, mainRow, mainCol - 1);
		well.setCell(4, mainRow, mainCol + 1);
		well.setCell(4, mainRow + 1, mainCol - 1);
	}
	if (rotation == 3)
	{
		well.setCell(4, mainRow, mainCol);
		well.setCell(4, mainRow - 1, mainCol);
		well.setCell(4, mainRow + 1, mainCol);
		well.setCell(4, mainRow - 1, mainCol - 1);
	}
}