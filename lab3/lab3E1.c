/*--------------------------------------
Student's Name: Salem Stockdale
Lab 3
Lab Section: X03L
Lab Instructor's Name: Salwa Abougamila
Lecture Instructor's Name: Ardy RD
--------------------------------------*/

#include <stdio.h>
#include <string.h>

void substring(char *str, char *sub, int start, int end);

int main()
{
    int item_count = -1;
    printf("Enter number of items: ");
    scanf("%d", &item_count);

    float unit_price = -1.0;
    printf("Enter unit price: ");
    scanf("%f", &unit_price);

    float total_price = item_count * unit_price;

    char date[10] = "";
    printf("Enter date (dd/mm/yyyy): ");
    scanf("%s", date);

    char date_formatted[11] = "";
    substring(date, date_formatted, 6, 10);
    strcat(date_formatted, ": ");
    substring(date, date_formatted + 6, 3, 6);
    substring(date, date_formatted + 9, 0, 2);


    printf("\nItem     Total     Purchase\n");
    printf("Count    Price     Date\n");
    printf("%d        $ %.2f   %s\n", item_count, total_price, date_formatted);

    return 0;
}

void substring(char *str, char *sub, int start, int end)
{
    int i = 0;
    while (i < end - start)
    {
        sub[i] = str[start + i];
        i++;
    }
    sub[i] = '\0';
}