#include <stdio.h>
#include <stdlib.h>

typedef int item;
struct Node
{
  item Data;
  Node *Left , *Right;
}Node;

typedef Node *Tree;
//Khởi tạo
void Init(Tree **T)
{
  *T == NULL;
}
//kiểm tra rỗng
int EmptyTree(Tree  T)
{
   return T==NULL;
}
//Truy cập con trỏ trái , phải
Tree  *LeftChild(Tree *T)
{

   if (T!=NULL)
     return T->Left;
     return NULL;
}

Tree *RightChild(Tree *T)
{
   if (T!=NULL)
     return T->Right;
     return NULL;
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
int IsLeaf(Tree  *T)
{
    if(T!=NULL)
	return(LeftChild(T)==NULL)&&(RightChild(T)==NULL);
        return -1;
}

//đếm số lượng Node
int countLeafNode(Tree *T)
{
  if( T == NULL)
    return 0;
  else
    return( countLeafNode( LeftChild(T)) +  countLeafNode(RightChild(T)));
}

//Tạo 1 cây từ 2 cây con
Tree makesubtree(item V , Tree L , Tree R)
{
    Tree *N = (Tree *)malloc(sizeof(Tree));
    N->data = V;
    N->Left = L;
    N->Right = R;
    return R;
}

// Thêm nút mới vào vị trí bên trái nhất
Tree Add_Left(Tree *T, item NewData)
{
      Node *New = makeNode(NewData);
      if (New == NULL) return (New);
      if (*T == NULL)
         *T = New;
      else
        {
           Node *Lnode = *T;
           while (Lnode->Left != NULL)
             Lnode = Lnode->Left;
             Lnode->Left = New;
        }
      return (New);
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
        return (New);
}
int main()
{
     Node *T;
     Init(&T);
     int lua_chon,x;
     int b,c,k;
     do
    {
        printf("\n===========================");
        printf("\n~~~~~~~~~~~MENU~~~~~~~~~~~~\n");
	printf("1.Them vao vi tri trai nhat\n"
	       "2.Them vao vi tri phai nhat\n"
	       "3.Tao cay tu hai cay con\n"
	       "4.Dem so luong Node\n"
	       "5.kiem tra xem co phai la la ko?\n "
	       "0.Thoat!\n ");
	printf("Ban chon: ");
	scanf("%d",&lua_chon);
        switch(lua_chon)
	  {
	  case 1:
	    Add_Left(T,x);
	    break;
	   case 2:
	     Add_Right(T,x);
	    break;
	   case 3:
	     printf("Nhap 2 node :");
	     scanf("%d%d",&b,&c);
	     makesubtree(x,b,c);
	     break;
	   case 4:
	     printf("nhap phan tu can kiem tra: ");
	     scanf("%d",&x);
	     k = IsLeaf(x);
	     if(k==-1)
	       printf("Khong la la\n" );
	     else
	       printf("la 1 la\n");
             break;
	   case 5:
	    break;
	   case 0:
	     printf("Ket thuc chuong trinh\n");
	    break;
	  }
    }while(lua_chon!=0);
