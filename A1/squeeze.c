/*--------------------------------------
Student's Name: Salem Stockdale
Assignment 1
Lab Section: X03L
Lab Instructor's Name: Salwa Abougamila
Lecture Instructor's Name: Ardy RD
--------------------------------------*/

#include <stdio.h>
#include <ctype.h>

int main() 
{
    char next_char, prev_char;
    int counter = 0;

    while ((next_char = getchar()) != EOF)
    {        
        // if next_char is same as prev and counter less than 9, increment
        if (next_char == prev_char && counter < 9)
        {
            counter++;
        }
        else
        {
            // if counter has counted and prev_char is alphabetical, print prev_char and count
            if (isalpha(prev_char))
            {
                if (counter > 1)
                {
                    printf("%c%d", prev_char, counter);
                }
                else
                {
                    printf("%c", prev_char);
                }
            }
            counter = 1;
        }
        // if next_char is newline, print newline
        if (next_char == '\n')
        {
            printf("\n");
        }
        // store next_char in prev_char
        prev_char = next_char;

    }
    return 0;
}