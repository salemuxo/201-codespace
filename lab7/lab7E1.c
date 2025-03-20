#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/*
Structure to represent a game.

Fields:
    double price: the price of the game in dollars and cents. 
    char title[25]: the title of the game.
    unsigned int popularity: the popularity of the game, from 1 to 4.
*/
typedef struct {
    double price;
    char title[25];
    unsigned int popularity : 3;
} game;

/*
Purpose: Compare two games by their title.
Parameters: 
    const void* a: a pointer to the first game.
    const void* b: a pointer to the second game.
Returns: int
    -1 if first game is less than second game
    1 if first game is greater than second game
    0 if they are equal.
*/
int compGamesByTitle(const void* a, const void* b)
{
    return strcmp(((game*)a)->title, ((game*)b)->title);
}

/*
Purpose: Compare two games by their price. 
Parameters: 
    const void* a: a pointer to the first game.
    const void* b: a pointer to the second game.
Returns: int
    -1 if first game is less than second game
    1 if first game is greater than second game
    0 if they are equal.   
*/
int compGamesByPrice(const void* a, const void* b)
{
    if (((game*)a)->price < ((game*)b)->price) return -1;
    else if (((game*)a)->price > ((game*)b)->price) return 1;
    else return 0;
}

/*
Purpose: Writes an array of games to a binary file "out.bin".
Parameters: 
    game* games: the array of games to write.
    int size: the number of games to write.
Returns: bool - true if the write was successful, false otherwise.
*/
bool writeBinary(game* games, int size)
{
    FILE* file = fopen("out.bin", "wb");
    if (file == NULL)
    {
        fprintf(stderr, "Error opening file.\n");
        return false;
    }

    size_t written = fwrite(games, sizeof(game), size, file);
    if (written != size)
    {
        fprintf(stderr, "Error writing to file.\n");
        return false;
    }

    fclose(file);
    return true;
}

/*
Purpose: Read the binary file "out.bin" into a dynamic array of games.
Parameters: 
    int size: the number of games to read.
Returns: game* - the dynamic array of games read from the file.
*/
game* readBinary(int size)
{
    FILE* file = fopen("out.bin", "rb");
    if (file == NULL)
    {
        fprintf(stderr, "Error opening file.\n");
        return NULL;
    }

    game* games = malloc(sizeof(game) * size);
    if (games == NULL)
    {
        fprintf(stderr, "Error allocating memory.\n");
        return NULL;
    }

    size_t read = fread(games, sizeof(game), size, file);
    if (read != size)
    {
        fprintf(stderr, "Error reading from file.\n");
        return NULL;
    }

    fclose(file);
    return games;
}

/*
Purpose: Count the number of digits in a double number, assuming 2 decimal places and including the decimal point.
Parameters: 
    double num: the number to count the digits of.
Returns: unsigned int - the number of digits in the number.
*/
unsigned int ddigits(double num)
{
    unsigned int count = 0;
    unsigned int n = (unsigned int)floor(num);
    while (n != 0)
    {
        n /= 10;
        count++;
    }
    
    if (count == 0) count = 1;

    return count + 3;
}

/*
Purpose: Print a character n times.
Parameters: 
    char* c: the character to print.
    int n: the number to print.
Returns: void
*/
void print_n_times(char* c, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%c", *c);
    }
}

/*
Purpose: Print a double number with 2 decimal places and a specified total space.
Parameters: 
    double num: the number to print.
    int total_space: the total space to print the number in.
Returns: void
*/
void space_double(double num, int total_space)
{
    printf("%.2lf", num);
    print_n_times(" ", total_space - ddigits(num));
}

/*
Purpose: Prints an array of games in a formatted table.
Parameters: 
    game* games: the array of games to print.
    int n: the number of games in the array.
Returns: void
*/
void print_games(game* games, int n)
{
    print_n_times("-", 54);
    printf("\n");
    printf("| PRICE          TITLE                    POPULARITY |\n");
    for (int i = 0; i < n; i++)
    {
        // print the start of the row
        printf("| ");

        // print the price
        space_double(games[i].price, 15);

        // print the title
        printf("%-25s", games[i].title);

        // print the popularity
        printf("%d", games[i].popularity);

        // print the end of the row
        print_n_times(" ", 10);
        printf("|\n");
    }
    print_n_times("-", 54);
    printf("\n");
}

int main()
{
    // Create the array of games and print it out
    game games[6] = {
        {22.79, "Opus Magnum", 1},
        {0.01, "Minecraft", 4},
        {14.99, "Trainz", 2},
        {0, "Code Combat", 3},
        {7.79, "Lemmings Revolution", 3},
        {64.96, "Warcraft", 1}
    };
    printf("Printing initial array...\n");
    print_games(games, 6);

    // Sort the games by title and print them out
    printf("Sorting by title...\n");
    qsort(games, 6, sizeof(game), compGamesByTitle);
    print_games(games, 6);

    // Sort the games by price and print them out
    printf("Sorting by price...\n");
    qsort(games, 6, sizeof(game), compGamesByPrice);
    print_games(games, 6);

    // Write games to binary file
    printf("Writing to binary file...\n");
    if (!writeBinary(games, 6))
    {
        fprintf(stderr, "Error writing to binary file.\n");
        return 1;
    }

    // Read games from binary file and print them out
    printf("Reading from binary file...\n");
    game* read_games = readBinary(6);
    print_games(read_games, 6);    
    free(read_games);
}