#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct Stack
{
    int top;
    int size;
    char *arr;
} Stack;

int isEmpty(Stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }

    return 0;
}

int isFull(Stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }

    return 0;
}

void push(Stack *ptr, char data)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow can't push '%c'", data);
        return;
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = data;
    }
}

int pop(Stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Overflow can't Pop");
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int MatchParenthesis(char *exp)
{
    Stack *sp;
    sp->size = MAX_SIZE;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            else
            {
                pop(sp);
            }
        }
    }

    if (isEmpty(sp))
    {
        return 1;
    }
    else
        return 0;
}

int main()
{
    char *exp[MAX_SIZE];

    printf("Enter the Expression:\n");
    fgets(exp, sizeof(exp), stdin);
    // scanf("%s",exp);

    if (MatchParenthesis(exp))
    {
        printf("The Parenthesis is Matching");
    }
    else
    {
        printf("The Parenthesis is not Matching");
    }

    return 0;
}