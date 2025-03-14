#include "../ht_impl.h"
#include "../ht.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    hashtable table;
    table = ht_create();

    if (table == NULL)
    {
        printf("Allocation failed.");
    }

    ht_insert(table, "key0", "val0");
    ht_insert(table, "key1", "val1");
    ht_insert(table, "key2", "val2");
    ht_insert(table, "key3", "val3");
    ht_insert(table, "key4", "val4");
    ht_insert(table, "key5", "val5");
    ht_insert(table, "key6", "val6");
    ht_insert(table, "key7", "val7");
    ht_insert(table, "key8", "val8");
    ht_insert(table, "key9", "val9");
    ht_insert(table, "key10", "val10");
    ht_insert(table, "key11", "val11");
    ht_insert(table, "key12", "val12");
    ht_insert(table, "key13", "val13");
    ht_insert(table, "key14", "val14");

    for (int i = 0; i < 15; i++)
    {
        char key[12]; 
        sprintf(key, "key%d", i);

        char* val = (char *)ht_lookup(table, key);

        printf("%s, ", val);
    }
    printf("\n");

    ht_remove(table, "key1");
    ht_remove(table, "key5");
    ht_remove(table, "key9");
    ht_remove(table, "key13");

    for (int i = 0; i < 15; i++)
    {
        char key[12]; 
        sprintf(key, "key%d", i);

        char* val = (char *)ht_lookup(table, key);

        printf("%s, ", val);
    }
    printf("\n");

    ht_free(table);

    return 0;
};