#include <stdio.h>

int main()
{
    int n;
    printf("Enter size of the array: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid input for array size.\n");
        return 1;
    }

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        if (scanf("%d", &arr[i]) != 1)
        {
            printf("Invalid input for array element.\n");
            return 1;
        }
    }

    // Insertion sort
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (j >= 1 && arr[j] < arr[j - 1])
        {
            // Swap elements
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;
        }
    }

    printf("The Sorted Array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}