#include <stdio.h>
#include <string.h>

int i, shift, len;
unsigned int input, output, a, b, rAnd, rOr, rXor;
char bStr[16];

void schreibBit(unsigned z)
{
    for (i=15 ; i >= 0 ; i--) {
        printf("%d", (z & 1<<i) != 0);
    }
    printf("\n");
}

unsigned int liesBit(void) {
    output = 0;
    scanf("%s", bStr);
    len = strlen(bStr);
    for(i = 0; i < len; i++) {
        output *= 2;
        if(bStr[i] == '1') {
            output++;
        }
    }
    if(len < 16) {
        shift = 15 - len +1;
        output << shift;
    }
    /*printf("%d\n", output);*/
    return output;
}

int main(void)
{

    a = liesBit();
    b = liesBit();

    printf("a & b = ");
    schreibBit(a & b);
    printf("a | b = ");
    schreibBit(a | b);
    printf("a ^ b = ");
    schreibBit(a ^ b);

    return 0;
}
