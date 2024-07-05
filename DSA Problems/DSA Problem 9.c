/*
    Reverse the linked list in pairs.
    If you have a linked list that holds 1 → 2 → 3 → 4 → X,
    then after the function has been called the linked list would hold 2 → 1 → 4 → 3 → X.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *addNode(Node *head, int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = data;
    ptr->next = NULL;

    if (head == NULL)
    {
        head = ptr;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = ptr;
    }
    return head;
}

Node *create(Node *head, int size)
{
    int data;
    for (int i = 0; i < size; i++)
    {
        printf("Enter data of Node %d: ", i + 1);
        scanf("%d", &data);
        head = addNode(head, data);
    }

    return head;
}

void display(Node *head)
{
    if (head == NULL)
    {
        printf("Empty List.\n");
        return;
    }

    Node *temp = head;
    int i = 0;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        if (temp->next != NULL)
        {
            printf(" -> ");
        }

        temp = temp->next;
        i++;
    }

    printf("\n");
}

// TODO: Iterative Method

// Node *reverseInPair(Node *head)
// {
//     if (head == NULL || head->next == NULL)
//     {
//         return head;
//     }

//     Node *prev = NULL;
//     Node *current = head;
//     Node *next = NULL;

//     while (current != NULL && current->next != NULL)
//     {
//         next = current->next;
//         current->next = next->next;
//         next->next = current;

//         if (prev == NULL)
//         {
//             head = next;
//         }
//         else
//         {
//             prev->next = next;
//         }

//         prev = current;
//         current = current->next;
//     }

//     return head;
// }

// TODO: Recursive Method
Node *reverseInPair(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    else
    {
        Node *temp;

        temp = head->next;
        head->next = temp->next;
        temp->next = head;
        head = temp;

        head->next->next = reverseInPair(head->next->next);
        return head;
    }
}

void freeList(Node *head)
{
    while (head != NULL)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    Node *head = NULL;

    int n;
    printf("Enter Number of Nodes: ");
    scanf("%d", &n);

    head = create(head, n);

    printf("The Linked List before Reverse:\n");
    display(head);

    head = reverseInPair(head);

    printf("The Linked List after Reverse:\n");
    display(head);

    freeList(head);
    return 0;
}