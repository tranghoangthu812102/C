#ifndef N
#define N

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
}elm;

typedef struct Node
{
  elm  data;
  struct Node *next;
}Node;
Node *head;
Node *tail;

Node *makeNode(elm data);
void insert_first(elm data);
void insert_last(elm data);
int len(Node *k);
void del_Node();
void del_first();
void del_last();
void del_Position(int n);
void daoNguocDS();


#endif
