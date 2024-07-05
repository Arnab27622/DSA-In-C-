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

Node *Insert(Node *tail, int index, int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = data;
    Node *p = tail->next;
    int i = 0;

    while (i != (index - 1))
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    if (p == tail)
    {
        tail = tail->next;
    }

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

    printf("The Circular LinkedList before Insertion:\n");
    Display(tail);

    int data;
    printf("Enter data You Want to Insert: ");
    scanf("%d", &data);

    int index;
    printf("Enter Index of the Node Where you want to Insert %d: ", data);
    scanf("%d", &index);

    tail = Insert(tail, (index - 1), data);

    printf("The Circular LinkedList after Insertion:\n");
    Display(tail);

    freeList(&tail);

    return 0;
}