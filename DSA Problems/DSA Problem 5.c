/* Given an array of integers nums, sort the array in increasing order.
   If multiple values have the same frequency, sort them in decreasing order.
*/

#include <stdio.h>
#include <stdbool.h>

void reverseSort(int arr[], int size)
{
   for (int i = 0; i < size - 1; i++)
   {
      bool flag = true;
      for (int j = 0; j < size - i - 1; j++)
      {
         if (arr[j] < arr[j + 1])
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
}

void forwardSort(int arr[], int size)
{
   for (int i = 0; i < size - 1; i++)
   {
      bool flag = true;
      for (int j = 0; j < size - i - 1; j++)
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
}

void rearrange(int arr[], int size)
{
   int i = 0, j = i + 1;
   bool flag = true;
   while (i < size)
   {
      while (j < size)
      {
         if (arr[i] == arr[j])
         {
            flag = false;
         }
         j++;
      }
      i++;
   }

   if (flag == true)
   {
      forwardSort(arr, size);
   }
   else
   {
      reverseSort(arr, size);
   }

   printf("The array after rearrange:\n");
   for (int i = 0; i < size; i++)
   {
      printf("%d ", arr[i]);
   }
}

int main()
{
   int n;
   printf("Enter the number of  array elements: ");
   scanf("%d", &n);

   int arr[n];
   printf("Enter the elements of the array:\n");
   for (int i = 0; i < n; i++)
   {
      scanf("%d", &arr[i]);
   }

   printf("The array before rearrange:\n");
   for (int i = 0; i < n; i++)
   {
      printf("%d ", arr[i]);
   }
   printf("\n");

   rearrange(arr, n);

   return 0;
}