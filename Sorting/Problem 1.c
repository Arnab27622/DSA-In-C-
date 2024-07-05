// Given an integer array arr[], move all 0's to the end of it while maintaining the relative order of the non-zero elements.
#include <stdio.h>
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

    int copy_Array[n];
    int Index = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            copy_Array[Index] = arr[i];
            Index++;
        }
    }
    while (Index < n)
    {
        copy_Array[Index] = 0;
        Index++;
    }

    printf("The Result array :\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", copy_Array[i]);
    }

    return 0;
}
