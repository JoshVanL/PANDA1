#include "ring.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct node {
  char *name;
  struct node *next;
  struct node *previous;
};





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


int main() {
  char *input;
  node *currentNode = new_ring();
  printf("t -- travel to next station\n");
  printf("a -- add new station\n");
  printf("d -- delete current station\n");
  printf("q -- exit program\n");

  while(1){
    printf("\nCurrent station : %s\n", currentNode->name);
    printf("Enter a command : ");
    input = inputFromUser();

    switch(input[0]) {
      case 't':
      currentNode = travel(currentNode);
      break;
      case 'a':
      printf("Enter new station name : ");
      input = inputFromUser();
      currentNode = new_node(input, currentNode);
      printf("Station added.");
      break;
      case 'd':
      currentNode = delete_node(currentNode);
      printf("Station deleted.");
      break;
      case 'q':
      return(0);
      default:
      printf("Invalid command.");
      break;
    }
  }
}
