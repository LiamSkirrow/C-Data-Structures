// include file for main list data structure definition

#ifndef LIST_H
#define LIST_H

typedef struct node Node;
typedef struct list List;

struct node{
    Node *next;
    char data;
};

struct list{
    Node *head;
    Node *tail;
    Node *walker;
    unsigned int size;
};

List *newList(void);
void addNode(List *l, char value);
void rmList(List *l);

#endif
