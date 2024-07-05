#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *addToEmpty(Node *tail, int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = data;

    ptr->next = ptr;
    ptr->prev = ptr;
    return ptr;
}

Node *addToTail(Node *tail, int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = data;

    ptr->next = tail->next;
    tail->next = ptr;
    ptr->prev = tail;
    tail = ptr;

    return tail;
}

Node *Create(Node *tail, int size)
{
    int data;
    printf("Enter data of the Node 1: ");
    scanf("%d", &data);
    tail = addToEmpty(tail, data);

    for (int i = 1; i < size; i++)
    {
        printf("Enter data of the Node %d: ", i + 1);
        scanf("%d", &data);
        tail = addToTail(tail, data);
    }
    return tail;
}

Node *InsertAtFirst(Node *tail, int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = data;

    Node *temp = tail->next;

    ptr->next = temp;
    ptr->prev = tail;
    temp->prev = ptr;
    tail->next = ptr;

    return tail;
}

Node *InsertAtEnd(Node *tail, int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = data;

    ptr->next = tail->next;
    ptr->prev = tail;
    tail->next = ptr;
    tail = ptr;

    return tail;
}

Node *InsertAtIndex(Node *tail, int index, int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = data;

    Node *p = tail->next;
    int i = 0;
    while (i != (index - 1))
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    ptr->prev = p;
    p->next = ptr;
    ptr->next->prev = ptr;

    return tail;
}

Node *DeleteAtFirst(Node *tail)
{
    Node *ptr = tail->next;

    tail->next = ptr->next;
    ptr->next->prev = tail;
    free(ptr);

    return tail;
}

Node *DeleteAtEnd(Node *tail)
{
    Node *ptr = tail->prev;

    ptr->next = tail->next;
    tail->next->prev = ptr;
    free(tail);
    tail = ptr;

    return tail;
}

Node *DeleteAtIndex(Node *tail, int index)
{
    Node *ptr = tail->next;
    Node *p = ptr->next;
    int i = 0;

    while (i != (index - 1))
    {
        ptr = ptr->next;
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next->prev = ptr;

    if (p == tail)
    {
        tail = ptr;
    }

    free(p);

    return tail;
}

int Count(Node *tail)
{
    Node *ptr = tail->next;
    int count = 0;
    do
    {
        ptr = ptr->next;
        count++;
    } while (ptr != tail->next);

    return count;
}

void Search(Node *tail, int data)
{
    if (tail == NULL)
    {
        printf("Empty LinkedList.");
        exit(1);
    }
    Node *ptr = tail->next;
    int i = 0;
    do
    {
        if (ptr->data == data)
        {
            printf("\nElement Found at Node %d", i + 1);
            return;
        }

        ptr = ptr->next;
        i++;
    } while (ptr != tail->next);

    printf("Element Not Found.");
}

void Display(Node *tail)
{
    Node *ptr = tail->next;
    int i = 0;
    do
    {
        printf("Element %d: %d\n", i + 1, ptr->data);
        ptr = ptr->next;
        i++;
    } while (ptr != tail->next);
}

void freeList(Node **tail)
{
    Node *current = (*tail)->next;
    Node *prev;

    while (current != *tail)
    {
        prev = current;
        current = current->next;
        free(prev);
    }

    free(current);

    *tail = NULL;
}

int main()
{
    Node *tail = NULL;

    int n;
    printf("Enter Number of Nodes: ");
    scanf("%d", &n);

    tail = Create(tail, n);

    int choice, data, index;
    while (1)
    {
        printf("\n");
        printf("1. Insert At Begining\n");
        printf("2. Insert At End\n");
        printf("3. Insert At Specified Index\n");
        printf("4. Delete At Begining\n");
        printf("5. Delete At End\n");
        printf("6. Delete At At Specified Index\n");
        printf("7. Count Number of Nodes\n");
        printf("8. Search an Element\n");
        printf("9. Display the Linked List\n");
        printf("10. Quit\n");
        printf("Please Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("The Circular Doubly LinkedList Before Insertion:\n");
            Display(tail);

            printf("Enter the value to be Inserted: ");
            scanf("%d", &data);
            tail = InsertAtFirst(tail, data);

            printf("The Circular Doubly LinkedList After Insertion:\n");
            Display(tail);
            break;
        case 2:
            printf("The Circular Doubly LinkedList Before Insertion:\n");
            Display(tail);

            printf("Enter the value to be Inserted: ");
            scanf("%d", &data);
            tail = InsertAtEnd(tail, data);

            printf("The Circular Doubly LinkedList After Insertion:\n");
            Display(tail);
            break;
        case 3:
            printf("The Circular Doubly LinkedList Before Insertion:\n");
            Display(tail);

            printf("Enter the value to be Inserted: ");
            scanf("%d", &data);

            printf("Enter the index of Node Where you Want to Insert %d: ", data);
            scanf("%d", &index);

            tail = InsertAtIndex(tail, (index - 1), data);

            printf("The Circular Doubly LinkedList After Insertion:\n");
            Display(tail);
            break;
        case 4:
            printf("The Circular Doubly LinkedList Before Deletion:\n");
            Display(tail);

            tail = DeleteAtFirst(tail);

            printf("The Circular Doubly LinkedList After Deletion:\n");
            Display(tail);
            break;
        case 5:
            printf("The Circular Doubly LinkedList Before Deletion:\n");
            Display(tail);

            tail = DeleteAtEnd(tail);

            printf("The Circular Doubly LinkedList After Deletion:\n");
            Display(tail);
            break;
        case 6:
            printf("The Circular Doubly LinkedList Before Deletion:\n");
            Display(tail);

            printf("Enter The index of the Node You want to Delete: ");
            scanf("%d", &index);

            tail = DeleteAtIndex(tail, (index - 1));

            printf("The Circular Doubly LinkedList After Deletion:\n");
            Display(tail);
            break;
        case 7:
            printf("Number of Nodes in the LinkedList = %d\n", Count(tail));
            break;
        case 8:
            printf("Enter the Element you want to Search: ");
            scanf("%d", &data);

            Search(tail, data);
            break;
        case 9:
            printf("The Circular Doubly Linked List:\n");
            Display(tail);
            break;
        case 10:
            printf("The Program Ends Here.\n");
            exit(1);
        default:
            printf("\nInvalid Choice! Please enter a valid number.\n");
            break;
        }
    }

    freeList(&tail);
    return 0;
}