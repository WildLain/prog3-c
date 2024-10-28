#include <stdio.h>

int i = 0, input;
int binaryVector[16];
unsigned int test;

void schreibBit(unsigned z) {
    do {
         binaryVector[i] = z % 2;
         z /= 2;
         i++;
    } while (z > 0);

    for (i -= 1;i>=0; i--) {
        printf("%d", binaryVector[i]);
    }
}

int main(void) {
    scanf("%u", &input);
    schreibBit(input);
    return 0;
}
