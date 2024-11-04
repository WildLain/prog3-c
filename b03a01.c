#include <stdio.h>
int main(void)
{
    char *a = NULL;
    int *b = NULL, v[17];
    double *c = NULL;
    printf("\n%ld %ld %ld\n%ld %ld %ld\n\n",
           (long)(a + 1), (long)(b + 1), (long)(c + 1),
           (long)(a + 5), (long)(b + 7), (long)(c + 17));
    printf("%p %p %p\n", (void *)v, (void *)&v[0], (void *)&v[10]);
    return 0;
}

/*
char *a = NULL      pointer a des Typs char zeigt auf NULL
int  *b = NULL      pointer b des Typs int zeigt auf NULL
int v[17]           deklaration eines vektors der Länge 17 und des Typs int
double *c           pointer c des Typs double zeigt auf NULL

printf()            gibt auf der Konsole aus
\n                  new line
%ld                 long int
(long)              explizites Casten auf long int

"\n%ld %ld %ld\n%ld %ld %ld\n\n"    Gibt 2 x 3 long int Werte aus

a + 1               erhöht die Adresse um 1 Byte (Größe von Char)
b + 1               erhöht die Adresse um 4 Byte (Größe von int)
c + 1               erhöht die Adresse um 8 Byte (Größe von Double)

a + 5               erhöht die Adresse um 5   Bytes (5 * Char)
b + 7               erhöht die Adresse um 28  Bytes (7 * int)
c + 17              erhöht die Adresse um 136 Bytes (17* Double)

Ausgabe             1 4 8
                    5 28 136

"%p %p %p\n"        Gibt 3 Adressen aus
(void*)v            Die Adresse von v
(void*)&v[0]        Die Adresse des ersten Elements von v
(void*)&v[10]       Die Adresse des elften Elements von v

Ausgabe             0x7ff7bfefee70 0x7ff7bfefee70 0x7ff7bfefee98

Die ersten beiden Ausgaben von den Adressen sind identisch.
D.h. der Pointer von v zeigt auf das erste Element des Vektors.
*/