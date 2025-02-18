/*--------------------------------------
Student's Name: Salem Stockdale
Assignment 1
Lab Section: X03L
Lab Instructor's Name: Salwa Abougamila
Lecture Instructor's Name: Ardy RD
--------------------------------------*/

#include <stdio.h>
#include <string.h>

void CardinalSort(char *input);

int main()
{
    char line[256] = "";
    while (fgets(line, 256, stdin) != NULL)
    {
        CardinalSort(line);
    }

    return 0;
}

void CardinalSort(char *input)
{
    // define boundaries for printable ascii characters
    int min = 32;
    int max = 126;

    int counts[95] = {0};

    for (int i = 0; i < strlen(input); i++)
    {
        if ((int)input[i] >= min && (int)input[i] <= max)
        {
            counts[(int)input[i] - min]++;
        }
    }

    for (int i = 0; i < 95; i++)
    {
        for (int c = 0; c < counts[i]; c++)
        {
            printf("%c", (char)i + min);
        }
    }
    printf("\n");
}