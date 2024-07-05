#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int x, y, fruitX, fruitY, height = 25, width = 30, flag, gameEnd, score, piece = 0;
int tailX[100], tailY[100];

void makeLogic()
{
    int i;
    int prevX, prevY, prev2X, prev2Y;

    prevX = tailX[0];
    prevY = tailY[0];

    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1; i <= piece; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prev2Y = prev2Y;
    }

    switch (flag)
    {
    case 1:
        x--;
        break;
    case 2:
        x++;
        break;
    case 3:
        y--;
        break;
    case 4:
        y++;
        break;
    default:
        break;
    }

    if (x == 0 || x == height || y == 0 || y == width)
    {
        gameEnd = 1;
    }

    if (x == fruitX && y == fruitY)
    {
    label3:
        fruitX = rand() % 25;
        if (fruitX == 0)
        {
            goto label3;
        }
    label4:
        fruitY = rand() % 30;
        if (fruitY == 0)
        {
            goto label4;
        }
        score += 10;
        piece++;
    }
}

void input()
{
    if (kbhit())
    {
        switch (getch())
        {
        case 'w':
            flag = 1;
            break;
        case 's':
            flag = 2;
            break;
        case 'a':
            flag = 3;
            break;
        case 'd':
            flag = 4;
            break;
        default:
            break;
        }
    }
}

void setUp()
{
    x = height / 2;
    y = width / 2;

label1:
    fruitX = rand() % 25;
    if (fruitX == 0)
    {
        goto label1;
    }
label2:
    fruitY = rand() % 30;
    if (fruitY == 0)
    {
        goto label2;
    }

    gameEnd = 0;
    score = 0;
    piece++;
}

void draw()
{
    system("cls");
    int i, j, k, ch;
    for (i = 0; i <= height; i++)
    {
        for (j = 0; j <= width; j++)
        {
            if (i == 0 || i == height || j == 0 || j == width)
            {
                printf("*");
            }
            else
            {
                if (i == x && j == y)
                {
                    printf("0");
                }
                else if (i == fruitX && j == fruitY)
                {
                    printf("#");
                }
                else
                {
                    ch = 0;
                    for (k = 0; k < piece; k++)
                    {
                        if (i == tailX[k] && j == tailY[k])
                        {
                            printf("0");
                            ch = 1;
                        }
                    }

                    if (ch == 0)
                    {
                        printf(" ");
                    }
                }
            }
        }
        printf("\n");
    }

    printf("Your Score is:\t %d\n", score);
}

int main()
{
    setUp();
    while (gameEnd != 1)
    {
        input();
        draw();
        makeLogic();
    }

    return 0;
}