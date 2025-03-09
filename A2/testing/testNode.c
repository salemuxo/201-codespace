#include "../ht_impl.h"
#include <stdio.h>

int main()
{
    node first = {"key1", "val1"};
    node second = {"key2", "val2"};
    node third = {"key3", "val3"};

    printf("%s, %s\n", first.key, first.value);
    printf("%s, %s\n", second.key, second.value);
    printf("%s, %s\n", third.key, third.value);

    return 0;
}