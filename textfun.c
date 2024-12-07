#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_WORD_LEN 25
#define MAX_LINE_LEN 255

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
    ListEle *current = NULL;
    assert(newEle);
    strncpy(newEle->suchWort, such, MAX_WORD_LEN - 1);
    newEle->suchWort[MAX_WORD_LEN - 1] = '\0';
    strncpy(newEle->ersetzungsWort, ersatz, MAX_WORD_LEN - 1);
    newEle->ersetzungsWort[MAX_WORD_LEN - 1] = '\0';


    if(wordList == NULL) {
        newEle->next = NULL;
        wordList = newEle;
    }
    else {
        current = wordList;
        while(current->next) {
            current = current->next;
        }
        current->next = newEle;
    }

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
    int i;
    char a, b;
    if(!current) EXIT_FAILURE;
    while (current)
    {
        const char *p1 = s;
        const char *p2 = current->suchWort;
        int len = strlen(p2);
        while (*p1 != '\0')
        {
            i = 0;
            a = *p1;
            b = *p2;
            if(a == b)
            {
                for(i = 1; i < len; i++) {
                    a = p1[i];
                    b = p2[i];
                    if(a == b)  continue;
                    else        break;
                }
            }
            if(i == len) {
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
    Fundstelle *gefunden = NULL;
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

        p1 = s + lenBefore + word1Len;

        free(gefunden);
        count++;
    }
    printf("%s\n", s);
    return count;
}

void saveFile(void) {
    FILE *save; /* FILE-Zeiger zum Zugriff auf Datei*/
    ListEle *current; /*aktuelles Listen-Element*/

    current = wordList;
    if(current == NULL) {
        printf("Fehler beim Speichern: Wortliste ist leer.\n");
        return;
    }
    save = fopen("glogomir.txt", "w");
    if(!save) {
        fprintf(stderr, "Fehler beim schreiben auf glogomir.txt\n");
        perror("Details");
        return;
    } else {
        while(current) {
            /*schreiben der Wortpaare in die Save-File*/
            fprintf(save, "%s=%s\n", current->suchWort, current->ersetzungsWort);
            current = current->next;
        }
    }
}

void loadFromFile(void) {
    FILE *load;
    char line[MAX_LINE_LEN];
    char such[MAX_WORD_LEN], ersatz[MAX_WORD_LEN];

    /*Datei im Lesemodus öffnen*/
    load = fopen("glogomir.txt", "r");
    if(!load)  {
        fprintf(stderr, "glogomir.txt nicht gefunden.\n");
        return;
    }

    /*Zeilenweise Datei durchgehen und der Struktur hinzufügen*/
    while(fgets(line, MAX_LINE_LEN, load) != NULL) {
        /*
        %24[^=]     Liest bis zu 24 Zeichen ein, die keine Gleichheitszeichen (=)
        %24[^\n]    Liest 24 Zeichen bis zum/ohne Zeilenumbruch ein
        */
        if(sscanf(line, "%24[^=]=%24[^\n]", such, ersatz) == 2 ) {
            addPair(such, ersatz);
        } else {
            fprintf(stderr, "Fehler beim einlesen.\n");
            return;
        }
    }
    fclose(load);
}
