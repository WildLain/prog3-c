#ifndef TEXTFUN_H
#define TEXTFUN_H

#define MAX_WORD_LEN 25

typedef struct listEle {
    char suchWort[MAX_WORD_LEN];
    char ersetzungsWort[MAX_WORD_LEN];
    struct listEle *next;
} ListEle;

extern ListEle *wordList;

typedef struct Fundstelle{
    const char *stelleImSuchstring;
    ListEle *ersetzung;
} Fundstelle;

void addPair(const char *such, const char *ersatz);
void clearList(void);
Fundstelle *find(const char *s);
int replaceAll(char *s);

#endif  