#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum
{
    STRLEN = 25
};

struct nd
{
    char name[STRLEN];
    struct nd *next;
} *newNode;

typedef struct nd Node;
void printRing(Node *head);

Node *createNode(const char *name)
{
    Node *newNode = malloc(sizeof(Node));
    if (!newNode)
        return NULL;

    strncpy(newNode->name, name, STRLEN);
    newNode->next = NULL;
    return newNode;
}

Node *addNode(Node *head, const char *name)
{
    Node *newNode = createNode(name);
    Node *current;

    if (head == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }
    current = head;
    while (current->next != head)
    {
        current = current->next;
    }

    current->next = newNode;
    newNode->next = head;

    return head;
}

void countOut(Node *head, int argc)
{
    int i;
    Node *current;
    while (head->next != head)
    {
        current = head;
        for(i = 0; i < argc-1; i++)
        {
            current = current->next;
        }
        if(current->next == head && current == head)
        {
            printf("Muss spülen: %s\n", head->name);
            free(head);
        }
        printf("Muss nicht: %s\n", current->next->name);
        if(current->next == head)
        {
            head = current->next->next;
        }
        free(current->next);
        current->next = current->next->next;
        printRing(head);
        continue;
    }
}

void printRing(Node *head)
{
    Node *current;
    if (head == NULL)
    {
        printf("Keiner da!\n");
        return;
    }

    current = head;
    do
    {
        printf("%s\n", current->name);
        current = current->next;
    } while (current != head);
    printf("\n");
}

int main(int argc, char *argv[])
{
    Node *ring = NULL;
    char name[STRLEN];

    while(scanf("%s", name) != EOF)
    {
        ring = addNode(ring, name);
    }
    printf("\n");

    countOut(ring, argc);   

    return 0;
}

    /*ring = addNode(ring, "Nhani");
    ring = addNode(ring, "Merle");
    ring = addNode(ring, "David");
    ring = addNode(ring, "Larissa");
    ring = addNode(ring, "Marvin");*/