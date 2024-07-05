#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *addToEmpty(Node *tail, int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = data;
    ptr->next = NULL;
    ptr->prev = NULL;

    ptr->next = ptr;
    ptr->prev = ptr;
    return ptr;
}

Node *addToEnd(Node *tail, int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = data;
    ptr->next = NULL;
    ptr->prev = NULL;

    ptr->next = tail->next;
    tail->next = ptr;
    ptr->prev = tail;
    tail=ptr;

    return tail;
}
Node *Create(Node *tail, int size)
{
    int data;
    printf("Enter the data of Node 1: ");
    scanf("%d", &data);
    tail = addToEmpty(tail, data);

    for (int i = 1; i < size; i++)
    {
        printf("Enter the data of Node %d: ", i + 1);
        scanf("%d", &data);
        tail = addToEnd(tail, data);
    }
    return tail;
}

void Display(Node *tail)
{
    Node *ptr = tail->next;
    if (tail == NULL)
    {
        printf("Empty Node.");
        exit(1);
    }
    else
    {
        int i = 0;
        do
        {
            printf("Element %d: %d\n", i + 1, ptr->data);
            ptr = ptr->next;
            i++;
        } while (ptr != tail->next);
    }
}

int main()
{
    Node *tail = NULL;

    int n;
    printf("Enter Number of Nodes: ");
    scanf("%d", &n);

    tail = Create(tail, n);

    printf("The Circular Doubly LinkedList:\n");
    Display(tail);

    return 0;
}
