#include "ring.h"
#include <stdio.h>
#include <stdlib.h>


void displayMenu(){
  printf("\nm -- display menu\n");
  printf("t -- travel to next station\n");
  printf("a -- add new station\n");
  printf("d -- delete current station\n");
  printf("l -- list stations\n");
  printf("r -- rename current station\n");
  printf("c -- clear all stations\n");
  printf("q -- exit program\n");
}


int main() {
  char *input;
  node *currentNode = new_ring();
  displayMenu();

  while(1){
    printf("\nCurrent station : %s\n", currentNode->name);
    printf("Enter a command : ");
    input = inputFromUser();

    switch(input[0]) {
      case 'm':
      displayMenu();
      break;

      case 't':
      currentNode = travel(currentNode);
      break;

      case 'a':
      printf("Enter new station name : ");
      input = inputFromUser();
      currentNode = new_node(input, currentNode);
      printf("Station added.\n");
      break;

      case 'd':
      currentNode = delete_node(currentNode);
      printf("Station deleted.\n");
      break;

      case 'l':
      printf("\n-----");
      list(currentNode);
      printf("-----\n");
      break;

      case 'r':
      printf("Enter new name for station : ");
      input = inputFromUser();
      currentNode = rename_node(input, currentNode);
      printf("Station renamed.\n");
      break;

      case 'c':
      currentNode = new_ring();
      printf("All stations cleared.\n");
      break;

      case 'q':
      return(0);

      default:
      printf("Invalid command.\n");
      break;
    }
  }
}
