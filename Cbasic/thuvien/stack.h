#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct DT
{
  int x;
}DT;
typedef struct NODE
{
	DT x;
	struct NODE *next;
}NODE;
typedef struct LIST
{
	NODE *Head;
}LIST;
int isEmpty(LIST *l);
NODE *CreatNODE(DT x);
void Push(LIST *l,DT x);
DT Pop(LIST *l);
void Free(LIST *l);
LIST *SeverseLIST(LIST *l);
