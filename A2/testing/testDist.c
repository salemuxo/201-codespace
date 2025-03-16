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
    ht_insert(table, "yeah", "stuff");
    ht_insert(table, "stuff", "things");
    ht_insert(table, "more things", "uh huh");
    ht_insert(table, "yet again", "words and words");
    ht_insert(table, "even more", "a value to store");
    ht_insert(table, "stuffery", "storage");
    ht_insert(table, "keys", "memory");
    ht_insert(table, "more keys", "yep");
    ht_insert(table, "finally", "yeah");

    ht_print_dist(table);

    ht_free(table);
    return 0;
}