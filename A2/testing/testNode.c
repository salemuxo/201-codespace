#include "../ht_impl.h"
#include <stdio.h>
#include <string.h>

int main()
{
    
    struct node* first = node_create("key1", "val1");
    struct node* second = node_create("key2", "val2");
    struct node* third = node_create("key3", "val3");

    printf("%s, %s\n", first->key, (char*)first->value);
    printf("%s, %s\n", second->key, (char*)second->value);
    printf("%s, %s\n", third->key, (char*)third->value);

    return 0;
}