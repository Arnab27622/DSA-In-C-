#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *addToEmpty(Node *tail, int data)
{
    // Allocate memory for the new node
    Node *ptr = (Node *)malloc(sizeof(Node));
    if (ptr == NULL)
    {
        printf("Memory allocation failed.\n");
        return tail;
    }

    ptr->data = data;

    ptr->next = ptr;
    return ptr;
}

Node *addToTail(Node *tail, int data)
{
    // Allocate memory for the new node
    Node *ptr = (Node *)malloc(sizeof(Node));
    if (ptr == NULL)
    {
        printf("Memory allocation failed.\n");
        return tail;
    }

    ptr->data = data;

    ptr->next = tail->next;
    tail->next = ptr;
    tail = ptr;

    return tail;
}
Node *Create(Node *tail, int size)
{
    int data;

    printf("Enter data of Node 1: ");
    scanf("%d", &data);
    tail = addToEmpty(tail, data);

    for (int i = 1; i < size; i++)
    {
        printf("Enter data of Node %d: ", i + 1);
        scanf("%d", &data);
        tail = addToTail(tail, data);
    }

    return tail;
}

int Count(Node *tail)
{
    Node *ptr = tail->next;
    int count = 0;

    do
    {
        count++;
        ptr = ptr->next;
    } while (ptr != tail->next);

    return count;
}

void freeList(Node **tail)
{
    Node *current = (*tail)->next;
    Node *previous;

    while (current != *tail)
    {
        previous = current;
        current = current->next;
        free(previous);
    }

    free(current);
    *tail = NULL;
}

int main()
{
    Node *tail = NULL;

    int n;
    printf("Enter Number of Nodes: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid number of nodes.\n");
        return 0;
    }

    tail = Create(tail, n);

    printf("Number of Elements in The Circular LinkedList: %d", Count(tail));

    freeList(&tail);

    return 0;
}