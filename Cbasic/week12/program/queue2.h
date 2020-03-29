#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
typedef struct
{
  char ID[20];
  int Memory;
}elem;
typedef struct Node
{
    elem Data;
    struct Node * Next;
    struct Node * prev;
}Node;
typedef struct
{
    Node *Front,*Rear;//Node đầu , node cuối
    int Sum;
}Queue;
void Init(Queue *Q);
int Isempty(Queue *Q);
Node *MakeNode(elem x);
void EnQueue(Queue *Q, elem x);
void Free(Queue *Q);
elem DeQueue(Queue *Q);
