#include <stdio.h>
#include <stdlib.h>

typedef int item;
typedef struct Node
{
  item Data;
  struct Node *Left , *Right;
}Node;

typedef struct Node *Tree;
//Khởi tạo
void Init(Tree *T)
{
  (*T) = NULL;
}
//kiểm tra rỗng
int EmptyTree(Tree  T)
{
   return T==NULL;
}
//Truy cập con trỏ trái , phải
Tree  LeftChild(Tree T)
{

   if (T!=NULL)
     return T->Left;
   else return NULL;
}

Tree RightChild(Tree T)
{
   if (T!=NULL)
     return T->Right;
    else   return NULL;
}
//Tạo Node
Node *makeNode(item x)
{
  Node *P =(Node *)malloc(sizeof(Node));
  if(P == NULL)
    {
      printf("Can't creat P\n");
      return NULL;
    }
  P-> Data = x;
  P->Left = P->Right = NULL;
  return P;
}
//kiểm tra xem node có là lá ko
int IsLeaf(Tree  T)
{
    if(T!=NULL)
	return(LeftChild(T)==NULL)&&(RightChild(T)==NULL);
    else    return -1;
}

//đếm số lượng Node
int countLeafNode(Tree T)
{
  if( T == NULL)
    return 0;
  else
    return( countLeafNode( LeftChild(T)) +  countLeafNode(RightChild(T)))+1;
}

//Tạo 1 cây từ 2 cây con
Tree makesubtree(item V , Tree L , Tree R)
{
    Tree *N = (Tree *)malloc(sizeof(Tree));
    (*N)->Data = V;
    (*N)->Left = L;
    (*N)->Right = R;
    return R;
}
// Thêm nút mới vào vị trí bên trái nhất
Tree Add_Left(Tree *T, item NewData)
{
      Node *New = makeNode(NewData);
      if (*T == NULL)
         *T = New;
      else
        {
           Node *Lnode = *T;
           while (Lnode->Left != NULL)
             Lnode = Lnode->Left;
             Lnode->Left = New;
        }
      return New;
}
// Thêm nút mới vào vị trí bên Phải nhất
Tree Add_Right(Tree *T, item NewData)
{
      Node *New = makeNode(NewData);
      if (New == NULL)
        return (New);
      if (*T == NULL)
        *T = New;
      else
      {
          Node *Rnode = *T;
          while (Rnode->Right != NULL)
             Rnode = Rnode->Right;
             Rnode->Right = New;
       }
        return New;
}
//Tra lai chieu cao cho cay
int high(Tree T)
{
 if(T == NULL) return 0;
 else
 {
     if(high(T->Left) > high(T->Right))
       return high(T->Left)+1;
    else
       return high(T->Right)+1;
}
}
//TRa lai so luong la
int numLeaf(Tree T)
{
    int leaf =0;
    if (T !=NULL)
    {
        if(T->Left == NULL && T->Right == NULL)
          leaf++;
        else 
         leaf = numLeaf(LeftChild(T))+numLeaf(RightChild(T));
    }
    return leaf;

}
//Tra lai so luong Node
int numInternal(Tree T)
{
    int count =0;
    if(!EmptyTree(T))
    {
        if((T->Left !=NULL) || (T->Right != NULL))
        {
            count = 1;
            if(T->Left !=NULL)
            count += numInternal(T->Left);
            if(T->Right !=NULL)
            count += numInternal(T->Right);
        }
    }
    return count;
}
//Dem so luong con phai
int numRightChild(Tree T)
{
    if(EmptyTree(T)) return 0;
    if(T->Right !=NULL)
    return 1 + numRightChild(T->Right)+numRightChild(T->Left);
    else return numRightChild(T->Left);
}

int main()
{
     Node *T = (Node *)malloc(sizeof(Node));
     EmptyTree(T);
     Init(&T);
     for(int i=1 ; i<=10 ; i++)
     {
        if( i%2) Add_Right(&T,i);
        else Add_Left(&T,i);

     }
     printf("numRightChild = %d\n",numRightChild(T));
     printf("NumInternal = %d\n",numInternal(T));
     printf("High = %d\n",high(T));
     
}