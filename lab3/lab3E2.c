/*--------------------------------------
Student's Name: Salem Stockdale
Lab 3
Lab Section: X03L
Lab Instructor's Name: Salwa Abougamila
Lecture Instructor's Name: Ardy RD
--------------------------------------*/

#include <stdio.h>
#include <math.h>

int count_value(double *total, double value);

int main()
{
    double total = -1.0;
    printf("Enter amount owed: ");
    scanf("%lf", &total);

    double paid = -1.0;
    printf("Enter amount paid: ");
    scanf("%lf", &paid);

    double change = paid - total;

    printf("\nChange of: %.2lf\n", change);

    int fifties = count_value(&change, 50.0);
    if (fifties > 0) {
        printf("%d fifty dollar bill\n", fifties);
    }
    
    int twenties = count_value(&change, 20.0);
    if (twenties > 0) {
        printf("%d twenty dollar bill\n", twenties);
    }

    int tens = count_value(&change, 10.0);
    if (tens > 0) {
        printf("%d ten dollar bill\n", tens);
    }

    int fives = count_value(&change, 5.0);
    if (fives > 0) {
        printf("%d five dollar bill\n", fives);
    }

    int toonies = count_value(&change, 2.0);
    if (toonies > 0) {
        printf("%d toonie\n", toonies);
    }

    int loonies = count_value(&change, 1.0);
    if (loonies > 0) {
        printf("%d loonie\n", loonies);
    }

    int quarters = count_value(&change, 0.25);
    if (quarters > 0) {
        printf("%d quarter\n", quarters);
    }

    int dimes = count_value(&change, 0.10);
    if (dimes > 0) {
        printf("%d dime\n", dimes);
    }

    int nickels = count_value(&change, 0.05);
    if (nickels > 0) {
        printf("%d nickel\n", nickels);
    }

    int pennies = count_value(&change, 0.01);
    if (pennies > 0) {
        printf("%d penny\n", pennies);
    }

    return 0;
}

int count_value(double *total, double value)
{
    int count = floor(*total / value);
    *total = fmod(*total, value);
    return count;
}