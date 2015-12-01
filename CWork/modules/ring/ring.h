#include <stdbool.h>


typedef char *item;

struct node;
typedef struct node node;


// Create a new empty ring of items.
node *new_ring();

node *new_node(char *station, node *currentNode);

node *delete_node(node *currentNode);

node *travel(node *currentNode);
