#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
  char name[30];
  char mssv[10];
  struct Node *Left ;
  struct Node *Right;
}Node;

Node *makeNode(char a[])
{
  int i,k =0 ;
  Node *P= (Node*)malloc(sizeof(Node));
  for(i = strlen(a) -1 ; i>= 0 ; i-- )
    if(a[i] == ' ')
      break;
  for(int j = i+1 ; j< strlen(a) ; j++)
    P->mssv[k++] = a[j];
    P->mssv[k] = '\0';
    strcpy(P->name ,a);
    P->name[i] = '\0';
    return P;
}

int sosanh(Node *T ,char a[])
{
  int i,j;
  for(i=strlen(T->name);i>=0 ; i--)
    if(T->name[i] == ' ')
      break;
  if(i<= 0 )
    {
      printf("Ten %s khong dung 1\n",T->name);
      exit(0);
    }
  for(j=strlen(a);j>=0;j--)
    if(a[j] == ' ')
      break;
  if(j<= 0)
    {
      printf("Ten %s khong dung\n",a);
      exit(0);
    }
  if(strcmp(T->name+i ,a+j) > 0)
    return 1;
  else if(strcmp(T->name+i,a+j)<0)
    return 0;
  else
    {
      for(i=0 ; i<strlen(T->name);i++)
	if(T->name[i]== ' ')
	  break;
      for(j = 0;j<strlen(a);j++)
	if(a[j] == ' ')
	  break;
      if(strcmp(T->name+i,a+j) > 0)
	return 1;
      else if(strcmp(T->name+i,a+j)<0)
        return 0;
      else
	{
	  if(strcmp(T->name,a)>0)
	    return 1;
	  if(strcmp(T->name,a)<0)
	    return 0;
	  }
      }
}
void Search(Node *T,char a[])
{
  if(T==NULL)
    return;
  else
    {
      if(strcmp(T->name ,a) == 0)
	{
	 printf("%-25s%s\n",T->name,T->mssv);
         return;
        }
      if(sosanh(T,a) == 1)
	return Search(T->Left,a);
      if(sosanh(T,a) == 0)
	return Search(T->Right,a);
    }
}
int STT= 1;
void LNR(Node *T)
{
  if(T!=NULL)
    {
        
      LNR(T->Left);
      printf("%-4d%-25s%s\n",STT,T->name,T->mssv);
      STT++;
      LNR(T->Right);      
    }
}
void freeTree(Node *T)
{
  if(T!= NULL)
    {
      freeTree(T->Left);
      freeTree(T->Right);
      free(T);
    }
}

Node *insertNode(Node *T,char a[] )
{
  Node *P = makeNode(a);
    if(T ==NULL)
      return P;
    else
    {
      int x = sosanh(T,P->name);
      if(x==1)
	T->Left=insertNode(T->Left ,a);//chen trai
      else 
	T->Right=insertNode(T->Right,a);//chen phai
    }      
}
Node *inPut(Node *T)
{
  T = NULL;
  FILE *file;
  if((file = fopen("danhsachlop.txt","r")) == NULL)
    {
      printf("Khong the mo file %s\n","danhsachlop.txt");
      exit(0);
    }
  char a[80];
    while(1)
    {
      fgets(a,80,file);
      
      if(feof(file))
	break;
      T = insertNode(T,a);
     }
 
    fclose(file);
    return T; 
}
int main()
{
     Node *T=NULL;
     T=inPut(T);
     int lua_chon;
     char a[80];
      do
       {
	 printf("========================\n");
	 printf("1.Hien Thi danh sach\n");
	 printf("2.Tim Kiem\n");
	 printf("0.Thoat\n");
	 printf("~~~~~~~~~~~~~~~~~~~~~~\n");
	 printf("Chon : ");
	 scanf("%d",&lua_chon);
	 if(lua_chon == 1)
	   {  
	     printf("%-4s%-25s%s\n","STT","HO VA TEN","MSSV");
	     LNR(T);
	   }
	 if(lua_chon == 2)
	   {
	     printf("Nhap ten sinh vien  can tim kiem :");
	     getchar();
	     gets(a);
	     Search(T,a);
	   }
	 if(lua_chon == 0)
	   {
	     printf("Ket thuc chuong trinh\n");
	     return 0;
	   }
       }while(lua_chon!=0);
     
     freeTree(T);  
}
