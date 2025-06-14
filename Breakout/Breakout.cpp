#include<raylib.h>
#include "paddle.h"
#include "ball.h"
#include "level.h"

int main()
{
	// Initialization
	const int screenWidth = 800;
	const int screenHeight = 450;
	const int paddleWidth = 100;
	const int paddleHeight = 20;
	const int paddleSpeed = 5;
	const int ballRadius = 8;
	const int ballSpeed = 3;
	const int brickWidth = 40; // Width of each brick
	const int brickHeight = 20; // Height of each brick
	int rows = 2; // Number of rows of bricks
	const int cols = 20; // Number of columns of bricks


	InitWindow(screenWidth, screenHeight, "Breakout Game");

	SetTargetFPS(60);

	// Main game loop
	while (!WindowShouldClose())
	{
		bool gameOver = false;
		bool gameWon = false;

		level gameLevel(rows, cols, brickWidth, brickHeight); // Initialize the level with bricks
		paddle playerPaddle(350, 400, paddleWidth, paddleHeight, paddleSpeed); // Example paddle initialization
		ball playerBall(400, 200, ballRadius, ballSpeed); // Example ball initialization

		while (!gameOver && !WindowShouldClose())
		{
			if (!playerBall.move(playerPaddle.getRect()))
				gameOver = true;

			if (gameLevel.checkCollision(playerBall)) {
				if (gameLevel.allBricksDestroyed()) {
					gameOver = true;
					gameWon = true;
				}
			}

			if (IsKeyDown(KEY_LEFT))
				playerPaddle.move(-1); // Move paddle left
			else if (IsKeyDown(KEY_RIGHT))
				playerPaddle.move(1); // Move paddle left

			//-----------------------------------------------------------------------//
			BeginDrawing();
			ClearBackground(RAYWHITE);

			if (gameOver && gameWon)
			{
				DrawText("You Win!", screenWidth / 2 - 50, screenHeight / 2 - 20, 20, GREEN);
				EndDrawing();
				// Delay for 2 seconds
				for (int i = 0; i < 120; i++) { // 120 frames at 60 FPS = 2 seconds
					BeginDrawing();
					ClearBackground(RAYWHITE);
					DrawText("You Win!", screenWidth / 2 - 50, screenHeight / 2 - 20, 20, GREEN);
					EndDrawing();
				}
				rows++;
			}
			else if (gameOver)
			{
				DrawText("Game Over!", screenWidth / 2 - 50, screenHeight / 2 - 20, 20, RED);
				EndDrawing();
				// Delay for 2 seconds
				for (int i = 0; i < 120; i++) { // 120 frames at 60 FPS = 2 seconds
					BeginDrawing();
					ClearBackground(RAYWHITE);
					DrawText("Game Over!", screenWidth / 2 - 50, screenHeight / 2 - 20, 20, RED);
					EndDrawing();
				}
			}
			else
			{
				gameLevel.draw(); // Draw the level with bricks
				playerBall.draw(); // Draw the ball
				playerPaddle.draw(); // Draw the paddle
			}

			EndDrawing();
		}
	}

	// De-Initialization
	CloseWindow(); // Close window and OpenGL context

	return 0;
}