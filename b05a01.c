#include <stdio.h>

enum { MAXLEN = 80}

union num {
    double a;
    unsigned int b,c;
} kitty;


int main(void)
{
    char line[MAXLEN];
    while(fgets(line, MAXLEN, stdin))
    {
        kitty = malloc(sizeof(union num));
        if(sscanf(line, "%lf", &kitty)== 1) {break;}
        printf("Fehler beim lesen. Bitte nochmal versuchen: ");
    }

    return 0;
}