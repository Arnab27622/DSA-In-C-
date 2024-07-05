#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Stack
{
    int size;
    int top;
    char **arr; // Use char ** for storing strings
} Stack;

int isEmpty(Stack *s)
{
    return s->top == -1;
}

int isFull(Stack *s)
{
    return s->top == s->size - 1;
}

void pushStr(Stack *s, char *str)
{
    if (isFull(s))
    {
        printf("Stack Overflow\n");
        return;
    }
    s->top++;
    s->arr[s->top] = strdup(str); // Allocate space and copy string
}

char *pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Underflow\n");
        return NULL;
    }
    return s->arr[s->top--];
}

int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

void prefixToPostfix(char *exp)
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->size = MAX_SIZE;
    s->top = -1;
    s->arr = (char **)malloc(s->size * sizeof(char *));

    int len = strlen(exp);
    for (int i = len - 1; i >= 0; i--) // Traverse from end to start
    {
        if (!isOperator(exp[i]))
        {
            char temp[2] = {exp[i], '\0'};
            pushStr(s, temp); // Push operands as strings
        }
        else
        {
            char *pop1 = pop(s);
            char *pop2 = pop(s);

            char temp[MAX_SIZE];
            strcpy(temp, pop1);
            strcat(temp, pop2);
            strncat(temp, &exp[i], 1);

            pushStr(s, temp);
            free(pop1);
            free(pop2);
        }
    }

    char *result = pop(s);
    if (result != NULL)
    {
        printf("%s\n", result);
        free(result);
    }

    // Free allocated memory
    for (int j = 0; j <= s->top; j++)
    {
        free(s->arr[j]);
    }
    free(s->arr);
    free(s);
}

int main()
{
    char exp[MAX_SIZE];
    printf("Enter the Prefix Expression:\n");
    fgets(exp, MAX_SIZE, stdin);

    exp[strlen(exp) - 1] = '\0'; // Remove newline character

    printf("\nThe Postfix Expression:\n");
    prefixToPostfix(exp);

    return 0;
}
