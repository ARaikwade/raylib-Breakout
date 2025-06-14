#include "ball.h"
#include "level.h"

ball::ball(float x, float y, float radius, float speed)
	: position{ x, y }, radius(radius), speed(speed), velocity{ speed, speed } {}

bool ball::move(Rectangle paddleRect) {
	// Move the ball based on its velocity
	if (!checkCollisionWithWalls(GetScreenWidth(), GetScreenHeight()))
		return false;// Check for wall collisions before moving
	checkCollisionWithPaddle(paddleRect); // Check for paddle collisions before moving
	position.x += velocity.x;
	position.y += velocity.y;
}

void ball::draw() const {
	// Draw the ball at its current position
	DrawCircleV(position, radius, RED);
}

Vector2 ball::getPosition() const {
	return position;
}
float ball::getRadius() const {
	return radius;
}
void ball::setVelocity(Vector2 newVelocity) {
	velocity = newVelocity;
}
Vector2 ball::getVelocity() const {
	return velocity;
}
bool ball::checkCollisionWithWalls(int screenWidth, int screenHeight) {
	// Check collision with walls and reverse velocity if necessary
	if (position.x - radius < 0 || position.x + radius > screenWidth) {
		velocity.x = -velocity.x; // Reverse horizontal direction
	}
	if (position.y - radius < 0) {
		velocity.y = -velocity.y; // Reverse vertical direction
	}

	if (position.y + radius > screenHeight)
	{
		return false;
	}
	return true;
}
void ball::checkCollisionWithPaddle(Rectangle paddleRect) {  
// Check collision with paddle and reverse vertical velocity if necessary  
if (CheckCollisionCircleRec(position, radius, paddleRect)) {  
	velocity.y = -velocity.y; // Reverse vertical direction  
	// Adjust position to be just above the paddle  
	position.y = paddleRect.y - radius;  

	// Tweak horizontal component based on distance from paddle center  
	float paddleCenter = paddleRect.x + paddleRect.width / 2;  
	velocity.x += (position.x - paddleCenter) * 0.1f; // Adds player control  
}  
}