#include <stdio.h>
#include <string.h>

union num {
    double d;
    unsigned int ui[2];
} value;

void printBinary(unsigned int z)
{
    int i;
    for(i = 31; i >= 0; i--)
    {
        printf("%d", (z >> i) & 1);
    }
}

int main(int argc, char *argv[])
{
    double input;
    /*char cinput[] = "3.5717178E-12";
    printf("Zahl:\t%s\n", cinput);*/

    if(sscanf(argv[1], "%lf", &input) == 0) {
        printf("Einlesen nicht geklappt.");
        return 1;
    }

    value.d = input;

    printBinary(value.ui[1]);
    printBinary(value.ui[0]);
    printf("\n");
    return 0;
}