#include "BT.h"

void Init(Node **T)
{
  *T = NULL;
}

Node  *LeftChild(Node *T)
{

   if (T!=NULL)
     return T->Left;
     return NULL;
}

Node  *RightChild(Node *T)
{
   if (T!=NULL)
     return T->Right;
     return NULL;
}
//Tao Node
Node *makeNode(int x)
{
  Node *P =(Node *)malloc(sizeof(Node));
  P->Data = x;
  P->Left = P->Right = NULL;
  return P;
}

int IsLeaf(Node  *T)
{
    if(T!=NULL)
	return(LeftChild(T)==NULL)&&(RightChild(T)==NULL);
        return -1;
}

//đếm số lượng Node
int countLeafNode(Node *T)
{
  if( T == NULL)
    return 0;
  else
    return( countLeafNode( LeftChild(T)) +  countLeafNode(RightChild(T)));
}


void insertNode(Node **T , int x)
{
  if(*T !=NULL)
    {
      if((*T)->Data == x)//Node nay da co
	      printf("Phan tu them vao bi trung \n");
	     
      if((*T)->Data > x)
	insertNode(&(*T)->Left ,x);//chen trai
      else if ((*T)->Data < x )
	insertNode(&(*T)->Right,x);//chen phai
    }
  else
      *T = makeNode(x);
      
}
// Thêm nút mới vào vị trí bên trái nhất
Node * Add_Left(Node *T, item NewData)
{
      Node *New = makeNode(NewData);
      if (New == NULL) return (New);
      if (T == NULL)
         T = New;
      else
        {
           Node *Lnode = T;
           while (Lnode->Left != NULL)
             Lnode = Lnode->Left;
             Lnode->Left = New;
        }
      return (New);
}
// Thêm nút mới vào vị trí bên Phải nhất
Node *Add_Right(Node  *T, item NewData)
{
      Node *New = makeNode(NewData);
      if (New == NULL)
        return (New);
      if (T == NULL)
        T = New;
      else
      {
          Node *Rnode = T;
          while (Rnode->Right != NULL)
             Rnode = Rnode->Right;
             Rnode->Right = New;
       }

           return (New);
}
void LNR(Node *T)
{
  if(T!=NULL)
    {
      LNR(T->Left);
      printf("%d  ",T->Data);
      LNR(T->Right);
    }
}
void LRN(Node *T)
{
  if(T!=NULL)
    {
      LRN(T->Left);
      LRN(T->Right);
      printf("%d  ",T->Data);
    }
}
void NRL(Node *T)
{
  if(T != NULL)
    {
      printf("%d  ",T->Data);;
      NRL(T->Right);
      NRL(T->Left);
    }
}
