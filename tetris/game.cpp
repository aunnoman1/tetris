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
bool Game::dropShape(sf::RectangleShape& shapemaker,sf::RenderWindow& window)
{
	return shapes[currentShape]->drop(well.grid, shapemaker, window);
}