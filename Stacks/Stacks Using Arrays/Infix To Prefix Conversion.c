#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Stack
{
    int size;
    int top;
    char *arr;
} Stack;

int isEmpty(Stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(Stack *s)
{
    if (s->top == s->size - 1)
    {
        return 1;
    }
    return 0;
}

void push(Stack *s, char operator)
{
    if (isFull(s))
    {
        printf("Stack Overflow\n");
        return;
    }
    s->top++;
    s->arr[s->top] = operator;
}

char pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Underflow\n");
        return 0;
    }
    return s->arr[s->top--];
}

int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        return 1;
    }
    return 0;
}

int precedence(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 2;
    }
    if (ch == '*' || ch == '/')
    {
        return 3;
    }
    return 0;
}

void infixToPostfix(char *exp, char *str)
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->size = MAX_SIZE;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));
    int i = 0, j = 0;

    while (exp[i] != '\0')
    {
        if (isOperator(exp[i]))
        {
            while (!isEmpty(s) && precedence(exp[i]) <= precedence(s->arr[s->top]))
            {
                str[j++] = pop(s);
            }
            push(s, exp[i]);
        }
        else if (exp[i] == '(')
        {
            push(s, exp[i]);
        }
        else if (exp[i] == ')')
        {
            while (!isEmpty(s) && s->arr[s->top] != '(')
            {
                str[j++] = pop(s);
            }
            if (!isEmpty(s) && s->arr[s->top] == '(')
            {
                pop(s); // Pop '('
            }
        }
        else
        {
            str[j++] = exp[i];
        }
        i++;
    }

    while (!isEmpty(s))
    {
        str[j++] = pop(s);
    }

    str[j] = '\0';

    free(s->arr);
    free(s);
}

void reverse(char *exp)
{
    int i = 0;
    while (exp[i] != '\0')
    {
        if (exp[i] == '(')
        {
            exp[i] = ')';
        }
        else if (exp[i] == ')')
        {
            exp[i] = '(';
        }
        i++;
    }

    strrev(exp);
}

int main()
{
    char exp[MAX_SIZE];
    char str[MAX_SIZE];
    printf("Enter the Infix Expression:\n");
    fgets(exp, MAX_SIZE, stdin);

    exp[strlen(exp) - 1] = '\0';

    reverse(exp);

    infixToPostfix(exp, str);

    strrev(str);

    printf("\nThe Prefix expression:\n");
    int i = 0;
    while (str[i] != '\0')
    {
        printf("%c", str[i]);
        i++;
    }

    return 0;
}