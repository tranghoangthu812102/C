#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree2search.h"

int isEmpty(node *root)
{
  return root == NULL;
}

void deleteTree(node *root)
{
  if (root != NULL)
    {
      deleteTree(root->left);
      deleteTree(root->right);
      free(root);
    }
}

node *makeNode(elType data)
{
  node *p = (node *) malloc(sizeof(node));
  if (p == NULL)
    return NULL;
  p->data = data;
  p->left = NULL;
  p->right = NULL;
  return p;
}

void insertTree(node **root, elType data)
{
  node *p = makeNode(data);
  if (*root == NULL)
    *root = p;
  else
    {
      if (strcmp((*root)->data.name, data.name) > 0)
	insertTree(&(*root)->left, data);
      else if (strcmp((*root)->data.name, data.name) < 0)
	insertTree(&(*root)->right, data);
      else
	printf("Trung lap du lieu!\n");
    }
}

node *searchTree(node *root, elType data)
{
  if (root == NULL)
    return NULL;

  if (strcmp(root->data.name, data.name) > 0)
    searchTree(root->left, data);
  else if (strcmp(root->data.name, data.name) < 0)
    searchTree(root->right, data);
  else
    return root;
}

node *removeNodeTree(node *root, elType data)
{
  if (root == NULL)
    return NULL;

  node *p;
  if (strcmp(root->data.name, data.name) > 0)
    root->left = removeNodeTree(root->left, data);
  else if (strcmp(root->data.name, data.name) < 0)
    root->right = removeNodeTree(root->right, data);
  else
    {
      if (root->left == NULL)
	{
	  p = root;
	  root = root->right;
	  free(p);
	}
      else if (root->right == NULL)
	{
	  p = root;
	  root = root->left;
	  free(p);
	}
      else
	{
	  p = root->right;
	  node *parent = NULL;
	  while (p->left != NULL)
	    {
	      parent = p;
	      p = p->left;
	    }
	  strcpy(root->data.name, p->data.name);

	  if (parent != NULL)
	    parent->left = removeNodeTree(parent->left, parent->left->data);
	  else
	    root->right = removeNodeTree(root->right, root->right->data);
	}
    }
  
  return root;
}


