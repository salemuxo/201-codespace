
#include "link.h"
#include <stdio.h>
#include <string.h>

int main(void){
    //test the linked list
    // create an empty linked list and a string to store datas
    struct node * myList;
    char add[15]="apple";

    // create a list with "apple" as first element
    myList=createList(add);
    // print the list
    printList(myList);
    printf("\n");
    // add "pear" to the front of the list
    strcpy(add, "pear");
    addFront(add, &myList);
    // add "grape" to the front of the list
    strcpy(add, "grape");
    addFront(add, &myList);
    // add "peach" to the front of the list
    strcpy(add, "peach");
    addFront(add, &myList);
    // add "orange" to the front of the list
    strcpy(add, "orange");
    addFront(add, &myList);
    // print the list
    printList(myList);
    printf("\n");
    // delete the "pear", "orange", and "apple" nodes
    deleteNode("pear", &myList);
    deleteNode("orange", &myList);
    deleteNode("apple", &myList);
    // print the list
    printList(myList);
    printf("\n");
    // destroy the list
    destroy(&myList);
    // print the list
    printList(myList);
    return 0;
}

