#include <stdio.h>
#include <string.h>

#ifdef DE
    #define SPRUCH "Ohne Hoergeraet hoere ich nichts"
#endif
#ifdef NL
    #define SPRUCH "Zonder gehoorapparaat hoor ik niets"
#endif
#ifdef FI
    #define SPRUCH "Ilman kuuloleitta en kuula mitaeaen"
#endif
#ifdef SE
    #define SPRUCH "Jag hoer ingentin utan hoerselapparat"
#endif
#ifdef IT
    #define SPRUCH "Senza l'apparecchio d'autito non sento niente"
#endif
#ifdef CN
    #define SPRUCH "mei zhu ting qi jiu tingbujian"
#endif
#ifndef SPRUCH
    #define SPRUCH "Ilman kuuloleitta en kuula mitaeaen"
#endif

#ifndef SIZE
    #define SIZE 3
#endif
int main(int argc, char *argv[]) {
    enum {STRLEN = 256};
    int i;
    int width = (strlen(SPRUCH) + (2 * SIZE) + 2);
    char zeile[STRLEN];
    char leerzeile[STRLEN];
    char sterne[STRLEN];

    /*Leerzeile*/
    memset(sterne, '*', width);
    sterne[width] = '\0';
    
    /*Leerzeile*/
    sprintf(leerzeile, "*%*s*", width-2, " ");

    /*Textzeile*/
    sprintf(zeile, "*%*s%s%*s*", SIZE, "", SPRUCH, SIZE, "");

    printf("%s\n", sterne);
    for(i = 0; i < SIZE; i++) printf("%s\n", leerzeile);
    printf("%s\n", zeile);
    for(i = 0; i < SIZE; i++) printf("%s\n", leerzeile);
    printf("%s\n", sterne);
    return 0;
}