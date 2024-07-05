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

Node *Insert(Node *head, int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = data;
    ptr->next = NULL;

    if ((head == NULL) || (data < head->data))
    {
        ptr->next = head;
        head = ptr;
    }
    else
    {
        Node *p = head;
        while (p->next != NULL && data > p->next->data)
        {
            p = p->next;
        }
        ptr->next = p->next;
        p->next = ptr;
    }

    return head;
}

Node *Merge(Node *head, Node *head1, Node *head2)
{
    Node *temp1 = head1;
    Node *temp2 = head2;

    while (temp1 != NULL)
    {
        head = Insert(head, temp1->data);
        temp1 = temp1->next;
    }

    while (temp2 != NULL)
    {
        head = Insert(head, temp2->data);
        temp2 = temp2->next;
    }

    return head;
}

void Display(Node *head)
{
    Node *temp = head;
    int i = 0;

    while (temp != NULL)
    {
        printf("Element %d: %d\n", i + 1, temp->data);
        temp = temp->next;
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
    Node *head1 = NULL;
    Node *head2 = NULL;

    int n;
    printf("Enter Number of Nodes of First LinkedList: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Enter a Valid Number.");
        exit(1);
    }

    head1 = Create(head1, n);
    printf("The first Sorted linked list:\n");
    Display(head1);

    int m;
    printf("Enter Number of Nodes of Second LinkedList: ");
    scanf("%d", &m);

    if (m <= 0)
    {
        printf("Enter a Valid Number.");
        exit(1);
    }

    head2 = Create(head2, m);
    printf("The Second Sorted linked list:\n");
    Display(head2);

    Node *head = NULL;

    head = Merge(head, head1, head2);

    printf("The Merged Sorted LinkedList:\n");
    Display(head);

    freeList(&head1);
    freeList(&head2);
    freeList(&head);
    return 0;
}