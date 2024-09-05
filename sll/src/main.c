// main file for linked list data structure
// do not include this file if importing into another project

#include <stdio.h>
#include "headers/list.h"

void printList(List *l);

int main(int argc, char **argv){

    char *str = "hi!";
    List *l = newList();

    // populate the linked list
    for(int i = 0; str[i] != '\0'; i++){
        addNode(l, str[i]);
    }

    // FIXME: there is a runtime error in this code!
    //        need to fix it...

    printList(l);
    rmNode(l, 1);
    printList(l);
    rmNode(l, 1);
    printList(l);
    rmNode(l, 1);
    printList(l);
    rmNode(l, 0);
    printList(l);

    // free the linked list before program end
    int max_size = l->size;
    rmList(l);

    return 0;
}

// print the linked list
void printList(List *l){
    if(!l->size == 0){
        Node *tmp;
        tmp = l->head;
        for(int i = 0; i < l->size; i++){
            printf("current node data = %c\n", tmp->data);
            tmp = tmp->next;
        }
    }
    printf("Size: %d\n", l->size);
}