#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
  FILE *fin = fopen ("test.txt", "r");
  char c = fgetc(fin);
  while (! feof(fin)){
    printf("%c", c);
    c = fgetc(fin);
  }
  fclose(fin);
}
