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
    unsigned int size;
};

// list operations
List *newList(void);
void rmList(List *l);
// node operations
void addNode(List *l, char value);
void rmNode(List *l, int index);  // not implemented yet
void mvNode(List *l, int from, int to); // not implemented yet

#endif
