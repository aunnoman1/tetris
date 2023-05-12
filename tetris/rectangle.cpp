#include"header.h"
rectangle::rectangle()
{
	colour[0] = 0;
	colour[1] = 255;
	colour[2] = 255;
	colour[3] = 255;
	outerColour[0] = 0;
	outerColour[1] = 204;
	outerColour[2] = 204;
	outerColour[3] = 255;
	mainRow = 0;
	mainCol = 4;
	rotation = 0;
	mainX = 500 + mainCol * 40;
	mainY = 100 + mainRow * 40;

}
void rectangle::rotateShape(Well& well)
{
	if (rotation == 0  && well.cellCheck(mainRow - 1, mainCol) == true && well.cellCheck(mainRow + 1, mainCol) == true && well.cellCheck(mainRow + 2, mainCol) == true)
	{
		rotation = 1; 
	}
	else if (rotation == 1 && mainCol<8 && mainCol>0 && well.cellCheck(mainRow, mainCol - 1) == true && well.cellCheck(mainRow, mainCol + 1) == true && well.cellCheck(mainRow, mainCol + 2) == true)
	{
		rotation = 0;
	}
}
bool rectangle::isSettled(Well& well) //returns false if every block under it is empty
{
	if (rotation == 0 && mainRow < 19 && well.cellCheck(mainRow + 1, mainCol - 1) == true && well.cellCheck(mainRow + 1, mainCol) == true && well.cellCheck(mainRow + 1, mainCol + 1) == true && well.cellCheck(mainRow + 1, mainCol + 2) == true)
	{
		return false;
	}
	if (rotation == 1 && mainRow<17 && well.cellCheck(mainRow+3, mainCol ) == true)
	{
		return false;
	}
	return true;

}
void rectangle::drop(Well& well, sf::RectangleShape& shapedrawer, sf::RenderWindow& window) //false = shape is not settled, true= shape is settled
{
	if (rotation == 0 && mainRow<19 && well.cellCheck(mainRow + 1, mainCol - 1) == true && well.cellCheck(mainRow + 1, mainCol) == true && well.cellCheck(mainRow + 1, mainCol + 1) == true && well.cellCheck(mainRow + 1, mainCol + 2) == true)
	{
		mainRow++;
		mainY = mainY + 40;
		draw(shapedrawer, window);
	}
	if (rotation == 1 &&mainRow<17 && well.cellCheck(mainRow+3, mainCol ) == true)
	{
		mainRow++;
		mainY = mainY + 40;
		draw(shapedrawer, window);
	}
}
void rectangle::draw(sf::RectangleShape& shapedrawer, sf::RenderWindow& window)
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
		shapedrawer.setPosition(mainX + 40, mainY );
		window.draw(shapedrawer);
		shapedrawer.setPosition(mainX + 80, mainY );
		window.draw(shapedrawer);
	}
	if (rotation == 1)
	{
		shapedrawer.setPosition(mainX, mainY);
		window.draw(shapedrawer);
		shapedrawer.setPosition(mainX , mainY - 40);
		window.draw(shapedrawer);
		shapedrawer.setPosition(mainX , mainY + 40);
		window.draw(shapedrawer);
		shapedrawer.setPosition(mainX , mainY +80);
		window.draw(shapedrawer);
	}
}
void rectangle::draw(sf::RectangleShape& shapedrawer, sf::RenderWindow& window , int x , int y)
{
	shapedrawer.setFillColor(sf::Color(colour[0], colour[1], colour[2], colour[3]));
	shapedrawer.setOutlineColor(sf::Color(outerColour[0], outerColour[1], outerColour[2], outerColour[3]));
	shapedrawer.setOutlineThickness(-3);
	shapedrawer.setPosition(x, y);
	window.draw(shapedrawer);
	shapedrawer.setPosition(x - 40, y);
	window.draw(shapedrawer);
	shapedrawer.setPosition(x + 40, y);
	window.draw(shapedrawer);
	shapedrawer.setPosition(x + 80, y);
	window.draw(shapedrawer);
}

void rectangle::resetLocation()
{
	mainRow = 0;
	mainCol = 4;
	rotation = 0;
	mainX = 500 + mainCol * 40;
	mainY = 100 + mainRow * 40;
}
void rectangle::moveRight(sf::RectangleShape& shapedrawer, sf::RenderWindow& window, Well& well)
{
	if (rotation==0 && mainCol < 7 && well.cellCheck(mainRow, mainCol + 3) == true )
	{
		mainCol++;
		mainX += 40;
		draw(shapedrawer, window);
	}
	if (rotation == 1 && mainCol < 9 && well.cellCheck(mainRow, mainCol + 1) == true && well.cellCheck(mainRow - 1, mainCol + 1) == true && well.cellCheck(mainRow + 1, mainCol + 1) == true && well.cellCheck(mainRow + 2, mainCol + 1) == true)
	{
		mainCol++;
		mainX += 40;
		draw(shapedrawer, window);
	}
}
void rectangle::moveLeft(sf::RectangleShape& shapedrawer, sf::RenderWindow& window, Well& well)
{
	if (rotation == 0 && mainCol >1  && well.cellCheck(mainRow, mainCol - 2) == true)
	{
		mainCol--;
		mainX -= 40;
		draw(shapedrawer, window);
	}
	if (rotation == 1 && mainCol >0  && well.cellCheck(mainRow, mainCol - 1) == true && well.cellCheck(mainRow - 1, mainCol - 1) == true && well.cellCheck(mainRow + 1, mainCol - 1) == true && well.cellCheck(mainRow + 2, mainCol - 1) == true)
	{
		mainCol--;
		mainX -= 40;
		draw(shapedrawer, window);
	}
}
void rectangle::updateWell(Well& well)
{
	if (rotation == 0)
	{
		well.setCell(2, mainRow, mainCol);
		well.setCell(2, mainRow, mainCol - 1);
		well.setCell(2, mainRow , mainCol + 1);
		well.setCell(2, mainRow , mainCol + 2);
	}
	if (rotation == 1)
	{
		well.setCell(2, mainRow, mainCol);
		well.setCell(2, mainRow - 1, mainCol);
		well.setCell(2, mainRow + 1, mainCol);
		well.setCell(2, mainRow + 2, mainCol);
	}
}