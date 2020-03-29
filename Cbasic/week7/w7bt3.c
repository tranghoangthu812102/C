#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h> //__fpurge(stdin)

#define MAX_LEN 81

typedef struct
{
  char name[30];
  char tel[11];
  char mail[50];
}elementtype;

typedef struct Node
{
  elementtype element;
  struct Node *next;
}Node;

Node *head = NULL;
Node *cur = NULL;
//Tao 1 Node moi 
Node *makeNode(elementtype X)
{
  Node *P=(Node *)malloc(sizeof(Node));
  if(P == NULL)
    {
      printf("Can't creat P\n");
      return NULL;
    }
  P->element = X;
  P->next = NULL;
  return P;
}
//Chen vao dau
void insert_first(elementtype X)
{
  Node *P = makeNode(X);
  if(head == NULL)
    head = cur = P;
  else
    {
      P->next = head;
      head = P;
    }
}
//chen vao cuoi 
void insert_last(elementtype X)
{
  Node *P = makeNode(X);
  if(head == NULL)
    head = cur =P;
  else
    {
      cur -> next = P;
      cur = P;
    }
}

//docfile
void inPut( )
{
  FILE *file;
  if((file = fopen("phone.dat","rb")) == NULL)
    {
      printf("Khong the mo file %s\n","phone.dat");
      return;
    }
  elementtype *X;
  X = (elementtype *)malloc(sizeof(elementtype) * 22 );
  while(1)
    {
      fread(X,sizeof(elementtype),1,file);
      if(feof(file))
	break;
      insert_first(*X);
     
    }
  free(X);
  fclose(file);
}
//in ra man hinh
void outPut()
{
  printf("%-4s %-15s %-15s %s\n","STT","HO TEN","SDT","MAIL");
  int i=0;
  for(Node *P=head;P != NULL; P=P->next)
    {
      i++;
      printf("%-4d %-15s %-15s %s\n",
	     i,P->element.name,P->element.tel,P->element.mail);
    }
}
//xoa Node
void del_Node()
{
  Node *P= NULL;
  while(head != NULL)
    {
      head = head -> next;
      free(P);
    }
}
void del_first()
{
  Node *P=head;
  if(head == NULL)
    return;
  head = head->next;
  free(P);
}

void del_last()
{
  for(Node *P = head;P!=NULL; P= P->next)
    {
      if(head == cur)
	del_first();
      if(P->next == cur)
	{
	  free(cur);
	  P->next = NULL;
	  cur = P;
	}
    }
}
void del_K()
{
  int k;
  int i=0;
  
  printf("Nhap vi tri can xoa : ");
  scanf("%d",&k);
  for(Node *P = head ; P!=NULL ; P=P->next)
    {
      i++;
      if(k == 0)
	del_first();
      if(k-1  == i)
	{
	  
          P->next = P->next->next ;
          
	  break;
	}
      
    }
  
}
/*void reverse()
{
  Node *Q = (Node *)malloc(sizeof(Node));
  Q = cur;
  Node *P = head;
  while(Q != NULL)
    {
      
    }
    }*/
void nhap_Dulieu(int n)
{
  elementtype *X = (elementtype * )malloc(sizeof(elementtype));
  __fpurge(stdin);
  printf("\nHo ten: ");
  gets(X->name);
  printf("\nSDT : ");
  gets(X->tel);
  printf("\nmail : ");
  gets(X->mail);
  if(n==1)
    insert_first(*X);
  if(n==2)
    insert_last(*X);
    }

int main()
{
  int n;
  inPut();
  do
    { printf("\n===============MENU==============\n");
      printf("1.Chen tren \n"
	     "2.Chen duoi \n"
	     "3.in ra man hinh\n"
	     "4.Reset Node\n"//cai dat lai Node
	     "5.Xoa dau\n"
	     "6.Xoa cuoi\n"
	     "7.Xoa vi tri bat ki\n"
	     "8.Thoat\n");
      printf("Ban chon : ");
      scanf("%d",&n);

      switch(n)
	{
	case 1:
	  nhap_Dulieu(n);
	  break;
	case 2 :
	  nhap_Dulieu(n);
	  break;
	case 3 :
	  outPut();
	  break;
	case 4 :
	  del_Node();
	  inPut();
	  break;
	case 5:
          del_first();
	  printf(" Ban da Xoa thanh cong!\n ");
	  break;
	case 6:
	  del_last();
          printf(" Ban da Xoa thanh cong!\n ");
	  break;
	case 7 :
	  del_K();
	  printf(" Ban da Xoa thanh cong!\n ");
	  break;
	case 8:
	  printf("KET THUC CHUONG TRINH \n");
	  break;
	default:
	  printf("nhap lai so ( tu 1 den 8) : ");
	  break;
	}
    }while(n!=8);

  del_Node();//su dung xong xoa di de cho no tro ve ban dau
}
