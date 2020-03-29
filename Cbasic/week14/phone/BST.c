#include "BST.h"

elmType *nhapTuBanPhim(elmType *data)
{
  printf("Ten dien thoai: ");
  scanf("%s", data->model);
  printf("Dung luong: ");
  scanf("%s", data->rom);
  printf("Kich co man hinh: ");
  scanf("%s", data->inch);
  printf("Gia tien: ");
  scanf("%s", data->tien);
  return data;
}
//Khởi tạo Tree
void Init(Node **T)
{
  *T = NULL;
}
int compare(elmType x, elmType y)
 { 
    return strcmp(x.model, y.model);
}
//Tao Node
Node *makeNode(elmType x)
{
  Node *P =(Node *)malloc(sizeof(Node));
  P->data = x;
  P->Left = P->Right = NULL;
  return P;
}

//Thêm phần tử X vào cây
void insertNode(Node **T,elmType x )
{
  if(*T !=NULL)
    {
      if(strcmp( (*T)->data.model ,x.model) == 0)//Node nay da co
	      printf("du lieu them vao bi trung \n");
      if(strcmp((*T)->data.model ,x.model) > 0)
	insertNode(&(*T)->Left ,x);//chen trai
      else if (strcmp((*T)->data.model ,x.model) < 0 )
	insertNode(&(*T)->Right,x);//chen phai
    }
  else
      *T = makeNode(x);
      
}
// xuất cây nhị phân


void NLR(Node *T)
{
  if(T!=NULL)
    {
      printf("%-15s %-15s %-15s %s\n",
	     T->data.model,T->data.rom,T->data.inch,T->data.tien);
      NLR(T->Left);
      NLR(T->Right);
    }
}

/*Tim mot node co data =x */
Node *Search(Node *T,elmType  x)
{
  if(T!=NULL)
    {
      if(strcmp(T->data.model ,x.model) == 0)
	return T;
      if(strcmp(T->data.model ,x.model) > 0)
	return Search(T->Left,x);
      if(strcmp(T->data.model ,x.model) < 0)
	return Search(T->Right,x);
    }
  return NULL;
}

//Xoa mot Node bat ki trong cay nhi phan
Node* Del_Node(Node *T,elmType data)
{
    if(T == NULL)
        return 0; 
    else
    {
        if(strcmp(T->data.model,data.model) > 0 )
           return Del_Node(T->Left,data);
        else if (strcmp(T->data.model,data.model) < 0)
          return  Del_Node(T->Right,data);
        else 
        {
            Node *X = T ; 
            if(T->Left == NULL)
              T = T->Right;

            else if(T-> Right == NULL)
              T = T->Left;
            else
            {  
	      X = T->Right;
	      Node *Parent = NULL;
	      while(X->Left !=NULL)
		{
		  Parent = X;
		  X= X->Left;
		}
	      strcpy(T->data.model , X->data.model);
	      if(Parent!=NULL)
		return Del_Node(Parent->Left , Parent->Left->data);
	      else
		return Del_Node(Parent->Right , Parent->Right->data);
	      
            }
            free(X);
        }
     }
    return T;
}


/*void saveFileDat()
{
  FILE *f1;
 if ((f1 = fopen("phoneDB.dat", "w+b ")) == NULL)
    {
      printf("Khong the mo %s\n", "phoneDB.dat");
      return; 
    }
 for (Node *P = head; P != NULL; P = P->next)
    {
      fwrite(P, sizeof(DB), 1, f1);
    }
 fclose(f1);
}*/
void freeTree(Node *T)
{
  if(T!= NULL)
    {
      freeTree(T->Left);
      freeTree(T->Right);
      free(T);
    }
}

   
