#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define COLS 25
#define ROWS 25
#define FOODS 50

char board[COLS * ROWS];

int isGameOver = 0;

struct SnakePart
{
    int x, y;
};
struct Snake
{
    int length;
    struct SnakePart part[256];
};
struct Snake snake;

struct Food
{
    int x, y;
    int consumed;
};
struct Food food[FOODS];

void fill_board()
{
    int x, y;

    for (y = 0; y < ROWS; y++)
    {
        for (x = 0; x < COLS; x++)
        {
            if (x == 0 || y == 0 || x == COLS - 1 || y == ROWS - 1)
            {
                board[y * COLS + x] = '#';
            }
            else
            {
                board[y * COLS + x] = ' ';
            }
        }
    }
}

void clear_screen()
{
    system("cls");
}

void print_board()
{
    int x, y;

    for (y = 0; y < ROWS; y++)
    {
        for (x = 0; x < COLS; x++)
        {
            putchar(board[y * COLS + x]);
        }
        putchar('\n');
    }
}

void draw_snake()
{
    int i;

    for (i = snake.length - 1; i > 0; i--)
    {
        board[snake.part[i].y * COLS + snake.part[i].x] = '*';
    }
    board[snake.part[0].y * COLS + snake.part[0].x] = '@';
}

void move_snake(int deltaX, int deltaY)
{
    int i;

    for (i = snake.length - 1; i > 0; i--)
    {
        snake.part[i] = snake.part[i - 1];
    }

    snake.part[0].x += deltaX;
    snake.part[0].y += deltaY;
}

void read_keyboard()
{
    int ch = getch();

    switch (ch)
    {
    case 'w':
        move_snake(0, -1);
        break;
    case 's':
        move_snake(0, 1);
        break;
    case 'a':
        move_snake(-1, 0);
        break;
    case 'd':
        move_snake(1, 0);
        break;
    case 'q':
        isGameOver = 1;
        break;
    }
}

void draw_food()
{
    int i;

    for (i = 0; i < FOODS; i++)
    {
        if (!food[i].consumed)
        {
            board[food[i].y * COLS + food[i].x] = '+';
        }
    }
}

void setup_food()
{
    int i;

    for (i = 0; i < FOODS; i++)
    {
        food[i].x = 1 + rand() % (COLS - 2);
        food[i].y = 1 + rand() % (ROWS - 2);
        food[i].consumed = 0;
    }
}

void setup_snake()
{
    snake.length = 1;
    snake.part[0].x = 1 + rand() % (COLS - 2);
    snake.part[0].y = 1 + rand() % (ROWS - 2);
}

void game_rules()
{
    int i;

    for (i = 0; i < FOODS; i++)
    {
        if (!food[i].consumed)
        {
            if (food[i].x == snake.part[0].x && food[i].y == snake.part[0].y)
            {
                food[i].consumed = 1;
                snake.length++;
            }
        }
    }

    if (snake.part[0].x == 0 || snake.part[0].x == COLS - 1 ||
        snake.part[0].y == 0 || snake.part[0].y == ROWS - 1)
    {
        isGameOver = 1;
    }

    for (i = 1; i < snake.length; i++)
    {
        if (snake.part[0].x == snake.part[i].x && snake.part[0].y == snake.part[i].y)
        {
            isGameOver = 1;
        }
    }
}

int main(int argc, char **argv)
{
    srand(time(0));

    setup_snake();
    setup_food();

    while (!isGameOver)
    {
        fill_board();
        draw_food();
        draw_snake();
        game_rules();
        clear_screen();
        printf("Snake Game, Score: %d\n", snake.length * 100);
        print_board();
        if (!isGameOver)
            read_keyboard();
    }

    printf("Game Over, Final score: %d\n", snake.length * 100);

    return 0;
}