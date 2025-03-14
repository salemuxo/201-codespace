#include "ht_impl.h"
#include "ht.h"
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#define SCALE_FACTOR 1.5

double ht_load(struct ht* ht)
{
    // load factor is size / capacity
    return (double)ht->size / (double)ht->capacity;
}

void ht_resize(struct ht* ht)
{
    // new capacity is next prime after current capacity * scale factor
    int new_capacity = next_prime(ht->capacity * SCALE_FACTOR);

    // allocate new array of pointers to entries
    struct entry** new_array = malloc(new_capacity * sizeof(struct entry*));
    if (new_array == NULL)
    {
        return;
    }

    // initialize each entry to NULL
    for (int i = 0; i < new_capacity; i++)
    {
        new_array[i] = NULL;
    }

    // store all entries in a temporary array
    struct entry* entries[ht->size];
    int entry = 0;

    for (int i = 0; i < ht->capacity; i++)
    {
        if (ht->array[i] != NULL)
        {
            entries[entry++] = ht->array[i];
        }
    }

    // free old array and update hashtable fields
    free(ht->array);
    ht->array = new_array;
    ht->capacity = new_capacity;
    ht->size = 0;

    // reinsert all entries
    for (int i = 0; i < entry; i++)
    {
        struct entry* entry = entries[i];
        ht_insert(ht, entry->key, entry->value);
        entry_free(entry);
    }
}

int ht_find_key(const struct ht* ht, const char* key)
{
    int start = hash(key) % ht->capacity;

    for (int i = 0; i < ht->capacity; i++)
    {
        int index = (start + i) % ht->capacity;
        if (ht->array[index] == NULL)
        {
            continue;
        }
        if (strcmp(ht->array[index]->key, key) == 0)
        {
            return index;
        }
    }

    return -1;
}

struct entry* entry_create(const char* key, void* value)
{
    struct entry* create;

    create = malloc(sizeof(struct entry));
    if (create == NULL)
    {
        return NULL;
    }

    create->key = malloc(strlen(key) + 1);
    if (create->key == NULL)
    {
        free(create);
        return NULL;
    }
    strcpy(create->key, key);

    create->value = value;

    return create;
}

void entry_free(struct entry* entry)
{
    if (entry == NULL)
    {
        return;
    }

    free(entry->key);
    free(entry);
}

uint64_t hash(const char *s)
{
    uint64_t ret = 5831;
    char c;

    while ((c = *s++))
    {
        ret = (unsigned char)(c) + (33 * ret);
    }

    return ret;
}

bool is_prime(const int num)
{
    // 2 is always prime
    if (num == 2)
    {
        return true;
    }
    // 1 or divisible by 2 is not prime
    else if ((num <= 1) | (num % 2 == 0))
    {
        return false;
    }
    
    // check divisibility by every odd number from 3 to num
    for (int i = 3; i < num; i += 2)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int next_prime(const int num)
{
    int i = num + 1;

    // if num is negative or 0, return 2
    if (num <= 0)
    {
        return 2;
    }
    // if num is even, make start point odd
    else if (i % 2 == 0)
    {
        i += 1;
    }
    // loop through each odd number until 2*num, return if prime
    for ( ; i < num * 2; i += 2)
    {
        if (is_prime(i))
        {
            return i;
        }
    }
    // if no prime found, return -1 (shouldnt happen?)
    return -1;
}