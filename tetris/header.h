#include<iostream>
#include <SFML/Graphics.hpp>
using namespace std;

class Well;

class tetrimino
{
protected:
	int mainX;
	int mainY;
	int rotation;
	int colour[4];
	int outerColour[4];
	int mainRow;
	int mainCol;
public:
	virtual void rotateShape(Well&) = 0;
	virtual void drop(Well&, sf::RectangleShape&, sf::RenderWindow&) = 0;
	virtual void draw(sf::RectangleShape&, sf::RenderWindow&) = 0;
	virtual void resetLocation() = 0;
	virtual void moveRight(sf::RectangleShape&, sf::RenderWindow&, Well&) = 0;
	virtual void moveLeft(sf::RectangleShape&, sf::RenderWindow&, Well&) = 0;
	virtual bool isSettled(Well&) = 0;
	virtual void updateWell(Well&) = 0;
	virtual void draw(sf::RectangleShape&, sf::RenderWindow& , int x , int y) = 0;
	sf::Color getColour()
	{
		return sf::Color(colour[0], colour[1], colour[2], colour[3]);
	}
	sf::Color getOuterColour()
	{
		return sf::Color(outerColour[0], outerColour[1], outerColour[2], outerColour[3]);
	}
};


class Well
{
	int grid[20][10];

public:
	friend class Game;
	Well();
	void drawWell(sf::RectangleShape&, sf::RenderWindow&, sf::RectangleShape&, tetrimino**&);
	bool cellCheck(int, int);
	void setCell(int, int, int);
};





class Game
{
	Well well;
	tetrimino** shapes;
	int currentShape;
	int nextShape;
	int score;
	int level;
	int lines;
	sf::Time interval;
public:
	Game();
	void drawGame(sf::RectangleShape&, sf::RenderWindow&, sf::RectangleShape&, sf::RectangleShape, sf::RectangleShape&, sf::Text&);
	void dropShape(sf::RectangleShape&, sf::RenderWindow&);
	void moveRight(sf::RectangleShape&, sf::RenderWindow&);
	void moveLeft(sf::RectangleShape&, sf::RenderWindow&);
	bool fixShape();
	void checkCombo();
	void rotateShape(sf::RectangleShape&, sf::RenderWindow&);
	sf::Time getInterval();
	void drawScore(sf::RenderWindow&, sf::RectangleShape&, sf::Text&);
	void drawNextShape(sf::RenderWindow&, sf::RectangleShape&, sf::RectangleShape&, sf::Text&);
	void drawLevel(sf::RenderWindow&, sf::RectangleShape&, sf::Text&);
	void drawUser(sf::RenderWindow&, sf::RectangleShape&, sf::Text&, string&);
	bool gameRunning();
	void drawNumLines(sf::RenderWindow&, sf::RectangleShape&, sf::Text&);
	void drawGameOver(sf::RenderWindow&, sf::RectangleShape&, sf::Text&);
	void drawGameOverScreen(sf::RenderWindow&, sf::RectangleShape&, sf::Text&, ifstream&, ifstream&);
};




class square : public tetrimino
{
public:
	square();
	void rotateShape(Well&);
	void drop(Well&, sf::RectangleShape& , sf::RenderWindow&);
	void draw(sf::RectangleShape&,sf::RenderWindow&);
	void resetLocation() ;
	void moveRight(sf::RectangleShape&, sf::RenderWindow&,Well&);
	void moveLeft(sf::RectangleShape&, sf::RenderWindow&, Well&);
	bool isSettled(Well&);
	void updateWell(Well&);
	void draw(sf::RectangleShape&, sf::RenderWindow&, int x, int y);
};

class rectangle : public tetrimino
{
public:
	rectangle();
	void rotateShape(Well&);
	void drop(Well&, sf::RectangleShape&, sf::RenderWindow&);
	void draw(sf::RectangleShape&, sf::RenderWindow&);
	void resetLocation();
	void moveRight(sf::RectangleShape&, sf::RenderWindow&, Well&);
	void moveLeft(sf::RectangleShape&, sf::RenderWindow&, Well&);
	bool isSettled(Well&);
	void updateWell(Well&);
	void draw(sf::RectangleShape&, sf::RenderWindow&, int x, int y);
};

class lReverse : public tetrimino
{
public:
	lReverse();
	void rotateShape(Well&);
	void drop(Well&, sf::RectangleShape&, sf::RenderWindow&);
	void draw(sf::RectangleShape&, sf::RenderWindow&);
	void resetLocation();
	void moveRight(sf::RectangleShape&, sf::RenderWindow&, Well&);
	void moveLeft(sf::RectangleShape&, sf::RenderWindow&, Well&);
	bool isSettled(Well&);
	void updateWell(Well&);
	void draw(sf::RectangleShape&, sf::RenderWindow&, int x, int y);
};

class lStraight : public tetrimino
{
public:
	lStraight();
	void rotateShape(Well&);
	void drop(Well&, sf::RectangleShape&, sf::RenderWindow&);
	void draw(sf::RectangleShape&, sf::RenderWindow&);
	void resetLocation();
	void moveRight(sf::RectangleShape&, sf::RenderWindow&, Well&);
	void moveLeft(sf::RectangleShape&, sf::RenderWindow&, Well&);
	bool isSettled(Well&);
	void updateWell(Well&);
	void draw(sf::RectangleShape&, sf::RenderWindow&, int x, int y);
};

class sStraight : public tetrimino
{
public:
	sStraight();
	void rotateShape(Well&);
	void drop(Well&, sf::RectangleShape&, sf::RenderWindow&);
	void draw(sf::RectangleShape&, sf::RenderWindow&);
	void resetLocation();
	void moveRight(sf::RectangleShape&, sf::RenderWindow&, Well&);
	void moveLeft(sf::RectangleShape&, sf::RenderWindow&, Well&);
	bool isSettled(Well&);
	void updateWell(Well&);
	void draw(sf::RectangleShape&, sf::RenderWindow&, int x, int y);
};

class sReverse : public tetrimino
{
public:
	sReverse();
	void rotateShape(Well&);
	void drop(Well&, sf::RectangleShape&, sf::RenderWindow&);
	void draw(sf::RectangleShape&, sf::RenderWindow&);
	void resetLocation();
	void moveRight(sf::RectangleShape&, sf::RenderWindow&, Well&);
	void moveLeft(sf::RectangleShape&, sf::RenderWindow&, Well&);
	bool isSettled(Well&);
	void updateWell(Well&);
	void draw(sf::RectangleShape&, sf::RenderWindow&, int x, int y);
};

class T : public tetrimino
{
public:
	T();
	void rotateShape(Well&);
	void drop(Well&, sf::RectangleShape&, sf::RenderWindow&);
	void draw(sf::RectangleShape&, sf::RenderWindow&);
	void resetLocation();
	void moveRight(sf::RectangleShape&, sf::RenderWindow&, Well&);
	void moveLeft(sf::RectangleShape&, sf::RenderWindow&, Well&);
	bool isSettled(Well&);
	void updateWell(Well&);
	void draw(sf::RectangleShape&, sf::RenderWindow&, int x, int y);
};