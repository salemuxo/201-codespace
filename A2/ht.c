/* ht.c
 *
 * TODO: Provide a high-level description of what is contained
 * in this file.
 *
 * Author: Salem Stockdale
 * Lab instructor: Salwa Abougamila
 * Lecture instructor: Ardy RD
 */

#include "ht.h"      /* Import the public hashtable header. */
#include "ht_impl.h" /* Also import the private header, just for us! */
#include <stdint.h>
#include <string.h>

#define MAX_LOAD 2.0 / 3.0

hashtable ht_create(void)
{
    hashtable create;

    // allocate memory for hashtable itself
    create = malloc(sizeof(struct ht));
    if (create == NULL)
    {
        return NULL;
    }

    // allocate memory for entry array (initial capacity 17)
    create->array = calloc(17, sizeof(struct entry*));
    if (create->array == NULL)
    {
        free(create);
        return NULL;
    }
    // initialize size and capacity
    create->capacity = 17;
    create->size = 0;

    return create;
}

void ht_free(hashtable ht)
{
    // if ht is already a null pointer, nothing to free
    if (ht == NULL)
    {
        return;
    }

    // free each entry in array
    for (int i = 0; i < ht->capacity; i++)
    {
        entry_free(ht->array[i]);
    }

    // free array and hashtable itself
    free(ht->array);
    free(ht);
}

void ht_insert(hashtable ht, char *key, void *value)
{
    // create the entry to insert
    struct entry* insert = entry_create(key, value);

    // starting index is hash constrained to capacity
    int start = hash(key) % ht->capacity;

    for (int i = 0; i < ht->capacity; i++)
    {
        // loop through each index starting at start
        int index = (start + i) % ht->capacity; 
        // if location is empty, insert here
        if (ht->array[index] == NULL)
        {
            ht->array[index] = insert;
            ht->size++;
            break;
        }
    }
    
    // if load exceeded max, resize
    if (ht_load(ht) > MAX_LOAD)
    {
        ht_resize(ht);
    }
}

void *ht_lookup(const hashtable ht, const char *key)
{
    int index = ht_find_key(ht, key);
    if (index == -1)
    {
        return NULL;
    }

    return ht->array[index]->value;
}

void ht_remove(hashtable ht, const char *key)
{
    int index = ht_find_key(ht, key);
    if (index == -1)
    {
        return;
    }

    // free the entry that was at index
    entry_free(ht->array[index]);
    ht->array[index] = NULL;
    ht->size--;

    for (int i = 1; i < ht->capacity; i++)
    {
        // loop through following entries
        int current = (index + i) % ht->capacity;

        // if next entry is not null, remove and reinsert
        if (ht->array[current] != NULL)
        {
            struct entry* entry = ht->array[current];
            ht->array[current] = NULL;
            ht->size--;

            ht_insert(ht, entry->key, entry->value);
            continue;
        }
        // if next entry is null, return
        else 
        {
            return;
        }
    }
}

void ht_print_dist(const hashtable ht)
{
    return;
}

void ht_foreach(const hashtable ht, ht_iter f)
{
    return;
}