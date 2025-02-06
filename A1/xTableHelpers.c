/*--------------------------------------
Student's Name: Salem Stockdale
Assignment 1
Lab Section: X03L
Lab Instructor's Name: Salwa Abougamila
Lecture Instructor's Name: Ardy RD
--------------------------------------*/

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