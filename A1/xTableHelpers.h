/*--------------------------------------
Student's Name: Salem Stockdale
Assignment 1
Lab Section: X03L
Lab Instructor's Name: Salwa Abougamila
Lecture Instructor's Name: Ardy RD
--------------------------------------*/

/*
Function to count the number of digits in a positive integer under 10,000.

Input: 
    int num: a positive integer under 10,000.

Output:
    returns int: the number of digits in the number.
*/
int idigits(int num);

/*
Function to count the number of digits (including the decimal) in a positive double under 1,000,000 assuming one decimal place. 

Input:
    double num: a positive double under 1,000,000.

Output:
    returns int: the number of digits (including the decimal) assuming one decimal place.
*/
int ddigits(double num);

/*
Prints the given number of spaces to the console.

Input:
    int n: the number of spaces to print.

Output:
    No return value, but prints n spaces to the console.
*/
void nspaces(int n);

/*
Prints an integer with enough spaces to fill total_space.

Input:
    int num: the number to print
    int total_space: the total width to space out to

Output:
    No return value, but prints number and spaces to console.
*/
void space_int(int num, int total_space);

/*
Prints a double to 1 decimal place with enough spaces to fill total_space.

Input:
    double num: the number to print
    int total_space: the total width to space out to

Output:
    No return value, but prints number and spaces to console.
*/
void space_double(double num, int total_space);