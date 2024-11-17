#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum
{
    STRLEN = 25
};

struct listnode
{
    char inhalt[STRLEN];
    struct listnode *prev;
    struct listnode *next;
};
typedef struct listnode nodep;

void printList(nodep *lst)
{
    printf("\n");
    while (lst != NULL)
    {
        printf("%p\t%s\n", &lst, lst->inhalt);
        lst = lst->next;
    }
    printf("\n");
}

nodep *insertAt(nodep *lst, int pos, char *inhalt)
{
    int i;
    nodep *current = lst;
    nodep *newNode = malloc(sizeof(nodep));
    strncpy(newNode->inhalt, inhalt, STRLEN);

    if (lst == NULL)
    {
        lst = newNode;
        lst->prev = NULL;
        lst->next = NULL;
        return lst;
    }
    else if (pos == -1)
    {
        current = lst;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
        return lst;
    }
    else
    {

        for (i = pos; i > 1; i--)
        {
            if (current->next == NULL)
                break;

            current = current->next;
        }
        if (current->next == NULL)
        {
            newNode->next = NULL;
        }
        else
        {
            newNode->next = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
        current->next->prev = newNode;
        current = newNode;
    }
    return lst;
}

int main(void)
{
    nodep *lst = NULL;

    lst = insertAt(lst, 0, "Hose");
    lst = insertAt(lst, 1, "Jacke");
    lst = insertAt(lst, -1, "Sonnenbrille");
    lst = insertAt(lst, 2, "T-Shirt");
    lst = insertAt(lst, 3, "Muetze");
    lst = insertAt(lst, 0, "Pullover");
    lst = insertAt(lst, -1, "Schal");
    lst = insertAt(lst, 2, "Handschuhe");


    printList(lst);
    return 0;
}