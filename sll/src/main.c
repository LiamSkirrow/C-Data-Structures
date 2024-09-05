// main file for linked list data structure
// do not include this file if importing into another project

#include <stdio.h>
#include "headers/list.h"

int main(int argc, char **argv){

    char *str = "hello world!";
    List *l = newList();
    Node *tmp;

    // populate the linked list
    for(int i = 0; str[i] != '\0'; i++){
        addNode(l, str[i]);
    }

    // print the linked list
    tmp = l->head;
    for(int i = 0; i < l->size; i++){
        printf("current node data = %c\n", tmp->data);
        tmp = tmp->next;
    }

    // free the linked list before program end
    int max_size = l->size;
    rmList(l);

    return 0;
}