// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

#include "dictionary.h"

int numberOfWords = 0;
// Represents a node in a hash table
struct node
{
    char word[LENGTH + 1];
    struct node *next;
};

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
struct node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int location = hash(word);
    struct node *curr = malloc(sizeof(struct node));
    curr = table[location];
    while(curr != NULL){
        if(strcasecmp(curr -> word, word) == 0){
            return true;
        }
        curr = curr -> next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int firstLetter = toupper(word[0]) - 'A';
    // int secondLetter = toupper(word[1]) - 'A';
    // int position = firstLetter*26 + secondLetter;
    return firstLetter;
    // return position;
    // return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    for (int i = 0; i < N; i++){
        table[i] = NULL;
    }
    FILE *dict = fopen(dictionary, "r");
    if(dict == NULL){
        printf("could not open dictionary\n");
        return false;
    }
    char temp[LENGTH];
    struct node *newStr;
    while(fscanf(dict, "%s", temp) != EOF){
        numberOfWords++;
        newStr = malloc(sizeof(struct node));
        strcpy(newStr -> word, temp );
        newStr -> next = NULL;

        int hashed = hash(temp);

        if(table[hashed] == NULL){
            table[hashed] = newStr;
        }
        else{
            newStr -> next = table[hashed];
            table[hashed] = newStr;
        }

    }

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return numberOfWords;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
      for (int i = 0; i < N; i++) {
        struct node *curr = table[i];
        while (curr != NULL) {
            struct node *next = curr->next;
            free(curr);
            curr = next;
        }
      }
    return true;
}
