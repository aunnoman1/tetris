#include"header.h"

Well::Well()
{
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 10; j++)
			grid[i][j] = 0;
}

void Well::drawWell(sf::RectangleShape& wellBoundary, sf::RenderWindow& window, sf::RectangleShape& wellfiller, tetrimino**& shapes)
{
	wellBoundary.setFillColor(sf::Color(12, 12, 12));
	wellBoundary.setOutlineThickness(2);
	wellBoundary.setOutlineColor(sf::Color(255, 255, 255));
	wellBoundary.setPosition(sf::Vector2f(500.f, 100.f));
	window.draw(wellBoundary);
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (grid[i][j] == 0)
			{
				wellfiller.setFillColor(sf::Color(12, 12, 12));
				wellfiller.setOutlineThickness(-1);
				wellfiller.setOutlineColor(sf::Color(46, 46, 46));
				wellfiller.setPosition(sf::Vector2f((500 + 40 * j), (100 + 40 * i)));
				window.draw(wellfiller);
			}
			else
			{
				wellfiller.setFillColor((shapes[grid[i][j] - 1])->getColour());
				wellfiller.setOutlineThickness(-3);
				wellfiller.setOutlineColor((shapes[grid[i][j] - 1])->getOuterColour());
				wellfiller.setPosition(sf::Vector2f((500 + 40 * j), (100 + 40 * i)));
				window.draw(wellfiller);
			}

		}
	}
}
bool Well::cellCheck(int row, int col) // return true if cell empty
{
	if (grid[row][col] == 0)
		return true;
	return false;
}
void Well::setCell(int val, int row, int col)
{
	grid[row][col] = val;
}