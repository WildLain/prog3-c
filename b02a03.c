#include <stdio.h>
enum {VEKLAENGE=20};
int  i, j, n, min, tmp, v[VEKLAENGE], v2[VEKLAENGE];

void printMyVec(void) {
    for(i = 0; i < n; i++) {
        printf("%6d\n", v[j]);
    }
}

void selectionSort(int v[VEKLAENGE]) {
    for(i = 0; i < n-1; i++) {
        min = i;
        for(j = i+1; j < n; j++) {
            if(v[min] > v[j]) {
                min = j;
                tmp = v[i];
                v[i] = v[min];
                v[min] = tmp;
            }
        }
    }
}

int main (void) {
    int input;
    n = 0;
    while(scanf("%d", &input) != EOF) {
        v[n] = input;
        n++;
    }
    printMyVec();
    selectionSort(v[VEKLAENGE]);
    printMyVec();
}
