#include <stdio.h>

void printArray(int arr[], int n);
void merge(int arr[], int low, int mid, int high);
void mergeSort(int arr[], int low, int high);

int main()
{
    int n;
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Array before sorting:\n");
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    printf("Array after sorting:\n");
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

void merge(int arr[], int low, int mid, int high)
{
    int brr[high - low + 1];         // Create an auxiliary array to hold merged elements
    int i = low, j = mid + 1, k = 0;

    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            brr[k++] = arr[i++];
        }
        else
        {
            brr[k++] = arr[j++];
        }
    }

    while (i <= mid)
    {
        brr[k++] = arr[i++];
    }
    while (j <= high)
    {
        brr[k++] = arr[j++];
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = brr[i - low];
    }
}

void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2; // Calculate mid-point to avoid overflow
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}
