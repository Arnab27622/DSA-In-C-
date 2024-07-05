#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int exponent;
    float coefficient;
    struct Node *next;
} Node;

Node *Insert(Node *head, float coeff, int expo)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
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
        Node *temp = head;
        while ((temp->next != NULL) && (temp->next->exponent >= expo))
        {
            temp = temp->next;
        }
        ptr->next = temp->next;
        temp->next = ptr;
    }
    return head;
}

Node *Create(Node *head, int size)
{
    int expo;
    float coeff;

    for (int i = 0; i < size; i++)
    {
        printf("Enter Coefficient for term %d: ", i + 1);
        scanf("%f", &coeff);
        printf("Enter Exponent for term %d: ", i + 1);
        scanf("%d", &expo);
        head = Insert(head, coeff, expo);
    }
    return head;
}

Node *polyMultiply(Node *head3, Node *head1, Node *head2)
{
    Node *ptr1 = head1;
    Node *ptr2 = head2;

    if ((head1 == NULL) || (head2 == NULL))
    {
        printf("ZERO Polynomial");
    }
    else
    {
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
    }

    Node *ptr3 = head3;
    Node *temp = NULL;

    while (ptr3->next != NULL)
    {
        if (ptr3->exponent == ptr3->next->exponent)
        {
            ptr3->coefficient = ptr3->coefficient + ptr3->next->coefficient;
            temp = ptr3->next;
            ptr3->next = ptr3->next->next;
            free(temp);
            temp = NULL;
        }
        else
        {
            ptr3 = ptr3->next;
        }
    }

    return head3;
}

void Display(Node *head)
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        printf("%.1fx^%d", ptr->coefficient, ptr->exponent);
        ptr = ptr->next;
        if (ptr != NULL)
        {
            printf(" + ");
        }
        else
            printf("\n");
    }
}
int main()
{
    Node *head1 = NULL;
    Node *head2 = NULL;

    int n1, n2;
    printf("Enter Number of Terms of First Polynomial: ");
    scanf("%d", &n1);
    head1 = Create(head1, n1);

    printf("Enter Number of Terms of Second Polynomial: ");
    scanf("%d", &n2);
    head2 = Create(head2, n2);

    Node *head3 = NULL;
    head3 = polyMultiply(head3, head1, head2);

    printf("The Multiplied Polynomial:\n");
    Display(head3);

    return 0;
}