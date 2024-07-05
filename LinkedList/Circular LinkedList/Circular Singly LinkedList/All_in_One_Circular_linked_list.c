#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

int length(Node *tail)
{
    int count = 0;
    Node *ptr = tail;
    do
    {
        count++;
        ptr = ptr->next;
    } while (ptr != tail);
    return count;
}

void search(Node *tail, int data)
{
    if (tail == NULL)
    {
        printf("Empty List.\n");
        return;
    }

    Node *ptr = tail->next;
    int i = 0;
    while (ptr != tail->next)
    {
        if (data == ptr->data)
        {
            printf("%d found at %d index.\n", data, i);
            return;
        }
        ptr = ptr->next;
        i++;
    }
    printf("Can't Found %d in list.\n", data);
    return;
}

Node *add_to_Empty(Node *tail, int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL)
    {
        printf("Memory allocation failed.\n");
        return tail;
    }
    temp->data = data;
    temp->next = temp;
    return temp;
}

Node *add_to_Tail(Node *tail, int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL)
    {
        printf("Memory allocation failed.\n");
        return tail;
    }
    temp->data = data;
    temp->next = NULL;

    if (tail == NULL)
    {
        tail = temp;
        tail->next = tail;
    }
    else
    {
        temp->next = tail->next;
        tail->next = temp;
        tail = temp;
    }
    return tail;
}

Node *add_to_Beginning(Node *tail, int data)
{
    if (tail == NULL)
    {
        tail = add_to_Empty(tail, data);
        return tail;
    }

    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL)
    {
        printf("Memory allocation failed.\n");
        return tail;
    }
    temp->data = data;
    temp->next = NULL;

    temp->next = tail->next;
    tail->next = temp;
    return tail;
}

Node *create(Node *tail, int size)
{
    int data;
    for (int i = 0; i < size; i++)
    {
        printf("Enter the data of Node %d: ", i);
        scanf("%d", &data);
        if (i == 0)
        {
            tail = add_to_Empty(tail, data);
        }
        else
        {
            tail = add_to_Tail(tail, data);
        }
    }
    return tail;
}

Node *add_before_Index(Node *tail, int data, int index)
{
    if (tail == NULL)
    {
        printf("Empty List.\n");
        return NULL;
    }

    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL)
    {
        printf("Memory allocation failed.\n");
        return tail;
    }
    temp->data = data;
    temp->next = NULL;

    if (index <= 0 || index > length(tail))
    {
        printf("Index out of bounds.\n");
        return tail;
    }

    if (index == 1)
    {
        tail = add_to_Beginning(tail, data);
        return tail;
    }

    Node *ptr = tail->next;
    int i = 0;
    while (i < index - 2)
    {
        ptr = ptr->next;
        i++;
    }
    temp->next = ptr->next;
    ptr->next = temp;
    return tail;
}

Node *add_after_Index(Node *tail, int data, int index)
{
    if (tail == NULL)
    {
        printf("Empty List.\n");
        return NULL;
    }

    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL)
    {
        printf("Memory allocation failed.\n");
        return tail;
    }
    temp->data = data;
    temp->next = NULL;
    if (index < 0 || index >= length(tail))
    {
        printf("Index out of bounds.\n");
        return tail;
    }

    Node *ptr = tail->next;
    int i = 0;
    if (i == length(tail))
    {
        tail = add_to_Tail(tail, data);
        return tail;
    }

    while (i < index)
    {
        ptr = ptr->next;
        i++;
    }
    temp->next = ptr->next;
    ptr->next = temp;
    return tail;
}

Node *delete_at_Beginning(Node *tail)
{
    if (tail == NULL)
    {
        printf("Empty List.\n");
        return NULL;
    }

    Node *temp = tail->next;
    tail->next = tail->next->next;
    temp->next = NULL;
    free(temp);
    return tail;
}

Node *delete_at_End(Node *tail)
{
    if (tail == NULL)
    {
        printf("Empty List.\n");
        return NULL;
    }

    Node *temp = tail->next;
    while (temp->next != tail)
    {
        temp = temp->next;
    }
    temp->next = tail->next;
    tail->next = NULL;
    free(tail);
    tail = temp;
    return tail;
}

Node *delete_by_Value(Node *tail, int data)
{
    if (tail == NULL)
    {
        printf("Empty List.\n");
        return NULL;
    }

    Node *ptr = tail->next;
    Node *prev = tail;
    while (ptr != tail)
    {
        if (ptr->data == data)
        {
            prev->next = ptr->next;
            ptr->next = NULL;
            free(ptr);
            return tail;
        }
        prev = ptr;
        ptr = ptr->next;
    }
    printf("%d isn't present in the list.", data);
    return tail;
}

Node *delete_by_Index(Node *tail, int index)
{
    if (tail == NULL)
    {
        printf("Empty List.\n");
        return NULL;
    }

    if (index == 0)
    {
        Node *temp = tail->next;
        if (temp->next == temp)
        {
            // If there's only one node in the list
            free(temp);
            return NULL; // Return NULL as the list is empty now
        }
        tail->next = temp->next;
        temp->next = NULL;
        free(temp);
        return tail;
    }

    Node *ptr = tail->next;
    Node *prev = NULL;
    int i = 0;
    while (i < index)
    {
        prev = ptr;
        ptr = ptr->next;
        i++;
    }

    if (ptr == tail)
    {
        // If the node to be deleted is the tail node
        prev->next = ptr->next;
        tail = prev; // Update the tail pointer
    }
    else
    {
        prev->next = ptr->next;
    }

    free(ptr);
    return tail;
}

Node *combine(Node *tail1, Node *tail2)
{
    if (tail1 == NULL && tail2 == NULL)
    {
        printf("Both Lists are Empty.\n");
        return NULL;
    }
    if (tail1 == NULL)
    {
        return tail2;
    }
    if (tail2 == NULL)
    {
        return tail1;
    }

    Node *temp = tail1->next;
    tail1->next = tail2->next;
    tail2->next = temp;
    return tail2;
}

Node *update_by_index(Node *tail, int index, int data)
{
    if (tail == NULL)
    {
        printf("Empty List.\n");
        return NULL;
    }

    int i = 0;
    Node *ptr = tail->next;
    while (i != index)
    {
        ptr = ptr->next;
        i++;
    }
    ptr->data = data;
    return tail;
}

Node *update_by_value(Node *tail, int old_data, int new_data)
{
    if (tail == NULL)
    {
        printf("Empty List.\n");
        return NULL;
    }

    Node *ptr = tail->next;
    while (old_data != ptr->data)
    {
        ptr = ptr->next;
    }
    ptr->data = new_data;
    return tail;
}

Node *reverse(Node *tail)
{
    if (tail == NULL)
    {
        printf("Empty List.\n");
        return NULL;
    }

    if (tail->next == tail)
    {
        return tail;
    }

    Node *temp1 = NULL;
    Node *temp2 = NULL;
    Node *ptr = tail->next;

    do
    {
        temp2 = ptr->next;
        ptr->next = temp1;
        temp1 = ptr;
        ptr = temp2;
    } while (ptr != tail->next);

    tail = temp1;
    return tail;
}

int isCircular(Node *tail)
{
    if (tail == NULL || tail->next == NULL)
    {
        return 0;
    }

    Node *slow = tail;
    Node *fast = tail->next;

    while (fast != NULL || fast->next != NULL)
    {
        if (slow == fast)
        {
            return 1;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return 0;
}

void display(Node *tail)
{
    if (tail == NULL)
    {
        printf("Empty List.\n");
        return;
    }
    Node *ptr = tail->next;
    int i = 0;
    do
    {
        printf("Data %d: %d\n", i, ptr->data);
        i++;
        ptr = ptr->next;
    } while (ptr != tail->next);
}

void freeList(Node **tail)
{
    if (*tail == NULL)
    {
        printf("Empty List.\n");
        return;
    }

    Node *current = (*tail)->next;
    Node *nextNode;

    do
    {
        nextNode = current->next;
        free(current);
        current = nextNode;
    } while (current != (*tail)->next);

    *tail = NULL;
}

int main()
{
    Node *tail = NULL;
    int n;
    printf("Enter Number of nodes: ");
    scanf("%d", &n);

    tail = create(tail, n);

    int data, data1, choice, index;
    while (1)
    {
        printf("\nChoice:\n1. Insert a Node at beginning.\n2. Insert a Node at end\n3. Insert before a given node\n4. insert after a given Node.\n5. Delete at Beginning.\n6. Delete at End.\n7. Deletion of a given node by Value.\n8. Deletion of a given node by Index\n9. Forward traversal.\n10. Search a element\n11. Count Number of elements\n12. Combine two Circular Linked List.\n13. Update the Value of a Node at a Specific Position.\ni4. Update the value of a node with a specific value\n15. Reversal of The Circular Linked List\n16. Check if the list is empty\n17. Check if the list is circular\n18. Display The Circular Linked List\n19. Exit.\n\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data you want to insert: ");
            scanf("%d", &data);

            tail = add_to_Beginning(tail, data);
            break;
        case 2:
            printf("Enter the data you want to insert: ");
            scanf("%d", &data);

            tail = add_to_Tail(tail, data);
            break;
        case 3:
            printf("Enter the data you wanna insert: ");
            scanf("%d", &data);
            printf("Enter the index before which you wanna insert %d: ", data);
            scanf("%d", &index);

            tail = add_before_Index(tail, data, index);
            break;
        case 4:
            printf("Enter the data you wanna insert: ");
            scanf("%d", &data);
            printf("Enter the index after which you wanna insert %d: ", data);
            scanf("%d", &index);

            tail = add_after_Index(tail, data, index);
            break;
        case 5:
            tail = delete_at_Beginning(tail);
            break;
        case 6:
            tail = delete_at_End(tail);
            break;
        case 7:
            printf("Enter the data you wanna delete: ");
            scanf("%d", &data);

            tail = delete_by_Value(tail, data);
            break;
        case 8:
            printf("Enter the index whose data you wanna delete: ");
            scanf("%d", &index);

            tail = delete_by_Index(tail, index);
            break;
        case 9:
            printf("Forward Traversal:\n");
            display(tail);
            break;
        case 10:
            printf("Enter the data you wanna search: ");
            scanf("%d", &data);
            search(tail, data);
            break;
        case 11:
            printf("The number of elements in the list is: %d", length(tail));
            break;
        case 12:
            printf("Enter Number of nodes of Second list: ");
            scanf("%d", &n);

            Node *tail2 = NULL;
            tail2 = create(tail2, n);

            Node *combine_list = NULL;
            combine_list = combine(tail, tail2);
            printf("The Combined Linked List:\n");
            display(combine_list);
            break;
        case 13:
            printf("Enter the index whose value you wanna update: ");
            scanf("%d", &index);
            printf("Enter the new value of the Node: ");
            scanf("%d", &data);

            tail = update_by_index(tail, index, data);
            break;
        case 14:
            printf("Enter the old value that you wanna update: ");
            scanf("%d", &data1);
            printf("Enter the new value of the Node: ");
            scanf("%d", &data);

            tail = update_by_value(tail, data1, data);
            break;
        case 15:
            printf("The Reversed Circular Linked List:\n");
            tail = reverse(tail);
            display(tail);
            break;
        case 16:
            if (tail == NULL)
            {
                printf("The List is Empty.\n");
            }
            else
            {
                printf("The List isn't empty and it has %d nodes.\n", length(tail));
            }
            break;
        case 17:
            if (isCircular(tail))
            {
                printf("The list is a Circular Linked List.\n");
            }
            else
            {
                printf("The list isn't a Circular Linked List.\n");
            }
            break;
        case 18:
            printf("The Circular Linked List:\n");
            display(tail);
            break;
        case 19:
            printf("Exiting...\n");
            freeList(&tail);
            exit(0);
        default:
            printf("Enter a valid choice.\n");
            break;
        }
    }

    return 0;
}