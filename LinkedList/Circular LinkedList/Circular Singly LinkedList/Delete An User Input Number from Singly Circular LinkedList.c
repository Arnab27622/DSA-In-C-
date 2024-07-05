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

Node *Delete(Node *tail, int data)
{
    if (tail == NULL)
    {
        return tail;
    }

    Node *ptr = tail->next;
    Node *p = ptr->next;

    if (ptr->data == data)
    {
        if (ptr == tail)
        {
            // The list has only one node, so we need to set tail to NULL
            tail = NULL;
        }
        else
        {
            // There are at least two nodes in the list, so we can update tail
            tail->next = ptr->next;
        }

        free(ptr);
        ptr = NULL;

        return tail;
    }

    while (ptr != tail && p->data != data)
    {
        ptr = ptr->next;
        p = p->next;
    }

    if (ptr == tail)
    {
        printf("Data not found in the list.\n");
        return tail;
    }

    ptr->next = p->next;
    if (p == tail)
    {
        tail = ptr;
    }

    free(p);
    p = NULL;

    return tail;
}

void Display(Node *tail)
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

    printf("The Circular LinkedList before Deletion:\n");
    Display(tail);

    int data;
    printf("Enter the data You Wanna Delete: ");
    scanf("%d", &data);

    tail = Delete(tail, data);

    printf("The Circular LinkedList after Deletion:\n");
    Display(tail);

    freeList(&tail);

    return 0;
}