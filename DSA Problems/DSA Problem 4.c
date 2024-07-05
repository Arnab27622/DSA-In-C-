/*
    Insert an element in an array. Then delete the element from that array.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void printArray(int arr[], int size);
void insert(int arr[], int size, int pos, int data);
void delete(int arr[], int size, int pos, int data);

int main()
{
    int n;
    printf("Enter Number of Elements of the Array: ");
    scanf("%d", &n);

    int arr[MAX_SIZE];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("The array before Insertion:\n");
    printArray(arr, n);

    int pos, data;
    printf("\nEnter the position where you want to insert Element: ");
    scanf("%d", &pos);
    printf("Enter the Element: ");
    scanf("%d", &data);

    if (pos < 0 || pos >= n)
    {
        printf("Enter a valid Position.");
        exit(1);
    }

    insert(arr, n, pos, data);
    n++;

    printf("The array after Insertion:\n");
    printArray(arr, n);

    delete (arr, n, pos, data);
    n--;

    printf("\nThe array after Deletion:\n");
    printArray(arr, n);

    return 0;
}
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

void insert(int arr[], int size, int pos, int data)
{
    for (int i = size - 1; i >= pos; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[pos] = data;
}

void delete(int arr[], int size, int pos, int data)
{
    for (int i = pos; i <= size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
}