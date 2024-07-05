#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *prev;
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
            printf("Found %d at index %d\n", data, i);
            i++;
            return;
        }
        head = head->next;
    }
    printf("Can't find %d.\n");
}

Node *add_to_Empty(Node *head, int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL)
    {
        printf("Memory Allocation failed.\n");
        return head;
    }
    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;

    head = temp;
    return head;
}

Node *add_to_End(Node *head, int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL)
    {
        printf("Memory Allocation failed.\n");
        return head;
    }
    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;

    Node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->prev = ptr;
    return head;
}

Node *add_before_Index(Node *head, int data, int index)
{
    if (head == NULL)
    {
        printf("Empty List.\n");
        return NULL;
    }

    if (index <= 0 || index > length(head))
    {
        printf("Index out of bounds.\n");
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
    temp->prev = NULL;

    if (index == 1)
    {
        head = add_to_Empty(head, data);
        return head;
    }

    Node *ptr = head;
    int i = 0;
    while (i < index - 2)
    {
        ptr = ptr->next;
        i++;
    }
    temp->next = ptr->next;
    if (ptr->next != NULL)
    {
        ptr->next->prev = temp;
    }
    ptr->next = temp;
    temp->prev = ptr;
    return head;
}

Node *add_after_Index(Node *head, int data, int index)
{
    if (head == NULL)
    {
        printf("Empty List.\n");
        return NULL;
    }

    if (index < 0 || index >= length(head))
    {
        printf("Index out of bounds.\n");
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
    temp->prev = NULL;

    Node *ptr = head;
    int i = 0;
    while (i < index)
    {
        ptr = ptr->next;
        i++;
    }
    temp->next = ptr->next;
    if (ptr->next != NULL)
    {
        ptr->next->prev = temp;
    }

    ptr->next = temp;
    temp->prev = ptr;
    return head;
}

Node *delete_at_Beginning(Node *head)
{
    if (head == NULL)
    {
        printf("Empty List.\n");
        return NULL;
    }

    Node *ptr = head;
    if (head->next != NULL)
    {
        head = head->next;
        head->prev = NULL;
    }
    else
    {
        head = NULL;
    }

    free(ptr);
    return head;
}

Node *delete_at_End(Node *head)
{
    if (head == NULL)
    {
        printf("Empty List.\n");
        return NULL;
    }

    Node *ptr = head;
    Node *p = ptr->next;
    while (p->next != NULL)
    {
        ptr = ptr->next;
        p = p->next;
    }
    ptr->next = p->next;
    p->prev = NULL;
    free(p);
    return head;
}

Node *delete_given(Node *head, int data)
{
    if (head == NULL)
    {
        printf("Empty List.\n");
        return NULL;
    }

    Node *ptr = head;
    Node *p = NULL;

    if (data == head->data)
    {
        p = head;
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL; // Update the prev pointer of the new head (if it exists)
        }
        free(p);
        return head;
    }

    while (ptr->next != NULL && ptr->next->data != data)
    {
        ptr = ptr->next;
    }
    if (ptr->next == NULL)
    {
        printf("Can't find %d in the linked list.", data);
        return head;
    }
    p = ptr->next;
    ptr->next = p->next;
    if (p->next != NULL)
    {
        ptr->next->prev = ptr;
    }

    free(p);
    return head;
}

Node *combine(Node *head1, Node *head2)
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

Node *insert(Node *head, int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    if (ptr == NULL)
    {
        printf("Memory Allocation failed.\n");
        return head;
    }
    ptr->data = data;
    ptr->prev = NULL;
    ptr->next = NULL;

    if (head == NULL)
    {
        head = ptr;
        return head;
    }

    if (data < head->data)
    {
        ptr->next = head;
        head->prev = ptr;
        head = ptr;
        return head;
    }

    Node *p = head;
    while (p->next != NULL && data >= p->next->data)
    {
        p = p->next;
    }

    ptr->next = p->next;
    if (p->next != NULL)
    {
        p->next->prev = ptr;
    }
    ptr->prev = p;
    p->next = ptr;

    return head;
}

Node *sort(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *sorted_head = NULL;

    Node *current = head;
    while (current != NULL)
    {
        sorted_head = insert(sorted_head, current->data);
        current = current->next;
    }

    return sorted_head;
}

Node *reverse(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *temp1 = NULL;
    Node *temp2 = NULL;
    while (head != NULL)
    {
        temp2 = head->next;
        head->next = temp1;
        head->prev = temp2;
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
        printf("Enter the data of Node %d: ", i);
        scanf("%d", &data);
        if (i == 0)
        {
            head = add_to_Empty(head, data);
        }
        else
        {
            head = add_to_End(head, data);
        }
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
        printf("Data %d: %d\n", i, temp->data);
        temp = temp->next;
        i++;
    }
}

void display_backward(Node *head)
{
    if (head == NULL)
    {
        printf("Empty List.\n");
        return;
    }

    // Traverse to the last node
    while (head->next != NULL)
    {
        head = head->next;
    }

    Node *temp = head;
    int i = 1;
    while (temp != NULL)
    {
        printf("Data %d: %d\n", i, temp->data);
        temp = temp->prev;
        i++;
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
    printf("Enter no of nodes: ");
    scanf("%d", &n);

    Node *head = NULL;
    head = create(head, n);

    int data, choice, index;

    while (1)
    {
        printf("Choice:\n1. Insert a Node at beginning.\n2. Insert a Node at ending\n3. Insert before a given node\n4. insert after a given Node.\n5. Delete at Beginning.\n6. Delete at End.\n7. Deletion of a given node.\n8. Forward traversal.\n9. Backward Traversal.\n10. Search a element\n11. Count Number of elements\n12. Combine two doubly Linked List.\n13. Sort the Doubly Linked List.\n14. Reversal of Doubly Linked List\n15. Display The Doubly Linked List\n16. Exit.\n\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data you wanna insert: ");
            scanf("%d", &data);

            head = add_to_Empty(head, data);
            break;
        case 2:
            printf("Enter the data you wanna insert: ");
            scanf("%d", &data);

            head = add_to_End(head, data);
            break;
        case 3:
            printf("Enter the data you wanna insert: ");
            scanf("%d", &data);
            printf("Enter the index before which you wanna insert %d: ", data);
            scanf("%d", &index);

            head = add_before_Index(head, data, index);
            break;
        case 4:
            printf("Enter the data you wanna insert: ");
            scanf("%d", &data);
            printf("Enter the index after which you wanna insert %d: ", data);
            scanf("%d", &index);

            head = add_after_Index(head, data, index);
            break;
        case 5:
            head = delete_at_Beginning(head);
            break;
        case 6:
            head = delete_at_End(head);
            break;
        case 7:
            printf("Enter the node value you wanna delete: ");
            scanf("%d", &data);
            head = delete_given(head, data);
            break;
        case 8:
            printf("Forward Traversal:\n");
            display(head);
            break;
        case 9:
            printf("Backward Traversal:\n");
            display_backward(head);
            break;
        case 10:
            printf("Enter the element you wanna search: ");
            scanf("%d", &data);

            search(head, data);
            break;
        case 11:
            printf("The number of elements in the linked list is %d\n", length(head));
            break;
        case 12:
            printf("Enter no of nodes of the Second linked list: ");
            scanf("%d", &n);

            Node *head2 = NULL;
            head2 = create(head2, n);
            printf("The Combined Doubly Linked List:\n");
            Node *combined_list = NULL;
            combined_list = combine(head, head2);
            display(combined_list);
            break;
        case 13:
            printf("The sorted Doubly Linked list:\n");
            head = sort(head);
            display(head);
            break;
        case 14:
            printf("The reversed Doubly linked list.\n");
            head = reverse(head);
            display(head);
            break;
        case 15:
            printf("The Doubly Linked List:\n");
            display(head);
            break;
        case 16:
            printf("Exiting...\n");
            freeList(&head);
            exit(0);
        default:
            printf("Enter a valid Choice\n\n");
            break;
        }
    }

    return 0;
}