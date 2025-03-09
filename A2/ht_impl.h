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
#ifndef _HT_IMPL_H_
#define _HT_IMPL_H_

/* TODO: think of some things that should go in here! */

typedef struct {
    char* key;
    char* value;
} node;

long long unsigned hash(const char *s, const int table_size);

bool is_prime(int num);

#endif
