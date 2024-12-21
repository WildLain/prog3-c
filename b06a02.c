#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct {
    char codezeichen;
    int anzahl;
} Ele;

int compare(const void *e1, const void *e2) {

    /*Wenn anzahl gleich ist, sortiere nach nach Codezeichen*/
    if(((Ele*)e1)->anzahl != ((Ele*)e2)->anzahl) {
        return ((Ele*)e2)->anzahl - ((Ele*)e1)->anzahl;
    }
    return ((Ele*) e1)->codezeichen - ((Ele*) e2)->codezeichen;
}

void analyze(FILE *origin) {
    enum {ALPHALEN = 26};
    Ele tabelle[ALPHALEN];
    char ersetzungen[ALPHALEN];
    int i, ch;
    char rangfolge[] = "eniastruhdlcmogkwbzfvpjxyq";

    /*Tabelle erstellen*/
    for(i = 0; i < ALPHALEN; i++) {
        tabelle[i].codezeichen = 'a' + i;
        tabelle[i].anzahl = 0;
    }

    /*Buchstaben zählen*/
    while((ch = fgetc(origin)) != EOF) {
        if(isalpha(ch)) {
            tabelle[ch - 'a'].anzahl++;
        }
    }
    /*tabelle sortieren*/
    qsort(tabelle, ALPHALEN, sizeof(Ele), compare);

    /*Debug, Hauefigkeitentabelle ausgeben*/
    for (i = 0; i < ALPHALEN; i++) {
    printf("Buchstabe: %c, Häufigkeit: %d\n", tabelle[i].codezeichen, tabelle[i].anzahl);
}

    /*auf Entschlüsselungstabelle abbilden*/
    for(i = 0; i < ALPHALEN; i++) {
        /*Stelle im eigentlichen Alphabet: tabelle[i].codezeichen - 'a', 
        ASCII-zeichen minus dem eigentlichen Zeichen gibt Pos auf dem Index zurück*/
        ersetzungen[tabelle[i].codezeichen - 'a'] = rangfolge[i];
    }

    rewind(origin);
    /*Entschlüsseln*/
    while((ch = fgetc(origin)) != EOF) {
        if(isalpha(ch)) {
            printf("%c", ersetzungen[ch-'a']);   
        }
        else {
            printf("%c", ch);
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *stream;
    /*argv[1] = "raeuberbriefenc.sec";*/
    stream = fopen(argv[1], "r");
    if (stream == NULL) {
        fprintf(stderr, "Fehler beim Öffnen von %s\n", argv[1]);
    } else {
        analyze(stream);
        fclose(stream);
    }
    return 0;
}