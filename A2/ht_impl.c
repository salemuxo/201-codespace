#include <stdint.h>
#include <stdbool.h>

long long unsigned hash(const char *s, const int table_size)
{
    uint64_t ret = 5831;
    char c;

    while ((c = *s++))
    {
        ret = (unsigned char)(c) + (33 * ret);
    }

    return ret % table_size;
}

bool is_prime(const int num)
{
    if (num % 2 == 0)
    {
        return false;
    }

    for (int i = 3; i < num; i += 2)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}