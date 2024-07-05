#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int data;
    struct Stack *next;
} Stack;

int isEmpty(Stack *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(Stack *top)
{
    Stack *ptr = (Stack *)malloc(sizeof(Stack));
    if (ptr == NULL)
    {
        return 1;
    }

    return 0;
}

Stack *push(Stack *top, int data)
{
    Stack *ptr = (Stack *)malloc(sizeof(Stack));
    ptr->data = data;
    ptr->next = NULL;

    if (isFull(ptr))
    {
        printf("Stack overflow can't push element %d\n", data);
    }
    else
    {
        ptr->next = top;
        top = ptr;
        return top;
    }
}

Stack *create(Stack *top)
{
    int n, i;
    int data;
    printf("\nEnter Number of Elements: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        printf("Enter the data of the element %d: ", i);
        scanf("%d", &data);
        top = push(top, data);
    }
    return top;
}

void Display(Stack *top)
{
    Stack *ptr = top;

    int i = 0;
    while (ptr != NULL)
    {
        printf("Element %d: %d\n", i + 1, ptr->data);
        ptr = ptr->next;
        i++;
    }

    return;
}

int main()
{
    Stack *top = NULL;

    printf("Is the Stack Empty? = %d", isEmpty(top));

    top = create(top);

    printf("The Stack:\n");
    Display(top);

    printf("Is the Stack Empty? = %d", isEmpty(top));

    return 0;
}