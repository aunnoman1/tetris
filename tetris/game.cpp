#include"header.h"
Game::Game()
{
	shapes = new tetrimino * [7];
	shapes[0] = new square;
	shapes[1] = new square;
	shapes[2] = new square;
	shapes[3] = new square;
	shapes[4] = new square;
	shapes[5] = new square;
	shapes[6] = new square;
	currentShape = rand() % 7;
}
void Game::drawGame(sf::RectangleShape& wellBoundary, sf::RenderWindow& window, sf::RectangleShape& wellFiller,sf::RectangleShape shapemaker)
{
	well.drawWell(wellBoundary, window, wellFiller,shapes);
	shapes[currentShape]->draw(shapemaker, window);

}
void Game::dropShape(sf::RectangleShape& shapemaker,sf::RenderWindow& window)
{
	shapes[currentShape]->drop(well, shapemaker, window);
	//if (shapes[currentShape]->isSettled(well))
	//{
	//	fixShape();
	//	shapes[currentShape]->resetLocation();
	//	currentShape = rand() % 7;
	//}
}
void Game::moveRight(sf::RectangleShape& shapeMaker, sf::RenderWindow& window)
{
	 shapes[currentShape]->moveRight(shapeMaker, window ,well);
	 //if (shapes[currentShape]->isSettled(well))
	 //{
		// fixShape();
		// shapes[currentShape]->resetLocation();
		// currentShape = rand() % 7;
	 //}
}
void Game::moveLeft(sf::RectangleShape& shapeMaker, sf::RenderWindow& window)
{
	shapes[currentShape]->moveLeft(shapeMaker, window, well);
	//if (shapes[currentShape]->isSettled(well))
	//{
	//	fixShape();
	//	shapes[currentShape]->resetLocation();
	//	currentShape = rand() % 7;
	//}
}
void Game::fixShape()
{
	if (shapes[currentShape]->isSettled(well))
	{
		shapes[currentShape]->updateWell(well);
		checkCombo();
		shapes[currentShape]->resetLocation();
		currentShape = rand() % 7;
	}
}
void Game::checkCombo()
{
	for (int i = 0; i < 20; i++)
	{
		bool combomade = true;
		for (int j = 0; j < 10; j++)
		{
			if (well.grid[i][j] == 0)
				combomade = false;
		}
		if (combomade)
		{
			for (int k = i; k > 0; k--)
			{
				for (int j = 0; j < 10; j++)
				{
					well.grid[k][j] = well.grid[k - 1][j];
					
				}
				
			}
			for (int j = 0; j < 10; j++)
			{
				well.grid[0][j] = 0;

			}
		}
	}
}