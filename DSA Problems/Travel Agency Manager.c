#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Details
{
    char Name[MAX_SIZE];
    char license_No[MAX_SIZE];
    char Route[MAX_SIZE];
    int Distance;
} Details;

int main()
{
    int n;
    printf("Enter the number of Employees: ");
    scanf("%d", &n);

    // Consume the newline character left in the input buffer
    getchar();

    Details arr[n];
    printf("Enter The Details of the Employees:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter the Name of the Employee: ");
        fgets(arr[i].Name, MAX_SIZE, stdin);

        arr[i].Name[(strlen(arr[i].Name) - 1)] == '\0';

        printf("Enter the License Number of the Employee: ");
        fgets(arr[i].license_No, MAX_SIZE, stdin);

        arr[i].license_No[(strlen(arr[i].license_No) - 1)] == '\0';

        printf("Enter the Route and Distance covered by the Employee:\n");
        printf("Route: ");
        fgets(arr[i].Route, MAX_SIZE, stdin);

        arr[i].Route[(strlen(arr[i].Route) - 1)] == '\0';

        printf("Distance Traveled: ");
        scanf("%d", &arr[i].Distance);

        // Consume the newline character left in the input buffer
        getchar();
    }

    printf("\nDetails of the Employees:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Employee %d:", i + 1);
        printf("\n\tName: %s\tLicense No.: %s\tRoute: %s\tDistance Covered: %dkm\n", arr[i].Name, arr[i].license_No, arr[i].Route, arr[i].Distance);
    }

    return 0;
}