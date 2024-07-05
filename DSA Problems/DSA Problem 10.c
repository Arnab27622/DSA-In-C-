/*
    Split a Circular Linked List into two equal parts. If the number of nodes in the list are odd then make first list one node extra than second list.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *addToEmpty(Node *tail, int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    tail->data = data;

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

Node *create(Node *tail, int size)
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

void display(Node *tail)
{
    if (tail == NULL)
    {
        printf("Empty List.");
        exit(1);
    }

    Node *ptr = tail->next;
    int i = 0;
    do
    {
        printf("Data %d: %d", i + 1, ptr->data);
        ptr = ptr->next;
        i++;
    } while (ptr->next != tail->next);
}

int main()
{
    Node *tail = NULL;

    int n;
    printf("Enter of Number of Nodes: ");
    scanf("%d", &n);

    tail = create(tail, n);

    printf("The circular Linked List:\n");
    display(tail);

    return 0;
}