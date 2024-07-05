#include <stdio.h>
#include <stdlib.h>

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

Node *Insert(Node *head, int index, int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = data;
    ptr->next = NULL;
    Node *p = head;
    int i = 0;

    while (i != (index - 1))
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;

    return head;
}

int main()
{
    Node *head = NULL;

    int n;
    printf("Enter No. of Nodes: ");
    scanf("%d", &n);

    head = Create(head, n);

    printf("The elements of the linkedList Before Insert:\n");
    Show(head);

    int k;
    printf("Enter the index of the element you want to Insert: ");
    scanf("%d", &k);

    int value;
    printf("Enter the value of the element you want to Insert: ");
    scanf("%d", &value);

    if (k <= 0 || k > n)
    {
        printf("Enter valid index");
        exit(1);
    }
    else
    {
        head = Insert(head, (k - 1), value);
    }

    printf("\nThe elements of the linkedList After Insert:\n");
    Show(head);

    return 0;
}