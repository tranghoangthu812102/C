#include <stdio.h>
#include <stdlib.h>
//Khai bao cau truc 1 node
typedef int item;
typedef struct Node
{
  int Data;//dữ liệu mà nó sẽ lưu trữ
  struct Node *Left ;
  struct Node *Right;
}Node;
void Init(Node **T);
Node  *LeftChild(Node *T);
Node  *RightChild(Node *T);
Node *makeNode(int x);
int IsLeaf(Node  *T);
int countLeafNode(Node *T);
void insertNode(Node **T , int x);
Node *  Add_Left(Node *T, item NewData);
Node * Add_Right(Node  *T, item NewData);
void LNR(Node *T);
void LRN(Node *T);
void NRL(Node *T);
