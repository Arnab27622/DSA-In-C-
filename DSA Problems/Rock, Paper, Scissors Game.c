#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int generateRandomNumber(int n)
{
    srand(time(NULL));
    return rand() % n;
}

int Match(char player, char cpu)
{
    if (player == cpu)
    {
        return -1;
    }
    else if (player == 'R' && cpu == 'P')
    {
        return 0;
    }
    else if (player == 'R' && cpu == 'S')
    {
        return 1;
    }
    else if (player == 'P' && cpu == 'S')
    {
        return 0;
    }
    else if (player == 'P' && cpu == 'R')
    {
        return 1;
    }
    else if (player == 'S' && cpu == 'R')
    {
        return 0;
    }
    else if (player == 'S' && cpu == 'P')
    {
        return 1;
    }
}

int main()
{
    int playerScore = 0, cpuScore = 0, temp;
    char playerName[10];
    char playerChoice, cpuChoice;
    char choice[] = {'R', 'P', 'S'};

    printf("Welcome To My Rock, Paper, Scissors Game:\n");
    printf("Enter Your Name: ");
    scanf("%s", playerName);

    printf("It will be a Best Out of 3 Game:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("Enter '1' for 'R'(Rock), '2' for 'S'(Scissors), '3' for 'P'(Paper):\n");
        printf("%s's Turn:\n", playerName);
        printf("Enter Your Choice: ");
        scanf("%d", &temp);

        getchar();
        playerChoice = choice[temp - 1];
        printf("You Chose '%c'\n", playerChoice);

        printf("\nCpu's Turn:\n");
        temp = generateRandomNumber(3) + 1;
        cpuChoice = choice[temp - 1];

        printf("Cpu Chose '%c'\n", cpuChoice);

        if (Match(playerChoice, cpuChoice) == 1)
        {
            playerScore++;
            printf("\n%s Won!\n", playerName);
        }
        else if (Match(playerChoice, cpuChoice) == 0)
        {
            cpuScore++;
            printf("\nCpu Won!\n");
        }
        else
        {
            printf("\nDraw!!\n");
            playerScore++;
            cpuScore++;
        }

        printf("Score:\n");
        printf("%s: %d\nCPU: %d\n\n", playerName, playerScore, cpuScore);
    }

    if (playerScore > cpuScore)
    {
        printf("Congratulations!\n%s Won! By %d Points\n", playerName, (playerScore - cpuScore));
    }
    else if (playerScore < cpuScore)
    {
        printf("Too Bad!\nCPU Won! By %d Points\n", (cpuScore - playerScore));
    }
    else
    {
        printf("It's a Draw!");
    }

    printf("\nThanks for Playing");

    return 0;
}