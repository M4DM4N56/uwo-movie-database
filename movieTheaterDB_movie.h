#ifndef MOVIETHEATERDB_MOVIE_H
#define MOVIETHEATERDB_MOVIE_H

#include "movieTheaterDB.h"  // points to movieTheaterDB header

// movie node structure
typedef struct MovieNode {
    int code;
    char name[100];
    char genre[25];
    float rating;
    struct MovieNode* next;
} MovieNode;

void insertMovie(MovieNode** head);
void searchMovie(MovieNode* head);
void updateMovie(MovieNode* head);
void printMovies(MovieNode* head);
void eraseMovie (MovieNode** head);

#endif
