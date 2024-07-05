#include <stdio.h>
#include <stdlib.h>

// Function to perform Depth-First Search (DFS) traversal
void DFS(int **arr, int size, int startNode, int visited[])
{
    // Print the current node
    printf("%d ", startNode);
    // Mark the current node as visited
    visited[startNode] = 1;

    // Traverse all adjacent nodes of the current node
    for (int j = 0; j < size; j++)
    {
        // If an adjacent node exists and has not been visited, recursively call DFS
        if (arr[startNode][j] == 1 && !visited[j])
        {
            DFS(arr, size, j, visited);
        }
    }
}

int main()
{
    int size;
    // Get the size of the Graph from the user
    printf("Enter the size of the Graph: ");
    scanf("%d", &size);

    // Check if the size is valid
    if (size <= 0)
    {
        printf("Invalid size. Size must be greater than 0.\n");
        return -1;
    }

    // Dynamically allocate memory for the adjacency matrix
    int **arr = (int **)malloc(size * sizeof(int *));
    if (arr == NULL)
    {
        printf("Memory Allocation Failed\n");
        return -1;
    }
    for (int i = 0; i < size; i++)
    {
        arr[i] = (int *)malloc(size * sizeof(int));
        if (arr[i] == NULL)
        {
            printf("Memory Allocation Failed\n");
            // Free the memory allocated so far
            for (int j = 0; j < i; j++)
            {
                free(arr[j]);
            }
            free(arr);
            return -1;
        }
    }

    // Get the adjacency matrix from the user
    printf("Enter the Adjacency Matrix (1 for connected, 0 for not connected):\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    // Dynamically allocate memory for the visited array
    int *visited = (int *)malloc(size * sizeof(int));
    if (visited == NULL)
    {
        printf("Memory Allocation Failed\n");
        // Free the memory allocated for the adjacency matrix
        for (int i = 0; i < size; i++)
        {
            free(arr[i]);
        }
        free(arr);
        return -1;
    }

    // Initialize the visited array
    for (int i = 0; i < size; i++)
    {
        visited[i] = 0;
    }

    int startNode;
    // Get the starting Node from the user
    printf("Enter the starting Node: ");
    scanf("%d", &startNode);

    // Check if the starting Node is valid
    if (startNode < 0 || startNode >= size)
    {
        printf("Invalid starting Node.");
        return -1;
    }

    // Perform DFS traversal from the starting Node
    DFS(arr, size, startNode, visited);

    // Free dynamically allocated memory
    free(visited);
    for (int i = 0; i < size; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}