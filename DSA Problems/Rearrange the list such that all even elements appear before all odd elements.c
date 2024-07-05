/* Given a linked list, write a C function to rearrange the list such that all even elements appear before all odd elements,
   preserving the relative order of even and odd numbers.*/

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

Node *Rearrange(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *EvenHead = NULL;
    Node *EvenTail = NULL;
    Node *OddHead = NULL;
    Node *OddTail = NULL;

    Node *current = head;

    while (current != NULL)
    {
        if (current->data % 2 == 0)
        {
            if (EvenHead == NULL)
            {
                EvenHead = EvenTail = current;
            }
            else
            {
                EvenTail->next = current;
                EvenTail = current;
            }
        }
        else
        {
            if (OddHead == NULL)
            {
                OddHead = OddTail = current;
            }
            else
            {
                OddTail->next = current;
                OddTail = current;
            }
        }
        current = current->next;
    }

    if (EvenHead != NULL)
    {
        head = EvenHead;
        EvenTail->next = OddHead;
    }
    else
    {
        head = OddHead;
    }

    if (OddTail != NULL)
    {
        OddTail->next = NULL;
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

    printf("The Linked List Before Rearrange:\n");
    Display(head);

    head = Rearrange(head);

    printf("The Linked List After Rearrange:\n");
    Display(head);

    freeList(&head);

    return 0;
}