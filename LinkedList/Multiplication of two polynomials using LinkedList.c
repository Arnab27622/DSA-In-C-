#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    float coefficient;
    int exponent;
    struct Node *next;
} Node;

Node *Insert(Node *head, float coeff, int expo)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->coefficient = coeff;
    ptr->exponent = expo;
    ptr->next = NULL;
    Node *p = head;
    if ((head == NULL) || (expo > head->exponent))
    {
        ptr->next = head;
        head = ptr;
    }
    else
    {
        while ((p->next != NULL) && (p->next->exponent >= expo))
        {
            p = p->next;
        }
        ptr->next = p->next;
        p->next = ptr;
    }
    return head;
}

Node *Create(Node *head)
{
    int n, i;
    float coeff;
    int expo;
    printf("Enter number of Elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter coefficient of Element %d: ", i + 1);
        scanf("%f", &coeff);
        printf("Enter exponent of Element %d: ", i + 1);
        scanf("%d", &expo);
        head = Insert(head, coeff, expo);
    }
    return head;
}

void show(Node *head)
{
    if (head == NULL)
    {
        printf("No Polynomial.");
    }
    else
    {
        Node *ptr = head;
        while (ptr != NULL)
        {
            printf("(%.1fx^%d)", ptr->coefficient, ptr->exponent);
            ptr = ptr->next;
            if (ptr != NULL)
            {
                printf(" + ");
            }
            else
            {
                printf("\n");
            }
        }
    }
}

void polyMulti(Node *head1, Node *head2)
{
    Node *ptr1 = head1;
    Node *ptr2 = head2;
    Node *head3 = NULL;

    if ((head1 == NULL) || (head2 == NULL))
    {
        printf("ZERO Polynomial.");
    }

    while (ptr1 != NULL)
    {
        while (ptr2 != NULL)
        {
            head3 = Insert(head3, (ptr1->coefficient * ptr2->coefficient), (ptr1->exponent + ptr2->exponent));
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
        ptr2 = head2;
    }

    printf("\nThe result Before LinkedList:\n");
    show(head3);

    Node *ptr3 = head3;
    Node *p = NULL;
    while (ptr3->next != NULL)
    {
        if (ptr3->exponent == ptr3->next->exponent)
        {
            ptr3->coefficient = ptr3->coefficient + ptr3->next->coefficient;
            p = ptr3->next;
            ptr3->next = ptr3->next->next;
            free(p);
        }
        else
        {
            ptr3 = ptr3->next;
        }
    }

    printf("\nThe result After LinkedList:\n");
    show(head3);
}

int main()
{
    Node *head1 = NULL;
    Node *head2 = NULL;
    printf("Enter the first polynomial:\n");
    head1 = Create(head1);
    printf("Enter the second polynomial:\n");
    head2 = Create(head2);

    polyMulti(head1, head2);
    return 0;
}