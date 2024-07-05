#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *addSortedNode(Node *head, int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = data;
    ptr->next = NULL;

    if (head == NULL || data < head->data)
    {
        ptr->next = head;
        head = ptr;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL && data > temp->next->data)
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
        head = addSortedNode(head, data);
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
    printf("Enter number of nodes of the Linked List: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Enter a Valid Number.");
        exit(1);
    }

    head = create(head, n);

    printf("The Sorted Linked List:\n");
    display(head);

    freeList(head);

    return 0;
}