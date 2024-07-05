/* Implement a C function to partition a linked list around a value x,
   such that all nodes less than x come before all nodes greater than or equal to x.
*/

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

Node *Rearrange(Node *head, int data)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *LessHead = NULL;
    Node *LessTail = NULL;
    Node *GreaterHead = NULL;
    Node *GreaterTail = NULL;

    Node *current = head;

    while (current != NULL)
    {
        if (current->data < data)
        {
            if (LessHead == NULL)
            {
                LessHead = LessTail = current;
            }
            else
            {
                LessTail->next = current;
                LessTail = current;
            }
        }
        else
        {
            if (GreaterHead == NULL)
            {
                GreaterHead = GreaterTail = current;
            }
            else
            {
                GreaterTail->next = current;
                GreaterTail = current;
            }
        }
        current = current->next;
    }

    if (LessHead != NULL)
    {
        head = LessHead;
        LessTail->next = GreaterHead;
    }
    else
    {
        head = GreaterHead;
    }

    if (GreaterTail != NULL)
    {
        GreaterTail->next = NULL;
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

    printf("The LinkedList Before Rearrange:\n");
    Display(head);

    int data;
    printf("Enter the Number the LinkedList will Partition around: ");
    scanf("%d", &data);

    head = Rearrange(head, data);

    printf("The LinkedList after Rearrange:\n");
    Display(head);

    freeList(&head);
    return 0;
}