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
}phone;

typedef struct Node
{
  phone data;
  struct Node *next;
}Node;

Node *head = NULL;
Node *cur = NULL;
//Tao 1 Node moi 
Node *makeNode(phone DB)
{
  Node *P=(Node *)malloc(sizeof(Node));
  if(P == NULL)
    {
      printf("Can't creat P\n");
      return NULL;
    }
  P->data = DB;
  P->next = NULL;
  return P;
}
//Chen vao dau
void insert_first(phone DB)
{
  Node *P = makeNode(DB);
  if(head == NULL)
    head = cur = P;
  else
    {
      P->next = head;
      head = P;
    }
}
//chen vao cuoi 
void insert_last(phone DB)
{
  Node *P = makeNode(DB);
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
  phone *DB;
  DB = (phone *)malloc(sizeof(phone) * 22 );
  while(1)
    {
      fread(DB,sizeof(phone),1,file);
      if(feof(file))
	break;
      insert_first(*DB);
     
    }
  free(DB);
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
      printf("%-4d %-15s %-15s %s\n",i,P->data.name,P->data.tel,P->data.mail);
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

void nhap_Dulieu(int n)
{
  phone *DB = (phone * )malloc(sizeof(phone));
  __fpurge(stdin);
  printf("\nHo ten: ");
  gets(DB->name);
  printf("\nSDT : ");
  gets(DB->tel);
  printf("\nmail : ");
  gets(DB->mail);
  if(n==1)
    insert_first(*DB);
  if(n==2)
    insert_last(*DB);
    }

int main()
{
  int n;
  inPut();
  do
    {
      printf("1.Chen tren \n"
	     "2.Chen duoi \n"
	     "3.in ra man hinh\n"
	     "4.Reset Node\n"//cai dat lai Node
	     "5.Thoat\n");
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
	case 5 :
	  printf("KET THUC CHUONG TRINH \n");
	  break;
	default:
	  printf("nhap lai so ( tu 1 den 5) : ");
	}
    }while(n!=5);

  del_Node();//su dung xong xoa di de cho no tro ve ban dau
}
