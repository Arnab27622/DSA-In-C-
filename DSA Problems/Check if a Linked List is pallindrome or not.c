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
    if (ptr == NULL)
    {
        printf("Memory allocation failed.\n");
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

Node *create(int size)
{
    if (size <= 0)
    {
        printf("Enter a valid size.\n");
        return NULL;
    }

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

Node *reverse(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *prev = NULL;
    Node *current = head;
    Node *next;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

int isPalindrome(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return 1; // List with 0 or 1 node is always a palindrome
    }

    // Step 1: Find the middle of the list
    Node *slow = head;
    Node *fast = head;
    Node *prev_slow = NULL;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        prev_slow = slow;
        slow = slow->next;
    }

    // Step 2: Reverse the second half of the list
    Node *second_half = slow;
    if (fast != NULL) // List has odd number of nodes
    {
        second_half = slow->next;
    }
    prev_slow->next = NULL; // Break the list into two halves

    Node *prev = NULL;
    Node *current = second_half;
    Node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    second_half = prev;

    // Step 3: Compare the first half with the reversed second half
    Node *first_half = head;
    while (first_half != NULL && second_half != NULL)
    {
        if (first_half->data != second_half->data)
        {
            return 0; // Not a palindrome
        }
        first_half = first_half->next;
        second_half = second_half->next;
    }

    // Step 4: Restore the original list structure
    prev = NULL;
    current = second_half;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    second_half = prev;
    prev_slow->next = second_half; // Connect the two halves

    return 1; // Palindrome
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
    int n;
    printf("Enter number of nodes of Linked List: ");
    scanf("%d", &n);

    Node *head = create(n);

    if (isPalindrome(head))
    {
        printf("The Linked List is a palindrome.\n");
    }
    else
    {
        printf("The Linked List is not a palindrome.\n");
    }

    freeList(head);

    return 0;
}