#include <stdio.h>
#include <stdlib.h>

// Structure to represent a queue
typedef struct Node
{
    int size;
    int frontIndex;
    int rearIndex;
    int *arr;
} Node;

// Function to check if the queue is empty
int isEmpty(Node *ptr)
{
    return ptr->frontIndex == ptr->rearIndex;
}

// Function to check if the queue is full
int isFull(Node *ptr)
{
    return ptr->frontIndex == ptr->size - 1;
}

// Function to enqueue an element into the queue
void enqueue(Node *ptr, int data)
{
    if (isFull(ptr))
    {
        printf("Queue is full.\n");
        return;
    }
    ptr->rearIndex++;
    ptr->arr[ptr->rearIndex] = data;
}

// Function to dequeue an element from the queue
int dequeue(Node *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Queue is empty.\n");
        return -1;
    }
    int data = ptr->arr[ptr->frontIndex + 1];
    ptr->frontIndex++;
    return data;
}

// Function to free the memory allocated for the queue
void freeQueue(Node **ptr)
{
    if (*ptr == NULL)
        return;
    free((*ptr)->arr);
    free(*ptr);
    *ptr = NULL;
}

int main()
{
    // Allocate memory for the queue
    Node *q = (Node *)malloc(sizeof(Node));
    if (q == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }
    q->size = 400;
    q->frontIndex = 0;
    q->rearIndex = 0;
    q->arr = (int *)malloc(q->size * sizeof(int));
    if (q->arr == NULL)
    {
        printf("Memory allocation failed.\n");
        free(q);
        return 1;
    }

    // Get the size of the graph from the user
    int size;
    printf("Enter the size of the graph: ");
    scanf("%d", &size);
    if (size <= 0)
    {
        printf("Invalid size. Size must be positive.\n");
        freeQueue(&q);
        return 1;
    }

    // Dynamically allocate memory for the adjacency matrix
    int **arr = (int **)malloc(size * sizeof(int *));
    if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
        freeQueue(&q);
        return 1;
    }
    for (int i = 0; i < size; i++)
    {
        arr[i] = (int *)malloc(size * sizeof(int));
        if (arr[i] == NULL)
        {
            printf("Memory allocation failed.\n");
            freeQueue(&q);
            for (int j = 0; j < i; j++)
                free(arr[j]);
            free(arr);
            return 1;
        }
    }

    // Get the adjacency matrix from the user
    printf("Enter the adjacency matrix (1 for connected, 0 for not connected):\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    // Get the starting node for BFS
    int startNode;
    printf("Enter the starting node for BFS: ");
    scanf("%d", &startNode);
    if (startNode < 0 || startNode >= size)
    {
        printf("Invalid starting node.\n");
        freeQueue(&q);
        for (int i = 0; i < size; i++)
            free(arr[i]);
        free(arr);
        return 1;
    }

    // Perform BFS traversal
    printf("%d ", startNode);
    int visited[size];
    for (int i = 0; i < size; i++)
    {
        visited[i] = 0;
    }
    visited[startNode] = 1;
    enqueue(q, startNode);

    while (!isEmpty(q))
    {
        int node = dequeue(q);
        for (int j = 0; j < size; j++)
        {
            if (arr[node][j] == 1 && visited[j] == 0)
            {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(q, j);
            }
        }
    }

    // Free dynamically allocated memory
    for (int i = 0; i < size; i++)
    {
        free(arr[i]);
    }
    free(arr);
    freeQueue(&q);

    return 0;
}