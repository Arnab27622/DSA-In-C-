// Given an integer array nums that does not contain any zeros, find the largest positive integer k such that -k also exists in the array.
#include <stdio.h>

int main()
{
    int n;
    printf("Enter number of elements array: ");
    scanf("%d", &n);

    int arr[n], k = 0;

    printf("Enter elements in array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        if (arr[i] > 0)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] == -arr[j])
                {
                    temp = arr[i];
                }
            }
        }
        if (k < temp)
        {
            k = temp;
        }
    }

    printf("The largest positive integer is %d such that -(%d) also exists in the array", k, k);

    return 0;
}