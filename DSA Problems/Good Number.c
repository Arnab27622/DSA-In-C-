#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 100
#define MOD 1000000007

int isEven(char ch)
{
    int digit = (int)ch - '0'; // Convert character to integer
    if (digit % 2 == 0)
        return 1;
    return 0;
}

int isPrime(char ch)
{
    int digit = (int)ch - '0'; // Convert character to integer

    if (digit == 2 || digit == 3 || digit == 5 || digit == 7)
        return 1;
    return 0;
}

int isGoodNum(char num[])
{
    int i = 0;
    while (num[i] != '\0')
    {
        if (i % 2 == 0 && !isEven(num[i]))
            return 0;
        else if (!isPrime(num[i]))
            return 0;
        i++;
    }
    return 1;
}

int Check(int n)
{
    int maxNum = pow(10, n) - 1;
    int i = 1;
    int count = 0;

    while (i <= maxNum)
    {
        int len = i;
        char num[n + 1];

        snprintf(num, sizeof(num), "%d", len);

        if (isGoodNum(num))
            count++;

        i++;
    }

    return count % MOD;
}

int main()
{
    int n;
    printf("Enter the length of the digit string:\n");
    scanf("%d", &n);

    int count = Check(n);
    printf("The total number of good digit strings of length %d is %d\n", n, count);

    return 0;
}