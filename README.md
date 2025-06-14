**Breakout Game**
A simple implementation of the classic Breakout game using the Raylib library. Players control a paddle to bounce a ball and break bricks. The game ends when the ball misses the paddle or all bricks are destroyed.
---
**Features**
•	Paddle Movement: Use keyboard controls to move the paddle left or right.
•	Ball Physics: The ball bounces off the paddle, walls, and bricks.
•	Brick Levels: Multiple rows of bricks to break.
•	Game States:
•	Game Over: When the ball misses the paddle.
•	You Win: When all bricks are destroyed.
•	Dynamic Difficulty: The number of brick rows increases after each win.
---
Installation
Prerequisites
•	Raylib: Ensure Raylib is installed on your system. You can download it from Raylib's official website.
•	C++ Compiler: A compiler that supports C++17 or later (e.g., GCC, Clang, or MSVC).
•	Visual Studio: Recommended IDE for building and running the project.
---
Steps to Run
1.	Clone the repository:
   git clone https://github.com/yourusername/BreakoutGame.git
   cd BreakoutGame
   2.	Build the project:
•	Open the project in Visual Studio.
•	Ensure Raylib is properly linked in your project settings.
•	Build and run the project.
3.	Play the game:
•	Use the Left Arrow and Right Arrow keys to move the paddle.
•	Bounce the ball to break all bricks and win the game.
---
File Structure
BreakoutGame/
├── Breakout.cpp       # Main game logic
├── paddle.h/.cpp      # Paddle class for player control
├── ball.h/.cpp        # Ball class for movement and collision
├── level.h/.cpp       # Level class for managing bricks
├── assets/            # Folder for game assets (textures, etc.)
└── README.md          # Project documentation

Controls
•	Left Arrow: Move paddle left.
•	Right Arrow: Move paddle right.
---
Future Improvements
•	Add sound effects for collisions and game events.
•	Implement more levels with increasing difficulty.
•	Add power-ups (e.g., larger paddle, faster ball).
•	Improve graphics with advanced textures and animations.
---
Credits
•	Raylib: For providing an easy-to-use game development library.
•	You: Amar Raikwade
