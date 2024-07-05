/* 1. Write a C function to detect a loop in a linked list.
   If a loop is found, write another function to find the starting node of the loop.
   Count the length of the loop.
*/

/* 2. Suppose we are given a pointer to the first element of a linked list L. There are two
   possibilities for L: it either ends (snake) or its last element points back to one of the
   earlier elements in the list (snail). Give an algorithm that tests whether a given list L is a
   snake or a snail.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createLinkedList(int size);
Node *addNode(Node *head, int data);
void createLoop(Node *head, int loopNodeValue);
Node *detectAndFindLoop(Node *head);
int countLoopLength(Node *loopNode);
void freeList(Node **head);

int main()
{
    Node *head = NULL;

    int n, loopNodeValue;
    printf("Enter the number of Nodes: ");
    scanf("%d", &n);

    head = createLinkedList(n);

    printf("Enter the value of the node where you want to create the loop: ");
    scanf("%d", &loopNodeValue);

    createLoop(head, loopNodeValue);

    // Detect and find the loop
    Node *loopStartNode = detectAndFindLoop(head);

    // Print the result
    if (loopStartNode != NULL)
    {
        int loopLength = countLoopLength(loopStartNode);
        printf("Linked list has a loop, and the loop starts at the node with value %d.\n", loopStartNode->data);
        printf("The length of the loop is %d.\n", loopLength);
    }
    else
    {
        printf("Linked list does not have a loop.\n");
    }

    // Free allocated memory
    freeList(&head);
    return 0;
}

Node *createLinkedList(int size)
{
    Node *head = NULL;
    int data;

    for (int i = 0; i < size; i++)
    {
        printf("Enter data of Node %d: ", i + 1);
        scanf("%d", &data);
        head = addNode(head, data);
    }

    return head;
}

Node *addNode(Node *head, int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    if (ptr == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

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

void createLoop(Node *head, int loopNodeValue)
{
    Node *loopNode = head;

    while (loopNode->data != loopNodeValue && loopNode->next != NULL)
    {
        loopNode = loopNode->next;
    }

    if (loopNode->data == loopNodeValue)
    {
        Node *lastNode = head;
        while (lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }
        lastNode->next = loopNode;
    }
}

Node *detectAndFindLoop(Node *head)
{
    Node *slowptr = head, *fastptr = head;

    while (slowptr && fastptr && fastptr->next)
    {
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;

        if (slowptr == fastptr)
        {
            // Loop detected, find the starting node
            slowptr = head;
            while (slowptr != fastptr)
            {
                slowptr = slowptr->next;
                fastptr = fastptr->next;
            }
            return slowptr;
        }
    }

    return NULL; // No loop
}

int countLoopLength(Node *loopNode)
{
    int length = 1;
    Node *current = loopNode->next;

    while (current != loopNode)
    {
        length++;
        current = current->next;
    }

    return length;
}

void freeList(Node **head)
{
    Node *current = *head;
    Node *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL; // Set the head to NULL after freeing all nodes
}