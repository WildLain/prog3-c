#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct {
    char codezeichen;
    int anzahl;
} Ele;

int compare(const void *e1, const void *e2) {
    Ele *eleA = e1;
    Ele *eleB = e2;

    /*Wenn anzahl gleich ist, soritere nach nach Codezeichen*/
    if(eleA->anzahl == eleB->anzahl) {
        return ((Ele*) e1)->codezeichen - ((Ele*) e2)->codezeichen;
    } else {
    /*Sonst nach Anzahl sortieren*/
        return ((Ele*)e1)->anzahl - ((Ele*)e2)->anzahl;
    }
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

    /*auf Entschlüsselungstabelle abbilden*/
    for(i = 0; i < ALPHALEN; i++) {
    }

    /*Entschlüsseln*/
    while((ch = fgetc(origin)) != EOF) {
        if(isalpha(ch)) {
            
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *org = fopen("raeuberbriefenc.sec", "r");
    analyze(org);
    return 0;
}