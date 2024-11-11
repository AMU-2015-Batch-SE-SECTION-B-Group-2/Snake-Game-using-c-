Snake Game in C++ - README
Overview
This is a simple implementation of the classic **Snake Game** in C++, where the player controls a snake that moves around a grid, eating food to grow longer while avoiding collisions with the walls and its own tail. The objective of the game is to score as many points as possible by eating the food, which spawns randomly on the grid. The game ends if the snake collides with the walls or its own tail.

Features
- Scoring: The player earns 10 points each time the snake eats a piece of food. The snake grows longer as it eats more food.
- Difficulty Levels: The player can choose from three difficulty levels: Easy, Medium, and Hard. The difficulty controls the speed at which the snake moves.

Game Controls
- Movement:
  - `W`: Move up
  - `A`: Move left
  - `S`: Move down
  - `D`: Move right
- Exit Game Press `X` to immediately quit the game.

 Game Flow
1. Start Screen: The player is prompted to enter their name at the beginning.
2. Game Initialization: Upon starting the game, the snake is placed in the center of the grid, and the first piece of food appears at a random location.
3. Gameplay:
   - The snake moves based on user input and grows longer as it eats food.
   - The snake’s movement is updated in real-time, and the game board is rendered after every update.
   - The snake's tail follows its head, and if the tail collides with the head, the game ends.
4. Game Over: The game ends when the snake collides with the boundary or its own body. The final score is displayed, and the game prompts the user to restart or exit.

Game Rendering
- The game board is drawn using text characters:
  - `O` represents the snake's head.
  - `o` represents the snake's body (tail).
  - `#` represents the food.
  - `|` and `-` form the walls of the game area.
- The game area is rendered after each move, updating the snake’s position and the food’s position.

Difficulty Levels
- Easy: Slow speed, allowing for easier navigation.
- Medium: Default speed, balanced difficulty.
- Hard: Fast speed, increasing the challenge.

Game Over Conditions
- The game ends when:
  - The snake hits a wall (`|` or `-` boundary).
  - The snake collides with its own tail (`o`).
  - The player presses `X` to quit.

Additional Information
- Snake Length: The snake’s tail grows each time it eats food. The snake can grow to a maximum length, determined by the number of food pieces consumed.
- Food Spawning: Food appears randomly on the grid after being consumed by the snake. It is represented by the `#` symbol.
- Score Tracking: The score is displayed in real-time and increases by 10 points each time the snake eats food.

*How to Run
1. Compile the Code: Ensure that you have a C++ compiler like GCC or MSVC installed.
   - To compile the program, use the following command:
     ```bash
     g++ -o snake_game snake_game.cpp
     ```
2.Run the Game:
   - After compiling, run the executable:
     ```bash
     ./snake_game
     ```

Requirements
- C++ Compiler (GCC, MSVC, or any modern C++ compiler).
- Windows operating system (because the code uses `windows.h` for `Sleep`).
- The program uses the `conio.h` library, which is available in many C++ compilers for DOS/Windows environments.

Limitations
- The game is text-based and runs in the console window, meaning it does not feature any graphical rendering.
- The `conio.h` library is not available in all compilers and may need to be replaced with another input-handling method for non-Windows platforms.

Conclusion
This simple Snake game provides a fun, interactive experience, utilizing basic concepts of C++ programming such as loops, conditionals, arrays, and user input. It also demonstrates how to create a basic console game with real-time updates and input handling.
