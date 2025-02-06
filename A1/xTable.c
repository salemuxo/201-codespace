/*--------------------------------------
Student's Name: Salem Stockdale
Assignment 1
Lab Section: X03L
Lab Instructor's Name: Salwa Abougamila
Lecture Instructor's Name: Ardy RD
--------------------------------------*/

#include <stdio.h>
#include <math.h>
#include "xTable.h"

int main()
{
    double vals[400];
    int i = 0;

    for (int y = 5; y <= 100; y += 5)
    {
        for (int x = 5; x <= 100; x += 5)
        {
            // calculate val based on expression n = (x^4)/(y^4) + sqrt(y)
            double val = (pow(x, 4) / pow(y, 4)) + sqrt(y);
            vals[i] = val;

            i++;
        }
    }

    // first row, print only x values
    printf("+         ");
    for (int x = 5; x <= 100; x += 5)
    {
        printf("%d", x);
        nspaces(10 - idigits(x));
    }
    printf("\n");

    for (int y = 5; y <= 100; y += 5)
    {
        printf("%d", y);
        nspaces(10 - idigits(y));

        int start = (y / 5 - 1) * 20;
        for (int n = start; n < start + 20; n++)
        {
            printf("%.1lf", vals[n]);
            nspaces(10 - ddigits(vals[n]));
        }
        printf("\n");
    }
    return 0;
}

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

void nspaces(double n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" ");
    }
    return;
}