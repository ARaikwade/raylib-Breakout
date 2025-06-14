#pragma once
#include<raylib.h>

class paddle
{
	//this class represent rectangle paddle in game
private:
	int speed; // speed of paddle movement
	Rectangle paddleRect; // rectangle representing the paddle
public:
	paddle(int x, int y, int width, int height, int speed);
	void move(int direction);
	void draw() const;
	Rectangle getRect() const;
	bool checkCollisionWithWalls(int screenWidth);
};

