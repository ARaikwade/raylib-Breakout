#include "level.h"

level::level(int rows, int cols, float brickWidth, float brickHeight)
	: rows(rows), cols(cols), brickWidth(brickWidth), brickHeight(brickHeight) {

	Texture2D brickTexture = LoadTexture("brick.png"); // Load the texture file

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			float x = j * brickWidth;
			float y = i * brickHeight;
			bricks.emplace_back(x, y, brickWidth, brickHeight, brickTexture);
		}
	}
}

void level::draw() const {
	for (const auto& b : bricks) {
		//draw only alive bricks
		if (b.isBrickAlive())
			b.draw();
	}
}

bool level::checkCollision(ball& playerBall) {  
for (auto& b : bricks) {  
	if (b.checkCollision(playerBall.getPosition(), playerBall.getRadius())) {
		b.destroy();
		Vector2 ballVelocity = playerBall.getVelocity();
		ballVelocity.y = -ballVelocity.y; // Reverse vertical direction
		playerBall.setVelocity(ballVelocity);
		return true;  
	}  
}  
return false;  
}

bool level::allBricksDestroyed() const {
	for (const auto& b : bricks) {
		if (b.isBrickAlive()) return false;
	}
	return true;
}