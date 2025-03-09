/*--------------------------------------
Student's Name: Salem Stockdale
Lab 5
Lab Section: X03L
Lab Instructor's Name: Salwa Abougamila
Lecture Instructor's Name: Ardy RD
--------------------------------------*/

#include <stdio.h>
#include "stuff.h"

int main()
{
    struct stuff *arr = makeArray(4);

    makeStuff("Salwa", &arr[0]);
    makeStuff("Dhara", &arr[1]);
    makeStuff("Abdullah", &arr[2]);
    makeStuff("Salem", &arr[3]);

    for (int i = 0; i < 4; i++)
    {
        printf("%s\n", arr[i].name);
    }

    freeStuff(4, arr);

    return 0;
}