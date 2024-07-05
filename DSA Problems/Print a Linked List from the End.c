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
        ptr->next = head;
        head = ptr;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        ptr->next = temp->next;
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

void freeList(Node **head)
{
    if (*head == NULL)
    {
        return;
    }

    Node *current = *head;
    Node *prev;

    while (current->next != NULL)
    {
        prev = current;
        current = current->next;
        free(prev);
    }
    free(current);

    *head = NULL;
}

void displayFromForward(Node *head)
{
    if (head == NULL)
    {
        printf("Empty List.");
        exit(1);
    }

    Node *temp = head;
    int i = 0;
    while (temp != NULL)
    {
        printf("Data %d: %d\n", i + 1, temp->data);
        temp = temp->next;
        i++;
    }
}

void displayFromEnd(Node *head)
{
    if (head == NULL)
    {
        return;
    }

    displayFromEnd(head->next);
    printf("Data: %d\n", head->data);
}

int main()
{
    Node *head = NULL;

    int n;
    printf("Enter number of nodes of the first Linked List: ");
    scanf("%d", &n);

    head = create(head, n);

    printf("The Linked List in forward:\n");
    displayFromForward(head);

    printf("The Linked List in backward:\n");
    displayFromEnd(head);

    freeList(&head);

    return 0;
}