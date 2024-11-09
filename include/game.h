#ifndef GAME_H
#define GAME_H

#include <curses.h>
#include <stdbool.h>

#define SNAKE_MAX_LENGTH 100
#define TIME_LIMIT 0 // Infinite

typedef struct
{
    int x;
    int y;
} Point;

// Function prototypes
void initializeGame(WINDOW **win, Point snake[], int *length, int *dirX, int *dirY, int *foodX, int *foodY);
void handleInput(int pressed, int *dirX, int *dirY);
void updateSnake(Point snake[], int *length, int dirX, int dirY);
int checkCollision(Point snake[], int length);
int checkFoodCollision(Point *snakeHead, int foodX, int foodY);
void placeFood(int *foodX, int *foodY);
void displayMainMenu(WINDOW *win);
void displayScore(WINDOW *win, int score);

#endif // GAME_H
