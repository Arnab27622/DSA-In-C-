// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's

#include <stdio.h>

int main()
{
    int m, n;
    printf("Enter number of rows of the matrix: ");
    scanf("%d", &n);
    printf("Enter number of columns of the matrix: ");
    scanf("%d", &m);

    int matrix[n][m];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    int rowsToZero[n];
    int colsToZero[m];

    // Initialize arrays
    for (int i = 0; i < n; i++)
    {
        rowsToZero[i] = 0;
    }
    for (int j = 0; j < m; j++)
    {
        colsToZero[j] = 0;
    }

    // Mark rows and columns to be zeroed
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                rowsToZero[i] = 1;
                colsToZero[j] = 1;
            }
        }
    }

    // Set rows to zero
    for (int i = 0; i < n; i++)
    {
        if (rowsToZero[i] == 1)
        {
            for (int j = 0; j < m; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }

    // Set columns to zero
    for (int j = 0; j < m; j++)
    {
        if (colsToZero[j] == 1)
        {
            for (int i = 0; i < n; i++)
            {
                matrix[i][j] = 0;
            }
        }
    }
    printf("The resultant matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}