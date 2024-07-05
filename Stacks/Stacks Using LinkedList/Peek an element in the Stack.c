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

    return 0;
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

Stack *push(Stack *top, int value)
{
    Stack *ptr = (Stack *)malloc(sizeof(Stack));
    ptr->data = value;
    ptr->next = NULL;

    ptr->next = top;
    top = ptr;
    return top;
}

Stack *create(Stack *top)
{
    int n, i;
    int data;
    printf("\nEnter the number of elements in stack: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        printf("Enter the Element %d: \n", i);
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
        printf("Element%d: %d\n", i + 1, ptr->data);
        ptr = ptr->next;
        i++;
    }
}

int peek(Stack *top, int index)
{
    Stack *ptr = top;
    for (int i = 0; (i < index - 1 && ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        return ptr->data;
    }
    else
        return -1;
}

int main()
{
    Stack *top = NULL;

    printf("Is the Stack Empty? ");
    if (isEmpty(top))
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }

    top = create(top);

    printf("The Elements of the Stack:\n");
    Display(top);

    int index;
    printf("Enter the position of the element you wish to peek: ");
    scanf("%d", &index);

    int p = peek(top, index);

    if (p != (-1))
    {
        printf("\nThe element at position %d is: %d\n", index, p);
    }
    else
    {
        printf("Enter a valid Index");
    }

    return 0;
}