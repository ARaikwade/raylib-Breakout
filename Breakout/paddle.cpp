#include "paddle.h"
paddle::paddle(int x, int y, int width, int height, int speed)
	: speed(speed), paddleRect{ (float)x, (float)y, (float)width, (float)height } {}

void paddle::move(int direction) {
	// Move the paddle left or right based on the direction
	//check collision with walls before moving
	if (checkCollisionWithWalls(GetScreenWidth())) {
		return; // If collision with walls, do not move
	}
	paddleRect.x += direction * speed;
}

void paddle::draw() const {
	DrawRectangleRec(paddleRect, BLUE);
}

Rectangle paddle::getRect() const {
	return paddleRect;
}
//check collision with wall
bool paddle::checkCollisionWithWalls(int screenWidth) {
	if (paddleRect.x < 0) {
		paddleRect.x = 0; // Prevent paddle from going off the left edge
		return true;
	}
	else if (paddleRect.x + paddleRect.width > screenWidth) {
		paddleRect.x = screenWidth - paddleRect.width; // Prevent paddle from going off the right edge
		return true;
	}
	return false;
}