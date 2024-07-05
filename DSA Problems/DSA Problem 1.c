// Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

void reverseLetters(char str[])
{
    int len = strlen(str);
    int start = 0;

    for (int i = 0; i <= len; i++)
    {
        if (str[i] == ' ' || str[i] == '\0')
        {
            int end = i - 1;
            while (start < end)
            {
                char temp = str[start];
                str[start] = str[end];
                str[end] = temp;
                start++;
                end--;
            }
            start = i + 1;
        }
    }
}

int main()
{
    char str[MAX_SIZE];
    printf("Enter a string:\n");
    fgets(str, sizeof(str), stdin);

    // Remove newline character if present
    if (str[strlen(str) - 1] == '\n')
    {
        str[strlen(str) - 1] = '\0';
    }

    reverseLetters(str);

    printf("The reversed string:\n");
    puts(str);

    return 0;
}