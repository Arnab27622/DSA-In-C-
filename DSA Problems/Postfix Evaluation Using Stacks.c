#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Stack
{
    int top;
    int size;
    int *arr;
} Stack;

int isEmpty(Stack *s)
{
    return s->top == -1;
}

int isFull(Stack *s)
{
    return s->top == s->size - 1;
}

void push(Stack *s, int num)
{
    if (isFull(s))
    {
        printf("Stack Overflow\n");
        return;
    }
    s->top++;
    s->arr[s->top] = num;
}

int pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->arr[s->top--];
}

int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void valueOfPostFix(char *exp)
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = -1;
    s->size = MAX_SIZE;
    s->arr = (int *)malloc(s->size * sizeof(int));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (!isOperator(exp[i]))
        {
            // Operand found, push onto stack
            push(s, exp[i] - '0');
        }
        else
        {
            // Operator found, pop two operands and perform operation
            int popped1 = pop(s);
            int popped2 = pop(s);
            int res;
            switch (exp[i])
            {
            case '+':
                res = popped2 + popped1;
                break;
            case '-':
                res = popped2 - popped1;
                break;
            case '*':
                res = popped2 * popped1;
                break;
            case '/':
                res = popped2 / popped1;
                break;
            default:
                printf("Enter a valid Operation");
                break;
            }
            // Push the result onto the stack
            push(s, res);
        }
    }

    printf("%d", pop(s));
}

int main()
{
    char exp[MAX_SIZE];
    printf("Enter the Expression:\n");
    fgets(exp, MAX_SIZE, stdin);

    exp[strlen(exp) - 1] = '\0';

    printf("The Value of the Postfix Expression:\n");
    valueOfPostFix(exp);

    return 0;
}