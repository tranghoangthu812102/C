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
}DB;

typedef struct Node
{
  DB  data;
  struct Node *next;
}Node;

Node *head;
Node *tail;

DB *nhapTuBanPhim(DB *data);
Node *makeNode(DB data);
void insert_first(DB data);
void insert_last(DB data);
int len(Node *k);
void insert_Position();
void del_Node();
void del_first();
void del_last();
void del_Position();
void daoNguocDS();
int searchMoveToFront(DB data);
int searchTranspose(DB data);

#endif
