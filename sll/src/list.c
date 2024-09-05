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

// NOTE: arg index starts from zero (ie: index = 0, means Node head)
// remove the node at location index in the list
void rmNode(List *l, int index){
    Node *tmp = l->head;
    Node *prev;

    if(tmp == NULL)
        return;
    if(index > l->size)
        return;

    else if(index == 0){
        // remove head
        if(l->size == 1){
            l->head = NULL;
            l->tail = NULL;
            free(tmp);
        }
        else{
            l->head = l->head->next;
            free(tmp);
        }
    }
    else if(index == l->size){
        // remove tail
        for(int i = 0; i < index-1; i++){
            tmp = tmp->next;
        }
        
    }
    else{
        // rm node at index
        for(int i = 0; i < index-1; i++){
            tmp = tmp->next;
        }
        prev = tmp;
        tmp = tmp->next;
        if(tmp->next == NULL)
            prev->next = NULL;
        else
            prev->next = tmp->next;

        free(tmp);
    }
    l->size--;
}

// free the list and all nodes therein
void rmList(List *l){
    Node *tmpNodeFront;
    Node *tmpNodeBack;
    int size;

    if(l->size > 0){
        tmpNodeFront = l->head;
        for(int i = 0; tmpNodeFront->next != NULL; i++){
            // save current node
            tmpNodeBack = tmpNodeFront;
            // advance to next node
            tmpNodeFront = tmpNodeFront->next;
            // delete current node
            free(tmpNodeBack);
        }
        // delete last remaining node
        free(tmpNodeFront);
        // delete the list itself!
        size = l->size;
        free(l);
    }
}
