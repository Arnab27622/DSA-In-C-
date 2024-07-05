// Given an array of digits (values are from 0 to 9), the task is to find the minimum possible sum of two numbers formed from digits of the array. Please note that all digits of the given array must be used to form the two numbers.
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

    /*
        Steps: 1) sort the array
    */

    for (int i = 0; i < n - 1; i++)
    {
        bool flag = true;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = false;
            }
        }
        if (flag == true)
        {
            break;
        }
    }

    int num1 = 0, num2 = 0;

    for (int i = 0; i < n; i++)
    {
        num1 *= 10;
        num1 += arr[i];
    }
    printf("%d\n", num1);

    int a = n - 1, b = n - 2;
    if (arr[a] == arr[b])
    {
        a--;
        b--;
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
    else
    {
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }

    for (int i = 0; i < n; i++)
    {
        num2 *= 10;
        num2 += arr[i];
    }
    printf("%d\n", num2);

    int sum = num1 + num2;
    printf("The result sum is %d", sum);

    return 0;
}