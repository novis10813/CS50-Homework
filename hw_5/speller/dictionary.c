// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int hash_value = hash(word);
    node *cursor = table[hash_value];
    while(cursor != NULL) {
        if (strcasecmp(cursor->word, word) == 0) {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}
int total_words = 0;
// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *data = fopen(dictionary, "r");
    if (data == NULL) {
        printf("Error loading\n");
        return false;
    }

    char words[LENGTH+1];
    while (fscanf(data, "%s", words) != EOF) {
        node *new = malloc(sizeof(node));
        if (new == NULL) {
            return false;
        }
        strcpy(new->word, words);
        new->next = NULL;

        int index = hash(words);

        if (table[index] == NULL) {
            table[index] = new;
        }
        else {
            new->next = table[index];
            table[index] = new;
        }
        total_words++;
        // printf("%s\n", word);
    }
    fclose(data);
    
    
    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return total_words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++) {
        // ith hash table index
        node *cursor = table[i];
        node *tmp = cursor;
        while (cursor != NULL) {
            cursor = cursor->next;
            free(tmp);
            tmp = cursor;
        }
    }
    return true;
}
