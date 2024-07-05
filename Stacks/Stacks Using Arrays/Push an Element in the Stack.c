#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int size;
    int top;
    int *arr;
} Stack;

int isEmpty(Stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
        return 0;
}

int isFull(Stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
        return 0;
}

void push(Stack *ptr, int value)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow can't push %d\n", value);
        return;
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

int main()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->size = 100;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    printf("Is Stack is Currently Empty: %d\n", isEmpty(s));

    push(s, 56);

    printf("Is Stack is Currently Empty: %d\n", isEmpty(s));

    free(s);

    return 0;
}
