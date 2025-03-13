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

    create = malloc(sizeof(struct ht));
    if (create == NULL)
    {
        return NULL;
    }

    create->array = calloc(17, sizeof(struct node*));
    if (create->array == NULL)
    {
        free(create);
        return NULL;
    }
    create->capacity = 17;
    create->size = 0;

    return create;
}

void ht_free(hashtable ht)
{
    if (ht == NULL)
    {
        return;
    }

    for (int i = 0; i < ht->capacity; i++)
    {
        node_free(ht->array[i]);
    }

    free(ht->array);
    free(ht);
}

void ht_insert(hashtable ht, char *key, void *value)
{
    struct node* insert = node_create(key, value);
    int start = hash(key) % ht->capacity;

    for (int i = 0; i < ht->capacity; i++)
    {
        int index = (start + i) % ht->capacity; 
        if (ht->array[index] == NULL) //  | (ht->array[index]->deleted == true)
        {
            ht->array[index] = insert;
            ht->size++;
            break;
        }
    }

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

    node_free(ht->array[index]);
    ht->array[index] = NULL;

    for (int i = 1; i < ht->capacity; i++)
    {
        int current = (index + i) % ht->capacity;

        if (ht->array[current] != NULL)
        {
            struct node* node = ht->array[current];
            ht->array[current] = NULL;
            ht_insert(ht, node->key, node->value);
            continue;
        }
        else 
        {
            return;
        }
    }

    return;
}

void ht_print_dist(const hashtable ht)
{
    return;
}

void ht_foreach(const hashtable ht, ht_iter f)
{
    return;
}