#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct param_node {
  char *value;
  struct param_node *right, *left;
};

typedef struct param_node Node;

void insert(Node **tree, Node *item) {
  if(!(*tree)) {
    *tree = item;
    return;
  }
  if(strcmp(item->value, (*tree)->value) > 0) 
    insert(&(*tree)->left, item);
  else if(strcmp((*tree)->value, item->value) > 0)
    insert(&(*tree)->right, item);
}

void sortparam(Node *tree, char out[]) {
  if(tree->right) sortparam(tree->right, out);
  strcat(out, tree->value);
  strcat(out, ";");
  if(tree->left) sortparam(tree->left, out);
}

static char * urlsort(char *in) {
  Node *root, *current;
  root = NULL;

  char *tok, *result;
  result = (char*)malloc(sizeof(char));
  result = strtok(in, "?");

  while(1) {
    current = (Node* )malloc(sizeof(Node));
    current->left = current->right = NULL;
    tok = strtok(NULL, ";");
    if(tok == NULL) break;
    current->value = tok;
    insert(&root, current);
  }
  char* sorted_url;
  sorted_url = (char*)malloc(sizeof(char));
  sortparam(root, sorted_url);
  strcat(result, "?");
  strcat(result, sorted_url);
  return result;
}

int main(int argc, char *argv[]) {
  char *out;
  out = urlsort(argv[1]);
  puts(out);
}

