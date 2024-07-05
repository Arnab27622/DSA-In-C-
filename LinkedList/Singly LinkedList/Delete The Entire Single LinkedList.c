#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void LinkedListTraversal(Node *head)
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

Node *Delete(Node *head)
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        ptr = ptr->next;
        free(head);
        head = ptr;
    }

    return head;
}

int main()
{
    Node *head = (Node *)malloc(sizeof(Node *));
    Node *second = (Node *)malloc(sizeof(Node *));
    Node *third = (Node *)malloc(sizeof(Node *));
    Node *fourth = (Node *)malloc(sizeof(Node *));

    head->data = 16;
    head->next = second;

    second->data = 54;
    second->next = third;

    third->data = 42;
    third->next = fourth;

    fourth->data = 88;
    fourth->next = NULL;

    printf("Linked List before deletion:\n");
    LinkedListTraversal(head);

    head = Delete(head);

    if (head == NULL)
    {
        printf("The linked list has successfully Deleted.");
    }

    return 0;
}