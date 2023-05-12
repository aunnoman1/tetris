#include"header.h"
Game::Game()
{
	shapes = new tetrimino * [7];
	shapes[0] = new square;
	shapes[1] = new rectangle;
	shapes[2] = new lReverse;
	shapes[3] = new lStraight;
	shapes[4] = new sStraight;
	shapes[5] = new sStraight;
	shapes[6] = new T;
	currentShape = rand() % 7;
	nextShape = rand() % 7;
	score = 0;
	level = 1;
	interval= sf::milliseconds(1000);
}
void Game::drawGame(sf::RectangleShape& wellBoundary, sf::RenderWindow& window, sf::RectangleShape& wellFiller,sf::RectangleShape shapemaker , sf::RectangleShape& gameDrawer, sf::Text& text)
{
	well.drawWell(wellBoundary, window, wellFiller,shapes);
	shapes[currentShape]->draw(shapemaker, window);
	drawScore(window, gameDrawer, text);
	drawNextShape(window, gameDrawer, text);
}

void Game::drawScore(sf::RenderWindow& window, sf::RectangleShape& gameDrawer, sf::Text& text)
{
	gameDrawer.setSize(sf::Vector2f(600.f, 80.f));
	gameDrawer.setFillColor(sf::Color(0, 0, 0));
	gameDrawer.setOutlineThickness(2);
	gameDrawer.setOutlineColor(sf::Color(255, 255, 255));
	gameDrawer.setPosition(sf::Vector2f(1200.f, 450.f));
	window.draw(gameDrawer);
	text.setString("Score : " + to_string(score));
	text.setCharacterSize(65);
	text.setFillColor(sf::Color::White);
	text.setPosition(sf::Vector2f(1215.f, 450.f));
	window.draw(text);
}

void drawNextShape(sf::RenderWindow& window, sf::RectangleShape& gameDrawer, sf::Text& text)
{
	gameDrawer.setSize(sf::Vector2f(600.f, 300.f));
	gameDrawer.setFillColor(sf::Color(0, 0, 0));
	gameDrawer.setOutlineThickness(2);
	gameDrawer.setOutlineColor(sf::Color(255, 255, 255));
	gameDrawer.setPosition(sf::Vector2f(1200.f, 100.f));
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
void Game::rotateShape(sf::RectangleShape& shapemaker, sf::RenderWindow& window)
{
	shapes[currentShape]->rotateShape(well);
}
void Game::fixShape()
{
	if (shapes[currentShape]->isSettled(well))
	{
		shapes[currentShape]->updateWell(well);
		checkCombo();
		shapes[currentShape]->resetLocation();
		currentShape = nextShape;
		nextShape = rand() % 7;
		system("CLS");
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				cout << well.grid[i][j] << " ";
			}
			cout << endl;
		}

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
			score += 100;
			if (score % 1000 == 0)
			{
				level++;
				interval = interval - (interval * float(0.1));
			}
			if (level%8 ==1)
			{
				level = 0;
				interval = sf::milliseconds(1000);
			}
		}
	}
}
sf::Time Game::getInterval()
{
	return interval;
}