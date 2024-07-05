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

Node *Delete(Node *tail)
{
    if (tail == NULL)
    {
        return tail;
    }
    else if (tail->next == tail)
    {
        free(tail);
        tail = NULL;
        return tail;
    }
    Node *ptr = tail->next;
    while (ptr->next != tail)
    {
        ptr = ptr->next;
    }
    ptr->next = tail->next;
    free(tail);
    tail = ptr;

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

    if (current != *tail)
    {
        previous = current;
        current = current->next;
        free(previous);
    }
    free(current);

    (*tail) = NULL;
}

int main()
{
    Node *tail = NULL;

    int n;
    printf("Enter Number of Nodes: ");
    scanf("%d", &n);

    tail = Create(tail, n);

    printf("The Circular LinkedList before Deletion:\n");
    Display(tail);

    tail = Delete(tail);

    printf("The Circular LinkedList after Deletion:\n");
    Display(tail);

    freeList(&tail);

    return 0;
}