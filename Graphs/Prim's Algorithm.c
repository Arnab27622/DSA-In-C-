#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define size 100

int minKey(int key[], int mstSet[], int n)
{
    int min = INT_MAX, minIndex;

    for (int v = 0; v < n; v++)
    {
        if (mstSet[v] == 0 && key[v] < min)
        {
            min = key[v];
            minIndex = v;
        }
    }

    return minIndex;
}

void printMST(int parent[], int graph[size][size], int n)
{
    printf("Edge   Weight\n");
    for (int i = 1; i < n; i++)
        printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int graph[size][size], int n)
{
    int parent[size];
    int key[size];
    int mstSet[size];

    for (int i = 0; i < n; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++)
    {
        int u = minKey(key, mstSet, n);
        mstSet[u] = 1;

        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph, n);
}

int main()
{
    int n;
    printf("Enter the number of vertices (maximum 100): ");
    scanf("%d", &n);

    if (n <= 0 || n > size)
    {
        printf("Invalid number of vertices.\n");
        return 1;
    }

    int graph[size][size];
    printf("Enter the adjacency matrix (0 for no edge, weight otherwise):\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    primMST(graph, n);

    return 0;
}