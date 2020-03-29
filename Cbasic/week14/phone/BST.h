#ifndef N
#define N

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char model[20];
  char rom  [8];
  char inch [15];
  char tien [15];
}elmType;

typedef struct Node
{
  elmType data;
  struct Node *Left ;
  struct Node *Right;
}Node;
elmType *nhapTuBanPhim(elmType *data);
void Init(Node **T);
int compare(elmType x, elmType y);
Node *makeNode(elmType x);
void insertNode(Node **T,elmType x);
Node *Search(Node *T,elmType x);
void NLR(Node *T);
//void saveFileDat();

Node *Del_Node(Node *T,elmType data);
void freeTree(Node *T);

#endif
