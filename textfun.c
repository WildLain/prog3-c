#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_WORD_LEN 25
#define MAX_LINE_LEN 200

typedef struct listEle
{
    char suchWort[MAX_WORD_LEN];
    char ersetzungsWort[MAX_WORD_LEN];
    struct listEle *next;
} ListEle;

typedef struct
{
    const char *stelleImSuchstring;
    ListEle *ersetzung;
} Fundstelle;

ListEle *wordList = NULL;

void addPair(const char *such, const char *ersatz)
{
    ListEle *newEle = malloc(sizeof(ListEle));
    assert(newEle);
    strncpy(newEle->suchWort, such, MAX_WORD_LEN - 1);
    newEle->suchWort[MAX_WORD_LEN - 1] = '\0';
    strncpy(newEle->ersetzungsWort, ersatz, MAX_WORD_LEN - 1);
    newEle->ersetzungsWort[MAX_WORD_LEN - 1] = '\0';
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
        free(temp);
    }
    wordList = NULL;
}

Fundstelle *find(const char *s)
{
    Fundstelle *newF = NULL;
    ListEle *current = wordList;
    while (current)
    {
        const char *p1 = s;
        const char *p2 = current->suchWort;
        int len = strlen(p2);
        while (*p1 != '\0')
        {
            if (strncmp(p1, p2, len) == 0)
            {
                newF = malloc(sizeof(Fundstelle));
                assert(newF);
                newF->stelleImSuchstring = p1;
                newF->ersetzung = current;
                return newF;
            }
            p1++;
        }
        current = current->next;
    }
    return NULL;
}

int replaceAll(char *s)
{
    int count = 0;
    Fundstelle *gefunden;
    char res[MAX_LINE_LEN];

    char const *p1 = s;

    while ((gefunden = find(p1)) != NULL)
    {
        int lenBefore = gefunden->stelleImSuchstring - s;
        int word1Len = strlen(gefunden->ersetzung->ersetzungsWort);
        int word2Len = strlen(gefunden->ersetzung->suchWort);

        strncpy(res, s, lenBefore);
        res[lenBefore] = '\0';

        strcat(res, gefunden->ersetzung->ersetzungsWort);
        strcat(res, gefunden->stelleImSuchstring + word2Len);

        strcpy(s, res);

        p1 = gefunden->stelleImSuchstring + word1Len;

        free(gefunden);
        count++;
    }
    printf("%s\n", s);
    return count;
}

int main(int argc, char *argv[])
{
    int i;
    char *orgStr, *such, *ersatz, *equalSign;
    char line[MAX_LINE_LEN];
    if (argc < 2)
    {
        printf("Keine Ersetzungen. Bitte Programm starten mit verbotenesWort=Ersetzung");
        assert(argc < 2);
    }
    else
    {
        for (i = 1; i < argc; i++)
        {
            orgStr = argv[i];
            equalSign = strstr(orgStr, "=");

            if (!equalSign)
            {
                printf("Formatierungsfehler. Bitte nochmal versuchen: verbotenesWort=Ersetzung");
                assert(!equalSign);
            }

            *equalSign = '\0';
            such = orgStr;
            ersatz = equalSign + 1;
            printf("Suche: %s\t Ersetze: %s\n", such, ersatz);
            addPair(such, ersatz);
        }
    }

    while (fgets(line, MAX_LINE_LEN, stdin) != NULL)
    {
        replaceAll(line);
    }
    return 0;
}