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


// initializer function initializes a word 
word word_ini(void) {
    word w;
    w = (word) malloc(sizeof(word_struct));
    w->cp = NULL;
    w->size = 0;
    return w;
}

// destructor function frees memory in a word 
void word_free(word wd) {
  if (wd->cp != NULL) free(wd->cp);
  free(wd);
}

// function creates a word construct from string input
void word_str_cp(word w, char *str) { 
  if (w->cp != NULL) free(w->cp);
  int n = strlen(str);
  w->cp = (char*) malloc((n+1)*sizeof(char));
  w->cp = str;
  w->size = n+1;
}

// function compares a string and a word
int word_cmp(char *str, word b) { 
  if (strlen(str) == b->size) {
    for (int i = 0; i < strlen(str)-1; i++) {
      if (str[i] != b->cp[i]) {
        return 1;
      }
    }
    return 0;
  } else {
    return 1;
  }
}

// function prints the contents of a word
void word_print(word w) {
  for (int i = 0; i < w->size; i++) {
    printf("%c",w->cp[i]);
  } 
  printf(" ");
}