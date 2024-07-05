#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Function to create a new node
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of a linked list
Node *insertAtBeginning(Node *head, int data)
{
    Node *newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// Function to display the linked list
void display(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to reverse a linked list in place
Node *reverse(Node *head)
{
    Node *prev = NULL, *current = head, *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// Function to add two numbers represented as linked lists
Node *addLinkedLists(Node *num1, Node *num2)
{
    Node *resultHead = NULL;
    Node *current = NULL;
    int carry = 0, sum;

    while (num1 != NULL || num2 != NULL || carry)
    {
        sum = carry;
        if (num1 != NULL)
        {
            sum += num1->data;
            num1 = num1->next;
        }
        if (num2 != NULL)
        {
            sum += num2->data;
            num2 = num2->next;
        }
        carry = sum / 10;
        sum %= 10;
        if (resultHead == NULL)
        {
            resultHead = createNode(sum);
            current = resultHead;
        }
        else
        {
            current->next = createNode(sum);
            current = current->next;
        }
    }

    return resultHead;
}

// Function to free the memory allocated for the linked list
void freeList(Node *head)
{
    Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d%d", &num1, &num2);

    Node *head1 = NULL;
    Node *head2 = NULL;
    Node *result = NULL;

    // Create linked list representations of the two numbers
    while (num1 != 0)
    {
        head1 = insertAtBeginning(head1, num1 % 10);
        num1 /= 10;
    }
    while (num2 != 0)
    {
        head2 = insertAtBeginning(head2, num2 % 10);
        num2 /= 10;
    }

    // Reverse the linked lists
    head1 = reverse(head1);
    head2 = reverse(head2);

    // Display the linked list representations
    printf("Linked List representation of First number:\n");
    display(head1);
    printf("Linked List representation of Second number:\n");
    display(head2);

    // Add the linked list representations
    result = addLinkedLists(head1, head2);

    // Display the result
    printf("Resultant Linked List after Addition:\n");
    display(result);

    // Free the memory allocated for the linked lists
    freeList(head1);
    freeList(head2);
    freeList(result);

    return 0;
}