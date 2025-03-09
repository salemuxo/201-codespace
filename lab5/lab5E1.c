/*--------------------------------------
Student's Name: Salem Stockdale
Lab 5
Lab Section: X03L
Lab Instructor's Name: Salwa Abougamila
Lecture Instructor's Name: Ardy RD
--------------------------------------*/

#include "dynamicArray.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float *arr = createArray(10, 2.5f);

    for (int i = 0; i < 10; i++)
    {
        printf("%f\n", arr[i]);
    }

    free(arr);

    return 0;
}