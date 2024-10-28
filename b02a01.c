#include <stdio.h>

long double x, w, new_w, abstand;
int main(void)
{
    scanf("%Lf", &x);
    w = (x + 1) / 2;
    do
    {
        new_w = (w + (x / w)) / 2;
        abstand = w - new_w;
        w = new_w;
    } while (abstand > 1e-7L);

    printf("%Lg \n", w);
    return 0;
}

