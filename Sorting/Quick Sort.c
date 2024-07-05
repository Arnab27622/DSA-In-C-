#include <stdio.h>

void printArray(int arr[], int n);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);

int main()
{
    int n;
    printf("Enter Number of elements in the array: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Number of elements should be greater than 0.\n");
        return 0;
    }

    int arr[n];
    printf("Enter the Elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nThe Array before sorting:\n");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("\nThe Array after sorting:\n");
    printArray(arr, n);

    return 0;
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low]; // First element is always the pivot
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (i <= high && arr[i] <= pivot) // Corrected condition to avoid out of bounds
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i <= j);

    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int partitionIndex = partition(arr, low, high);

        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}