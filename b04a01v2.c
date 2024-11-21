#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    char name[25];
    struct node *next;
} *head, *current, *newNode;

typedef struct node Node;

void printRing(Node *head);

int main(argc)
{
    int i;
    char input[25];
    head = NULL;

    while (scanf("%s", input) != EOF)
    {
        if (head == NULL)
        {
            head = malloc(sizeof(Node));
            strncpy(head->name, input, 25);
            head->next = head;
        }
        else
        {
            current = head;
            while (current->next != head)
            {
                current = current->next;
            }
            newNode = malloc(sizeof(Node));
            if (!newNode)
                return 1;

            current->next = newNode;
            strncpy(newNode->name, input, 25);
            newNode->next = head;
        }
    }

    printf("Kopf:\t\t %s\n", head->name);

    /*printRing(head);*/

    if (head == NULL)
    {
        printf("Keine Eingabe erfolgt.\n");
        return 0;
    }

    while (head->next != head)
    {
        Node *ausgezaehlt = malloc(sizeof(Node));
        current = head;
        for (i = argc - 1; i > 0; i--)
        {
            current = current->next;
        }
        ausgezaehlt = current;
        printf("Muss nicht:\t %s\n", current->name);

        while (current->next != ausgezaehlt)
        {
            current = current->next;
        }
        if (ausgezaehlt == head)
        {
            head = head->next;
        }
        current->next = current->next->next;
        free(ausgezaehlt);
    }

    printf("Muss spülen:\t %s\n", head->name);
    free(head);

    return 0;
}

void printRing(Node *head)
{
    Node *current = head;
    while (current->next != head)
    {
        printf("%s\n", current->name);
        current = current->next;
    }
    printf("%s\n", current->name);
}