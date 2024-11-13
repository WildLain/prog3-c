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

Node *createNode(const char *name)
{
    Node *newNode = malloc(sizeof(Node));
    if (!newNode) return NULL;

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

Node *findNode(Node *head, char name[STRLEN])
{
    Node *current = head;

    if (head == NULL)
        return NULL;

    do
    {
        if (strncmp(current->name, name, STRLEN) == 0)
        {
            return current;
        }
        current = current->next;
    } while (current != head);

    return NULL;
}

Node *removeNode(Node *head, char *name)
{
    Node *nodeToRemove, *current;
    if (head == NULL)
        return NULL;

    nodeToRemove = findNode(head, name);
    if (nodeToRemove == NULL)
        return head; /*Knoten nicht gefunden*/

    if (head == nodeToRemove && head->next == head)
    {
        free(head);
        return NULL;
    }

    current = head;
    do
    {
        if (current->next == nodeToRemove)
        {
            current->next = nodeToRemove->next;
            if(head == nodeToRemove)
            {
                head = nodeToRemove->next;
            }
            free(nodeToRemove);
            return head;
        }
        current = current->next;
    } while (current->next != head);
    current->next = current->next->next;
    free(nodeToRemove);
    return head;
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

int main(void)
{
    Node *ring = NULL;

    /*while(scanf("%s", &name) != EOF)
    {
        head = addNode(head, name);
    }*/

    ring = addNode(ring, "Nhani");
    ring = addNode(ring, "Merle");
    ring = addNode(ring, "David");
    ring = addNode(ring, "Larissa");
    ring = addNode(ring, "Marvin");

    printRing(ring);

    /*Node *nodeToFind = findNode(ring, "Larissa");*/

    ring = removeNode(ring, "Larissa");

    printRing(ring);

    return 0;
}
