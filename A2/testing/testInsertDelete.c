#include "../ht_impl.h"
#include "../ht.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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

    assert(table->size == 5);
    assert(ht_load(table) == 5.0 / 17.0);
    assert(ht_load(table) == (double)table->size / (double)table->capacity);

    ht_insert(table, "key5", "val5");
    ht_insert(table, "key6", "val6");
    ht_insert(table, "key7", "val7");
    ht_insert(table, "key8", "val8");
    ht_insert(table, "key9", "val9");

    assert(table->size == 10);
    assert(ht_load(table) == (double)table->size / (double)table->capacity);

    ht_insert(table, "key10", "val10");
    ht_insert(table, "key11", "val11");
    ht_insert(table, "key12", "val12");
    ht_insert(table, "key13", "val13");
    ht_insert(table, "key14", "val14");

    assert(table->size == 15);

    for (int i = 0; i < 15; i++)
    {
        char key[12]; 
        sprintf(key, "key%d", i);

        char* val = ht_lookup(table, key);

        printf("%s, ", val);
    }
    printf("\n");

    ht_remove(table, "key1");
    ht_remove(table, "key3");
    ht_remove(table, "key5");
    ht_remove(table, "key7");
    ht_remove(table, "key9");
    ht_remove(table, "key11");
    ht_remove(table, "key13");

    assert(table->size == 8);
    assert(ht_load(table) == 8.0 / 29.0);
    assert(ht_load(table) == (double)table->size / (double)table->capacity);

    for (int i = 0; i < 15; i++)
    {
        char key[12]; 
        sprintf(key, "key%d", i);

        char* val = ht_lookup(table, key);

        printf("%s, ", val);
    }
    printf("\n");

    ht_insert(table, "key1", "val1");
    ht_insert(table, "key3", "val3");
    ht_insert(table, "key5", "val5");
    ht_insert(table, "key7", "val7");
    ht_insert(table, "key9", "val9");
    ht_insert(table, "key11", "val11");
    ht_insert(table, "key13", "val13");

    assert(table->size == 15);
    assert(ht_load(table) == 15.0 / 29.0);
    assert(ht_load(table) == (double)table->size / (double)table->capacity);

    for (int i = 0; i < 15; i++)
    {
        char key[12]; 
        sprintf(key, "key%d", i);

        char* val = ht_lookup(table, key);

        printf("%s, ", val);
    }
    printf("\n");

    ht_free(table);

    return 0;
};