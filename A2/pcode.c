#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ht.h"

int main(int argc, char *argv[])
{
    // check for correct number of arguments
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <input file>\n", argv[0]);
        return 1;
    }

    // open file, return error if couldnt open
    FILE* file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Cannot open file\n");
        return 1;
    }

    // create the hash table
    hashtable table;
    table = ht_create();

    // loop through each line in the file
    char line[256];
    while(fgets(line, 256, file) != NULL)
    {
        // separate the city and postal code to their own strings
        char* city = strtok(line, ",");
        char* postal_code = strtok(NULL, "\n");

        // find value associated with city in table
        char* existing_value = ht_lookup(table, city);
        char* new_value;

        // if city was already in table, append postal code to existing value
        if (existing_value != NULL)
        {
            // allocate memory for new value: length of existing_value + length of postal_code + 1 for comma
            new_value = malloc(strlen(existing_value) + strlen(postal_code) + 2);
            if (new_value == NULL)
            {
                fprintf(stderr, "Error: Memory allocation failed\n");
                return 1;
            }
            
            // concatenate existing value and postal code with comma and store in new_value
            sprintf(new_value, "%s,%s", existing_value, postal_code);
            
            // remove old value from table
            ht_remove(table, city);
        }
        // if city was not in table, set value to postal code
        else
        {
            // allocate memory for new value: length of postal_code + 1 for null terminator
            new_value = malloc(strlen(postal_code) + 1);
            if (new_value == NULL)
            {
                fprintf(stderr, "Error: Memory allocation failed\n");
                return 1;
            }

            // copy postal code to new_value
            strcpy(new_value, postal_code);
        }

        // insert city and new_value into table, then free new_value
        ht_insert(table, city, new_value);
        free(new_value);
    }
    // close file when done
    fclose(file);

    // let user enter city names, print postal codes if city is in table
    char query[256];
    while (fgets(query, 256, stdin) != NULL)
    {
        query[strcspn(query, "\n")] = 0;
        char* result = (char*)ht_lookup(table, query);
        if (result != NULL)
        {
            printf("%s\n", result);
        }
    }

    // free table
    ht_free(table);

    return 0;
}