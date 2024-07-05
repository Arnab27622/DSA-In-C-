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
    Node *p = head;
    ptr->coefficient = coeff;
    ptr->exponent = expo;
    ptr->next = NULL;
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

    printf("Enter number of terms: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the co-efficient of term %d: ", i + 1);
        scanf("%f", &coeff);
        printf("Enter the exponent of term %d: ", i + 1);
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
void polyAdd(Node *head1, Node *head2)
{
    Node *ptr1 = head1;
    Node *ptr2 = head2;
    Node *head3 = NULL;
    while ((ptr1 != NULL) && (ptr2 != NULL))
    {
        if (ptr1->exponent == ptr2->exponent)
        {
            head3 = Insert(head3, (ptr1->coefficient + ptr2->coefficient), ptr1->exponent);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if (ptr1->exponent > ptr2->exponent)
        {
            head3 = Insert(head3, ptr1->coefficient, ptr1->exponent);
            ptr1 = ptr1->next;
        }
        else if (ptr1->exponent < ptr2->exponent)
        {
            head3 = Insert(head3, ptr2->coefficient, ptr2->exponent);
            ptr2 = ptr2->next;
        }
    }

    while (ptr1 != NULL)
    {
        head3 = Insert(head3, ptr1->coefficient, ptr1->exponent);
        ptr1 = ptr1->next;
    }
    while (ptr2 != NULL)
    {
        head3 = Insert(head3, ptr2->coefficient, ptr2->exponent);
        ptr2 = ptr2->next;
    }
    printf("The Added Polynomial is:\n");
    show(head3);
}

int main()
{
    Node *head1 = NULL;
    Node *head2 = NULL;

    printf("Enter the first polynominal:\n");
    head1 = Create(head1);
    printf("Enter the second polynominal:\n");
    head2 = Create(head2);

    polyAdd(head1, head2);
}
