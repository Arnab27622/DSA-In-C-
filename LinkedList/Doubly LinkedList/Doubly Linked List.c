#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *previous;
    struct Node *next;
};

void DoublylinkedListTraversal(struct Node *head)
{
    struct Node *ptr = head;
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
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 5;
    head->previous = NULL;
    head->next = second;

    second->data = 9;
    second->previous = head;
    second->next = third;

    third->data = 98;
    third->previous = second;
    third->next = fourth;

    fourth->data = 59;
    fourth->previous = third;
    fourth->next = NULL;

    DoublylinkedListTraversal(head);
    return 0;
}