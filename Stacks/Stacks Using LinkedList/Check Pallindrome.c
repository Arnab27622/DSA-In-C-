#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

typedef struct Stack
{
    char data;
    struct Stack *next;
} Stack;

int IsEmpty(Stack *top)
{
    if (top == NULL)
    {
        return 1;
    }

    return 0;
}

Stack *push(Stack *top, char data)
{
    Stack *ptr = (Stack *)malloc(sizeof(Stack));
    if (ptr == NULL)
    {
        printf("Stack Overflow can't push %c", data);
        exit(1);
    }
    else
    {
        ptr->data = data;
        ptr->next = NULL;

        ptr->next = top;
        top = ptr;
        return top;
    }
}

char pop(Stack *top)
{
    if (IsEmpty(top))
    {
        printf("Stack Underflow");
        exit(1);
    }
    else
    {
        Stack *ptr = top;
        char data = ptr->data;
        top = top->next;
        free(ptr);
        return data;
    }
}

void checkPalindrome(char *str)
{
    Stack *top = NULL;
    int i = 0;

    while (str[i] != '\0' && str[i] != '\n')
    {
        top = push(top, str[i]);
        i++;
    }

    while (str[i])
    {
        if (IsEmpty(top) || str[i] != pop(top))
        {
            printf("The Word isn't a Palindrome");
            exit(1);
        }
        i++;
    }
    if (IsEmpty(top))
    {
        printf("The Word is a Palindrome");
    }
    else
    {
        printf("The Word isn't a Palindrome");
    }
}

int main()
{
    char str[MAX_SIZE];
    printf("Enter the Word: ");
    fgets(str, MAX_SIZE, stdin);

    // Remove newline character from input string
    str[strcspn(str, "\n")] = '\0';

    checkPalindrome(str);
    return 0;
}