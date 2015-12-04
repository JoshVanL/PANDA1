#include "ring.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


//Define node structure
struct node {
  char *name;
  struct node *next;
  struct node *previous;
};


typedef struct node node;


//Define ring structure
struct ring {
  struct node *firstNode;
  struct node *currentNode;
  int size;
};


//Create new ring
ring *new_ring(){
  ring *newRing = malloc(sizeof(ring));
  node *newNode = malloc(sizeof(node));
  newRing->firstNode = newNode->next = newNode->previous = newNode;
  newRing->currentNode = newNode;
  newNode->name = NULL;
  newNode->next = newNode;
  newNode->previous = newNode;
  newRing->size = 1;
  return newRing;
}


//Add item next in list
ring *push_next(ring *r, char *name){
  node *newNode = malloc(sizeof(node));
  newNode->name = name;
  newNode->next = r->currentNode->next;
  newNode->previous = r->currentNode;

  r->currentNode->next = newNode;
  newNode->next->previous = newNode;
  r->currentNode = newNode;
  r->size++;
  return r;
}

//Add item previous in list
ring *push_previous(ring *r, char *name){
  node *newNode = malloc(sizeof(node));
  newNode->name = name;
  newNode->next = r->currentNode;
  newNode->previous = r->currentNode->previous;

  r->currentNode->previous->next = newNode;
  r->currentNode->previous = newNode;
  r->currentNode = newNode;
  r->size++;
  return r;
}


//Change current position to next in list
void next(ring *r){
  r->currentNode = r->currentNode->next;
}

//Change position to previous in list
void previous(ring *r){
  r->currentNode = r->currentNode->previous;
}


//Retreive item from current node in list
char *pull(ring *r){
  return r->currentNode->name;
}

//Rename current item in list
ring *rename_Item(ring *r, char *name){
  r->currentNode->name = name;
  return r;
}


//Delete current pointer
ring *delete_Item(ring *r){
  if (r->firstNode != r->currentNode){
    node *delNode = r->currentNode;
    r->currentNode->previous->next = r->currentNode->next;
    r->currentNode->next->previous = r->currentNode->previous;

    free(r->currentNode);
    r->currentNode = delNode->next;
    r->size--;
  }
  return r;
}


void start_ring(ring *r){
  r->currentNode = r->firstNode;
}

bool isStart_ring(ring *r){
  if (r->currentNode == r->firstNode) return true;
  return false;
}

int sizeOf_ring(ring *r){
  return r->size;
}
