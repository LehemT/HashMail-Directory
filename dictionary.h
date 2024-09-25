/** 
 * @file dictionary.c
 * @author Lehem Temesgen
 * @version 12/08/2023
 * @brief A contact directory implemented using a hashtable for storing & retrieving email addresses.
 * 
 * This header file contains the necessary function declarations and structs for creating and manipulating a dictionary.
 */

#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__

#define TABLESIZE 11

typedef struct entry {
    struct entry *next;  // next entry in the linked list
    char *key;
    char *value;         // value associated with the key
} entry_t;

/* A variable of type *dict_t is a pointer to a dictionary;
 * that is, a pointer to the first element in hash table.
 */
typedef entry_t *dict_t;

dict_t *make_dictionary(void);
char *get(dict_t *dict, char *key);
void put(dict_t *dict, char *key, char *value);

// function declerations
void print_dictionary(dict_t *dict);
_Bool replace(dict_t *dict, char *key, char *value);
void clear(dict_t *dict);
#endif


