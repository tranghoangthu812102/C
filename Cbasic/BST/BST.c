#include "BST.h"
void Empty(TREE *T)  
{
  *T = NULL;
}
NODE *CreatNODE(DT x)
{
  NODE *P =(NODE *)malloc(sizeof(NODE));
  P->x = x;
  P->Left = P->Right = NULL;
  return P;
}
void Insert(TREE *T , DT x)
{
  if(*T )
    {
      if(strcmp((*T)->x.Model,x.Model)==0) (*T)->x.x++;	     
      else if(strcmp((*T)->x.Model,x.Model)>0) Insert(&(*T)->Left ,x);
      else Insert(&(*T)->Right,x);
    }
  else *T = CreatNODE(x); 
}
NODE *Search(TREE *T,DT x)
{
  if(*T)
    {
      if(strcmp((*T)->x.Model,x.Model)==0)	return *T;
      if(strcmp((*T)->x.Model,x.Model)>0)	return Search(&(*T)->Left,x);
      return Search(&(*T)->Right,x);
    }
  return NULL;
}
void NODE_2child(TREE *X, TREE *Y)
{
    if((*Y)->Left ) NODE_2child(X, &(*Y)->Left);
    else
    {
        strcpy((*X)->x.Model,(*Y)->x.Model);
        *X = *Y;
        *Y = (*Y)->Right;
    }
}
NODE *Delete(TREE *T,DT x)
{
    if(*T == NULL) 
    {
        printf("Not found\n");
        return NULL;
    }
    if(strcmp((*T)->x.Model,x.Model)>0) Delete(&(*T)->Left,x);
    else if (strcmp((*T)->x.Model,x.Model)<0) Delete(&(*T)->Right,x);
    else
    {
        NODE *X = *T ; 
        if((*T)->Left == NULL) *T = (*T)->Right;
        else if((*T)-> Right == NULL) *T = (*T)->Left;
        else  NODE_2child(&X,&(*T)->Right);
        return X;
    }
}
void FreeTREE(TREE *T)
{
  if(*T)
    {
      FreeTREE(&(*T)->Left);
      FreeTREE(&(*T)->Right);
      free(*T);
    }
}