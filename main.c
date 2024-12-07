#include "textfun.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>

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
        line[MAX_LINE_LEN-1] = '\0'; 
        replaceAll(line);
    }
    saveFile();
    clearList();
    return 0;
}

/*int main(void) {
    char line[200] = "Der Glogomir hat mein Haus abgenommen.";
    
    addPair("Haus", "Unterkunft");
    addPair("Glogomir", "Freund");

    printf("Ersetzungen durchgeführt: %d\n", replaceAll(line));
    
    printf("Ergebnis: %s\n", line);

    clearList();
    
    return 0;
}*/

