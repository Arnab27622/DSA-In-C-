#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *addToEmpty(Node *tail, int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = data;

    ptr->next = ptr;

    return ptr;
}

Node *addToTail(Node *tail, int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = data;

    ptr->next = tail->next;
    tail->next = ptr;
    tail = ptr;
    return tail;
}

Node *Create(Node *tail, int size)
{
    int data;

    printf("Enter Element of Node 1: ");
    scanf("%d", &data);
    tail = addToEmpty(tail, data);

    for (int i = 1; i < size; i++)
    {
        printf("Enter Element of Node %d: ", i + 1);
        scanf("%d", &data);
        tail = addToTail(tail, data);
    }
    return tail;
}

Node *Insert(Node *tail, int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = data;
    ptr->next = NULL;
    ptr->next = tail->next;
    tail->next = ptr;
}

void Display(Node *tail)
{
    if (tail == NULL)
    {
        printf("Empty LinkedList");
        exit(1);
    }
    else
    {
        Node *ptr = tail->next;
        int i = 0;

        do
        {
            printf("Element %d: %d\n", i + 1, ptr->data);
            ptr = ptr->next;
            i++;
        } while (ptr != tail->next);
    }
}

void freeList(Node **tail)
{
    Node *current = (*tail)->next;
    Node *previous;

    // Traverse the list and free each node
    while (current != *tail)
    {
        previous = current;
        current = current->next;
        free(previous);
    }

    // Free the tail node
    free(current);

    // Set the tail pointer to NULL
    *tail = NULL;
}

int main()
{
    Node *tail = NULL;

    int n;
    printf("Enter Number of Nodes: ");
    scanf("%d", &n);

    tail = Create(tail, n);

    printf("The circular LinkedList:\n");
    Display(tail);

    int data;
    printf("Enter number you wanna insert: ");
    scanf("%d", &data);

    tail = Insert(tail, data);

    printf("The circular LinkedList after insertion:\n");
    Display(tail);

    freeList(&tail);

    return 0;
}