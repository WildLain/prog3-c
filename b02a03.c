#include <stdio.h>
enum {VEKLAENGE=20};
int  i, j, n, min, max, v[VEKLAENGE], v2[VEKLAENGE];

void printMyVec(void) {
    for(j = 0; j < i; j++) {
        printf("%6d\n", v[j]);
    }
}

void selectionSort(int v[VEKLAENGE]) {
    for(n = 0; n < i-2; n++) {
        
    }
}

int main (void) {
    int input;
    i = 0;
    while(scanf("%d", &input) != EOF) {
        v[i] = input;
        i++;
    }
    printMyVec();
}
