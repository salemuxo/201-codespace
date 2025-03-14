#include "../ht.h"
#include "../ht_impl.h"

int main()
{
    hashtable table;
    table = ht_create();

    if (table == NULL)
    {
        printf("Allocation failed.");
    }

    for (int i = 0; i < 20; i++)
    {
        char key[8]; 
        sprintf(key, "key%d", i);
        
        char val[8];
        sprintf(val, "val%d", i);

        ht_insert(table, key, val);

        printf("(%s, %lf); ", (char *)ht_lookup(table, key), ht_load(table));
    }
    printf("\n");

    return 0;
}