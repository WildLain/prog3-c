#include <stdio.h>
#include <string.h>

enum {LINE_LENGTH=100};
const char alph[] = "abcdefghijklmnopqrstuvwxyz";
const char cryp[] = "wgsnqcdvmeyluzoabhrjfkxipt";

char encryptF(void) {
    char line[LINE_LENGTH], input;
    char *p, c;
    int i;
    
    for(i = 0; i < 26; i++) {
        if(c == alph[i]) {
            p = cryp + i;
            break;
        }
    }

    return *p;
}

void decryptF(void) {
    char line[LINE_LENGTH];
    
}

int main(int argc, char *argv[]) {
    char line[LINE_LENGTH];
    char input, encrypt[] = "encrypt", decrypt[] = "decrypt";

    if(argc != 2) {
        printf("Verwendung: %s encrypt/decrypt", argv[0]);
        return 1;
    }

    if(strcmp(argv[1], encrypt) == 0) {
        encryptF();
    }
    else if(strcmp(argv[1], decrypt) == 0) {
        decryptF();
    }

    return 0;
}