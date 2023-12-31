#include "movieTheaterDB.h"
#include "movieTheaterDB_actor.h"
#include "movieTheaterDB_movie.h"

#include <stdio.h>

MovieNode* mHead = NULL;
ActorNode* aHead = NULL;


void helpBlurb() {
    printf("\nWelcome to the 2211 Theater Database!\n\n");
    printf("1. [h] Help: Displays this very helpful display message.\n");
    printf("2. [q] Quit: Closes the program. All data is lost upon closure.\n");
    printf("3. [m] Control Movies: Enter the movie database. You can insert, search, update, erase, and print movie information.\n");
    printf("   3.1 [i] Insert a new movie\n");
    printf("   3.2 [s] Search for a movie\n");
    printf("   3.3 [u] Update a movie\n");
    printf("   3.4 [p] Print the entire list of movies\n");
    printf("   3.5 [e] Erase a movie\n\n");
    printf("4. [a] Control Actors: Enter the movie database. You can insert, search, update, erase, and print actor information.\n\n");
    printf("Commands for Managing Actors:\n");
    printf("   4.1 [i] Insert a new actor\n");
    printf("   4.2 [s] Search for an actor\n");
    printf("   4.3 [u] Update an actor\n");
    printf("   4.4 [p] Print the entire list of actors\n");
    printf("   4.5 [e] Erase an actor\n\n\n\n");
} // method helpBlurb


void controlMovie(){
    char choice = ' ';
    // prompt user for their input
    printf("\nEnter [i], [s], [u], [p], or [e]: ");
    scanf(" %c", &choice);

    // brings user to corresponding function
    switch (choice) {
        case 'i':
            insertMovie(&mHead);
            break;
        case 's':
            searchMovie(mHead);
            break;
        case 'u':
            updateMovie(mHead);
            break;
        case 'p':
            printMovies(mHead);
            break;
        case 'e':
            eraseMovie(&mHead);
            break;
        default:
            printf("Sorry, please enter a valid input ([i], [s], [u], [p], [q] or [e])\n");
    } // switch

} // controlMovie


void controlActor(){
    char choice = ' ';
    // prompt user for their input
    printf("\nEnter [i], [s], [u], [p], or [e]: ");
    scanf(" %c", &choice);

    // brings user to corresponding function
    switch (choice) {
        case 'i':
            insertActor(&aHead);
            break;
        case 's':
            searchActor(aHead);
            break;
        case 'u':
            updateActor(aHead);
            break;
        case 'p':
            printActors(aHead);
            break;
        case 'e':
            eraseActor(&aHead);
            break;
        default:
            printf("Sorry, please enter a valid input ([i], [s], [u], [p], [q] or [e])\n");
    } // switch

} // controlMovie


int main(){
    char choice = ' ';


    // print cool title I generated from website
    printf("\n");
    printf("  ___  ___  __ __   __  __            _         _____ _                            \n");
    printf(" |__ \\|__ \\/_ /_ | |  \\/  |          (_)       / ____(_)                           \n");
    printf("    ) |  ) || || | | \\  / | _____   ___  ___  | |     _ _ __   ___ _ __ ___   __ _ \n");
    printf("   / /  / / | || | | |\\/| |/ _ \\ \\ / / |/ _ \\ | |    | | '_ \\ / _ \\ '_ ` _ \\ / _` |\n");
    printf("  / /_ / /_ | || | | |  | | (_) \\ V /| |  __/ | |____| | | | |  __/ | | | | | (_| |\n");
    printf(" |____|____||_||_| |_|  |_|\\___/ \\_/ |_|\\___|  \\_____|_|_| |_|\\___|_| |_| |_|\\__,_|\n");

    while (1){
        // prompt user for their input
        printf("\nEnter [h], [q], [m], or [a]: ");
        scanf(" %c", &choice);

        // close program and cut off loop if they choose quit
        if (choice == 'q'){
            break;
        } // if

        switch (choice) {
            case 'h':
                helpBlurb();
                break;
            case 'm':
                controlMovie();
                break;
            case 'a':
                controlActor();
                break;
            default:
                printf("Sorry, please enter a valid input ([h], [q], [m], or [a])\n");
        } // switch
    } // while

    return 0;

} // function main