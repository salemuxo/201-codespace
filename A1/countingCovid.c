/*--------------------------------------
Student's Name: Salem Stockdale
Assignment 1
Lab Section: X03L
Lab Instructor's Name: Salwa Abougamila
Lecture Instructor's Name: Ardy RD
--------------------------------------*/

#include <stdio.h>
#include <string.h>
#include "countingCovidHelpers.h"

int main()
{    
    char line[256];
    
    // discard first line
    fgets(line, sizeof(line), stdin);

    char date[11] = "";
    char prev_date[11] = "";
    int start = 0;
    int count = 0;

    while (fgets(line, sizeof(line), stdin))
    {
        // line starts with quote -- date starts after second quote
        if (line[0] == '"')
        {
            start = find_char(line, '"', 2) + 2;
        }
        // line doesn't start with quote -- date starts after first comma
        else
        {
            start = find_char(line, ',', 1) + 1;
        }
        
        // store date in variable
        strncpy(date, line + start, 10);

        // date is different from prev_date -- print previous date and count, reset counter
        if (strncmp(date, prev_date, 10) != 0 && strncmp(prev_date, "", 1) != 0)
        {
            printf("%s: %d\n", prev_date, count);
            count = 1;
        }
        // date is same as prev_date -- increment counter
        else
        {
            count++;
        }

        // copy date to prev_date
        strncpy(prev_date, date, 10);
    }
    printf("%s: %d\n", prev_date, count);
    return 0;
}