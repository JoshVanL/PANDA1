#include "ring.h"
#include <stdio.h>
#include <stdlib.h>


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
