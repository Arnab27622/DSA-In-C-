// Given an array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number.
// Optimized 
#include <stdio.h>
#include <stdbool.h>
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

    int target;
    printf("Enter the target element: ");
    scanf("%d", &target);

    int i = 0;
    int j = n - 1;
    while (i < j)
    {
        if ((arr[i] + arr[j]) == target)
        {
            printf("The numbers are %d and %d", arr[i], arr[j]);
            break;
        }
        else if ((arr[i] + arr[j]) > target)
        {
            j--;
        }

        else
            i++;
    }

    return 0;
}