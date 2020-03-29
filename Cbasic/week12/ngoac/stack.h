#include <stdio.h>
#include <stdlib.h>
typedef int item; //kieu du lieu
typedef struct 
{
  char Data;
  int N;
}elem;
typedef struct Node
{
    item Data;
     struct Node *Next;//link
}Node;

typedef struct
{
   struct Node *Top;
}Stack;
void Init(Stack *S);
int Isempty(Stack *S);
Node *MakeNode(item x);
void Push(Stack *S,item x);
int Peak(Stack S);
int Pop(Stack *S);
