/*--------------------------------------
Student's Name: Salem Stockdale
Assignment 1
Lab Section: X03L
Lab Instructor's Name: Salwa Abougamila
Lecture Instructor's Name: Ardy RD
--------------------------------------*/

int find_char(const char *str, const char chr, const int occurrence)
{
    int occurrences = 0;
    for (int i = 0; i < strlen(str); i++)
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