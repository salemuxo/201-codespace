#include "../ht_impl.h"
#include <stdio.h>
#include <string.h>

int main()
{
    
    struct entry* first = entry_create("key1", "val1");
    struct entry* second = entry_create("key2", "val2");
    struct entry* third = entry_create("key3", "val3");

    printf("%s, %s\n", first->key, (char*)first->value);
    printf("%s, %s\n", second->key, (char*)second->value);
    printf("%s, %s\n", third->key, (char*)third->value);

    entry_free(first);
    entry_free(second);
    entry_free(third);

    return 0;
}