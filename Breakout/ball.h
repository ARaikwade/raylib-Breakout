#pragma once
#include <raylib.h>

class ball
{
	//this class represent circle ball in game
private:
	float speed; // speed of ball movement
	Vector2 position; // position of the ball
	float radius; // radius of the ball
	Vector2 velocity; // velocity vector of the ball

public:
	ball(float x, float y, float radius, float speed);
	bool move(Rectangle paddleReact);

	void draw() const;

	Vector2 getPosition() const;
	float getRadius() const;
	void setVelocity(Vector2 newVelocity);
	Vector2 getVelocity() const;
	bool checkCollisionWithWalls(int screenWidth, int screenHeight);
	void checkCollisionWithPaddle(Rectangle paddleRect);
};

