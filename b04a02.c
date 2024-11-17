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
    int pos;
    struct listnode *prev;
    struct listnode *next;
};
typedef struct listnode nodep;

void printList(nodep *lst)
{
    printf("\n");
    while (lst != NULL)
    {
        printf("%d\t%p\t%s\n",lst->pos, &lst, lst->inhalt);
        lst = lst->next;
    }
    printf("\n");
}

nodep *insertAt(nodep *lst, int pos, char *inhalt)
{
    nodep *current = lst;
    nodep *newNode = NULL;
    int i;
    if (lst == NULL)
    {
        lst = malloc(sizeof(nodep));
        strncpy(lst->inhalt, inhalt, STRLEN);
        lst->pos = 0;
        lst->prev = NULL;
        lst->next = NULL;
    }
    /*else if (lst->pos - pos < 0)
    {
        while (current->next != NULL)
        {
            current = current->next;
        }
        newNode = malloc(sizeof(nodep));
        strncpy(newNode->inhalt, inhalt, STRLEN);
        current->next = newNode;
        newNode->prev = current;
        newNode->next = NULL;
    }*/
    else
    {
        newNode = malloc(sizeof(nodep));
        strncpy(newNode->inhalt, inhalt, STRLEN);

        if(pos < 0)
        {
            current = lst;
            while(current->next != NULL)
            {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
            newNode->pos = current->pos + 1;
            return lst;
        }
        for(i = pos; i > 0; i--)
        {
            if(current->next == NULL)
            break;

            current = current->next;
        }
        if(current->next == NULL)
        {
            newNode->next = NULL;
        }
        else
        {
            newNode->next = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
        newNode->pos = pos;
        current = newNode;
        while (current->next != NULL)
        {
            current = current->next;
            current->pos++;
        }
    }
    return lst;
}

int main(void)
{
    nodep *lst = NULL;

    lst = insertAt(lst, 0,  "Hose");
    lst = insertAt(lst, 1,  "Jacke");
    lst = insertAt(lst, 2,  "T-Shirt");
    lst = insertAt(lst, 3,  "Muetze");
    lst = insertAt(lst, -1, "Sonnenbrille");
    lst = insertAt(lst, 2,  "Handschuhe");

    printList(lst);
    return 0;
}