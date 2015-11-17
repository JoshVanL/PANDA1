#include <stdio.h>
#include <stdlib.h>

int fib(int n){
  if (n < 2) return n;
  return fib(n-1) + fib(n-2);

}

int main(int argc, char *argv[]) {
  int j = atoi(argv[1]);
  for(int x = 0; x <= j; x++){
    printf("%d ", fib(x));
  }
  printf("\n");
  return 0;
}
