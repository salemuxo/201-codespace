
#include <stdio.h>
#include "link.h"
#include <string.h>
#include <stdlib.h>

void printList(struct node * list){
    int count;
    
    // loops through the list until the element is null (meaning end of list)
    for (count = 1; list != NULL; count++, list = list->next)
        // prints element number and data for each element
        printf("Element number: %d is %s \n", count, list->data);
}


struct node * createList(char * firstE){
    struct node * create;
    // allocates memory for the node
    create = malloc(sizeof(struct node));
    // allocates memory for the data string
    create->data = malloc(sizeof(struct node));
    // copies firstE to the node's data field
    strcpy(create->data, firstE);
    // sets next pointer to NULL
    create->next = NULL;
    return create;
}

void addFront(char * element, struct node ** list){
    struct node * newFront;
    // allocates memory for the node
    newFront = malloc(sizeof(struct node));
    // allocates memory for the data string
    newFront->data = malloc(strlen(element) + 1);
    // copies element to the node's data field
    strcpy(newFront->data, element);
    // sets the new node's next pointer to the old first element
    newFront->next = *list;
    // sets list pointer to the new first node
    *list = newFront;
}

void addRear(long * element, struct node ** list){
    struct node * newRear;
    // allocates memory for the node
    newRear = malloc(sizeof(struct node));   
    // sets next pointer to NULL
    newRear -> next = NULL;
    // sets final list element's next pointer to the new node
    (*list) -> next = newRear;
}

void deleteNode(char * element, struct node ** list){
    struct node * prev, *cur;
    
    prev = NULL;
    cur = *list;
    // loops until node containing element is found or end of list
    while (cur != NULL && (strcmp(element, cur->data) != 0)){
        prev = cur;
        cur = cur->next;
    }
    // if no node found, return
    if (cur==NULL) return;
    // if found node is first node, set next node as front of list
    if (prev==NULL)
        *list = cur->next;
    // otherwise, set the previous node's next node to the deleted node's next node
    else
        prev->next = cur->next;
    // if deleted node has data, free memory
    if (cur->data != NULL)
        free(cur->data);
    // free memory for deleted node
    free(cur);
}

void destroy(struct node ** list){
    struct node * dest, * link;
    
    // loop through each element of the list
    dest = *list;
    while (dest != NULL){
        link = dest->next;
        // if node has data, free memory
        if (dest->data != NULL)
            free(dest->data);
        // free memory for node
        free(dest);
        // move to next node
        dest = link;
    }
    // set list pointer to NULL
    *list = NULL;
}
