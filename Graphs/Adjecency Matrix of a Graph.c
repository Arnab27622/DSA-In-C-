#include <stdio.h>
#include <stdlib.h>

// Function to create Adjacency Matrix
void createAdjMatrix(int N, int M, int Adj[][N], int arr[][2])
{
    // Initialise all values in the adjacency matrix to zero
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            Adj[i][j] = 0;
        }
    }

    // Traverse the array of edges
    for (int i = 0; i < M; i++)
    {
        // Find vertices of the edge
        int x = arr[i][0];
        int y = arr[i][1];

        // Update adjacency matrix to indicate edge existence
        Adj[x - 1][y - 1] = 1;
        Adj[y - 1][x - 1] = 1;
    }
}

// Function to print the created Adjacency Matrix
void printAdjMatrix(int N, int Adj[][N])
{
    // Traverse the adjacency matrix
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // Print the value at Adj[i][j]
            printf("%d ", Adj[i][j]);
        }
        printf("\n");
    }
}

// Driver Code
int main()
{
    int N, M;

    // Number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &N);

    // Given edges
    printf("Enter the number of edges: ");
    scanf("%d", &M);

    int arr[M][2];
    printf("Enter the edge connections:\n");
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }

    // Dynamically allocate memory for adjacency matrix
    int(*Adj)[N] = malloc(N * sizeof(*Adj));

    // Check if memory allocation is successful
    if (Adj == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Function call to create adjacency matrix
    createAdjMatrix(N, M, Adj, arr);

    // Print adjacency matrix
    printf("The adjacency matrix is:\n");
    printAdjMatrix(N, Adj);

    // Free dynamically allocated memory
    free(Adj);

    return 0;
}