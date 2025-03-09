//some basic linked-list functions

/*
Struct to represent a node in a linked list.
Fields:
    char* data: the string to store in the node. 
    struct node* next: the pointer to the next element in the list.
*/
struct node {
    char * data;
    struct node * next;
};

/*
Purpose: Prints the elements of a linked list.
Parameters:
    struct node* list: the pointer to the first node of the linked list.
Returns: None, but prints the list to the console.
*/
void printList(struct node * list);

/*
Purpose: Creates a linked list with one element.
Parameters: 
    char* firstE: the string to store in the first node.
Returns:
    struct node*: the pointer to the first node in the linked list.
*/
struct node * createList(char * firstE);

/*
Purpose: Adds a new node to the front of the linked list.
Parameters:
    char* element: the string to store in the new node.
    struct node** list: the list to append the new node to.
Returns: None, but shifts the list pointer to the new first element.
*/
void addFront(char * element, struct node ** list);

/*
Purpose: Deletes the node containing the given string.
Parameters:
    char* element: the string of the node to delete.
    struct node** list: the list to delete the node from.
Returns: None, but deletes the given node if it exists.
*/
void deleteNode(char * element, struct node ** list);

/*
Purpose: Deletes a linked list and frees up all memory.
Parameters:
    struct node** list: the list to delete.
Returns: None, but deletes and frees the linked list.
*/
void destroy(struct node ** list);