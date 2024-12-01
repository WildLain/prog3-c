#include "textfun.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>

int main(void) {
    char line[200] = "Der Glogomir hat mein Haus abgenommen.";
    
    addPair("Haus", "Unterkunft");
    addPair("Glogomir", "Freund");

    printf("Ersetzungen durchgeführt: %d\n", replaceAll(line));
    
    printf("Ergebnis: %s\n", line);

    clearList();
    
    return 0;
}
