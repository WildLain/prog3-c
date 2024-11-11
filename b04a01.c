#include <stdio.h>
#include <string.h>

enum
{
    STRLEN = 25
};

struct nd
{
    char name[STRLEN];
    struct nd *next;
} *ogKitty, *nextKitty;

typedef struct nd Node;

int main(void)
{
    int i = 0, j = 0;
    char input[STRLEN];

    scanf("%s", &input);
    ogKitty = malloc(sizeof(Node));
    strcopy(ogKitty->name, input);
    

    while (scanf("%s", &input) != EOF)
    {
        i++;
        nextKitty = calloc(i, sizeof(Node));
        if (!nextKitty)
            return 1;
        strcpy(nextKitty->name, input);
    };

    return 0;
}
