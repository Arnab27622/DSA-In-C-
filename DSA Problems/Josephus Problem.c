/*The Josephus problem is a theoretical problem related to a certain counting-out game. In this problem, there are N people standing in a circle, and they are sequentially eliminated in a predefined order until only one person remains. The problem is to find the position of the last person remaining.

To solve this problem using a linked list in C, we can represent the people as nodes in the linked list. We will simulate the process of elimination by repeatedly skipping a fixed number of people and removing them from the circle until only one person remains.

Here's the implementation of the Josephus problem using a circular linked list in C:
*/

#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the circular linked list
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the circular linked list
void insertAtEnd(struct Node **headRef, int data)
{
    struct Node *newNode = createNode(data);
    if (*headRef == NULL)
    {
        *headRef = newNode;
        newNode->next = newNode; // Circular reference
    }
    else
    {
        struct Node *last = *headRef;
        while (last->next != *headRef)
        {
            last = last->next;
        }
        last->next = newNode;
        newNode->next = *headRef;
    }
}

// Function to delete a node from the circular linked list
void deleteNode(struct Node **headRef, struct Node *delNode)
{
    if (*headRef == NULL || delNode == NULL)
    {
        return;
    }
    if (*headRef == delNode)
    {
        *headRef = delNode->next;
    }
    struct Node *temp = *headRef;
    while (temp->next != delNode && temp->next != *headRef)
    {
        temp = temp->next;
    }
    temp->next = delNode->next;
    free(delNode);
}

// Function to print the circular linked list
void display(struct Node *head)
{
    if (head == NULL)
    {
        printf("Circular linked list is empty!\n");
        return;
    }
    struct Node *temp = head;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Function to solve the Josephus problem
void josephus(int n, int k)
{
    struct Node *head = NULL;
    // Populate the circular linked list with numbers from 1 to n
    for (int i = 1; i <= n; i++)
    {
        insertAtEnd(&head, i);
    }
    // Start the elimination process
    struct Node *current = head;
    while (current->next != current)
    {
        // Move k-1 steps forward
        for (int i = 1; i < k; i++)
        {
            current = current->next;
        }
        // Eliminate the person at the current position
        struct Node *nextNode = current->next;
        printf("Eliminated: %d\n", current->data);
        deleteNode(&head, current);
        current = nextNode;
    }
    // Print the last person remaining
    printf("Last person remaining: %d\n", current->data);
    // Free memory
    free(current);
}

int main()
{
    int n, k;
    printf("Enter the number of people (N): ");
    scanf("%d", &n);
    printf("Enter the elimination count (K): ");
    scanf("%d", &k);
    josephus(n, k);
    return 0;
}

/* In this implementation:

We define a circular linked list where each node represents a person standing in the circle.
We use the insert function to insert nodes at the end of the circular linked list.
We use the deleteNode function to remove nodes from the circular linked list.
The josephus function simulates the Josephus problem by eliminating people from the circular linked list until only one person remains.
Finally, we free the memory allocated for the nodes.
*/