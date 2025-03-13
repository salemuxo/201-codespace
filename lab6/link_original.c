
#include <stdio.h>
#include "link.h"
#include <string.h>
#include <stdlib.h>

void printList(struct node * list){
    int count;
    
    for (count = 1; list != NULL; count++, list = list->next)
        printf("Element number: %d is %s \n", count, list->data);
}


struct node * createList(char * firstE){
    struct node * create;
    
    create = malloc(sizeof(struct node));
    strcpy(create->data, firstE);
    create->next = NULL;
    return create;
}

void addFront(char * element, struct node ** list){
    struct node * newFront;
    
    newFront = malloc(sizeof(struct node));
    newFront->data = malloc(strlen(element) + 1);
    strcpy(newFront->data, element);
    newFront->next = *list;
    *list = newFront;
}
void addRear(long * element, struct node ** list){
    struct node * newRear;

    newRear = malloc(sizeof(struct node));   
    newRear -> next = NULL;
    (*list) -> next = newRear;
}


void deleteNode(char * element, struct node ** list){
    struct node * prev, *cur;
    
    prev = NULL;
    while (cur != NULL && (strcmp(element, cur->data) != 0)){
        prev = cur;
        cur = cur->next;
    }
    if (cur==NULL) return;
    if (prev==NULL)
        *list = cur->next;
    else
        prev->next = cur->next;
    if (cur->data != NULL)
        free(cur->data);
    free(cur);
}

void destroy(struct node ** list){
    struct node * dest, * link;
    
    dest = *list;
    while (dest != NULL){
        if (dest->data != NULL)
            free(dest->data);
        free(dest);
        dest = link;
        if (link != NULL)
            link=link->next;
    }
    *list = NULL;
}
