#include <stdio.h>
#include <string.h>

enum
{
    VEKLAENGE = 20
};

void printMyVec(int v[VEKLAENGE], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%6d\n", v[i]);
    }
}

void selectionSort(int v[VEKLAENGE], int n)
{
    int i, j, min, tmp;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (v[min] > v[j])
            {
                min = j;
            }
        }
        if (min != i)
        {
            tmp = v[i];
            v[i] = v[min];
            v[min] = tmp;
        }
    }
}

int main(void)
{
    char line[VEKLAENGE];
    int v[VEKLAENGE];
    int input, n = 0;
    while (scanf("%d", &input) != EOF)
    {
        v[n] = input;
        n++;
    }
    selectionSort(v, n);
    printMyVec(v, n);

    /*Testen Sie bitte, wie sich printf() verhält, 
    wenn Sie Zahlen mit mehr als sechs Stellen eingeben 
    (also die Ausgabe-Feldbreite überschritten wird)
    
    -Die Zahl wird einfach über die Rechtsbündige Grenze hinaus dargestellt.
    
    Was müssten Sie ändern, um bei der Ausgabe der Zahlen anstelle der führenden 
    Auffüll-Leerzeichen links mit Nullen auffüllen zu lassen (bitte ausprobieren)?

    printf("%06d\n", v[i]);

    also eine "0" vor die Anzahl der aufzufüllenden Stellen hinschreiben.
    */
}
