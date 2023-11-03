// CS2211b 2023
// Assignment 4
// Jawaad Ahmar
// 251237757
// jahmar 
// 09/03/2023

// import librariess
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// import file containing headers
#include "headers.h"


// initializer function initializes a paragraph
para para_ini(void) {
    para p;
    p = (para) malloc(sizeof(para_struct));
    p->lp = NULL;
    p->size=0;
    return p;
}

// destructor function frees memory in a paragraph
void para_free(para p) {
    int i;
    for (i=0; i<p->size; i++) {
        line_free(p->lp[i]);
    }
    free(p); 
}

// function adds a line to a paragraph
void para_add(para p, line l) {
    if (p->size == 0) {
        p->lp = (line*) malloc(sizeof(line));
    } else {
        p->lp = (line*) realloc(p->lp,(p->size+1)*(sizeof(line)));
    }
    p->size++;
    p->lp[p->size-1] =  malloc((sizeof(line)));
    p->lp[p->size-1] = l;
}

// function prints the contents of a paragraph
void para_print(para p) {
    for (int i = 0; i < p->size; i++) {
        line_print(p->lp[i]);
    }
}

// function searches a paragraph for a string 
int para_search_print(para p, char *str) {
    bool found = false;
    for (int i = 0; i < p->size; i++) {
        if (line_search(p->lp[i],str,i) == 0) {
            found = true;
        }
    }
    if (found == false) {
        printf("\n----No Match Found----\n");
        return 1;
    } else {
        return 0;
    }
}