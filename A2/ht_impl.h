/* ht_impl.h
 *
 * For any "private"  declarations that should not be visible to the public
 * users of the hash table, but might want to be shared across various source
 * files in the hash table implementation.
 * 
 * It is a common convention to append "_impl" to a private implementation of
 * some public interface, so we do so here.
 *
 * Author: Salem Stockdale
 * Lab instructor: Salwa Abougamila
 * Lecture instructor: Ardy RD
 */

#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#ifndef _HT_IMPL_H_
#define _HT_IMPL_H_

/* TODO: think of some things that should go in here! */

// hashtable stuff

struct ht {
    struct node** array;
    int capacity;
    int size;
};

double ht_load(struct ht* table);

void ht_resize(struct ht* ht);

int ht_find_key(const struct ht* ht, const char* key);

// node stuff

struct node {
    char* key;
    void* value;
};

struct node* node_create(const char* key, void* value);

void node_free(struct node* node);

// other stuff

uint64_t hash(const char *s);

bool is_prime(int num);

int next_prime(const int num);

#endif
