#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void replace(char *line, char *word)
{
    char *p = line;
    char *p2 = word;
    int i;
    while(*p != '\0')
    {
        if(*p == *p2)
        {
            for(i = 0; i < strlen(word); i++)
            {
                char c1 = p[i];
                char c2 = p2[i];
                if(c1 == c2)    continue;
                else            break;
            }
             if(i == strlen(word))
            {
                for(i = 1; i < strlen(word); i++)                
                    {p[i] = '*';}
                
            }   
        }
        p++;
    }
}

int main(int argc, char const *argv[])
{
    enum    { MAXLEN = 200 };
    char input[MAXLEN], word[80];
    int i;
    while (fgets(input, MAXLEN, stdin) != NULL)
    {
        int len = strlen(input);
        if (input[len - 1] == '\n')
        {
            input[len - 1] = '\0';
            for (i = 1; i < argc; i++)
            {
                strcpy(word, argv[i]);
                replace(input, word);
            }
            printf("%s\n", input);
        }
    }
    return 0;
}
