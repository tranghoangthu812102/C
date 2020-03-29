#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
typedef struct
{
  int x;
  char b[20];
  int mau;
  int tc;
  int nn;
  int pt;
}DT;
typedef struct NODE
{
  DT x;
  struct NODE *next;
  struct NODE *prew;
}NODE;
typedef struct
{
  NODE *Head;
  NODE *Tail;
  int Sum;
}LIST;
void Empty(LIST *l);
int isEmpty(LIST *l);
NODE *CreatNODE(DT a);
void EnQueue(LIST *l,DT a);
void Free(LIST *l);
DT DeQueue(LIST *l);
