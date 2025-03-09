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
    return 0;
}