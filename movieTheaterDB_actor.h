#ifndef MOVIETHEATERDB_ACTOR_H
#define MOVIETHEATERDB_ACTOR_H

#include "movieTheaterDB.h"  // points to movieTheaterDB header

// actor structure
typedef struct ActorNode {
    int code;
    char name[50];
    int age;
    char imdbProfile[50];
    struct ActorNode* next;
} ActorNode;

void insertActor(ActorNode** head);
void searchActor(ActorNode* head);
void updateActor(ActorNode* head);
void printActors(ActorNode* head);
void eraseActor (ActorNode** head);

#endif