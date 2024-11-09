#include <stdio.h>
#include <string.h>

enum
{
    LINE_LENGTH = 100
};
char alph[] = "abcdefghijklmnopqrstuvwxyz";
char cryp[] = "wgsnqcdvmeyluzoabhrjfkxipt";
char crypt(char c, char src[], char dst[]);

char crypt(char c, char src[], char dst[])
{
    char line[LINE_LENGTH];
    char *p;
    int i;

    if (c >= 'a' && c <= 'z')
    {
        for (i = 0; i < strlen(alph); i++)
        {
            if (c == src[i])
            {
                p = dst + i;
                break;
            }
        }
        return *p;
    }
    else
    {
        return c;
    }
}

int main(int argc, char *argv[])
{
    char encrypt[] = "encrypt", decrypt[] = "decrypt";
    char input;

    if (argc != 2)
    {
        printf("Verwendung: %s encrypt/decrypt", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], encrypt) == 0)
    {
        while ((scanf("%c", &input) != EOF))
        {
            printf("%c", crypt(input, alph, cryp));
        }
    }
    else if (strcmp(argv[1], decrypt) == 0)
    {
        while ((scanf("%c", &input) != EOF))
        {
            printf("%c", crypt(input, cryp, alph));
        }
    }

    return 0;
}
