/** 
 * @file dictionary.c
 * @author Lehem Temesgen
 * @version 12/08/2023
 * @brief A contact directory implemented using a hashtable for storing & retrieving email addresses.
 * 
 * This file is the main interface for the program. It demonstrates
 * the programs key functionalities by creating a dictionary (hash table) and adds multiple key-value 
 * pairs (name and email address) to the dictionary. It also includes examples of how to use the 
 * functions (put, get, replace, and clear as well as tests them.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

int main(void)
{
    printf("Creating a dictionary of names & email addresses\n");
    dict_t *addresses = make_dictionary();

    printf("Adding key: %s, value: %s\n", "Lynn", "lynn.marshall@carleton.ca");
    put(addresses, "Lynn", "lynn.marshall@carleton.ca");

    // Multiple keys can be associated with the duplicate values
    printf("Adding key: %s, value: %s\n", "Don", "donald.bailey@carleton.ca");
    put(addresses, "Don", "donald.bailey@carleton.ca");
    printf("Adding key: %s, value: %s\n", "Donald", "donald.bailey@carleton.ca");
    put(addresses, "Donald", "donald.bailey@carleton.ca");

    printf("Adding key: %s, value: %s\n", "Babak", "babak.esfandiari@carleton.ca");
    put(addresses, "Babak", "babak.esfandiari@carleton.ca");
    printf("Adding key: %s, value: %s\n", "Greg", "gregory.franks@carleton.ca");
    put(addresses, "Greg", "gregory.franks@carleton.ca");
    printf("Adding key: %s, value: %s\n", "Jason", "jason.jaskolka@carleton.ca");
    put(addresses, "Jason", "jason.jaskolka@carleton.ca");

    printf("Email for Babak is %s\n", get(addresses, "Babak"));
    printf("Email for Lynn is %s\n", get(addresses, "Lynn"));
    printf("Email for Jason is %s\n", get(addresses, "Jason"));
    printf("Email for Don is %s\n", get(addresses, "Don"));
    printf("Email for Donald is %s\n", get(addresses, "Donald"));
    printf("Email for Greg is %s\n", get(addresses, "Greg"));

    printf("Changing %s to %s\n", "Babak", "babak@sce.carleton.ca");
    put(addresses, "Babak", "babak@sce.carleton.ca");
    printf("Email for Babak is now %s\n", get(addresses, "Babak"));

    printf("\n***Testing print dictionary***\n");
    print_dictionary(addresses);

    // test replace function
    printf("\n***Testing replace function***\n");

    _Bool result = replace(addresses, "Babak", "babak@sce.carleton.ca");
    if (result)
    {
        printf("Replace successful.\n");
    }
    else
    {
        printf("Key not found; dictionary not changed.\n");
    }

    printf("Email for Babak is now %s\n", get(addresses, "Babak"));

    // print dictionary to verify no changes
    print_dictionary(addresses);

    printf("\n***Testing clear function***\n");
    clear(addresses);

    print_dictionary(addresses);

    return EXIT_SUCCESS;
}
