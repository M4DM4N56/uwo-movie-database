#include "movieTheaterDB_actor.h"
#include <stdio.h>
#include <stdlib.h>


void insertActor(ActorNode** head) {
    int code, age;
    ActorNode *newActor = (ActorNode*)malloc(sizeof(ActorNode));
    ActorNode *current = *head;

    printf("Enter actor code: ");
    scanf("%d", &code);

    // iterates through the LL to check for duplicate codes
    while (current != NULL) {
        if (current->code == code) {
            printf("Error: Actor code must be unique. Try again.\n");
            // free memory
            free(newActor);
            return;
        } // if
        current = current->next;
    } // while

    newActor->code = code;

    // clears input buffer
    while (getchar() != '\n');
    newActor->next = NULL;

    // prompt user for actor name
    printf("Enter actor name: ");
    scanf(" %49[^\n]", newActor->name);

    // prompt user for actor age
    printf("Enter actor age: ");
    scanf("%d", &age);

    // age must be reasonable
    if (age < 0 || age > 120) {
        printf("Error: Invalid age. Age must be between 0 and 120. Try again.\n");
        // free memory
        free(newActor);
        return;
    } // if

    newActor->age = age;

    // clears input buffer
    while (getchar() != '\n');

    // prompt user for code and imdb profile
    printf("Enter actor IMDb profile: ");
    scanf(" %49[^\n]", newActor-> imdbProfile);

    // add actor to LL
    if (*head == NULL) *head = newActor;
    else {
        current = *head;
        while (current->next != NULL) current = current->next;
        current->next = newActor;
    } // else

    printf("The actor has been inserted\n");

} // method insert


void searchActor(ActorNode* head) {
    int code;

    // prompt user for code
    printf("Enter actor code: ");
    code = scanf("%d", &code);

    if (code < 0){
        printf("Invalid actor code\n");
        return;
    } // if

    while (getchar() != '\n'); // clears input buffer

    // search in LL using code
    const ActorNode* current = head;

    while (current != NULL) {
        if (current->code == code) {
            printf("Code: %d\n", current->code);
            printf("Name: %s\n", current->name);
            printf("Age: %d\n", current->age);
            printf("IMDb Profile: %s\n", current->imdbProfile);
            return;
        } // if
        current = current->next;
    } // while

    printf("Actor not found!\n");

} // method searchActor


void updateActor(struct ActorNode* head) {
    ActorNode* current = head;

    int code, age;

    // prompt user for code
    printf("Enter actor code to update: ");
    scanf("%d", &code);

    if (code < 0){
        printf("Invalid actor code");
        return;
    } // if

    // search through LL
    while (current != NULL) {
        if (current->code == code) {
            // actor found
            printf("Enter updated actor name: ");
            scanf(" %49[^\n]", current -> name);

            printf("Enter updated actor age: ");
            scanf("%d", &age);
            if (age < 0 || age > 120) {
                printf("Error: Invalid age. Age must be between 0 and 120. Try again.\n");
                return;
            } // if

            printf("Enter updated actor IMDb profile: ");
            scanf(" %49s", current-> imdbProfile);

            current->age = age;

            return;
        } // if
        current = current->next;
    } // while

    printf("Actor not found\n");
} // method update Actor


void printActors(ActorNode* head) {
    const ActorNode* current = head;

    // formatted header
    printf("%-10s %-20s %-10s %-30s\n", "Code", "Name", "Age", "IMDb Profile");

    // formatted details of each actor
    while (current != NULL) {
        printf("%-10d %-20s %-10d %-30s\n", current->code, current->name, current->age, current->imdbProfile);
        current = current->next;
    } // while

} // method print actors


void eraseActor(ActorNode** head) {
    ActorNode* current = *head;
    ActorNode* prev = NULL;

    int searchCode;
    printf("Enter actor code: ");
    scanf("%d", &searchCode);

    // search through LL
    while (current != NULL) {
        if (current->code == searchCode) {
            // actor is first in list
            if (prev == NULL) *head = current->next;
            // skips node entirely and erases the memory
            else prev->next = current->next;
            free(current);

            printf("Actor erased successfully\n");
            return;
        } // if

        prev = current;
        current = current->next;
    } // while

    printf("Actor not found\n");
} // method erase actor
