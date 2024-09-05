// a messy but simple C linked list

// TODO
// - null checking after mallocing

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include "headers/list.h"

List *newList(void){
    List *l = malloc(sizeof(List));
    l->size = 0;
    l->head   = NULL;
    l->tail   = NULL;
    l->walker = NULL;

    return l;
}

// add a node with the data field set to value
void addNode(List *l, char value){
    Node *n = malloc(sizeof(Node));
    Node *tmp;
    n->next = NULL;
    n->data = value;

    // add element to list
    // if this is the first element
    if(l->size == 0){
        l->head = l->tail = n;
    }
    // otherwise, iterate along and append this node to the end
    else{
        tmp = l->head;
        for(; tmp->next != NULL ;){
            tmp = tmp->next;
        }
        // now we've reached the end, we can append the Node
        tmp->next = n;
        l->tail = n;
    }
    l->size++;
}

// remove the final node from the list
void rmList(List *l){
    Node *tmpNodeFront;
    Node *tmpNodeBack;
    int i = 0, size;

    if(l->size > 0){
        tmpNodeFront = l->head;
        for(i = 0; tmpNodeFront->next != NULL; i++){
            // save current node
            tmpNodeBack = tmpNodeFront;
            // advance to next node
            tmpNodeFront = tmpNodeFront->next;
            // delete current node
            free(tmpNodeBack);
        }
        // delete last remaining node
        free(tmpNodeFront); i++;
        // delete the list itself!
        size = l->size;
        free(l);
        
        // did we delete all the nodes?
        printf("Stored size: %d\nMeasured size: %d\n", size, i);
    }
}
