#include <stdio.h>
#include <string.h>

enum
{
    STRLEN = 25
};

struct nd
{
    char name[STRLEN];
    struct nd *next;
};

typedef struct nd Node;

Node* createNode(const char* name)
{
    Node *newNode = malloc(sizeof(Node));
    if(!newNode) return 1;

    strcpy(newNode->name, name);
    newNode->next = NULL;
    return newNode;
}

void addNode(Node **head, const char* name)
{
    Node *newNode = createNode(name);
    if(*head == NULL) 
    {
        *head = newNode;
    }
    else
    {
        newNode->next = *head;
    }
}

void removeNode(Node **head, Node *nodeToRemove)
{
    
}

void printRing(Node *head)
{

}

int main(void)
{
    Node *head = NULL;
    char name[25];

    while(scanf("%s", &name) != EOF)
    {
        addNode(&head, name);
    }

    return 0;
}

/*int main(void)
{
    int i = 0, j = 0;
    char input[STRLEN];

    scanf("%s", &input);
    preKitty = malloc(sizeof(Node));
    strcopy(preKitty->name, input);
    preKitty->next = preKitty;
    

    while (scanf("%s", &input) != EOF)
    {
        Node *tmp;
        nextKitty = malloc(sizeof(Node));
        if (!nextKitty)
            return 1;
        strcpy(nextKitty->name, input);
        tmp = preKitty->next;
        preKitty->next = nextKitty;
        nextKitty->next = tmp;        
    };

    return 0;
}*/
