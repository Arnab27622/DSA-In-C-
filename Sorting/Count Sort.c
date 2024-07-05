#include <stdio.h>
#include <stdlib.h>

// Function to find the minimum and maximum values in the array
void findMinMax(int arr[], int n, int *min, int *max)
{
    *min = *max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < *min)
            *min = arr[i];
        else if (arr[i] > *max)
            *max = arr[i];
    }
}

void countSort(int arr[], int n)
{
    // Find the minimum and maximum values in the array
    int min, max;
    findMinMax(arr, n, &min, &max);

    // Determine the range of values (including negative values)
    int range = max - min + 1;

    // Create a count array to store the frequency of each element
    int *count = (int *)calloc(range, sizeof(int));
    if (count == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    // Update the count array with the frequency of each element
    for (int i = 0; i < n; i++)
    {
        count[arr[i] - min]++;
    }

    // Reconstruct the array using the count array
    int j = 0;
    for (int i = 0; i < range; i++)
    {
        while (count[i] > 0)
        {
            arr[j++] = i + min;
            count[i]--;
        }
    }

    // Free dynamically allocated memory
    free(count);
}

int main()
{
    int n;
    printf("Enter size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    countSort(arr, n);

    printf("The sorted array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}