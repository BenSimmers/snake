#ifndef GAME_H
#define GAME_H

// Header file for the snake game, defining functions and structures needed for gameplay.

#include <curses.h>
#include <stdbool.h>

// Maximum length of the snake.
#define SNAKE_MAX_LENGTH 100

// Time limit for the game (0 means infinite).
#define TIME_LIMIT 0

// Structure to represent a point in 2D space (e.g., snake's body part or food position).
typedef struct
{
    int x; // The x-coordinate.
    int y; // The y-coordinate.
} Point;

/**
 * Initializes the game with initial parameters, setting up the game window and snake properties.
 * @param win Pointer to the window object for the game.
 * @param snake Array representing the snake's body as a series of Points.
 * @param length Pointer to an integer for the length of the snake.
 * @param dirX Pointer to an integer representing the snake's x-direction movement.
 * @param dirY Pointer to an integer representing the snake's y-direction movement.
 * @param foodX Pointer to an integer for the x-coordinate of the food.
 * @param foodY Pointer to an integer for the y-coordinate of the food.
 */
void initializeGame(WINDOW **win, Point snake[], int *length, int *dirX, int *dirY, int *foodX, int *foodY);

/**
 * Handles keyboard input and updates the snake's direction accordingly.
 * @param pressed The integer representing the key that was pressed.
 * @param dirX Pointer to an integer for updating the x-direction.
 * @param dirY Pointer to an integer for updating the y-direction.
 */
void handleInput(int pressed, int *dirX, int *dirY);

/**
 * Updates the position of the snake based on the current direction.
 * @param snake Array representing the snake's body as a series of Points.
 * @param length Pointer to the current length of the snake.
 * @param dirX The x-direction movement.
 * @param dirY The y-direction movement.
 */
void updateSnake(Point snake[], int *length, int dirX, int dirY);

/**
 * Checks if the snake has collided with itself or the game boundaries.
 * @param snake Array representing the snake's body.
 * @param length The length of the snake.
 * @return 1 if a collision is detected, 0 otherwise.
 */
int checkCollision(Point snake[], int length);

/**
 * Checks if the snake's head has collided with the food.
 * @param snakeHead Pointer to the head of the snake.
 * @param foodX The x-coordinate of the food.
 * @param foodY The y-coordinate of the food.
 * @return 1 if the food is eaten, 0 otherwise.
 */
int checkFoodCollision(Point *snakeHead, int foodX, int foodY);

/**
 * Places food at a new random location.
 * @param foodX Pointer to an integer for the x-coordinate of the food.
 * @param foodY Pointer to an integer for the y-coordinate of the food.
 */
void placeFood(int *foodX, int *foodY);

/**
 * Displays the main menu in the game window.
 * @param win The window object where the main menu is displayed.
 */
void displayMainMenu(WINDOW *win);

/**
 * Displays the current score in the game window.
 * @param win The window object where the score is displayed.
 * @param score The current score to display.
 */
void displayScore(WINDOW *win, int score);

#endif // GAME_H
