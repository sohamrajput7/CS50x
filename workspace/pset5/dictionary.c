/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>
#include <ctype.h>

#include "dictionary.h"

#define HASHTABLES 27

typedef struct node
{
    char* word;
    struct node* next;
}
node;

node* hashtable[HASHTABLES];

char word[LENGTH + 1];

int counter = 0;

// prototype
int hash(const char* word);

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // TODO
    node* checker = malloc(sizeof(node));
    
    checker = hashtable[hash(word)];
    while(checker != NULL)
    {
        if (strcasecmp(checker->word, word) == 0)
        {
            return true;
        }
        checker = checker->next;
    }
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // TODO
    FILE* dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        printf("Could not open file.\n");
        return false;
    }
    
    while(fscanf(dict, "%s\n", word) != EOF)
    {
        node* new_node = malloc(sizeof(node));
        new_node->word = malloc(strlen(word) + 1);
        strcpy(new_node->word, word);
        
        int hashed_int = hash(word);
        
        if (hashtable[hashed_int] == NULL)
        {
            hashtable[hashed_int] = new_node;
            new_node->next = NULL;
        }
        
        else
        {
            new_node->next = hashtable[hashed_int];
            hashtable[hashed_int] = new_node;
        }
        counter++;
    }
    
    fclose(dict);
    return true;
}

/**
 * Returns number of word in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return counter;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    for(int i = 0; i < HASHTABLES; i++)
    {
        node* cursor = hashtable[i];
        
        while(cursor != NULL)
        {
            node* temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
        hashtable[i] = NULL;
    }
    return true;
}

int hash(const char* word)
{
    int index = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        index += tolower(word[i]);
    }
    return index % HASHTABLES;
}
