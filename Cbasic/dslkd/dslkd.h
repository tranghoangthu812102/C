#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int item
typedef struct Node
{
  item  data;
  struct Node *next;
}Node;

Node *head = NULL;
Node *tail = NULL;

Node *makeNode(item data);
void insert_first(item data);
void insert_last(item data);
void insertP_sauQ(Node * P ,item data);
void insertP_truocQ(Node *P ,item data);
void chenvitribatki(Node *P ,int vtri);
void del_Node();
void del_first();
void del_last();
void xoasau(Node *Q);
void xoabatki(int data);
void daoNguocDS();
void searchMoveToFront(item data);
void searchTranspose(item data);
