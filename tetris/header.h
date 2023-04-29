#include<iostream>
#include <SFML/Graphics.hpp>
using namespace std;

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
	virtual void rotateShape() = 0;
	virtual bool drop(int well[][10], sf::RectangleShape&, sf::RenderWindow&) = 0;
	virtual void draw(sf::RectangleShape&, sf::RenderWindow&) = 0;
	virtual void resetLocation() = 0;
	virtual void move(sf::RectangleShape&, sf::RenderWindow&, bool) = 0;
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
};





class Game
{
	Well well;
	tetrimino** shapes;
	int currentShape;
public:
	Game();
	void drawGame(sf::RectangleShape&, sf::RenderWindow&, sf::RectangleShape&, sf::RectangleShape);
	bool dropShape(sf::RectangleShape&, sf::RenderWindow&);
};




class square : public tetrimino
{
public:
	square();
	void rotateShape();
	bool drop(int well[][10], sf::RectangleShape& , sf::RenderWindow&);
	void draw(sf::RectangleShape&,sf::RenderWindow&);
	void resetLocation() ;
	void move(sf::RectangleShape&, sf::RenderWindow&, bool);
};

class rectangle : public tetrimino
{
public:
	rectangle();
	void rotateShape();
	bool drop(int well[][10], sf::RectangleShape& , sf::RenderWindow &);
	void draw();
	void resetLocation();
};