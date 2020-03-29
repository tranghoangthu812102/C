#include <stdio.h>
#include <stdlib.h>

typedef int item; 
struct Node
{
  item Data;
  Node *Left , *Right;
}Node;

typedef Node *Tree;

void Init(Tree **T)
{
  *T == NULL;
}
int EmptyTree(Tree  T)
{
   return T==NULL;
}
Tree  *LeftChild(Tree *T)
{

   if (T!=NULL)
     return T->Left;
     return NULL;
}

Tree *RightChild(Tree *T)
{
   if (T!=NULL)
     return T->Right;
     return NULL;
}

Node *makeNode(item x)
{
  Node *P =(Node *)malloc(sizeof(Node));
  if(P == NULL)
    {
      printf("Can't creat P\n");
      return NULL;
    }
  P-> Data = x;
  P->Left = P->Right = NULL;
  return P;
}

int IsLeaf(Tree  *T)
{
    if(T!=NULL)
	return(LeftChild(T)==NULL)&&(RightChild(T)==NULL);
        return -1;
}
int dem(Tree *T)
{
  if( T == NULL)
  return 0;
 else
   return (dem(T->Left) + dem(T->Right) +1);
}

