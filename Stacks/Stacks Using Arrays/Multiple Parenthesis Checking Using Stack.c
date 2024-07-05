#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct Stack
{
    int top;
    int size;
    char *arr;
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

void push(Stack *ptr, char data)
{
    if (IsFull(ptr))
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
    if (IsEmpty(ptr))
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

char Matched(char a, char b)
{
    if (a == '(' && b == ')')
    {
        return 1;
    }
    else if (a == '{' && b == '}')
    {
        return 1;
    }
    else if (a == '[' && b == ']')
    {
        return 1;
    }
    return 0;
}

int MatchParenthesis(char *exp)
{
    Stack *sp = (Stack *)malloc(sizeof(Stack));
    sp->size = MAX_SIZE;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * (sizeof(char)));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (IsEmpty(sp))
            {
                return 0;
            }
            char popped_ch = pop(sp);
            if (!Matched(popped_ch, exp[i]))
            {
                return 0;
            }
        }
    }

    if (!IsEmpty(sp))
    {
        return 0;
    }

    return 1;
}

int main()
{
    char exp[MAX_SIZE];

    printf("Enter the expression:\n");
    fgets(exp, sizeof(exp), stdin);

    if (MatchParenthesis(exp))
    {
        printf("Parenthesis is matching");
    }
    else
    {
        printf("Parenthesis is not matching");
    }

    return 0;
}