/*--------------------------------------
Student's Name: Salem Stockdale
Lab 5
Lab Section: X03L
Lab Instructor's Name: Salwa Abougamila
Lecture Instructor's Name: Ardy RD
--------------------------------------*/

struct stuff
{
    char * name;
    int length;
};

/*******************************************************************************
 Purpose: Creates a dynamic array of struct stuff of size ‘size’
 Parameters: size
 Return: a pointer to the array or NULL if allocation fails
********************************************************************************/
struct stuff * makeArray(int size);

/*******************************************************************************
Purpose: Given a C-string input and a valid struct stuff pointer, the function fills the struct stuff with the
 provided name and sets the length to the string length
Parameters: data, entry
Return: None
********************************************************************************/
void makeStuff(char *data, struct stuff * entry);

/*******************************************************************************
Purpose: Given a valid struct stuff pointer, this function prints the stored string to stdout
Parameters: entry
Return: None
********************************************************************************/
void printStuff(struct stuff * entry);

/*******************************************************************************
Purpose: This function takes a dynamic array of struct stuff and frees it along with all its
 dynamically allocated components
Parameters: myArray
Return: None
********************************************************************************/
void freeStuff(int size, struct stuff * myArray);