#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int top;
    int size;
    int *arr;
} Stack;

int IsEmpty(Stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
        return 0;
}

int IsFull(Stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
        return 0;
}

int main()
{
    Stack *s;

    s->size = 100;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    int n = IsFull(s);
    int m = IsEmpty(s);
    printf("%d\n%d", m, n);
    return 0;
}