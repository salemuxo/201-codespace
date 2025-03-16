#include <stdio.h>
#include "../ht.h"

int main()
{
    hashtable table = ht_create();
    ht_insert(table, "a key", "something");
    ht_insert(table, "word", "something else");
    ht_insert(table, "blah blah blah", "another value");
    ht_insert(table, "stufff", "more");
    ht_insert(table, "things", "yet another");
    ht_insert(table, "yup", "even more");

    ht_print_dist(table);
}