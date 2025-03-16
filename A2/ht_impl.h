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

/*
Struct to represent a hash table

Fields:
    struct entry** array: pointer to an array of pointers to entries
    int capacity: the total number of 
*/
struct ht {
    struct entry** array;
    int capacity;
    int size;
};

/*
Purpose: Calculates the load factor of a hash table (size / capacity)
Parameters:
    struct ht* table: the hash table to calculate the load factor of
Returns: double - the load factor of the hash table
*/
double ht_load(const struct ht* table);

/*
Purpose: Resizes the hash table to the next prime number after the current capacity * SCALE_FACTOR.
Parameters:
    struct ht* table: the hash table to resize
Returns: Nothing, but resizes the hash table.
*/
void ht_resize(struct ht* ht);

/*
Purpose: Finds the index of a key in a hash table.
Parameters:
    const struct ht* ht: the hash table to search
    const char* key: the key to search for
Returns: int - The index of the key in the hash array, or -1 if the key is not found.
*/
int ht_find_key(const struct ht* ht, const char* key);

/*
Struct to represent a single entry in a hash table.

Fields:
    char* key: the key to lookup the entry in the table
    char* value: the value associated with the key 
    bool deleted: whether the entry has been deleted
*/
struct entry {
    char* key;
    char* value;
    bool deleted;
};

/*
Purpose: Creates a new entry with the given key and value.
Parameters:
    const char* key: the key to associate with the entry
    const char* value: the value to associate with the entry
Returns:
    struct entry* - a pointer to the newly created entry
*/
struct entry* entry_create(const char* key, const char* value);

/*
Purpose: Frees the memory associated with an entry.
Parameters:
    struct entry* entry: the entry to free
Returns: Nothing, but frees the memory associated with the entry.
*/
void entry_free(struct entry* entry);

/*
Purpose: Deletes an entry by freeing the memory associated with it, setting the key and value to empty strings, and setting deleted to true.
Parameters:
    struct entry* entry: the entry to delete
Returns: Nothing, but deletes the entry.
*/
void entry_delete(struct entry* entry);

/*
Purpose: Hashes a string to a 64-bit unsigned integer.
Parameters: 
    const char* s: the string to hash
Returns: uint64_t - the hash of the string
*/
uint64_t hash(const char *s);

/*
Purpose: Determines whether a number is prime.
Parameters:
    int num: the number to check
Returns: bool - true if the number is prime, false otherwise
*/
bool is_prime(int num);

/*
Purpose: Finds the next prime number after a given number.
Parameters:
    const int num: the number to find the next prime after
Returns: int - the next prime number after the given number
*/
int next_prime(const int num);

#endif
