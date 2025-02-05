/*--------------------------------------
Student's Name: Salem Stockdale
Assignment 1
Lab Section: X03L
Lab Instructor's Name: Salwa Abougamila
Lecture Instructor's Name: Ardy RD
--------------------------------------*/

#include <stdio.h>

int main() 
{
    char next_char = "";
    while ((next_char = getchar()) != EOF)
    {
        printf("%c", next_char);
    }
    return 0;
}