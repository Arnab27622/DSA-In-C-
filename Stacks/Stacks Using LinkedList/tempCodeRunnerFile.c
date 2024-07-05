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

Stack *pop(Stack *top)
{
    Stack *ptr = top;

    if (isEmpty(ptr))
    {
        printf("The Stack is empty can't be popped");
    }
    else
    {
        top = top->next;
        return ptr;
    }
}

Stack *Free(Stack *top)
{
    Stack *ptr = top;
    while (ptr != NULL)
    {
        ptr = ptr->next;
        free(top);
        top = ptr;
    }
    return top;
}

Stack *create(Stack *top)
{
    int n, i;
    int data;

    printf("\nEnter no. of Elements: ");
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
}

Stack *Reverse(Stack *new, Stack *old)
{
    Stack *sp;

    while (old != NULL)
    {
        sp = pop(old);
        old = sp->next;
        new = push(new, sp->data);
    }

    return new;
}

int main()
{
    Stack *top = NULL;
    Stack *temp1Top = NULL;
    Stack *temp2Top = NULL;

    top = create(top);

    printf("The Stack Before Reverse:\n");
    Display(top);

    temp1Top = Reverse(temp1Top, top);
    top = Free(top);

    temp2Top = Reverse(temp2Top, temp1Top);
    temp1Top = Free(temp1Top);

    top = Reverse(top, temp2Top);
    temp2Top = Free(temp2Top);

    printf("The Stack After Reverse:\n");
    Display(temp1Top);

    return 0;
}