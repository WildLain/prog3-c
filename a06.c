#include <stdio.h>

int main(void)
{
    int rotKey = 13;
    char input, output;
    while (scanf("%c", &input) != EOF)
    {
        if (input >= 'A' && input <= 'Z')
        {
            output = (input - 'A' + rotKey) % 26 + 'A';
            printf("%c", output);
        }
        else if (input >= 'a' && input <= 'z')
        {
            output = (input - 'a' + rotKey) % 26 + 'a';
            printf("%c", output);
        }
        else
        {
            output = input;
            printf("%c", output);
        }
    }
    fflush(stdout);
    return 0;
}
