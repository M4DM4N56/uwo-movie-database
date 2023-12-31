#include "movieTheaterDB_movie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void insertMovie(MovieNode** head) {
    int code;
    char name[100];
    char genre[25];
    float rating;

    // prompt uer for movie details
    printf("Enter movie code: ");

    if (scanf("%d", &code) != 1 || code < 0) {
        printf("Error: invalid code\n");
        while (getchar() != '\n');  // clear input buffer
        return;
    } // if

    // check for duplicate movie code
    MovieNode* current = *head;
    while (current != NULL) {
        if (current->code == code) {
            printf("Error: movie code taken\n");
            return;
        } // if
        current = current->next;
    } // while


    printf("Enter movie name: ");
    scanf(" %99[^\n]", name);
    printf("Enter movie genre: ");
    scanf(" %24[^\n]", genre);

    printf("Enter movie rating: ");
    if (scanf("%f", &rating) != 1 || rating < 0.0 || rating > 10.0) {
        printf("Error: invalid rating\n");
        while (getchar() != '\n');  // clear input buffer
        return;
    } // if

    // Create a new movie node
    MovieNode* newMovie = (MovieNode*)malloc(sizeof(MovieNode));
    if (newMovie == NULL) {
        printf("Error: memory issue\n");
        return;
    } // if
    newMovie->code = code;
    strcpy(newMovie->name, name);
    strcpy(newMovie->genre, genre);
    newMovie->rating = rating;

    // insert node
    newMovie->next = *head;
    *head = newMovie;

    printf("Movie inserted successfully\n");
} // method insert


void searchMovie(MovieNode* head) {
    int code;

    // prompt user for code
    printf("Enter movie code to search: ");
    if (scanf("%d", &code) != 1 || code < 0) {
        printf("Error: invalid movie code\n");
        while (getchar() != '\n');  // clear input buffer
        return;
    } // if


    // search though LL for movie
    const MovieNode* current = head;
    while (current != NULL) {
        if (current->code == code) {
            printf("Movie found!\n");
            printf("Code: %d\n", current->code);
            printf("Name: %s\n", current->name);
            printf("Genre: %s\n", current->genre);
            printf("Rating: %.2f\n", current->rating);
            return;
        } // if
        current = current->next;
    } // while

    printf("Movie not found\n");
} // method search


void updateMovie(MovieNode* head) {
    int code;
    char name[100];
    char genre[25];
    float rating;

    // prompt user for code
    printf("Enter movie code to update: ");
    if (scanf("%d", &code) != 1 || code < 0) {
        printf("Error: invalid movie code\n");
        while (getchar() != '\n');  // clear input buffer
        return;
    } // if

    // update though LL for movie
    MovieNode *current = head;
    while (current != NULL) {
        if (current->code == code) {

            printf("Enter movie name: ");
            scanf(" %99[^\n]", name);
            printf("Enter movie genre: ");
            scanf(" %24[^\n]", genre);

            printf("Enter movie rating: ");
            if (scanf("%f", &rating) != 1 || rating < 0.0 || rating > 10.0) {
                printf("Error: invalid rating\n");
                while (getchar() != '\n');  // clear input buffer
                return;
            } // if

            // update movie details
            strcpy(current->name, name);
            strcpy(current->genre, genre);
            current->rating = rating;

            printf("Movie updated successfully\n");
            return;
        } // if
        current = current->next;
    } // while
} // method update


void printMovies(MovieNode* head) {
    const MovieNode* current = head;

    // print formatted header
    printf("%-10s %-30s %-15s %-10s\n", "Code", "Name", "Genre", "Rating");

    // print formatted movie information
    while (current != NULL) {
        printf("%-10d %-30s %-15s %-10.2f\n", current->code, current->name, current->genre, current->rating);
        current = current->next;
    } // while

} // method print


void eraseMovie(MovieNode** head) {
    MovieNode* current = *head;
    MovieNode* prev = NULL;

    int code;

    // Prompt user for movie code to erase
    printf("Enter movie code to erase: ");
    if (scanf("%d", &code) != 1 || code < 0) {
        printf("Error: invalid movie code\n");
        while (getchar() != '\n');  // clear input buffer
        return;
    } // if

    // search through LL
    while (current != NULL) {
        if (current->code == code) {
            // movie is first node
            if (prev == NULL) *head = current->next;
            // movie is somewhere else in the LL
            else prev->next = current->next;

            free(current); // free memory

            printf("Movie erased successfully\n");
            return;

        } // if

        prev = current;
        current = current->next;
    } // while

    printf("Movie not found!\n");
} // method erase