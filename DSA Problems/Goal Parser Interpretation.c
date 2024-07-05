/* You own a Goal Parser that can interpret a string command. The command consists of an alphabet of "G", "()" and/or "(al)" in some order.
   The Goal Parser will interpret "G" as the string "G", "()" as the string "o", and "(al)" as the string "al".
   The interpreted strings are then concatenated in the original order
*/

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

void Goal_parser(char str[])
{
    int i = 0, j = 0;
    while (str[i] != '\0')
    {
        if (str[i] == 'G')
        {
            str[j++] = 'G';
            i++;
        }
        else if (str[i] == '(' && str[i + 1] == ')')
        {
            str[j++] = 'o';
            i += 2;
        }
        else if (str[i] == '(' && str[i + 1] == 'a')
        {
            str[j++] = 'a';
            i += 2;
        }
        else if (str[i] == 'l' && str[i + 1] == ')')
        {
            str[j++] = 'l';
            i += 2;
        }
        else if (str[i] == ' ')
        {
            i++;
        }
        else
        {
            i++;
        }
    }

    str[j] = '\0';

    printf("The Result:\n");
    for (i = 0; str[i] != '\0'; i++)
    {
        printf("%c", str[i]);
    }
}

int main()
{
    char str[MAX_SIZE];
    printf("Enter the string:\n");
    fgets(str, MAX_SIZE, stdin);

    str[strlen(str) - 1] = '\0';

    Goal_parser(str);

    return 0;
}