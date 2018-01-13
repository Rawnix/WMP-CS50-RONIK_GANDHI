/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#include "dictionary.h"

int words = 0;


node* root = NULL;

void fillNode(node* n)
{
    n->isIt = false;
    for(int i=0; i<27; i++)
    {
        n->next[i] = NULL;
    }
}

// deletes the given node location and also all its contents recursively
void delWholeNode(node* ptr)
{

    // exit condition : if no node is there at the location pointed by ptr
    if(ptr == NULL) return;

    // delete all child nodes
    for(int i=0; i<27; i++)
    {
        delWholeNode(ptr->next[i]);
        ptr->next[i] = NULL;
    }

    // delete the given node itself
    free(ptr);
    ptr = NULL;

}


/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    // TODO
    int len = strlen(word);

    // check if the word is not null
    if(len == 0) return false;

    node* ptr = root;   // ptr will traverse through trie
    int index = 0;      // the index of character in the word we are reading

    while(ptr != NULL)
    {
        if(word[index] == '\'') ptr = ptr->next[0];
        else ptr = ptr->next[(int)tolower(word[index])-96];

        index++;

        if(index == len)    // when all the characters of the word are scanned
        {
            if((ptr == NULL) || !ptr->isIt) return false;
            else return true;
        }
    }

    return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    // TODO

    // initialization of dictionary
    root = (node*)malloc(sizeof(node));
    fillNode(root);
    // memset(&(root->next[0]), 0, 27);

    // opening file stream for reading the dictionary
    FILE* fp = fopen(dictionary, "r");

    // check if the file stream is succesfully opened
    if(fp == NULL) return false;

    // pointer that will traverse through trie
    node* ptr = root;

    // start reading from file
    for(int c = fgetc(fp); c != EOF; c = fgetc(fp))
    {

        if(feof(fp)) return false;

        if(c == '\n')
        {
            ptr->isIt = true;
            ptr = root;
            words++;
        }
        else
        {
            if(c == '\'')
            {
                if(ptr->next[0] == NULL)
                {
                    ptr->next[0] = (node*)malloc(sizeof(node));
                    fillNode(ptr->next[0]);
                }
                // ptr->isIt = false;
                ptr = ptr->next[0];
                // memset(&(ptr->next[0]), 0, 27);
            }
            else
            {

                if(ptr->next[(int)c - 96] == NULL)
                {
                    ptr->next[(int)c - 96] = (node*)malloc(sizeof(node));
                    fillNode(ptr->next[(int)c - 96]);
                }
                // ptr->isIt = false;
                ptr = ptr->next[(int)c - 96];
                // memset(&(ptr->next[0]), 0, 27);
            }
        }
    }

    fclose(fp);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return words;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    // TODO

    delWholeNode(root);

    return true;
}
