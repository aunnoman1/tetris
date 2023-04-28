#include<iostream>
#include <SFML/Graphics.hpp>
using namespace std;
class tetrimino
{
protected:
	int MainX;
	int MainY;
	int rotation;
	int colour[4];
	int outerColour[4];
	int row;
	int col;
public:
	virtual void rotateShape() = 0;
	virtual bool drop(int well[][10]) = 0;
	virtual void draw(sf::RectangleShape,sf::RenderWindow) = 0;
	sf::Color getColour()
	{
		return sf::Color(colour[0], colour[1], colour[2], colour[3]);
	}
	sf::Color getOuterColour()
	{
		return sf::Color(outerColour[0], outerColour[1], outerColour[2], outerColour[3]);
	}
};

class square : public tetrimino
{
public:
	square();
	void rotateShape();
	bool drop(int well[][10]);
	void draw(sf::RectangleShape,sf::RenderWindow);
};

class rectangle : public tetrimino
{
public:
	rectangle();
	void rotateShape();
	bool drop(int well[][10]);
	void draw();
};