#include <stdbool.h>

struct tree;
typedef struct tree tree;

tree *new_tree();

void insert_tree(tree *t, int n);

bool search_tree(tree *t, int n);
