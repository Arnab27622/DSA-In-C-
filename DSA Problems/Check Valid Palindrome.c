/* Given a string s, return true if the s can be palindrome after deleting at most one character from it.
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

int isPalindrome(char str[])
{
    int length = strlen(str);

    // Start from the two ends and compare characters
    for (int i = 0; i < length / 2; i++)
    {
        if (str[i] != str[length - i - 1])
        {
            return 0;
        }
    }

    return 1;
}

bool validPalindrome(char str[])
{
    int len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        // Create a modified string by removing the character at index i
        char modifiedStr[len];
        int k = 0;
        for (int j = 0; j < len; j++)
        {
            if (j != i)
            {
                modifiedStr[k++] = str[j];
            }
        }
        modifiedStr[k] = '\0';

        // Check if the modified string is a palindrome
        if (isPalindrome(modifiedStr))
        {
            return true;
        }
    }
    // None of the modifications resulted in a palindrome
    return false;
}

int main()
{
    char str[MAX_SIZE];
    printf("Enter a string: ");
    fgets(str, MAX_SIZE, stdin);

    str[strcspn(str, "\n")] = '\0';

    if (validPalindrome(str))
    {
        printf("%s is a valid palindrome\n", str);
    }
    else
    {
        printf("%s is not a valid palindrome\n", str);
    }

    return 0;
}