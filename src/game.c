#include <curses.h>
#include <stdlib.h>
#include <time.h>
#include "../include/game.h"

// Initialize the game state and curses window
void initializeGame(WINDOW **win, Point snake[], int *length, int *dirX, int *dirY, int *foodX, int *foodY)
{
    *win = initscr();
    keypad(*win, true);
    nodelay(*win, true);
    curs_set(0); // Hide the cursor

    *length = 1; // Initial length of the snake
    *dirX = 1;
    *dirY = 0;

    int WIDTH, HEIGHT;
    getmaxyx(*win, HEIGHT, WIDTH);

    snake[0].x = WIDTH / 2;
    snake[0].y = HEIGHT / 2;

    srand(time(NULL));       // Seed the random number generator
    placeFood(foodX, foodY); // Note: No WIDTH and HEIGHT are needed here now
}

// Handle user input for changing the snake's direction
void handleInput(int pressed, int *dirX, int *dirY)
{
    if (pressed == KEY_LEFT && *dirX == 0)
    {
        *dirX = -1;
        *dirY = 0;
    }
    if (pressed == KEY_RIGHT && *dirX == 0)
    {
        *dirX = 1;
        *dirY = 0;
    }
    if (pressed == KEY_UP && *dirY == 0)
    {
        *dirX = 0;
        *dirY = -1;
    }
    if (pressed == KEY_DOWN && *dirY == 0)
    {
        *dirX = 0;
        *dirY = 1;
    }
}

// Update the snake's position based on the current direction
void updateSnake(Point snake[], int *length, int dirX, int dirY)
{
    for (int i = *length - 1; i > 0; i--)
    {
        snake[i] = snake[i - 1];
    }
    snake[0].x += dirX;
    snake[0].y += dirY;
}

// Check for collisions with the border or itself
int checkCollision(Point snake[], int length)
{
    int WIDTH, HEIGHT;
    getmaxyx(stdscr, HEIGHT, WIDTH);

    // Check for collisions with the border
    if (snake[0].x <= 0 || snake[0].x >= WIDTH - 1 || snake[0].y <= 0 || snake[0].y >= HEIGHT - 1)
    {
        return 1;
    }

    for (int i = 1; i < length; i++)
    {
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y)
        {
            return 1;
        }
    }

    return 0;
}

int checkFoodCollision(Point *snakeHead, int foodX, int foodY)
{
    return (snakeHead->x == foodX && snakeHead->y == foodY);
}

// Place food at a new random position
void placeFood(int *foodX, int *foodY)
{
    int WIDTH, HEIGHT;
    getmaxyx(stdscr, HEIGHT, WIDTH);

    *foodX = rand() % (WIDTH - 2) + 1;
    *foodY = rand() % (HEIGHT - 2) + 1;
}

// Display the main menu
void displayMainMenu(WINDOW *win)
{
    // Get terminal size dynamically
    int WIDTH, HEIGHT;
    getmaxyx(win, HEIGHT, WIDTH); // Get terminal dimensions

    clear();
    mvprintw(HEIGHT / 3, WIDTH / 3, "Welcome to Snake Game!");
    mvprintw(HEIGHT / 2, WIDTH / 3, "Press 's' to Start or 'q' to Quit.");
    refresh();
}

void displayScore(WINDOW *win, int score)
{
    int WIDTH, HEIGHT;
    getmaxyx(win, HEIGHT, WIDTH); // Get terminal dimensions

    mvprintw(1, WIDTH + 2, "Score: %d", score);
    refresh();
}
