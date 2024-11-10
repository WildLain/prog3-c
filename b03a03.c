#include <stdio.h>
#include <string.h>
#include <ctype.h>

enum { slen = 100, rlen = 7};


void soundex(const char s[], char res[]) {
    /*char c = c - 'a' + 'A';*/
    int i, z, j = 1;
    char c;
    res[0] = toupper(s[0]);
    for(i = 1; i < strlen(s); i++) {
        z = 0;
        c = toupper(s[i]);

        switch(c) 
        {
            case 'B':
            case 'F':
            case 'P':
            case 'V':
                z = 1;
                break;
            case 'C':
            case 'G':
            case 'J':
            case 'K':
            case 'Q':
            case 'S':
            case 'X':
            case 'Z':
                z = 2;
                break;
            case 'D':
            case 'T':
                z = 3;
                break;
            case 'L':
                z = 4;
                break;
            case 'M':
            case 'N':
                z = 5;
                break;
            case 'R':
                z = 6;
                break;
            default:
                break;
        }
        if (z != 0) 
        {
            if((res[j-1] != z + '0') && j < 5) {
            res[j] = z + '0';
            j++;
            }
            else
            {
                res[j] = z + '0';
            }
        }
    }

    if(j < 5) 
    {
        for(;j <=5; j++)
        {
            res[j] = '0';
        }
    }
    res[6] = '\0';
    printf("%s\n", res);
}

int main(void) {
    char res[rlen] = {'0', '0', '0', '0', '0', '0'};
    char s[slen];

    while(scanf("%s", s) != EOF)  
    {
        soundex(s, res);
    }

    return 0;
}
