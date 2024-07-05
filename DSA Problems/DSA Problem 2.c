// Given an array of positive integers arr, return the sum of all possible odd-length subarrays of arr.

#include <stdio.h>
#include <string.h>

int sumOddLengthSubArrays(int arr[], int size);

int main()
{
    int size;
    printf("Enter Number of elements of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("\nEnter Elements of the Array:\size");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    int sum = sumOddLengthSubArrays(arr, size);
    printf("The sum of all possible odd-length subarrays of arr is = %d\size", sum);

    return 0;
}

int sumOddLengthSubArrays(int arr[], int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j += 2)
        {
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }
        }
    }

    return sum;

    return sum;
}