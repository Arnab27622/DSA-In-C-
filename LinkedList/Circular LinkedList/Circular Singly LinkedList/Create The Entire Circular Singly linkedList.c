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

Node *addAtEnd(Node *tail, int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = data;
    ptr->next = NULL;
    ptr->next = tail->next;
    tail->next = ptr;
    tail = tail->next;
    return tail;
}

Node *createList(Node *tail)
{
    int n, data, i;
    printf("Enter the number of Nodes: ");
    scanf("%d", &n);

    if (n == 0)
    {
        return tail;
    }
    printf("Enter the data of Node 1: ");
    scanf("%d", &data);
    tail = addToEmpty(tail, data);

    for (int i = 1; i < n; i++)
    {
        printf("Enter the data of Node %d: ", i + 1);
        scanf("%d", &data);
        tail = addAtEnd(tail, data);
    }
    return tail;
}

void CircularLinkedListTraversal(Node *tail)
{
    if (tail == NULL)
    {
        printf("No node in the list.");
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

int main()
{
    Node *tail = NULL;

    tail = createList(tail);

    printf("\nThe Doubly Linked List:\n");
    CircularLinkedListTraversal(tail);
    return 0;
}