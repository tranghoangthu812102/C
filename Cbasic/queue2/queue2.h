#include <stdio.h>
#include <stdlib.h>

typedef int item ;
typedef struct
{
    item Data;
    struct Node * Next;
    struct Node * prev;
}Node;

typedef struct
{
    Node *Front,*Rear;//Node đầu , node cuối
   
}Queue;


void Init(Queue *Q);
int Isempty(Queue *Q);
Node *MakeNode(item x);
void EnQueue(Queue *Q, item x);
int DeQueue(Queue *Q);
