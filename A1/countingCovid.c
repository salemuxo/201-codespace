#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_char(const char *str, const char chr, const int occurrence);

int main()
{
    FILE* file = fopen("covidData_100.csv", "r");
    char line[256];
    
    if (file != NULL)
    {
        fgets(line, sizeof(line), file);

        char date[10] = "";
        // char last_date[10] = "";
        while (fgets(line, sizeof(line), file))
        {
            int start = find_char(line, ',', 2) + 1;
            strncpy(date, line, 10);

            printf("%s\n", date);

            // char last_date[10] = date;
        }
    }

    return 0;
}

int find_char(const char *str, const char chr, const int occurrence)
{
    int occurrences = 0;
    for (int i = 0; i < 256; i++)
    {
        if (str[i] == chr)
        {
            occurrences++;
            if (occurrences >= occurrence)
            {
                return i;
            }
        }
        else if (str[i] == '\0')
        {
            return -1;
        }
        
    }
    return -1;
}