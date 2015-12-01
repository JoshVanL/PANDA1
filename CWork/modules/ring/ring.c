#include "ring.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>




node *new_ring() {
  node *p = malloc(sizeof(node));
  p->next = p;
  p->previous = p;
  p->name = "Start Station";
  return p;
}


node *new_node(char *station, node *currentNode) {
  node *n = malloc(sizeof(node));
  n->name = station;
  node *temp = currentNode->next;
  currentNode->next = n;
  n->previous = currentNode;
  n->next = temp;
  if (temp != NULL){
    temp->previous = n;
  }
  return n;
}

node *delete_node(node *currentNode){
  node *n = currentNode->next;
  currentNode->previous->next = currentNode->next;
  currentNode->next->previous = currentNode->previous;
  free(currentNode);
  return n;
}


node *travel(node *currentNode){
  return currentNode->next;
}


char *inputFromUser() {
  int bufferSize = 100;
  char *buffer = malloc(sizeof(char)*bufferSize);
  char *input = buffer;
  fgets(input, bufferSize, stdin);
  size_t ln = strlen(input) - 1;
  if (input[ln] == '\n') input[ln] = '\0';

  return input;
}
