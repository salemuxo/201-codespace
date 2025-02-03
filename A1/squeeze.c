#include <stdio.h>

int main() 
{
    char next_char = "";
    while ((next_char = getchar()) != EOF)
    {
        printf("%c", next_char);
    }
    return 0;
}