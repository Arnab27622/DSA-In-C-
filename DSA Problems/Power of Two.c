#include <stdio.h>
#include <stdbool.h>

bool IsPower(int n)
{
    int check = 1;
    while (check <= n)
    {

        if (check == n)
        {
            return true;
        }
        else
        {
            check *= 2;
        }
    }
    return false;
}

int main()
{
    int n;
    printf("Enter a number to check: ");
    scanf("%d", &n);

    if (IsPower(n))
    {
        printf("%d is a power of 2\n", n);
    }
    else
    {
        printf("%d is not a power of 2\n", n);
    }

    return 0;
}