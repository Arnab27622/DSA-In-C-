// Given the head of a linked list, remove the nth node from the end of the list and return its head.

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

Node *DeleteAtFirst(Node *head)
{
    Node *ptr = head;

    head = head->next;
    ;
    free(ptr);

    return head;
}

Node *Delete(Node *head, int index)
{
    Node *ptr = head;
    Node *p = head->next;
    int i = 0;

    int count = 0;

    // Count the number of nodes in the list
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }

    if (index == count)
    {
        head = DeleteAtFirst(head);
        return head;
    }

    // Reset ptr to head and p to head->next
    ptr = head;
    p = head->next;

    // Move ptr to the node before the one to be deleted
    for (i = 0; i < (count - index - 1); i++)
    {
        ptr = ptr->next;
        p = p->next;
    }

    ptr->next = p->next;
    free(p);

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
    Node *ptr = *head;
    Node *previous;

    while (ptr->next != NULL)
    {
        previous = ptr;
        ptr = ptr->next;
        free(previous);
    }
    free(ptr);

    *head = NULL;
}

int main()
{
    Node *head = NULL;

    int n;
    printf("Enter Number of Nodes: ");
    scanf("%d", &n);

    head = Create(head, n);

    printf("The LinkedList Before Deletion:\n");
    Display(head);

    int index;
    printf("Enter the index of the node: ");
    scanf("%d", &index);

    if (index > n || index <= 0)
    {
        printf("Enter a valid index.");
        exit(1);
    }

    head = Delete(head, index);

    printf("The LinkedList after Deletion:\n");
    Display(head);

    freeList(&head);
    return 0;
}