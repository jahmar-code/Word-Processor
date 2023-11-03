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

// main function handles input and calls functions accordingly
int main(void) {
    bool loopVar = true;

    // char array for user input
    char str[1024];

    para p = para_ini();

    // while loop iterates until user enters a blank line
    while (loopVar == true) {
        printf("\nPlease enter a line of text: ");
        fgets(str, sizeof(str), stdin);
        if (str[0] == '\n') {
            goto jump;
        }

        // for loop parses words from input and adds to word and line constructs
        int wordLen = 0;
        line l = line_ini();
        for (int i = 0; str[i] != '\0'; i++) {
            if ((str[i] == ' ') || (str[i] == '\n')) {
                if (wordLen == 0) {
                   goto next;
                } else {
                    word w = word_ini();
                    char *ptr = (char*) malloc((wordLen)*sizeof(char)); 
                    strncpy(ptr,&str[i-wordLen],wordLen); 
                    word_str_cp(w,ptr);
                    line_add(l,w);
                    next:
                        wordLen = 0;
                }
            } else {
                wordLen++;
            }  
        }
        para_add(p,l);
    }
    jump: 
        para_print(p);

    // while loop iterates until user enters a blank line
    while (loopVar == true) {
        memset(str, 0, sizeof(str));
        printf("\nPlease enter a word to search for: ");
        fgets(str, sizeof(str), stdin);
        if (str[0] == '\n') {
            goto end;
        }

        // function checks if input is in paragraph
        para_search_print(p,str);
    }
    end:
        printf("\n----Exit----");
        return 0;
}