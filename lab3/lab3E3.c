/*--------------------------------------
Student's Name: Salem Stockdale
Lab 3
Lab Section: X03L
Lab Instructor's Name: Salwa Abougamila
Lecture Instructor's Name: Ardy RD
--------------------------------------*/

#include <stdio.h>
#include "change.h"

int main()
{
    double total = -1.0;
    double paid = -1.0;

    while (1) {
        printf("\nEnter amount owed: ");
        if (scanf("%lf", &total) == EOF) {
            break;
        }

        printf("Enter amount paid: ");
        if (scanf("%lf", &paid) == EOF) {
            break;
        }

        changeCalculator(total, paid);
    }

    
}