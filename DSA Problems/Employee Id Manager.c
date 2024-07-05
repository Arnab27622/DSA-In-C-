#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int num;
    printf("Enter number of employees: ");
    scanf("%d", &num);

    char **id = (char **)malloc(num * sizeof(char *));

    for (int i = 0; i < num; i++)
    {
        int id_Length;
        printf("Enter the length of Your Id: ");
        scanf("%d", &id_Length);

        id[i] = (char *)malloc((id_Length + 1) * sizeof(char)); // +1 for null terminator
        printf("Enter your id: ");
        scanf("%s", id[i]);
    }

    printf("Id of the employees:\n");
    for (int i = 0; i < num; i++)
    {
        printf("Employee %d Id: %s\n", i + 1, id[i]);
        free(id[i]); // free the allocated memory for each id
    }

    free(id); // free the array of pointers

    return 0;
}
