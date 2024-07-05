/*  Suppose you are given two singly linked lists representing non-negative integers, where each node contains a single digit.
    How would you add these numbers together to create a new linked list representing the sum? */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *addToEmpty(Node *head, int data)
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
    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    ptr->next = temp->next;
    temp->next = ptr;
    ptr->next = NULL;

    return head;
}

Node *Create(Node *head, int size)
{
    int data;

    printf("Enter data of Node 1: ");
    scanf("%d", &data);
    head = addToEmpty(head, data);

    for (int i = 1; i < size; i++)
    {
        printf("Enter data of Node %d: ", i + 1);
        scanf("%d", &data);
        head = addToEnd(head, data);
    }

    return head;
}

Node *Insert(Node *head, int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = data;
    ptr->next = NULL;

    if (head == NULL)
    {
        ptr->next = head;
        head = ptr;
    }
    else
    {
        Node *p = head;

        while (p->next != NULL)
        {
            p = p->next;
        }
        ptr->next = p->next;
        p->next = ptr;
    }

    return head;
}

Node *Sum(Node *head, Node *head1, Node *head2)
{
    Node *ptr1 = head1;
    Node *ptr2 = head2;

    while (ptr1 != NULL && ptr2 != NULL)
    {
        head = Insert(head, (ptr1->data + ptr2->data));
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    while (ptr1 != NULL)
    {
        head = Insert(head, ptr1->data);
        ptr1 = ptr1->next;
    }

    while (ptr2 != NULL)
    {
        head = Insert(head, ptr2->data);
        ptr2 = ptr2->next;
    }

    return head;
}

void Display(Node *head)
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

void freeList(Node **head)
{
    Node *current = *head;
    Node *previous;

    while (current->next != NULL)
    {
        previous = current;
        current = current->next;
        free(previous);
    }
    free(current);

    *head = NULL;
}

int main()
{
    Node *head1 = NULL;
    Node *head2 = NULL;

    printf("Create First Singly LinkedList:\n");
    int n;
    printf("Enter Number of Nodes of First LinkedList: ");
    scanf("%d", &n);

    head1 = Create(head1, n);

    printf("The First LinkedList:\n");
    Display(head1);

    printf("Create Second Singly LinkedList:\n");
    int m;
    printf("Enter Number of Nodes of Second LinkedList: ");
    scanf("%d", &m);

    head2 = Create(head2, m);

    printf("The Second LinkedList:\n");
    Display(head2);

    Node *head = NULL;

    head = Sum(head, head1, head2);

    printf("The Resultant LinkedList:\n");
    Display(head);

    freeList(&head1);
    freeList(&head2);
    freeList(&head);
    return 0;
}