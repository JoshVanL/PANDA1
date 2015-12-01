#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>


//Define list structure
typedef struct node {
  struct node *next;
  char word[20];
  int count;
} node_t;

void addWord(node_t * root, char string[20], int n) {
  node_t * current = root;
  bool match = false;
  while(current != NULL) {
    if (current->word[0] == string[0]){
      match = true;
      for(int i = 1; i < n; i++){
        if (string[i] != current->word[i]) match = false;
      }
      if (match = true) {
        for(int i = 0; i < n; i++){
          current->word[i] = string[i];
        }
        current->count++;
        current->next = malloc(sizeof(node_t));
        current->next->next = NULL;
        return;
      }
    }
    current = current->next;
  }
  for(int i = 0; i < n; i++){
    current->word[i] = string[i];
  }
  current->count++;
  current->next = malloc(sizeof(node_t));
  current->next->next = NULL;
}




//Read in file and extract words
void readfile(char *filename, node_t * root){
  char word[20];
  FILE *in = fopen(filename, "r");
  int i;
  char check[] = ". ,;:*!?'-\n\0\r";
  while (! feof(in)) {
    i = 0;
    word[i] = fgetc(in);
    if ( feof(in)) break;
    while(strchr(check, word[i]) == NULL){
      printf("%c", word[i]);
      i++;
      word[i] = fgetc(in);
    }
  //  addWord(root, word, i);
    printf("--");
  }
  fclose(in);
  printf("\n");
  printf("\nEOF\n");
}

// take one word
// find posistion in list
// add to list




int main(int argc, char *args[argc]){
  char *filename = args[1];
  node_t * root = NULL;
  root = malloc(sizeof (node_t));
  root->next = NULL;
  root->count = 0;
  root->word[0] = '#';
  readfile(filename, root);
  return 0;
}
