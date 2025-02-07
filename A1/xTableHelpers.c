/*--------------------------------------
Student's Name: Salem Stockdale
Assignment 1
Lab Section: X03L
Lab Instructor's Name: Salwa Abougamila
Lecture Instructor's Name: Ardy RD
--------------------------------------*/

#include <stdio.h>

int idigits(int num)
{
    if (num >= 1000) return 4;
    else if (num >= 100) return 3;
    else if (num >= 10) return 2;
    else return 1;
}

int ddigits(double num)
{
    if (num >= 99999.95) return 8;
    else if (num >= 9999.95) return 7;
    else if (num >= 999.95) return 6;
    else if (num >= 99.95) return 5;
    else if (num >= 9.95) return 4;
    else return 3;
}

void nspaces(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" ");
    }
    return;
}

void space_int(int num, int total_space)
{
    printf("%d", num);
    nspaces(total_space - idigits(num));
    return;
}

void space_double(double num, int total_space)
{
    printf("%.1lf", num);
    nspaces(total_space - ddigits(num));
    return;
}