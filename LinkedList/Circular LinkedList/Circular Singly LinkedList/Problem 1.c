// Write a program to create a circular link list, insert an element, then delete that element.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *addToEmpty(int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    if (ptr == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    ptr->data = data;
    ptr->next = ptr; // Points to itself
    return ptr;
}

Node *addToTail(Node *tail, int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    if (ptr == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    ptr->data = data;
    ptr->next = tail->next; // New node points to the head of the list
    tail->next = ptr;       // Tail now points to the new node
    return ptr;
}

Node *create(int size)
{
    if (size <= 0)
        return NULL;

    Node *tail = NULL;
    int data;

    printf("Enter data of Node 1: ");
    scanf("%d", &data);
    tail = addToEmpty(data);

    for (int i = 1; i < size; i++)
    {
        printf("Enter data of Node %d: ", i + 1);
        scanf("%d", &data);
        tail = addToTail(tail, data);
    }

    return tail;
}

Node *insert(Node *tail, int data, int index)
{
    if (tail == NULL)
        return addToEmpty(data);

    Node *ptr = (Node *)malloc(sizeof(Node));
    if (ptr == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    ptr->data = data;

    if (index == 0) // Insertion at the beginning
    {
        ptr->next = tail->next;
        tail->next = ptr;
        return ptr;
    }

    Node *p = tail->next; // Points to the head of the list
    for (int i = 0; i < index - 1; i++)
    {
        if (p == tail)
        {
            printf("Index out of bounds. Cannot insert at specified index.\n");
            free(ptr);
            return tail;
        }
        p = p->next;
    }

    ptr->next = p->next;
    p->next = ptr;

    if (p == tail) // If inserted at the end, update tail
        tail = ptr;

    return tail;
}

Node *Delete(Node *tail, int data)
{
    if (tail == NULL)
        return tail;

    if (tail->next == tail && tail->data == data) // Only one node in the list
    {
        free(tail);
        return NULL;
    }

    Node *ptr = tail->next;
    Node *p = ptr->next;

    if (ptr->data == data)
    {
        if (ptr == tail)
            tail = NULL;
        else
            tail->next = ptr->next;

        free(ptr);
        return tail;
    }

    while (p != tail && p->data != data)
    {
        ptr = ptr->next;
        p = p->next;
    }

    if (p == tail)
        printf("Data not found in the list.\n");
    else
    {
        ptr->next = p->next;
        if (p == tail)
            tail = ptr;
        free(p);
    }

    return tail;
}

void Display(Node *tail)
{
    if (tail == NULL)
    {
        printf("Empty List\n\n");
        return;
    }

    Node *ptr = tail->next;
    int i = 0;

    do
    {
        printf("Data %d: %d\n", i + 1, ptr->data);
        ptr = ptr->next;
        i++;
    } while (ptr != tail->next);

    printf("\n");
}

void freeList(Node **tail)
{
    if (*tail == NULL)
        return;

    Node *current = (*tail)->next;
    Node *temp;

    while (current != (*tail))
    {
        temp = current;
        current = current->next;
        free(temp);
    }

    free(*tail);
    *tail = NULL;
}

int main()
{
    Node *tail = NULL;

    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    tail = create(n);

    int data, index;
    printf("Enter the data you want to insert: ");
    scanf("%d", &data);
    printf("Enter the index where you want to insert %d: ", data);
    scanf("%d", &index);

    tail = insert(tail, data, (index - 1));

    printf("\nThe Circular Linked List after Insertion:\n");
    Display(tail);

    tail = Delete(tail, data);

    printf("\nThe Circular Linked List after Deletion:\n");
    Display(tail);

    freeList(&tail);

    return 0;
}