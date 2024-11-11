/* Snake Game using C++
   developed by AMU 2015 BATCH SOFTWARE ENGINEERING STUDENTS
   APPROVED BY:- Miss Yitayish Lema
   Updated by: [sifen], November 2024 */

// required header files
#include <conio.h>
#include <iostream>
#include <windows.h>
using namespace std;

// height and width of the boundary
const int width = 80;
const int height = 20;

// Snake head coordinates (x, y)
int x, y;
// Food coordinates
int fruitCordX, fruitCordY;
// variable to store the player's score
int playerScore;
// Array to store the coordinates of the snake's tail (x, y)
int snakeTailX[100], snakeTailY[100];
// variable to store the length of the snake's tail
int snakeTailLen;
// Direction of snake's movement (enum)
enum snakeDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
snakeDirection sDir;
// Game-over flag
bool isGameOver;

// Initialize game variables
void GameInit() {
    isGameOver = false;
    sDir = STOP;
    x = width / 2;
    y = height / 2;
    fruitCordX = rand() % width;
    fruitCordY = rand() % height;
    playerScore = 0;
}

// Render the game board
void GameRender(string playerName) {
    system("cls");  // Clear the console screen

    // Creating top wall
    for (int i = 0; i < width + 2; i++)
        cout << "-";
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j <= width; j++) {
            // Creating side walls
            if (j == 0 || j == width)
                cout << "|";
            // Creating snake's head
            if (i == y && j == x)
                cout << "O";
            // Creating snake's food
            else if (i == fruitCordY && j == fruitCordX)
                cout << "#";
            else {
                bool printTail = false;
                for (int k = 0; k < snakeTailLen; k++) {
                    if (snakeTailX[k] == j && snakeTailY[k] == i) {
                        cout << "o";
                        printTail = true;
                    }
                }
                if (!printTail)
                    cout << " ";
            }
        }
        cout << endl;
    }

    // Bottom wall
    for (int i = 0; i < width + 2; i++)
        cout << "-";
    cout << endl;

    // Display score
    cout << playerName << "'s Score: " << playerScore << endl;
}

// Update game state
void UpdateGame() {
    int prevX = snakeTailX[0], prevY = snakeTailY[0];
    int prev2X, prev2Y;
    snakeTailX[0] = x;
    snakeTailY[0] = y;

    // Move snake's body
    for (int i = 1; i < snakeTailLen; i++) {
        prev2X = snakeTailX[i];
        prev2Y = snakeTailY[i];
        snakeTailX[i] = prevX;
        snakeTailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    // Move snake's head
    switch (sDir) {
        case LEFT: x--; break;
        case RIGHT: x++; break;
        case UP: y--; break;
        case DOWN: y++; break;
    }

    // Check for collisions with walls
    if (x >= width || x < 0 || y >= height || y < 0)
        isGameOver = true;

    // Check for collisions with the tail
    for (int i = 0; i < snakeTailLen; i++) {
        if (snakeTailX[i] == x && snakeTailY[i] == y)
            isGameOver = true;
    }

    // Check for collision with food
    if (x == fruitCordX && y == fruitCordY) {
        playerScore += 10;
        fruitCordX = rand() % width;
        fruitCordY = rand() % height;
        snakeTailLen++;
    }
}

// Set difficulty
int SetDifficulty() {
    int dfc, choice;
    cout << "\nSET DIFFICULTY\n1: Easy\n2: Medium\n3: Hard\n";
    cout << "NOTE: If not chosen, difficulty will default to Medium.\n";
    cout << "Choose difficulty level: ";
    cin >> choice;

    // Difficulty levels
    switch (choice) {
        case 1: dfc = 50; break;  // Easy
        case 2: dfc = 100; break;  // Medium
        case 3: dfc = 150; break;  // Hard
        default: dfc = 100;  // Default to medium
    }
    return dfc;
}

// Handle user input
void UserInput() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'a': sDir = LEFT; break;
            case 'd': sDir = RIGHT; break;
            case 'w': sDir = UP; break;
            case 's': sDir = DOWN; break;
            case 'x': isGameOver = true; break;  // End game
        }
    }
}

// Main game loop
int main() {
    string playerName;
    cout << "Enter your name: ";
    cin >> playerName;
    int dfc = SetDifficulty();  // Get difficulty level

    GameInit();
    while (!isGameOver) {
        GameRender(playerName);  // Display game state
        UserInput();  // Get user input
        UpdateGame();  // Update game state

        // Sleep according to difficulty
        Sleep(dfc);
    }

    cout << "Game Over! Final Score: " << playerScore << endl;  // Game over message
    return 0;
}
