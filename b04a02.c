#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum
{
    STRLEN = 25
};

struct listnode
{
    char *inhalt;
    struct listnode *prev;
    struct listnode *next;
};
typedef struct listnode nodep;

void printList(nodep *lst)
{
    if (lst == NULL)
    {
        printf("Liste leer!");
    }
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
    if (!newNode)
        return NULL;

    newNode->inhalt = malloc(sizeof(strlen(inhalt) + 1));
    if (!newNode->inhalt)
        return NULL;

    strncpy(newNode->inhalt, inhalt, sizeof(strlen(inhalt) + 1));

    if (lst == NULL)
    {
        lst = newNode;
        lst->prev = NULL;
        lst->next = NULL;
        return lst;
    }

    switch (pos)
    {
    case 0:
        current->prev = newNode;
        newNode->next = current;
        newNode->prev = NULL;
        lst = newNode;
        break;
    case -1:
        current = lst;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
        break;
    default:
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
        break;
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
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }
    if (current->prev != NULL)
    {
        printf("Vorgänger: \t%s\n", current->prev->inhalt);
    }
    printf("Wird gelöscht:\t%s\n", current->inhalt);
    free(current);
    printList(lst);
    return lst;
}

nodep *copyList(nodep *lst)
{
    nodep *newList = NULL;
    nodep *current = lst;
    newList = insertAt(newList, 0, lst->inhalt);

    do
    {
        newList = insertAt(newList, -1, current->inhalt);
        current = current->next;
    } while (current->next != NULL);
    return newList;
}

void deleteList(nodep *lst)
{
    nodep *current = lst;
    
    while(current != NULL)
    {
        deleteAt(current, 0);
        current = current->next;
    }
}

int main(void)
{
    nodep *lst = NULL;
    nodep *lstToCpy = NULL;

    lst = insertAt(lst, 0, "Hose");
    lst = insertAt(lst, 1, "Jacke");
    lst = insertAt(lst, 2, "T-Shirt");
    lst = insertAt(lst, 3, "Muetze");
    /*lst = insertAt(lst, 0, "Pullover");
    lst = insertAt(lst, -1, "Schal");
    lst = insertAt(lst, -1, "Sonnenbrille");
    lst = insertAt(lst, 2, "Handschuhe");*/

    printList(lst);

    /*lst = deleteAt(lst, 2);
    lst = deleteAt(lst, 0);
    lst = deleteAt(lst, 1);
    lst = deleteAt(lst, 0);*/
    
    printf("Kopie: \n");
    lstToCpy = copyList(lst);
    printList(lstToCpy);

    deleteList(lstToCpy);
    return 0;
}