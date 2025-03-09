/*--------------------------------------
Student's Name: Salem Stockdale
Lab 5
Lab Section: X03L
Lab Instructor's Name: Salwa Abougamila
Lecture Instructor's Name: Ardy RD
--------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

float * createArray(int size, float initialValue)
{
    float* arr = (float *)malloc(size * sizeof(float));

    if (arr == NULL)
    {
        printf("Memory allocation failed!\n");
        free(arr);
        return NULL;
    }

    for (int i = 0; i < size; i++)
    {
        arr[i] = initialValue;
    }

    return arr;
}