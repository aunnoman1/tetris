#include"header.h"
Game::Game()
{
	shapes = new tetrimino * [7];
	shapes[0] = new square;
	shapes[1] = new rectangle;
	shapes[2] = new lReverse;
	shapes[3] = new lStraight;
	shapes[4] = new sStraight;
	shapes[5] = new sReverse;
	shapes[6] = new T;
	currentShape = rand() % 7;
	nextShape = rand() % 7;
	score = 0;
	level = 1;
	interval= sf::milliseconds(1000);
	lines = 0;
	names.open("names.txt");
	scores.open("scores.txt");
	newNames.open("tempnames.txt");
	newScores.open("tempscores.txt");
	name = "";
}
void Game::setname(string n)
{
	name = n;
}
void Game::drawGame(sf::RectangleShape& wellBoundary, sf::RenderWindow& window, sf::RectangleShape& wellFiller,sf::RectangleShape shapemaker , sf::RectangleShape& gameDrawer, sf::Text& text)
{
	well.drawWell(wellBoundary, window, wellFiller,shapes);
	shapes[currentShape]->draw(shapemaker, window);
	drawScore(window, gameDrawer, text);
	drawNextShape(window, gameDrawer, shapemaker, text);
	drawLevel(window,gameDrawer,text);
	drawNumLines(window, gameDrawer, text);
	drawLeaderBoard(window, gameDrawer, text);
}

void Game::drawScore(sf::RenderWindow& window, sf::RectangleShape& gameDrawer, sf::Text& text)
{
	gameDrawer.setSize(sf::Vector2f(600.f, 80.f));
	gameDrawer.setFillColor(sf::Color(0, 0, 0));
	gameDrawer.setOutlineThickness(2);
	gameDrawer.setOutlineColor(sf::Color(255, 255, 255));
	gameDrawer.setPosition(sf::Vector2f(1200.f, 320.f));
	window.draw(gameDrawer);
	text.setString("Score : " + to_string(score));
	text.setCharacterSize(65);
	text.setFillColor(sf::Color::White);
	text.setPosition(sf::Vector2f(1215.f, 320.f));
	window.draw(text);
}

void Game::drawNextShape(sf::RenderWindow& window, sf::RectangleShape& gameDrawer,sf::RectangleShape& shapemaker, sf::Text& text)
{
	gameDrawer.setSize(sf::Vector2f(600.f, 250.f));
	gameDrawer.setFillColor(sf::Color(0, 0, 0));
	gameDrawer.setOutlineThickness(2);
	gameDrawer.setOutlineColor(sf::Color(255, 255, 255));
	gameDrawer.setPosition(sf::Vector2f(1200.f, 50.f));
	window.draw(gameDrawer);
	gameDrawer.setSize(sf::Vector2f(600.f, 2.f));
	gameDrawer.setFillColor(sf::Color(255, 255, 255));
	gameDrawer.setOutlineThickness(0);
	gameDrawer.setOutlineColor(sf::Color(255, 255, 255));
	gameDrawer.setPosition(sf::Vector2f(1200.f, 130.f));
	window.draw(gameDrawer);
	text.setString("NEXT SHAPE");
	text.setCharacterSize(65);
	text.setFillColor(sf::Color::White);
	text.setPosition(sf::Vector2f(1280.f, 50.f));
	window.draw(text);
	shapes[nextShape]->draw(shapemaker, window, 1455, 195);
}

void Game::drawLevel(sf::RenderWindow& window, sf::RectangleShape& gameDrawer, sf::Text& text)
{
	gameDrawer.setSize(sf::Vector2f(600.f, 80.f));
	gameDrawer.setFillColor(sf::Color(0, 0, 0));
	gameDrawer.setOutlineThickness(2);
	gameDrawer.setOutlineColor(sf::Color(255, 255, 255));
	gameDrawer.setPosition(sf::Vector2f(1200.f, 420.f));
	window.draw(gameDrawer);
	text.setString("Level : " + to_string(level));
	text.setCharacterSize(65);
	text.setFillColor(sf::Color::White);
	text.setPosition(sf::Vector2f(1215.f, 420.f));
	window.draw(text);
}

void Game::drawUser(sf::RenderWindow& window , sf::RectangleShape& gameDrawer, sf::Text& text , string& name)
{
	gameDrawer.setFillColor(sf::Color(0, 0, 0, 0));
	gameDrawer.setSize(sf::Vector2f(430.f, 80.f));
	gameDrawer.setPosition(sf::Vector2f(745, 500.f));
	gameDrawer.setOutlineColor(sf::Color(255, 255, 255, 255));
	gameDrawer.setOutlineThickness(2);
	window.draw(gameDrawer);
	text.setString("Enter Your Name");
	text.setCharacterSize(65);
	text.setFillColor(sf::Color::White);
	text.setPosition(sf::Vector2f(650.f, 400.f));
	window.draw(text);

	text.setString(name);
	text.setCharacterSize(65);
	text.setFillColor(sf::Color::White);
	text.setPosition(sf::Vector2f(780.f, 500.f));
	window.draw(text);
}

bool Game::gameRunning()
{
	if (well.grid[0][3] > 0 || well.grid[0][4] > 0 || well.grid[0][5] > 0 || well.grid[0][6] > 0)
	{
		return false;
	}
	return true;
}

void Game::drawNumLines(sf::RenderWindow& window, sf::RectangleShape& gameDrawer, sf::Text& text)
{
	gameDrawer.setSize(sf::Vector2f(600.f, 80.f));
	gameDrawer.setFillColor(sf::Color(0, 0, 0));
	gameDrawer.setOutlineThickness(2);
	gameDrawer.setOutlineColor(sf::Color(255, 255, 255));
	gameDrawer.setPosition(sf::Vector2f(1200.f, 520.f));
	window.draw(gameDrawer);
	text.setString("Lines : " + to_string(lines));
	text.setCharacterSize(65);
	text.setFillColor(sf::Color::White);
	text.setPosition(sf::Vector2f(1215.f, 520.f));
	window.draw(text);
}
void Game::drawLeaderBoard(sf::RenderWindow& window, sf::RectangleShape& gameDrawer, sf::Text& text)
{
	string temp;
	gameDrawer.setFillColor(sf::Color(0, 0, 0, 0));
	gameDrawer.setSize(sf::Vector2f(600.f, 300.f));
	gameDrawer.setPosition(sf::Vector2f(1200, 700.f));
	gameDrawer.setOutlineColor(sf::Color(255, 255, 255, 255));
	gameDrawer.setOutlineThickness(2);
	window.draw(gameDrawer);

	gameDrawer.setSize(sf::Vector2f(600.f, 80.f));
	gameDrawer.setPosition(sf::Vector2f(1200, 620.f));
	window.draw(gameDrawer);

	text.setString("leaderBoard");
	text.setCharacterSize(65);
	text.setFillColor(sf::Color::White);
	text.setPosition(sf::Vector2f(1250.f, 620.f));
	window.draw(text);
	int moveby = 0;
	while (getline(names, temp))
	{
		text.setString(temp);
		text.setCharacterSize(50);
		text.setFillColor(sf::Color::White);
		text.setPosition(sf::Vector2f(1210.f, (700+moveby)));
		window.draw(text);
		moveby += 60;
	}
	names.clear();
	names.seekg(0);
	moveby = 0;
	while (getline(scores, temp))
	{
		text.setString(temp);
		text.setCharacterSize(50);
		text.setFillColor(sf::Color::White);
		text.setPosition(sf::Vector2f(1600.f, (700 + moveby)));
		window.draw(text);
		moveby += 60;
	}
	scores.clear();
	scores.seekg(0);
}

void Game::UpdateLeaderboard()
{
	string  oldscore,oldname ;
	int i = 1  , sLine,nLine;
	bool scoreAdded = false;
	while (i<6)
	{
		sLine = scores.tellg();
		nLine = names.tellg();
		getline(scores, oldscore);
		getline(names, oldname);
		if (score > stoi(oldscore) && !scoreAdded)
		{
			newNames<<(to_string(i) +". " + name)<<endl;
			newScores << to_string(score)<<endl;
			scoreAdded = true;
			scores.seekg(sLine);
			names.seekg(nLine);
		}
		else
		{
			newNames << oldname<<endl;
			newScores << oldscore<<endl;
		}
		i++;
	}
	scores.close();
	names.close();
	newScores.close();
	newNames.close();
	remove("scores.txt");
	remove("names.txt");
	rename("tempscores.txt", "scores.txt");
	rename("tempnames.txt", "names.txt");
	names.open("names.txt");
	scores.open("scores.txt");
	newNames.open("tempnames.txt");
	newScores.open("tempscores.txt");
}
void Game::drawGameOver(sf::RenderWindow& window, sf::RectangleShape& gameDrawer, sf::Text& text)
{
	gameDrawer.setSize(sf::Vector2f(460.f, 100.f));
	gameDrawer.setFillColor(sf::Color(0, 0, 0));
	gameDrawer.setOutlineThickness(2);
	gameDrawer.setOutlineColor(sf::Color(255, 0, 0));
	gameDrawer.setPosition(sf::Vector2f(470.f, 420.f));
	window.draw(gameDrawer);
	text.setString("Game over");
	text.setCharacterSize(65);
	text.setFillColor(sf::Color::White);
	text.setPosition(sf::Vector2f(500.f, 430.f));
	window.draw(text);


}

void Game::drawGameOverScreen(sf::RenderWindow& window, sf::RectangleShape& gameDrawer, sf::Text& text)
{
	string temp;
	int moveby = 0;
	gameDrawer.setSize(sf::Vector2f(700.f, 170.f));
	gameDrawer.setFillColor(sf::Color::White);
	gameDrawer.setOutlineThickness(2);
	gameDrawer.setOutlineColor(sf::Color(255, 0, 0));
	gameDrawer.setPosition(sf::Vector2f(610.f, 100.f));
	window.draw(gameDrawer);
	text.setString("Game over");
	text.setCharacterSize(110);
	text.setFillColor(sf::Color::Red);
	text.setPosition(sf::Vector2f(640.f, 115.f));
	window.draw(text);

	gameDrawer.setFillColor(sf::Color(0, 0, 0, 0));
	gameDrawer.setSize(sf::Vector2f(700.f, 400.f));
	gameDrawer.setPosition(sf::Vector2f(610, 500.f));
	gameDrawer.setOutlineColor(sf::Color(255, 255, 255, 255));
	gameDrawer.setOutlineThickness(2);
	window.draw(gameDrawer);
	text.setString("leaderBoard");
	text.setCharacterSize(65);
	text.setFillColor(sf::Color::White);
	text.setPosition(sf::Vector2f(720.f, 400.f));
	window.draw(text);

	while (getline(names, temp))
	{
		text.setString(temp);
		text.setCharacterSize(70);
		text.setFillColor(sf::Color::White);
		text.setPosition(sf::Vector2f(620.f, (500 + moveby)));
		window.draw(text);
		moveby += 75;
	}
	names.clear();
	names.seekg(0);
	moveby = 0;
	while (getline(scores, temp))
	{
		text.setString(temp);
		text.setCharacterSize(70);
		text.setFillColor(sf::Color::White);
		text.setPosition(sf::Vector2f(1065.f, (500 + moveby)));
		window.draw(text);
		moveby += 75;
	}
	scores.clear();
	scores.seekg(0);
}

void Game::dropShape(sf::RectangleShape& shapemaker,sf::RenderWindow& window)
{
	shapes[currentShape]->drop(well, shapemaker, window);
}
void Game::moveRight(sf::RectangleShape& shapeMaker, sf::RenderWindow& window)
{
	 shapes[currentShape]->moveRight(shapeMaker, window ,well);
}
void Game::moveLeft(sf::RectangleShape& shapeMaker, sf::RenderWindow& window)
{
	shapes[currentShape]->moveLeft(shapeMaker, window, well);
}
void Game::rotateShape(sf::RectangleShape& shapemaker, sf::RenderWindow& window)
{
	shapes[currentShape]->rotateShape(well);
}
bool Game::fixShape()
{
	if (shapes[currentShape]->isSettled(well))
	{
		shapes[currentShape]->updateWell(well);
		checkCombo();
		shapes[currentShape]->resetLocation();
		currentShape = nextShape;
		nextShape = rand() % 7;
		return true;
		//system("CLS");
		//for (int i = 0; i < 20; i++)
		//{
		//	for (int j = 0; j < 10; j++)
		//	{
		//		cout << well.grid[i][j] << " ";
		//	}
		//	cout << endl;
		//}

	}
	return false;
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
			lines++;
			if (score % 1000 == 0)
			{
				level++;
				interval = interval - (interval * float(0.1));
				double temp = interval.asMilliseconds();
			}
			if ( level != 1 && level%8 ==1)
			{
				interval = sf::milliseconds(1000);
			}
		}
	}
}
sf::Time Game::getInterval()
{
	return interval;
}