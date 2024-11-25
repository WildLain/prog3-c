#include "textfun.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

ListEle *wordList = NULL;

void addPair(const char *such, const char *ersatz)
{
    ListEle *newEle = malloc(sizeof(ListEle));
    assert(newEle);
    strncpy(newEle->suchWort, such, MAX_WORD_LEN);
    strncpy(newEle->ersetzungsWort, ersatz, MAX_WORD_LEN);
    newEle->next = wordList;
    wordList = newEle;
}

void clearList(void)
{
    ListEle *current = wordList;
    while (current)
    {
        ListEle *temp = current;
        current = current->next;
        free(current);
    }
    wordList = NULL;
}

Fundstelle *find(const char *s)
{
    Fundstelle *newF = NULL;
    ListEle *current = wordList;
    char *p1 = s, *p2;
    int i;
    while(current)
    {
        char *p2 = current->suchWort;
        int len = strlen(p2);
        while(*p1 != '\0')
        {
            if(*p1 == *p2)
            {
                for(i = 1; i < len; i++)
                {
                    char c1 = p1[i];
                    char c2 = p2[i];
                    if(c1 == c2)    continue;
                    else            break;
                }
                if(i == len)
                {
                    newF = malloc(sizeof(Fundstelle));
                    newF->stelleImSuchstring = p1;
                    strcpy(newF->ersetzung, current->ersetzungsWort);
                    return newF;
                }
            }
            p1++;
        }
        current = current->next;
    }    
    return newF;
}

int replaceAll(char *s)
{
    Fundstelle *gefunden = NULL;
    int i;
    char *pStart = s, *pEnde;
    char *subStr, res[200];
    do
    {
        gefunden = find(s);
        if(gefunden)
        {
            int lenB4 = gefunden->stelleImSuchstring - pStart;
            int wordLen = strlen(gefunden->ersetzung);

            strncpy(res, s, lenB4);
            res[lenB4] = '\0';

            strcat(res, gefunden->ersetzung);

            strcat(res, gefunden->stelleImSuchstring + wordLen);
        }
    } while (gefunden);
}

int main(int argc, char const *argv[])
{

    return 0;
}