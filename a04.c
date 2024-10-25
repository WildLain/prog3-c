#include <stdio.h>

int main(void) {
    int zahl, i, C=100, L=50, X=10, V=5, I=1;
    scanf("%d", &zahl);

    while (zahl >= C) {
        printf("C");
        zahl -= C;
    }
    while(zahl >= L) {
        printf("L");
        zahl -= L;
    }
    while (zahl >= X) {
        printf("X");
        zahl -= X;
    }

    while (zahl >= I) {
        printf("I");
        zahl -= I;
    }
    printf("\n");    
}
