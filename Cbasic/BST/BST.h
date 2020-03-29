#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
typedef struct 
{
    char Model[MAX];
    int x;
}DT;
typedef struct NODE
{
  DT x;
  struct NODE *Left ;
  struct NODE *Right;
}NODE;
typedef struct NODE* TREE;
void Empty(TREE *T);
NODE *CreatNODE(DT x);
void Insert(TREE *T , DT x);
void NLR(TREE *T);
NODE *Search(TREE *T,DT x);
void NODE_2child(TREE *X, TREE *Y);
NODE *Delete(TREE *T,DT x);
void FreeTREE(TREE *T);