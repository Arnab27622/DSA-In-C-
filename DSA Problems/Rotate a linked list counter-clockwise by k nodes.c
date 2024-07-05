// Write a C function to rotate a linked list counter-clockwise by k nodes, where k is a given positive integer

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

Node *Rotate(Node *head, int turn)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    for (int i = 0; i < turn; i++)
    {
        Node *ptr = head;
        Node *p = head->next;
        while (p->next != NULL)
        {
            p = p->next;
            ptr = ptr->next;
        }
        ptr->next = p->next;
        p->next = head;
        head = p;
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

    printf("The LinkedList Before Rotation:\n");
    Display(head);

    int k;
    printf("Enter the Number by which You Want to Rotate the LinkedList: ");
    scanf("%d", &k);

    if (k > n)
    {
        k = k % n;
    }
    if (k < 0)
    {
        printf("Enter a valid Number.");
        exit(1);
    }

    head = Rotate(head, k);

    printf("The LinkedList After Rotation:\n");
    Display(head);

    freeList(&head);
    return 0;
}