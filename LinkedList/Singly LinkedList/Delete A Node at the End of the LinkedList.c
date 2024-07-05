#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    int i = 0;
    while (ptr != NULL)
    {
        printf("Element %d: %d\n", i + 1, ptr->data);
        ptr = ptr->next;
        i++;
    }
}

struct Node *DeleteAtEnd(struct Node *head)
{
    struct Node *ptr = head;
    struct Node *q = head->next;
    while (q->next != NULL)
    {
        ptr = ptr->next;
        q = q->next;
    }

    ptr->next = NULL;
    free(q);

    return head;
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

    head->data = 56;
    head->next = second;

    second->data = 72;
    second->next = third;

    third->data = 45;
    third->next = fourth;

    fourth->data = 91;
    fourth->next = NULL;

    printf("Linked List before deletion:\n");
    linkedListTraversal(head);

    head = DeleteAtEnd(head);

    printf("Linked List after deletion:\n");
    linkedListTraversal(head);
    return 0;
}