#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

typedef struct
{
  char model[20];
  char rom  [8];
  char inch [15];
  char tien [15];
}elem;

typedef struct Node
{
  elem  data;
  struct Node *next;
  struct Node *prev;
}Node;

Node *head = NULL;
Node *tail = NULL;
Node *cur  = NULL;

Node *makeNode(elem  data);
void insert_first(elem data);
void insert_last(elem data);
void insert_before(elem data);
void Free();
void insert_Position();
void ADDNode();
void del_first();
void del_last();
void Del_Cur();
void Del_Position(int n);

