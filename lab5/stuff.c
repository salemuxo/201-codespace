/*--------------------------------------
Student's Name: Salem Stockdale
Lab 5
Lab Section: X03L
Lab Instructor's Name: Salwa Abougamila
Lecture Instructor's Name: Ardy RD
--------------------------------------*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct stuff
{
    char * name;
    int length;
};

struct stuff * makeArray(int size)
{
    struct stuff * arr = (struct stuff *)malloc(size * sizeof(struct stuff));

    if (arr == NULL)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    return arr;
}

void makeStuff(char *data, struct stuff * entry)
{
    entry->name = (char *)malloc(strlen(data) + 1);

    if (entry->name == NULL)
    {
        printf("Memory allocation for name failed!\n");
        return;
    }

    strcpy(entry->name, data);
    entry->length = strlen(entry->name);

    return;
}

void printStuff(struct stuff * entry)
{
    printf("%s\n", entry->name);

    return;
}

void freeStuff(int size, struct stuff * myArray)
{
    for (int i = 0; i < size; i++)
    {
        free(myArray[i].name);
    }
    free(myArray);

    return;
}