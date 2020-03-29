#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct 
{
  char name[20];
  char tel[11];
  char email[25];
}ADD;
typedef struct Node
{
  ADD data;
  struct Node *next;
}Node;
Node *head = NULL;
Node *cur = NULL;
void inPut()
{
  printf("Nhap ten: ");
  gets(data->name);
  printf("Nhap tel: ");
  gets(data->tel);
  printf("Nhap email: ");
  gets(data->email);
}
//Tao 1 Node moi
ADD *makeNode(ADD add)
{
  ADD *P=(ADD *)malloc(sizeof(ADD));
  if ( P == NULL)
    {
      printf("Can't creat P\n");
      return NULL;
    }
  strcpy(P->name,data->name);
  strcpy(P->tel,data->tel);
  strcpy(P->email,data->email);
  P->data =add;
  P->next=NULL;
  return P;
}
//Chen Node P vao vi tri dau tien 
void insert_first(ADD add)
{
  Node *P=makeNode(add);
  if(head==NULL)
    Head= cur = P;
  else
    {
      P->next=head;
      head=P;
    }
}
//Chen Node P vao vi tri cuoi cung
void insert_Last(ADD add)
{
  Node *P = makeNode(add);
  if(head == NULL)
    head = cur = P;
  else
    {
      cur->next = P;
      cur = P;
    }
}
//Chen Node P vao vi tri k
void insert_K(ADD add,int k)
{ 
  Node *P = makeNode(add);
  Node *Q;
  int i=1;
  if(k==1)
    insert_first(add);
  else
    {
      while (Q!= NULL && i!=k-1)
	{
	  i++;
	  Q = Q->next;
	}
      P->next = Q->next;
      P->next= P;
    }
    
}

void outPut()
{
  if(data == NULL)
    printf("Loi con tro NULL\n");
  else
    printf("%-25s%-15s%s\n",data->name,data->tel,data->email);
}
void In()
{
  Node *P=head;
  printf("------------- DANH SACH --------------\n");
  printf("%-25s%-15s%s\n","Ho va ten","Tel","Email");
  while(P!=NULL)
    {
      outPut(P);
      P=P->next;
    }
}
void del_Node()
{
  Node *P = NULL;
  while(head != NULL)
    {
      P = head;
      head = head->next;
      free(P);
    }
}
int main()
{
  int N;
  printf("Nhap so phan tu : ");
  scanf("%d%*c",&N);
  for(int i=0;i<N;i++)
    {
      inPut();
      insert_first(add);
    }
  In();
  return 0;
}
  
