// CS2211b 2023
// Assignment 4
// Jawaad Ahmar
// 251237757
// jahmar 
// 09/03/2023

// import libraries
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// import file containing headers
#include "headers.h"


// initializer function initializes a line
line line_ini(void) {
    line l;
    l = (line) malloc(sizeof(line_struct));
    l->wp = NULL;
    l->size = 0;
    return l;
}

// destructor function frees memory in a line
void line_free(line l) {
    for (int i=0; i<l->size; i++) {
        word_free(l->wp[i]);
    }
    free(l); 
}

// function adds a word to a line
void line_add(line l, word w) {
    if (l->size == 0) {
        l->wp = (word*) malloc(sizeof(word));
    } else {
        l->wp = (word*) realloc(l->wp,(l->size+1)*sizeof(word));
    }
    l->size++;
    l->wp[l->size-1] =  malloc((sizeof(word)));
    l->wp[l->size-1] = w;
}

// function prints the contents of a line
void line_print(line l) {
    for (int i = 0; i < l->size; i++) {
        word_print(l->wp[i]);
    }
}

// function searches a line for a string
int line_search(line l, char *str, int pos) {
    bool found = false;
    for (int i = 0; i < l->size; i++) {
        if (word_cmp(str,l->wp[i]) == 0) {
            printf("\n----Match Found----\n");
            printf("\nLine: %d", pos + 1);
            printf("\nIndex: %d", i);
            found = true;
        }
    }
    if (found == true) {
        return 0;
    } else {
        return 1;
    }
}


