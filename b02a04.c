#include <stdio.h>
#include <string.h>

enum
{
    LINE_LENGTH = 80,
    SQUARE_LENGTH
};

int readInput(void)
{
    char line[LINE_LENGTH];
    int input = -1;
    printf("Bitte gib eine ungerade Ganzzahl ein: ");
    while (fgets(line, LINE_LENGTH, stdin))
    {
        if (sscanf(line, "%d", &input) == 1 && input % 2 == 1)
        {
            break;
        };
        printf("Fehleingabe: %s. Neuer Versuch: ", line);
    }
    printf("Eingabe : %d \n", input);
    return input;
}

void printSquare(int square[SQUARE_LENGTH][SQUARE_LENGTH], int n)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        printf("\n");
        for (j = 0; j < n; j++)
        {
            printf("%3d", square[i][j]);
        }
    }
    printf("\n");
}

void magicSquare(int n)
{
    int square[SQUARE_LENGTH][SQUARE_LENGTH] = {0};
    int row = n / 2, newR,
        column = n / 2, newC,
        i;

    for(i = 1; i <= n*n; i++) {
        square[row][column] = i;
        newR = (row + 1 + n) % n;
        newC = (column - 1 + n) % n;

        if(square[newR][newC] != 0) {
            row = (row + 2 + n) % n;
        }
        else {
            row = newR;
            column = newC;
        }
    }
    printSquare(square, n);
}

int main(void)
{
    int n, middle;
    n = readInput();
    magicSquare(n);
    return 0;
}
