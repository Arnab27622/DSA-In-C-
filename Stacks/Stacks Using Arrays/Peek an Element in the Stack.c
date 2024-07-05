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

int peek(Stack *ptr, int index)
{
    int arrIndex = ptr->top - index + 1;
    if (isEmpty(ptr))
    {
        printf("Stack Underflow can't peek any element");
        return -1;
    }
    else if (arrIndex < 0)
    {
        printf("Not a valid position in stack");
        return -1;
    }
    else
    {
        return ptr->arr[arrIndex];
    }
}

int main()
{
    Stack *s = (Stack *)malloc(sizeof(Stack)); // Allocate memory for the Stack structure
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

    int i = 1;
    while (i <= s->top + 1)
    {
        printf("The value at %d is %d\n", i, peek(s, i));
        i++;
    }

    free(s->arr); // Free the memory allocated for the integer array
    free(s);      // Free the memory allocated for the Stack structure

    return 0;
}