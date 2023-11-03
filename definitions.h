// CS2211b 2023
// Assignment 4
// Jawaad Ahmar
// 251237757
// jahmar 
// 09/03/2023

// type definitions for word line and para
typedef struct {
    char *cp;
    int size;
} word_struct;
typedef word_struct* word;

typedef struct {
    word *wp;
    int size;
} line_struct;
typedef line_struct* line;

typedef struct {
    line *lp;
    int size;
} para_struct;
typedef para_struct* para;