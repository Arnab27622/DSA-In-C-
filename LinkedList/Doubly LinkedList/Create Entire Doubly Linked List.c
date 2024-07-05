#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *addToEmpty(Node *head, int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->prev = NULL;
    ptr->data = data;
    ptr->next = NULL;
    head = ptr;
    return head;
}

Node *addAtEnd(Node *head, int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    Node *p = head;
    ptr->data = data;
    ptr->prev = NULL;
    ptr->next = NULL;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->prev = p;
    return head;
}

Node *createList(Node *head)
{
    int n, data, i;
    printf("Enter the number of Nodes: ");
    scanf("%d", &n);

    if (n == 0)
    {
        return head;
    }
    printf("Enter the data of Node 1: ");
    scanf("%d", &data);
    head = addToEmpty(head, data);

    for (int i = 1; i < n; i++)
    {
        printf("Enter the data of Node %d: ", i + 1);
        scanf("%d", &data);
        head = addAtEnd(head, data);
    }
    return head;
}

void DoublylinkedListTraversal(Node *head)
{
    Node *ptr = head;
    int i = 0;
    while (ptr != NULL)
    {
        printf("Element %d: %d\n", i + 1, ptr->data);
        ptr = ptr->next;
        i++;
    }
}

int main()
{
    Node *head = NULL;

    head = createList(head);

    printf("\nThe Doubly Linked List:\n");
    DoublylinkedListTraversal(head);
    return 0;
}