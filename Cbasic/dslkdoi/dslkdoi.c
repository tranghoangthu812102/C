#include "dslkdoi.h"
Node *makeNode(elem data)
{
  Node *P=(Node *)malloc(sizeof(Node));
  if(P == NULL)
    {
      printf("Can't creat P\n");
      return NULL;
    }
  P->data = data;
  P->next = NULL;
  P->prev = NULL;
  return P;
}

void insert_first(elem data)
{
  Node *P = makeNode(data);
  if(head == NULL)
    head = tail = P;
  else
    {
      head->prev = P;
      P->next = head;
      head = P;
    }
}
void insert_last(elem data)
{
  Node *P = makeNode(data);
  if(head == NULL)
    head = tail =P;
  else
    {
      tail -> next = P;
      P->prev = tail;
      tail = P;
    }
    cur = P;
}
void Free()
{
Node *P = head;
while (P!=NULL)
{
   head = head->next;
   free(P);
   P = head; 
}
  free(P);
}
void insert_before(elem data)
{
   Node *P= makeNode(data);
    if(head == NULL)
    head = tail =P;
    else if(cur->prev = NULL)
     insert_first(*data);
    else
      {
        P-> next = cur;
        P->prev = cur->prev;
        cur->prev->next = P;
        cur->prev = P;
      }
     cur =P;
}
void insert_after(elem data)
{
   Node *P= makeNode(data);
    if(head == NULL)
    head = tail =P;
    else if(cur->next = NULL)
     insert_last(*data);
    else
      {
        P-> prev = cur;
        P->next= cur->next;
        cur->next->prev = P;
        cur->next = P;
      }
     cur =P;
}
void insert_Position(elem data ,int n)
{
   Node *Q= head;
   for(int i=0; i<n ; i++)
   {  
      if(Q = NULL)
        break;
        Q= Q->next;
   }
   if(Q= NULL)
    printf("Khong ton tai vi tri");
    else
      {
        if(n == 0)
          insert_first(*data);
        else if(Q == tail)
          insert_last(*data);
        else insert_before(*data);
}
void AddNode(elem P)
{
	printf("Moi ban chon che do \n");
	printf("1. insert Before\n");
	printf("2. insert After\n");
	printf("Ban chon: ");
	int N;
	scanf("%d%*c",&N);
	switch(N)
	{
		case 1:			
			insert_before(*data);
			break;
		case 2:				
			insert_after(*data);
			break;
	}
}
void del_first()
{ 
  Node *P=head;
  if(head == NULL)
    {
      tail=head= NULL;
    }
  else
    {
      head=head->next;
      head->prev=NULL;
      cur = head;
    }
  free(P);
  printf("Xoa thanh cong\n ");
}

void del_last()
{ 
  Node *P= tail;
  if(head == NULL)
    {
      head = tail = P;
    }
  if(head == tail)
	del_first();
  else
    {
      tail = tail->prev;
      tail-> next = NULL;
      cur = tail;
    }
  free(P);
  printf("Xoa thanh cong\n ");
}
void Del_Cur()
{
  if(head == NULL)
    printf("danh sach rong !\n");
  else if(tail == head)
     Free();
  else if(cur == head)
     del_first();
  else if(cur == tail)
     del_last();
  else
    {
      Node *P = cur;
         cur->prev->next = cur->next;
         cur->next->prev = cur->prev;
         cur = cur->next;
         free(P);
      printf("Xoa thanh cong\n");   
    }
  
}

void Del_Position(int n)
{
   Node *P = head;
   for (int i=0 ; i<n;i++)
   {
     if(P= NULL)
        break;
     P = P->next;
   }
   cur = P;
   if(P=NULL) 
      printf("Khong ton tai vi tri\n");
    else 
      Del_Cur();
}
