#include<iostream>
using namespace std;
class tetrimino
{
protected:
	int topLeft;
	int rotation;
	int colour;
public:
	virtual void rotatesHape() = 0;
	virtual void setTopLeft() = 0;
	virtual void draw() = 0;
};

class square : public tetrimino
{
public:
	square();
	void rotateShape();
	void setTopLeft();
	void draw();
};

class rectangle : public tetrimino
{
public:
	rectangle();
	void rotateShape();
	void setTopLeft();
	void draw();
};