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

int pop(Stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow can't pop any element");
        return -1;
    }
    else
    {
        int value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}

int main()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    push(s, 56);
    push(s, 65);
    push(s, 78);
    push(s, 10);
    push(s, 4);
    push(s, 26);

    printf("\nIs Stack is Currently Full: %d\n", isFull(s));

    int p = pop(s);

    printf("\nIs Stack is Currently Full: %d\n", isFull(s));
    printf("The popped Value is %d\n", p);

    return 0;
}