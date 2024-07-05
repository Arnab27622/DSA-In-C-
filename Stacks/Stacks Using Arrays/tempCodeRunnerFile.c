#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Stack
{
    int size;
    int top;
    7 char *arr;
} Stack;

int isEmpty(Stack *s)
{
    return s->top == -1;
}

int isFull(Stack *s)
{
    return s->top == s->size - 1;
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
        return '\0'; // Return null character on underflow
    }
    return s->arr[s->top--];
}

int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int precedence(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    return 0;
}

void infixToPostfix(char *exp)
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->size = MAX_SIZE;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));

    int i = 0;
    while (exp[i] != '\0')
    {
        if (isOperator(exp[i]))
        {
            while (!isEmpty(s) && precedence(exp[i]) <= precedence(s->arr[s->top]))
            {
                printf("%c", pop(s));
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
                printf("%c", pop(s));
            }
            if (!isEmpty(s) && s->arr[s->top] == '(')
            {
                pop(s); // Pop '('
            }
        }
        else
        {
            printf("%c", exp[i]);
        }
        i++;
    }

    while (!isEmpty(s))
    {
        printf("%c", pop(s));
    }

    free(s->arr);
    free(s);
}

int main()
{
    char exp[MAX_SIZE];
    printf("Enter the Infix Expression:\n");
    fgets(exp, MAX_SIZE, stdin);

    exp[strlen(exp) - 1] = '\0'; // Remove the newline character from input

    printf("The Postfix expression:\n");
    infixToPostfix(exp);

    return 0;
}