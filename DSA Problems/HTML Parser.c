// take a html tag as input and give the output of the text inside it with removing the leading and trailing whitespace

#include <stdio.h>
#include <string.h>

void Parse(char *html)
{
    int new = 0;
    int in = 0;
    for (int i = 0; i < strlen(html); i++)
    {
        if (html[i] == '<')
        {
            in = 1;
            continue;
        }
        else if (html[i] == '>')
        {
            in = 0;
            continue;
        }

        if (in == 0)
        {
            html[new ++] = html[i];
        }
    }

    html[new] = '\0';

    while (html[0] == ' ')
    {
        for (int i = 0; i < strlen(html); i++)
        {
            html[i] = html[i + 1];
        }
    }

    while (html[strlen(html) - 1] == ' ')
    {
        html[strlen(html) - 1] = '\0';
    }
}

int main()
{
    char html[100];
    printf("Enter the html tag: ");
    fgets(html, sizeof(html), stdin);

    html[strlen(html) - 1] = '\0';

    Parse(html);

    printf("The Parsed HTML is:\n");
    printf("~~%s~~", html);

    return 0;
}