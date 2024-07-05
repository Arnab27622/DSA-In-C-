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

Node *create(Node *head)
{
    int n;
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

void Show(Node *head)
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

int main()
{
    Node *head = NULL;
    printf("Enter the polynomial:\n");
    head = create(head);
    Show(head);
    return 0;
}