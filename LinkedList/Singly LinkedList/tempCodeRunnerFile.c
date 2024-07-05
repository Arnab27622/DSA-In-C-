#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *Insert(Node *head, int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;

    if (head == NULL)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        Node *temp1 = head;
        while (temp1->next != NULL)
        {
            temp1 = temp1->next;
        }
        temp1->next = temp;
    }

    return head;
}

Node *Create(Node *head, int size)
{
    int data;
    for (int i = 0; i < size; i++)
    {
        printf("Enter the data of Node %d: ", i + 1);
        scanf("%d", &data);
        head = Insert(head, data);
    }
    return head;
}

Node *Delete(Node *head)
{
    if (head == NULL)
    {
        printf("Empty List. Cannot delete.");
        return NULL;
    }

    if (head->next == NULL) // If there's only one node in the list
    {
        free(head);
        return NULL;
    }

    Node *ptr = head;
    Node *prev = NULL;

    while (ptr->next != NULL)
    {
        prev = ptr;
        ptr = ptr->next;
    }

    prev->next = NULL;
    free(ptr);

    return head;
}

void Display(Node *head)
{
    if (head == NULL)
    {
        printf("Empty List.");
        return;
    }

    Node *temp = head;
    int i = 0;

    while (temp != NULL)
    {
        printf("Node-Element %d: %d\n", i + 1, temp->data);
        temp = temp->next;
        i++;
    }
}

void freeList(Node **head)
{
    Node *current = *head;
    Node *prev;

    while (current != NULL)
    {
        prev = current;
        current = current->next;
        free(prev);
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

    if (n < 0)
    {
        printf("Enter A Valid size.");
        exit(0);
    }

    head = Create(head, n);

    int data, index;
    printf("Enter the data you want to Insert: ");
    scanf("%d", &data);

    head = Insert(head, data);

    printf("The Singly Linked List after Insertion:\n");
    Display(head);

    head = Delete(head);

    printf("The Singly Linked List after Deletion:\n");
    Display(head);

    freeList(&head);
    return 0;
}