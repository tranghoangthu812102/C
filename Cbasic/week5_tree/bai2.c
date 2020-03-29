#include <stdio.h>
#include <stdlib.h>

typedef int item;
typedef struct NODE
{
  item key;
  struct NODE *Left ;
  struct NODE *Right;
}NODE;
typedef struct NODE* TREE;
void Empty(TREE *T)  
{
  *T = NULL;
}
NODE *CreatNODE(item key)
{
  NODE *P =(NODE *)malloc(sizeof(NODE));
  P->key= key;
  P->Left = P->Right = NULL;
  return P;
}
int Insert(TREE *T , item x)
{
  if(*T != NULL )
    {
      if((*T)->key == x) return -1;	     
      if((*T)->key >x) 
         return Insert(&(*T)->Left,x);
      else Insert(&(*T)->Right,x);
    }
  else *T = CreatNODE(x); 
}
NODE *Search(TREE *T,item x)
{
  if(*T)
    {
      if((*T)->key == x)	return *T;
      if((*T)->key > x)	return Search(&(*T)->Left,x);
      return Search(&(*T)->Right,x);
    }
  return NULL;
}
void NODE_2child(TREE *X, TREE *Y)
{
    if((*Y)->Left ) NODE_2child(X, &(*Y)->Left);
    else
    {
        (*X)->key=(*Y)->key;
        *X = *Y;
        *Y = (*Y)->Right;
    }
}
NODE *Delete(TREE *T,item x)
{
    if(*T == NULL) 
    {
        printf("Not found\n");
        return NULL;
    }
    if((*T)->key > x) Delete(&(*T)->Left,x);
    else if ((*T)->key < x) Delete(&(*T)->Right,x);
    else
    {
        NODE *X = *T ; 
        if((*T)->Left == NULL) *T = (*T)->Right;
        else if((*T)-> Right == NULL) *T = (*T)->Left;
        else  NODE_2child(&X,&(*T)->Right);
        return X;
    }
}
void FreeTREE(TREE *T)
{
  if(*T)
    {
      FreeTREE(&(*T)->Left);
      FreeTREE(&(*T)->Right);
      free(*T);
    }
}
void LNR(NODE *T)
{
    if(T !=NULL)
    {
        LNR(T->Left);
        printf("%d ",T->key);
        LNR(T->Right);
    }
}
void NLR(NODE *T)
{
  if(T!=NULL)
    {
      printf("%d ",T->key);
      NLR(T->Left);
      NLR(T->Right);
    }
}
//Tìm MAX trong cây nhị phân
int SearchMax(TREE T)
{
    if( T-> Right == NULL)
        return T->key;
    return SearchMax(T->Right);
}
//Tìm MIN trong cây nhị phân
int SearchMin(TREE T)
{
    if(T->Left == NULL )
        return T->key;
    return SearchMin(T->Left);
}

int main()
{
    TREE T ;
    Empty(&T);
    int i , n ,k;
    int a[]={43,31,64,20,28,33,40,56,89,47,59};
    for(i =0 ; i<11 ; i++)
    Insert(&T,a[i]);
    printf("1.Nhap vao 1 so can tim kiem : ");
    scanf("%d%*c",&n);
    TREE P = Search(&T,n);
    if(P != NULL) 
    printf("==>>Phan tu %d do co trong cay\n",n);
    else printf("==>>Phan tu %d khong co trong cay\n",n);
    printf ("2.In theo thu tu tu be den lon\n");
    LNR(T);
    printf("\n");
    printf("3.Phan tu nho nhat la %d\n",SearchMin(T));
    printf("4.Phan tu lon nhat la %d\n",SearchMax(T));
    printf("5.In thu tu cua cay \n");
    NLR(T);
    printf("\n");
    printf("6.Nhap phan tu can xoa : ");
    scanf("%d%*c",&k);
    Delete(&T,k);
    printf("Da xoa thanh cong\n");
    printf("=>>cay sau khi xoa phan tu %d la : \n",k);
    NLR(T);
    printf("\n");
    FreeTREE(&T);
}