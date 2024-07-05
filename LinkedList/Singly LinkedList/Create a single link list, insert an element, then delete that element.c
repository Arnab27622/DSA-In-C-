#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

int size(Node *head)
{
    Node *ptr = head;
    int count = 0;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}

Node *addToEmpty(Node *head, int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL)
    {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    temp->data = data;
    temp->next = NULL;

    if (head == NULL)
    {
        return temp;
    }

    temp->next = head;
    head = temp;
    return head;
}

Node *addToEnd(Node *head, int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL)
    {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    temp->data = data;
    temp->next = NULL;

    Node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    return head;
}

Node *create(Node *head, int size)
{
    int data;
    for (int i = 0; i < size; i++)
    {
        printf("Enter the data of Node %d: ", i);
        scanf("%d", &data);
        if (i == 0)
        {
            head = addToEmpty(head, data);
        }
        else
        {
            head = addToEnd(head, data);
        }
    }
    return head;
}

Node *insert(Node *head, int data, int index)
{
    if (index < 0 || index > size(head))
    {
        printf("Enter a valid index.\n");
        return NULL;
    }

    if (head == NULL)
    {
        head = addToEmpty(head, data);
        return head;
    }

    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL)
    {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    temp->data = data;
    temp->next = NULL;

    if (index == 0)
    {
        temp->next = head;
        return temp;
    }

    int i = 0;
    Node *ptr = head;
    while (i != index - 1)
    {
        ptr = ptr->next;
        i++;
    }
    temp->next = ptr->next;
    ptr->next = temp;
    return head;
}

Node *delete(Node *head, int index)
{
    if (head == NULL)
    {
        printf("Empty List.\n");
        return NULL;
    }

    Node *ptr = head;
    Node *p = ptr->next;
    int i = 0;
    while (i != index - 1)
    {
        ptr = ptr->next;
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    free(p);
    return head;
}

void display(Node *head)
{
    if (head == NULL)
    {
        printf("Empty List.\n");
        return;
    }

    int i = 0;
    Node *ptr = head;
    while (ptr != NULL)
    {
        printf("Data %d: %d\n", i, ptr->data);
        i++;
        ptr = ptr->next;
    }
    printf("\n");
}

void freeList(Node **head)
{
    if (head == NULL)
    {
        return;
    }

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
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Enter valid number of nodes.\n");
        exit(0);
    }

    Node *head = NULL;
    head = create(head, n);

    int data, choice, index;
    while (1)
    {
        printf("Choice:\n1. Insert an element.\n2. Delete an element.\n3. Display the linked list.\n4. Exit\nEnter your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element you wanna insert: ");
            scanf("%d", &data);
            printf("Enter the index where you wanna insert %d: ", data);
            scanf("%d", &index);

            head = insert(head, data, index);
            break;
        case 2:
            head = delete (head, index);
            break;
        case 3:
            printf("The Linked List:\n");
            display(head);
            break;
        case 4:
            printf("Exiting...\n");
            freeList(&head);
            exit(0);
        default:
            printf("Enter a valid choice.\n");
            break;
        }
    }
    return 0;
}