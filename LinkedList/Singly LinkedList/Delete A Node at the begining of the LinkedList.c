#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *DeleteAtFirst(struct Node *head)
{
    if (head == NULL)
    {
        printf("The list is empty");
    }
    else
    {
        struct Node *ptr = head;
        head = head->next;
        free(ptr);
        return head;
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
    head->next = second;

    second->data = 9;
    second->next = third;

    third->data = 98;
    third->next = fourth;

    fourth->data = 59;
    fourth->next = NULL;

    printf("Linked List before deletion:\n");
    linkedListTraversal(head);

    head = DeleteAtFirst(head);
    printf("Linked List after deletion:\n");
    linkedListTraversal(head);
    return 0;
}