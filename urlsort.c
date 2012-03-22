#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <syslog.h>

struct param_node {
  char *value;
  struct param_node *right, *left;
};

typedef struct param_node Node;

static void insert(Node **tree, Node *item) {
  if(!(*tree)) {
    *tree = item;
    return;
  }
  if(strcmp(item->value, (*tree)->value) > 0) 
    insert(&(*tree)->left, item);
  else if(strcmp((*tree)->value, item->value) > 0)
    insert(&(*tree)->right, item);
}

static void sortparam(Node *tree, char *out) {
  if(tree->right) sortparam(tree->right, out);
  strcat(out, tree->value);
  strcat(out, "&\0");
  if(tree->left) sortparam(tree->left, out);
}

void freetree(Node *root)
{
  if(root!=NULL)
  {
    freetree(root->left);
    freetree(root->right);
    free(root);
  }
}

static char * urlsort(char *in) {
  Node *root, *current;
  root = NULL;

  char *token, *sorted_params, *url, *params, *tmp;
  sorted_params = (char*) malloc(strlen(in));
  
  url = strdup(in);
  params = strchr(url, '?');
  if(params == NULL) return in;
  params[0] = '\0';
  
  for(token = strtok_r(++params, "&", &tmp); token; token = strtok_r(NULL , "&", &tmp)) {
      current = (Node* )malloc(sizeof(Node));
      current->left = current->right = NULL;
      if(token == NULL) break;
      current->value = token;
      insert(&root, current);
  }
  
  if(root == NULL) return in;
  sorted_params[0] = 0;
  sortparam(root, sorted_params);
  strcat(url, "?");
  sorted_params[strlen(sorted_params) - 1] = 0; 
  strcat(url, sorted_params);
  free(token);
  free(sorted_params);
  free(tmp);
  freetree(root);
  return url;
}

