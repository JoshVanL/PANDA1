#include <stdbool.h>


typedef char *item;

struct node {
  char *name;
  struct node *next;
  struct node *previous;
};


typedef struct node node;




// Create a new empty ring of items.
node *new_ring();

node *new_node(char *station, node *currentNode);

node *delete_node(node *currentNode);

node *travel(node *currentNode);

node *rename_node(char *input, node *currentNode);

char *inputFromUser();

void list(node *currentNode);
