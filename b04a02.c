#include <stdio.h>
#include <stdlib.h>

struct listnode {
    struct listnode *prev;
    struct listnode *next;

};
typedef struct listnode nodep;

void printList(nodep lst) {
    while(lst->next != NULL)
    {

    }
}

int main(void)
{
    return 0;
}