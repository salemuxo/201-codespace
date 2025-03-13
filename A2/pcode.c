#include <stdio.h>
#include "ht.h"
#include "ht_impl.h"

int main()
{
    hashtable table;
    table = ht_create();

    if (table == NULL)
    {
        printf("Allocation failed.");
    }

    ht_insert(table, "key1", "val1");
    ht_insert(table, "key2", "val2");

    printf("One: %s, %s\n", (char *)ht_lookup(table, "key1"), (char *)ht_lookup(table, "key2"));

    ht_remove(table, "key1");

    printf("Two: %s, %s\n", (char *)ht_lookup(table, "key1"), (char *)ht_lookup(table, "key2"));

    ht_insert(table, "key1", "val1");

    printf("Three: %s, %s\n", (char *)ht_lookup(table, "key1"), (char *)ht_lookup(table, "key2"));

    ht_free(table);

    return 0;
}