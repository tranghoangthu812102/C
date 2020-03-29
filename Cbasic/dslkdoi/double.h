#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
typedef struct 
{
  char Model[15];
  char Mem[10];
  char Sign[10];
  char Gia[10];
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
    NODE *Cur;
}LIST;
void Empty(LIST *l);
NODE *CreatNODE(DT a);
void AddHead(LIST *l,DT a);
void AddTail(LIST *l,DT a);
void AddBefor(LIST *l,DT a);
void Free(LIST *l);
void InsertPos(LIST *l, DT p,int n);
void AddNODE(LIST *l,DT p);
void DeleteHeal(LIST *l);
void DeleteTail(LIST *l);
void DeleteCur(LIST *l);
void DeletePos(LIST *l,int x);
LIST *SeverseLIST(LIST *l);