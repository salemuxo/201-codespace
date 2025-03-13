#include "../ht_impl.h"
#include <stdio.h>

int main()
{
    for (int i = 0; i < 100; i++)
    {
        if (is_prime(i))
        {
            printf("%d, ", i);
        }
    }

    printf("\n");
    
    for (int i = 0; i < 100; i += 10)
    {
        printf("%d, ", next_prime(i));
    }
    return 0;
}