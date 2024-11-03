#include <stdio.h>
#include <string.h>

enum {VEKLAENGE=20};

void printMyVec(int v[VEKLAENGE], int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("%6d\n", v[i]);
    }
}

void selectionSort(int v[VEKLAENGE], int n) {
    int i, j, min, tmp;
    for(i = 0; i < n-1; i++) {
        min = i;
        for(j = i+1; j < n; j++) {
            if(v[min] > v[j]) {
                min = j;
            }
        }
        if (min != i) {
            tmp = v[i];
            v[i] = v[min];
            v[min] = tmp;
        }
    }
}

int main (void) {
    char line[VEKLAENGE];
    int v[VEKLAENGE];
    int input, n = 0;
    while(fgets(line, VEKLAENGE, stdin) && n < VEKLAENGE) {
        if(sscanf(line, "%d", &input) == 1) {
            v[n] = input;
            n++;
        }
    }
   /*while(scanf("%d", &input) != EOF) {
        v[n] = input;
        n++;
    }*/
    selectionSort(v, n);
    printMyVec(v, n);
}
