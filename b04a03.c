#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *replace(char *line, char *word)
{
    char *p = strstr(line, word);
    int i;
    if (p != NULL)
    {
        for (i = 1; i < strlen(word); i++)
        {
            printf("%s", p);
            p[i] = '*';
        }
    }
    printf("%s", line);
    return line;
}

int main(int argc, char const *argv[])
{
    enum
    {
        MAXLEN = 200
    };
    char input[MAXLEN], word[80];
    int i;

    /*userInput*/
    while (fgets(input, MAXLEN, stdin) != NULL)
    {
        size_t len = strlen(input);
        if(input[len-1] == '\n')
        {
            input[len-1] = '\0';
        }
        for (i = 1; i < argc; i++)
        {
            strcpy(word, argv[i]);
            strcpy(input, replace(input, word));
        }
    }
    return 0;
}
