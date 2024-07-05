#include <stdio.h>
#include <stdlib.h>

// Note: The LinkedList has to be sorted From Begining

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *addToStart(Node *head, int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = data;
    ptr->next = NULL;

    ptr->next = head;
    head = ptr;
    return head;
}

Node *addToEnd(Node *head, int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = data;
    ptr->next = NULL;
    Node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

Node *Create(Node *head, int size)
{
    int data;

    printf("Enter Element of Node 1: ");
    scanf("%d", &data);
    head = addToStart(head, data);

    for (int i = 1; i < size; i++)
    {
        printf("Enter Element of Node %d: ", i + 1);
        scanf("%d", &data);
        head = addToEnd(head, data);
    }

    return head;
}

void Show(Node *head)
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

Node *Reverse(Node *head)
{
    Node *temp1 = NULL;
    Node *temp2 = NULL;

    while (head != NULL)
    {
        temp2 = head->next;
        head->next = temp1;
        temp1 = head;
        head = temp2;
    }
    head = temp1;

    return head;
}

int main()
{
    Node *head = NULL;

    int n;
    printf("Enter No. of Nodes: ");
    scanf("%d", &n);

    head = Create(head, n);

    printf("The elements of the linkedList Before Reverse:\n");
    Show(head);

    head = Reverse(head);

    printf("\nThe elements of the linkedList After Reverse:\n");
    Show(head);

    return 0;
}