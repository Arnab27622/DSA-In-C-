// Given an integer array and an integer k where k <= size of array, We need to return the kth smallest element of the array.
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int main()
{
    int n;
    printf("Enter size of the array : ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array :\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int k;
    printf("Enter the value of 'k': ");
    scanf("%d", &k);

    if (k > n)
    {
        printf("'k' must be <= array size");
        exit(0);
    }
    else
    {
        for (int i = 0; i < k - 1; i++)
        {
            int min = INT_MAX;
            int minIndex = -1;
            for (int j = i; j <= k - 1; j++)
            {
                if (min > arr[j])
                {
                    min = arr[j];
                    minIndex = j;
                }
            }

            int temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
        }
    }

    printf("The kth smallest element is %d", arr[k - 1]);
    return 0;
}