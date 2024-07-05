/*
    Suppose there are two singly linked lists both of which intersect at some point and become a single linked list.
    The head or start pointers of both the lists are known, but the intersecting node is not known. Also, the number of nodes in each of the lists before
    they intersect is unknown and may be different in each list. List1 may have n nodes before it reaches the intersection point,
    finding the merging point.
    and List2 might have m nodes before it reaches the intersection point where m and n may be m = n,m < n or m > n. Give an algorithm for
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

void display(Node *head)
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
        printf("Element %d: %d\n", i + 1, temp->data);
        temp = temp->next;
        i++;
    }
}

int hasIntersection(Node *head1, Node *head2)
{
    if (head1 == NULL || head2 == NULL)
    {
        return 0;
    }

    int len1 = 0, len2 = 0, diff = 0;
    Node *temp1 = head1;
    Node *temp2 = head2;

    while (temp1 != NULL)
    {
        len1++;
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        len2++;
        temp2 = temp2->next;
    }

    if (len1 > len2)
    {
        temp1 = head1;
        temp2 = head2;
        diff = len1 - len2;
    }
    else
    {
        temp1 = head2;
        temp2 = head1;
        diff = len2 - len1;
    }

    for (int i = 0; i < diff; i++)
    {
        temp1 = temp1->next;
    }

    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1 == temp2)
        {
            return temp1->data;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return 0;
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

int main()
{
    Node *head1 = NULL, *head2 = NULL;

    int n;
    printf("Enter number of nodes of the first Linked List: ");
    scanf("%d", &n);

    head1 = create(head1, n);

    int m;
    printf("Enter number of nodes of the second Linked List: ");
    scanf("%d", &m);

    head2 = create(head2, m);

    printf("The first Linked List:\n");
    display(head1);
    printf("The second Linked List:\n");
    display(head2);

    if (hasIntersection(head1, head2))
        printf("The linked lists merge at %d Node of first Linked List.", hasIntersection(head1, head2));
    else
        printf("The linked lists don't intersect.");

    freeList(&head1);
    freeList(&head2);

    return 0;
}