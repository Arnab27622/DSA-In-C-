/* Given two strings a and b consisting of lowercase characters.
   Check whether two given strings are an anagram of each other or not.
*/

#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

// int isAnagram(char str1[], char str2[]) // I made this one and it's correct
// {
//     int len1 = strlen(str1);
//     int len2 = strlen(str2);

//     if (len1 != len2)
//     {
//         return 0;
//     }

//     int i = 0, j = 0;
//     while (str1[i] != '\0')
//     {
//         for (j = 0; j < len2 - 1; j++)
//         {
//             if (str1[i] == str2[j])
//             {
//                 break;
//             }
//         }
//         if (str1[i] != str2[j])
//         {
//             return 0;
//         }

//         i++;
//     }

//     return 1;
// }

int isAnagram(char str1[], char str2[])
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 != len2)
    {
        return 0; // Different lengths, not anagrams
    }

    for (int i = 0; i < len1 - 1; i++) // Adjust the loop condition to avoid comparing newline character
    {
        int found = 0;

        for (int j = 0; j < len2 - 1; j++) // Adjust the loop condition to avoid comparing newline character
        {
            if (str1[i] == str2[j])
            {
                found = 1;
                break;
            }
        }

        if (!found)
        {
            return 0; // Characters are not matching, not an anagram
        }
    }

    return 1; // All characters matched, anagrams
}

int main()
{
    char str1[MAX_SIZE];
    char str2[MAX_SIZE];

    printf("Enter the first string:\n");
    fgets(str1, MAX_SIZE, stdin);

    str1[strcspn(str1, "\n")] = '\0';
    printf("Enter the second string:\n");
    fgets(str2, MAX_SIZE, stdin);

    str2[strcspn(str2, "\n")] = '\0';

    if (isAnagram(str1, str2))
    {
        printf("The strings are anagram.");
    }
    else
    {
        printf("The strings are not anagram.");
    }

    return 0;
}