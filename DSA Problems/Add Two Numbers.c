#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
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

Node *addTwoNumbers(Node *head1, Node *head2)
{
    Node *head = NULL;
    Node *current = NULL;
    int carry = 0;

    while (head1 || head2 || carry)
    {
        int sum = carry;

        if (head1)
        {
            sum += head1->data;
            head1 = head1->next;
        }

        if (head2)
        {
            sum += head2->data;
            head2 = head2->next;
        }

        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = sum % 10;
        newNode->next = NULL;

        if (current)
        {
            current->next = newNode;
            current = newNode;
        }
        else
        {
            head = current = newNode;
        }

        carry = sum / 10;
    }

    return head;
}

// Function to print the linked list
void printList(Node *head)
{
    while (head)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to create a new node with a given value
Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int main()
{
    Node *head1 = NULL;
    Node *head2 = NULL;

    printf("Create First Singly LinkedList:\n");
    int n;
    printf("Enter Number of Nodes of First LinkedList: ");
    scanf("%d", &n);

    head1 = Create(head1, n);

    printf("The First LinkedList:\n");
    Display(head1);

    printf("Create Second Singly LinkedList:\n");
    int m;
    printf("Enter Number of Nodes of Second LinkedList: ");
    scanf("%d", &m);

    head2 = Create(head2, m);

    printf("The Second LinkedList:\n");
    Display(head2);

    Node *head = addTwoNumbers(head1, head2);

    printf("The Resultant LinkedList:\n");
    Display(head);

    freeList(&head1);
    freeList(&head2);
    freeList(&head);

    return 0;
}