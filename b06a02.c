#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define ALPHABET_SIZE  26

typedef struct {
    char codezeichen;
    int anzahl;
} Ele;

/* Vergleichsfunktion für qsort */
int compare(const void *a, const void *b) {
    Ele *eleA = (Ele *)a;
    Ele *eleB = (Ele *)b;

    /* Sortiere zuerst nach absteigender Hauefigkeit */
    if(eleB->anzahl != eleA->anzahl) {
        return eleB->anzahl - eleA->anzahl;
    }

    /* Bei gleicher Häufigkeit nach aufsteigendem Zeichenwert */
    return eleA->codezeichen - eleB->codezeichen;
}

void analyzeHauefigkeit(FILE *file, Ele *haeufigkeiten) {
    int ch, i;

    /* initialisiere die Hauefigkeitsstruktur */
    for (i = 0; i < ALPHABET_SIZE; i++) {
        haeufigkeiten[i].codezeichen = 'a' + i;
        haeufigkeiten[i].anzahl = 0;
    }

    /* Zähle die Buchstabenhäufigkeiten */
    while((ch = fgetc(file)) != EOF) {
        if(isalpha(ch)) {
            haeufigkeiten[ch - 'a'].anzahl++;
        }
    }    
}

/* Funktion zur Entschlüsselung des Textes */
void entschluesseln(FILE *file, Ele *haeufigkeiten, const char *klartextReihenfolge) {
    char ersetzung[ALPHABET_SIZE];
    int ch, i;

    /* Erstelle die Zuordungstabelle basieren auf der Klartext-Reihenfolge */
    for (i= 0; i < ALPHABET_SIZE; i++) {
        ersetzung[haeufigkeiten[i].codezeichen - 'a'] = klartextReihenfolge[i];
    }
}