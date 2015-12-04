#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct node {
  struct node *left;
  char word[20];
  int count;
  struct node *right;
};
typedef struct node node;

struct tree {
  struct node *rootNode;
  struct node *currentNode;
};



tree *new_tree() {
  tree *newTree = commit malloc(sizeof(tree));
  newTree->rootNode = newTree->currentNode = NULL;
  return newTree;
}


node *new_node(char *word ){
  node *p = malloc(sizeof(node));
  *p = (node) {NULL, word, 1, NULL};
  return p;
}

node *insert_node(node *p, char *word){
  if (p == NULL) p = new_node(n);
  else if (strcmp)/////////////////////
  else if (n < p->key)
  p->left = insert_node(p->left, n);
  else if (n > p->key)
  p->right = insert_node(p->right, n);
  return p;
}

void insert_tree(tree *t, int n) {
  t->currentNode = insert_node(t->rootNode, n);
}

node *find_node(node *p, int n){
  if(p == NULL) {}
  else if (n < p->key)
  p = find_node(p->left, n);
  else if (n > p-> key)
  p = find_node(p->right, n);
  return p;
}

bool search_tree(tree *t, int n) {
  return find_node(t,n) != NULL;
}




int main() {

  return 0;
}
