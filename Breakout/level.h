#pragma once
#include <raylib.h>
#include "ball.h"
#include <vector>

class brick
{
	//this class represent rectangle brick in game
private:
	Rectangle brickRect; // rectangle representing the brick
	bool isAlive; // flag to check if the brick is destroyed
	Texture2D texture; // texture for the brick (optional, can be used for better visuals)

public:
	brick(float x, float y, float width, float height, Texture2D brickTexture)
		: brickRect{ x, y, width, height }, isAlive(true), texture{brickTexture} {}

	void draw() const {
		if (isAlive) {

			DrawTextureRec(texture, { 0, 0, brickRect.width, brickRect.height }, { brickRect.x, brickRect.y }, WHITE);

			//DrawRectangleRounded(brickRect, 0.1f, 0, BROWN); // Draw rounded corners for better aesthetics
			//DrawRectangleRoundedLines(brickRect, 0.1f, 0, BLACK); // Draw border around the brick with rounded corners
			
		}
	}

    bool checkCollision(Vector2 position, float radius) const {
		return isAlive && CheckCollisionCircleRec(position, radius, brickRect);
    }

	void destroy() {
		isAlive = false;
	}

	bool isBrickAlive() const {
		return isAlive;
	}

};


class level
{
	//this class holds the vector of bricks and manages the level
private:
	std::vector<brick> bricks; // vector of bricks in the level
	int rows; // number of rows of bricks
	int cols; // number of columns of bricks
	float brickWidth; // width of each brick
	float brickHeight; // height of each brick

public:
	level(int rows, int cols, float brickWidth, float brickHeight);

	void draw() const;

	bool checkCollision(ball& playerBall);

	bool allBricksDestroyed() const;
};

