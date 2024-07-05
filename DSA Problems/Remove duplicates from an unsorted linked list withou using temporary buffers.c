// Write a C program to remove duplicates from an unsorted linked list. How would you solve this problem if temporary buffers are not allowed?

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

Node *RemoveDuplicates(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *ptr = head;
    Node *current;

    while (ptr != NULL)
    {
        current = ptr;
        while (current->next != NULL)
        {
            if (current->next->data == ptr->data)
            {
                current->next = current->next->next;
            }
            else
            {
                current = current->next;
            }
        }
        ptr = ptr->next;
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
    Node *head = NULL;

    int n;
    printf("Enter Number of Nodes: ");
    scanf("%d", &n);

    head = Create(head, n);

    printf("The LinkedList Before Deleting Duplicates:\n");
    Display(head);

    head = RemoveDuplicates(head);

    printf("The LinkedList after Deleting Duplicates:\n");
    Display(head);

    freeList(&head);
    return 0;
}