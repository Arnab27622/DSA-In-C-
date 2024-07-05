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

struct Node *DeleteGivenElement(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *q = head->next;

    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }

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

    head = DeleteGivenElement(head, 45);

    printf("Linked List after deletion:\n");
    linkedListTraversal(head);
    return 0;
}