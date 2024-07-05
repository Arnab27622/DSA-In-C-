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

struct Node *InsertAtBegining(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
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

    second->data = 8;
    second->next = third;

    third->data = 45;
    third->next = fourth;

    fourth->data = 34;
    fourth->next = NULL;

    printf("Linked List before insertion:\n");
    linkedListTraversal(head);

    head = InsertAtBegining(head, 76);

    printf("Linked List after insertion:\n");
    linkedListTraversal(head);
    return 0;
}
