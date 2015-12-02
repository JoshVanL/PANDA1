#include "ring.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Display command menu
void displayMenu(){
  printf("\nm -- display menu\n");
  printf("t -- go to next item\n");
  printf("b -- go to previous item\n");
  printf("s -- go to start of list\n");
  printf("a -- add new item to next\n");
  printf("p -- add new item to previous\n");
  printf("r -- rename current item\n");
  printf("d -- delete current itemn\n");
  printf("l -- list items\n");
  printf("n -- dispay number of items\n");
  printf("c -- clear all items\n");
  printf("q -- exit program\n");
}

//Take input from the user
char *inputFromUser() {
  int bufferSize = 100;
  char *buffer = malloc(sizeof(char)*bufferSize);
  char *input = buffer;
  if (fgets(input, bufferSize, stdin) != NULL){
    size_t ln = strlen(input) - 1;
    if (input[ln] == '\n') input[ln] = '\0';
    return input;
  }
  return "";
}


//Executes users commands on the list
int main() {
  char *input;
  displayMenu();
  ring *r = new_ring();
  rename_Item(r, ">First Item<");

  while(1){
    printf("\nCurrent item : %s\n", pull(r));
    printf("Enter a command : ");
    input = inputFromUser();

    switch(input[0]) {
      case 'm':
      displayMenu();
      break;

      case 't':
      next(r);
      break;

      case 'b':
      previous(r);
      break;

      case 'a':
      printf("Enter new item name : ");
      input = inputFromUser();
      push_next(r, input);
      printf("Item added.\n");
      break;

      case 'p':
      printf("Enter new item name : ");
      input = inputFromUser();
      push_previous(r, input);
      printf("Item added.\n");
      break;

      case 'd':
      r = delete_Item(r);
      printf("Item deleted.\n");
      break;

      case 'l':
      printf("\n-----\n");
      start_ring(r);
      printf("%s\n", pull(r));
      next(r);
      while(isStart_ring(r) != true){
        printf("%s\n", pull(r));
        next(r);
      }
      printf("-----\n");
      break;

      case 'n':
      printf("Number of items: %i\n", sizeOf_ring(r));
      break;

      case 'r':
      printf("Enter new name for item : ");
      input = inputFromUser();
      r = rename_Item(r, input);
      printf("Item renamed.\n");
      break;

      case 's':
      start_ring(r);
      printf("Returning to start item.\n");
      break;

      case 'c':
      free(r);
      r = new_ring();
      printf("All items cleared.\n");
      rename_Item(r, ">First Item<");
      break;

      case 'q':
      return(0);

      default:
      printf("Invalid command.\n");
      break;
    }
  }
}
