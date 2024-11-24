#include <stdio.h>
#include <string.h>
int multipliziere(int x, int y)
{
    return x * y;
}

int addiere(int x, int y)
{
    return x + y;
}

int sortiere(void)
{
    return 0;
}

int main(void)
{
    int (*verf)(int, int);
    char op[10], input[10];
    int x, y, res;

    printf("Verfügbare Befehle\nadd\tmult\tsort\n");
    while (scanf("%s", op) != EOF)
    {
        if (strcmp(op, "add") == 0)
        {
            verf = addiere;
            break;
        }
        else if (strcmp(op, "mult") == 0)
        {
            verf = multipliziere;
            break;
        }
        else if(strcmp(op, "sort") == 0)
        {
            verf = sortiere;
        }
        else
        {
            printf("Fehler, bitte gültigen Befehl eingeben: ");
        }
    }

    printf("Bitte gib x und y getrennt durch ein Komma ein: ");
    while(scanf("%s", input) != EOF)
    {
        if(sscanf(input, "%d,%d", &x, &y) == 2)
        {
            res = verf(x, y);
            printf("Ergebnis: %d\n", res);
            break;
        }
        printf("Fehler bei Eingabe. Neuversuch: ");
    }
    return 0;
}
