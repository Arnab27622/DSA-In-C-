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
        exit(1);
    }
    else
    {
        int value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}

Stack *primeFactor(Stack *ptr, int num)
{
    int i = 2;
    while (num != 1)
    {
        while (num % i == 0)
        {
            push(ptr, i);
            num = num / i;
        }
        i++;
    }

    return ptr;
}

void Display(Stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow can't display elements\n");
    }
    else
    {
        while (ptr->top != -1)
        {
            printf("%d, ", pop(ptr));
        }
    }
}

int main()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    int num;
    printf("Enter the Number to find prime factor: ");
    scanf("%d", &num);

    s = primeFactor(s, num);
    printf("The Prime Factors of %d are: ", num);
    Display(s);

    return 0;
}