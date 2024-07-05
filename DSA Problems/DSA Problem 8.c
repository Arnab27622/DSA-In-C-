/*
    If the head of a Linked List is pointing to kth element, then how will you get only the elements after kth element?
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
        printf("Data %d: %d\n", i + 1, temp->data);
        temp = temp->next;
        i++;
    }
}

Node *getPreviousElements(Node *head, int k)
{
    if (head == NULL || k <= 0)
    {
        printf("Empty List.");
        exit(1);
    }

    Node *current = head;
    Node *prev = head;

    for (int i = 0; i < k + 1 && current != NULL; i++)
    {
        prev = current;
        current = current->next;
    }

    return prev;
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
    printf("Enter number of nodes of Linked List: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Enter a Valid Number.");
        exit(1);
    }

    head = create(head, n);

    int k;
    printf("Enter the Number: ");
    scanf("%d", &k);

    Node *after = getPreviousElements(head, k);

    printf("The Elements After kth Element:\n");
    display(after);

    freeList(head);

    return 0;
}