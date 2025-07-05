#include <curses.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "../include/game.h"

int main()
{
    WINDOW *win;
    Point snake[SNAKE_MAX_LENGTH];
    int length, dirX, dirY, foodX, foodY, score = 0;

    win = initscr();
    keypad(win, true);
    nodelay(win, true);
    curs_set(0); // Hide the cursor

    int WIDTH, HEIGHT;
    getmaxyx(win, HEIGHT, WIDTH);

    displayMainMenu(win);
    int pressed;
    while ((pressed = wgetch(win)) != 's' && pressed != 'q' && pressed != 27)
    {
        if (pressed == 'q' || pressed == 27) // 'q' key or ESC key
        {
            endwin();
            printf("Exiting the game.\n");
            return 0;
        }
    }

    // Initialize the game state
    initializeGame(&win, snake, &length, &dirX, &dirY, &foodX, &foodY);

    // Game loop with no time limit
    while (true)
    {
        pressed = wgetch(win);

        if (pressed == 'q' || pressed == 27) // 'q' key or ESC key
        {
            break;
        }

        handleInput(pressed, &dirX, &dirY);

        updateSnake(snake, &length, dirX, dirY);

        if (checkCollision(snake, length))
        {
            break; // End the game if a collision occurs
        }

        // Check if the snake has eaten the food
        if (checkFoodCollision(&snake[0], foodX, foodY))
        {
            if (length < SNAKE_MAX_LENGTH)
            {
                length++; // Increase the snake's length
            }
            else
            {
                printf("Snake reached max length!\n");
            }
            score++;
            placeFood(&foodX, &foodY);
        }

        erase();
        box(win, 0, 0);

        for (int i = 0; i < length; i++)
        {
            mvaddch(snake[i].y, snake[i].x, '*');
        }

        mvaddch(foodY, foodX, '&');

        displayScore(win, score);

        // printf("Snake Length: %d, Head Position: (%d, %d)\n", length, snake[0].x, snake[0].y);

        refresh();
        usleep(100000);
    }

    endwin();
    printf("Game Over! Your score: %d\n", score);
    return 0;
}
