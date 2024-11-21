#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *replace(char *line, char *word)
{
    char *p = line;
    char *p2 = word;
    int i;
    while(*p != '\n')
    {
        if(*p == *p2)
        {
            for(i = 0; i < strlen(word); i++)
            {
                p = p + i;
                p2 = p2 + i;
                if(*p == *p2)
                {
                    continue;
                }
                else
                {
                    break;
                }
            }
            if(i == strlen(word)-1)
            {
                p = p - strlen(word)-1;
                while(isalpha(*p) != 0)
                {
                    *p = '*';
                    p++;
                }
            }   
        }
        p++;
    }

    /*char *p = strstr(line, word);
    int i;
    if (p != NULL)
    {

        for (i = 1; i < strlen(word); i++)
        {
            p[i] = '*';
        }
    }*/
    return line;
}

int main(int argc, char const *argv[])
{
    char input[] = "Liebe Tante, unser Elend unter Glogomir ist unbeschreibbar.";
    char word[] = "Elend";

    replace(input, word);
    printf("%s", input);

    /*enum
    {
        MAXLEN = 200
    };
    char input[MAXLEN], word[80];
    int i;

    
    while (fgets(input, MAXLEN, stdin) != NULL)
    {
        size_t len = strlen(input);
        if (input[len - 1] == '\n')
        {
            input[len - 1] = '\0';
            for (i = 1; i < argc; i++)
            {
                strcpy(word, argv[i]);
                strcpy(input, replace(input, word));
            }
            printf("\n%s\n", input);
            printf("\n");
        }
    }*/
    return 0;
}
