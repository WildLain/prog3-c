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
        printf("%p\t%s\n", (void *)lst, lst->inhalt);
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
    else if (pos == 0)
    {
        current->prev = newNode;
        newNode->next = current;
        newNode->prev = NULL;
        return newNode;
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

        for (i = 1; i < pos; i++)
        {
            if (current->next == NULL)
            {
                newNode->next = NULL;
                break;
            }
            current = current->next;
        }
        if (current->next != NULL)
        {
            newNode->next = current->next;
        }
        newNode->prev = current;
        current->next = newNode;
    }
    return lst;
}

nodep *deleteAt(nodep *lst, int pos)
{
    nodep *current = lst;
    int i;
    for (i = 0; i < pos; i++)
    {
        current = current->next;
    }
    if (current->prev == NULL)
    {
        if (current->next != NULL)
        {
            current->next->prev = NULL;
        }
        lst = current->next;
    }
    else if (current->next == NULL)
    {
        current->prev->next = NULL;
    }
    else
    {
        printf("Vorgänger: \t%s\n", current->prev->inhalt);
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }
    printf("Wird gelöscht:\t%s\n", current->inhalt);
    free(current);
    printList(lst);
    return lst;
}

nodep *copyList(nodep *lst)
{
    nodep *cpyFrm = lst;
    nodep *newList = NULL;
    nodep *tail = NULL;
    nodep *tmp = NULL;
    do
    {
        newNode = malloc(sizeof(nodep));
        if (newList == NULL)
        {
            tail->prev = NULL;
            tail->inhalt = cpyFrm->inhalt;
            tail->next = cpyFrm->next;

            newList = tail;
            cpyFrm = cpyFrm->next;
        }
        else
        {
            tmp = malloc(sizeof(nodep));
            tmp->prev = newNode;
            tmp->inhalt = *cpyFrm->inhalt;
            tmp->next = cpyFrm->next;
            cpyFrm = cpyFrm->next;
            newNode = tmp;
        }
    } while (cpyFrm->next != NULL);
    return newList;
}

int main(void)
{
    nodep *lst = NULL;

    lst = insertAt(lst, 0, "Hose");
    lst = insertAt(lst, 1, "Jacke");
    lst = insertAt(lst, 2, "T-Shirt");
    lst = insertAt(lst, 3, "Muetze");
    /*lst = insertAt(lst, 0, "Pullover");
    lst = insertAt(lst, -1, "Schal");
    lst = insertAt(lst, -1, "Sonnenbrille");
    lst = insertAt(lst, 2, "Handschuhe");*/

    printList(lst);

    lst = deleteAt(lst, 2);
    lst = deleteAt(lst, 0);
    lst = deleteAt(lst, 1);
    lst = deleteAt(lst, 0);

    lst = copyList(lst);
    printList(lst);
    return 0;
}