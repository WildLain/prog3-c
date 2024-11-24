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

Fundstelle find(const char *s)
{
    ListEle *current = wordList;
    char *p1 = s;
    char *p2 = current->suchWort;
    while (isalpha(*p1))
    {
        if(*p1 == *p2)
        {
            int i;
            for(i = 1; i < strlen(current->suchWort); i++)
            {
                if(p1[i] == p2[i])  continue;
                else                break;
            }
            if(i == strlen(current->suchWort))
            {
                Fundstelle stelle;
                stelle.stelleImSuchstring = p1;
                stelle.ersetzung = current->suchWort;
            }
        }
    }
}

int main(int argc, char const *argv[])
{

    return 0;
}