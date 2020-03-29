#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 20
typedef struct 
{
    int key;
    char x[MAX];
    char v[MAX];
}DT;
typedef struct NODE
{
  DT x;
  struct NODE *Left ;
  struct NODE *Right;
}NODE;
typedef struct NODE* LIST;
void Empty(LIST *T);
NODE *CreatNODE(DT x);
void Insert(LIST *T , DT x);
void NODE_2child(LIST *X, LIST *Y);
NODE *Search(LIST *T,DT x);
NODE *Delete(LIST *T,DT x);
void FreeLIST(LIST *T);
