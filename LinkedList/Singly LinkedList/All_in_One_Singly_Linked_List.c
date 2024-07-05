// Linked List
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

int length(Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

void search(Node *head, int data)
{
    int i = 0;
    while (head != NULL)
    {
        if (head->data == data)
        {
            printf("%d found at index %d", data, i);
            return;
        }
        head = head->next;
    }
    printf("Can't find %d", data);
}

Node *addToEmpty(Node *head, int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL)
    {
        printf("Memory Allocation failed.\n");
        return head;
    }

    temp->data = data;
    temp->next = NULL;

    if (head == NULL)
    {
        return temp;
    }

    temp->next = head;
    return temp;
}

Node *addToEnd(Node *head, int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL)
    {
        printf("Memory Allocation failed.\n");
        return head;
    }
    temp->data = data;
    temp->next = NULL;

    if (head == NULL)
    {
        // If the list is empty, the new node becomes the head and the tail
        return temp;
    }

    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    // Append the new node to the end of the list
    tail->next = temp;

    return head;
}

Node *addBeforeIndex(Node *head, int data, int index)
{
    if (head == NULL)
    {
        printf("Empty list.");
        return NULL;
    }

    if (index < 0 || index > length(head))
    {
        printf("Index out of bounds.");
        return head;
    }

    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL)
    {
        printf("Memory Allocation failed.\n");
        return head;
    }
    temp->data = data;
    temp->next = NULL;

    if (index == 0)
    {
        temp->next = head;
        return temp;
    }

    Node *ptr = head;
    int i = 0;
    while (i < index - 1)
    {
        ptr = ptr->next;
        i++;
    }
    temp->next = ptr->next;
    ptr->next = temp;

    return head;
}

Node *addAfterIndex(Node *head, int data, int index)
{
    if (head == NULL)
    {
        printf("Empty list.");
        return NULL;
    }

    if (index < 0 || index > length(head))
    {
        printf("Index out of bounds.");
        return head;
    }

    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL)
    {
        printf("Memory Allocation failed.\n");
        return head;
    }
    temp->data = data;

    Node *ptr = head;
    int i = 0;
    while (i <= index)
    {
        ptr = ptr->next;
        i++;
    }
    temp->next = ptr->next;
    ptr->next = temp;

    return head;
}

Node *deleteAtBegin(Node *head)
{
    if (head == NULL)
    {
        printf("Empty List.");
        return NULL;
    }

    Node *ptr = head;
    head = head->next;
    free(ptr);

    return head;
}

Node *deleteAtEnd(Node *head)
{
    if (head == NULL)
    {
        printf("Empty List.");
        return NULL;
    }

    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }

    Node *ptr = head;
    Node *p = ptr->next;

    while (p->next != NULL)
    {
        ptr = ptr->next;
        p = p->next;
    }

    ptr->next = NULL;
    free(p);

    return head;
}

Node *deleteBeforeIndex(Node *head, int index)
{
    if (head == NULL)
    {
        printf("Empty List.");
        return NULL;
    }

    if (index <= 0 || index >= length(head))
    {
        printf("Index out of bounds.");
        return head;
    }

    if (index == 1)
    {
        Node *temp = head->next;
        free(head);
        return temp;
    }

    Node *ptr = head;
    Node *p = ptr->next;
    int i = 0;
    while (i != index - 2)
    {
        ptr = ptr->next;
        p = p->next;
        i++;
    }

    ptr->next = p->next;
    free(p);

    return head;
}

Node *deleteAfterIndex(Node *head, int index)
{
    if (head == NULL)
    {
        printf("Empty List.");
        return NULL;
    }

    if (index < 0 || index >= length(head))
    {
        printf("Index out of bounds.");
        return head;
    }

    Node *ptr = head;
    Node *p = ptr->next;
    int i = 0;
    while (i < index)
    {
        ptr = ptr->next;
        p = p->next;
        i++;
    }

    ptr->next = p->next;
    free(p);

    return head;
}

Node *deleteSpecified(Node *head, int data)
{
    if (head == NULL)
    {
        printf("Empty List.");
        return NULL;
    }

    Node *ptr = head;
    Node *p = NULL;

    if (head->data == data)
    {
        p = head;
        head = head->next;
        free(p);
        return head;
    }

    while (ptr->next != NULL && ptr->next->data != data)
    {
        ptr = ptr->next;
    }

    if (ptr->next == NULL)
    {
        printf("Data not found in the linked list.");
        return head;
    }

    p = ptr->next;
    ptr->next = ptr->next->next;
    free(p);
    return head;
}

Node *insert(Node *head, int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    if (ptr == NULL)
    {
        printf("Memory Allocation failed.\n");
        return head;
    }
    ptr->data = data;
    ptr->next = NULL;

    if (head == NULL || data < head->data)
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

Node *merge(Node *head1, Node *head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }

    Node *temp = head1;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head2;

    return head1;
}

Node *sort(Node *sorted_head, Node *head)
{
    while (head != NULL)
    {
        sorted_head = insert(sorted_head, head->data);
        head = head->next;
    }
    return sorted_head;
}

Node *reverse(Node *head)
{
    Node *temp1 = NULL;
    Node *temp2 = NULL;
    while (
        head != NULL)
    {
        temp2 = head->next;
        head->next = temp1;
        temp1 = head;
        head = temp2;
    }
    head = temp1;
    return head;
}

Node *create(Node *head, int size)
{
    int data;
    for (int i = 0; i < size; i++)
    {
        printf("Enter data of Node %d: ", i);
        scanf("%d", &data);
        if (i == 0)
        {
            head = addToEmpty(head, data);
        }
        else
        {
            head = addToEnd(head, data);
        }
    }
    return head;
}

void Display(Node *head)
{
    if (head == NULL)
    {
        printf("Empty list.");
        return;
    }

    int i = 0;
    Node *ptr = head;
    while (ptr != NULL)
    {
        printf("Data %d: %d\n", i, ptr->data);
        i++;
        ptr = ptr->next;
    }
}

void freeList(Node **head)
{
    if (*head == NULL)
    {
        printf("Empty list.");
        return;
    }

    Node *current = *head;
    Node *nextNode;

    while (current != NULL)
    {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    *head = NULL;
}

int main()
{
    int n;
    printf("Enter Number of Nodes: ");
    scanf("%d", &n);

    Node *head = NULL;
    head = create(head, n);

    int data, index, choice;
    while (1)
    {
        printf("\n1. insert node at beginning.\n2. insert node at end.\n3. insert node before specified index.\n4. insert node after specified index\n5. Delete node at beginning.\n6. Delete node at end.\n7. Delete node before specified index\n8. Delete node after specified index\n9. Delete a given value\n10. Search By value.\n11. Search By Index\n12. Count number of nodes.\n13. Iterative Traversal.\n14. Recursive Traversal\n15. Merge two Linked list\n16. Sort the linked list\n17. Reverse the linked list\n18. Display the linked list.\n19. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data you want to insert: ");
            scanf("%d", &data);

            head = addToEmpty(head, data);
            break;
        case 2:
            printf("Enter the data you want to insert: ");
            scanf("%d", &data);

            head = addToEnd(head, data);
            break;
        case 3:
            printf("Enter the data you want to insert: ");
            scanf("%d", &data);
            printf("Enter the index before which you want to insert %d: ", data);
            scanf("%d", &index);

            head = addBeforeIndex(head, data, index - 1);
            break;
        case 4:
            printf("Enter the data you want to insert: ");
            scanf("%d", &data);
            printf("Enter the index after which you want to insert %d: ", data);
            scanf("%d", &index);

            head = addAfterIndex(head, data, index - 1);
            break;
        case 5:
            head = deleteAtBegin(head);
            break;
        case 6:
            head = deleteAtEnd(head);
            break;
        case 7:
            printf("Enter the index, the data before which will be deleted: ");
            scanf("%d", &index);

            head = deleteBeforeIndex(head, index);
            break;
        case 8:
            printf("Enter the index, the data after which will be deleted: ");
            scanf("%d", &index);

            head = deleteAfterIndex(head, index);
            break;
        case 9:
            printf("Enter the value you want to delete: ");
            scanf("%d", &data);

            head = deleteSpecified(head, data);
            break;
        case 10:
            printf("Enter the data you want to search: ");
            scanf("%d", &data);

            search(head, data);
            break;
        case 12:
            printf("Number of Nodes present is: %d", length(head));
            break;
        case 15:
            printf("Enter Number of Nodes of second Linked List: ");
            scanf("%d", &n);

            Node *head2 = NULL;
            head2 = create(head2, n);

            printf("The Merged Linked List:\n");
            Node *merged_head = merge(head, head2);
            Display(merged_head);
            head = merged_head;
            break;

        case 16:
            printf("The Sorted Linked List:\n");
            Node *Sorted_head = NULL;
            Sorted_head = sort(Sorted_head, head);
            Display(Sorted_head);
            break;
        case 17:
            printf("The Reversed Linked List:\n");
            head = reverse(head);
            Display(head);
            break;
        case 18:
            printf("The Singly Linked List:\n");
            Display(head);
            break;
        case 19:
            printf("Exiting...\n");
            freeList(&head);
            exit(0);
        default:
            printf("Enter a Valid Choice");
            break;
        }
    }

    return 0;
}