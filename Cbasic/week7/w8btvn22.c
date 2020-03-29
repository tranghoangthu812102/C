#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h> //__fpurge(stdin)
#define MAX_LEN 100
int tong=0;
typedef struct
{
  char model[20];
  char rom  [8];
  char inch [15];
  char tien [15];
}DT;

typedef struct Node
{
  DT  data;
  struct Node *next;
}Node;

Node *head = NULL;
Node *cur = NULL;

Node *makeNode(DT  DB)
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
void insert_first(DT DB)
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
//Chen vao cuoi 
void insert_last(DT DB)
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
//Doc tu Dat
void inPut_Dat()
{ int  tong = 0;
  FILE *file;
  if((file = fopen("PhoneDB.dat","rb")) == NULL)
    {
      printf("Khong the mo file %s\n","PhoneDB.dat");
      exit(0);
    }
  DT *DB;
  DB = (DT *)malloc(sizeof(DT));
  while(1)
    {
      fread(DB,sizeof(DT),1,file);
      if(feof(file))
	break;
      tong++; 
      insert_last(*DB);
     
    }
  free(DB);
  fclose(file);
}
//Doc tu Txt
void inPut_Txt()
{ int tong = 0;
  FILE *file;
  if((file = fopen("PhoneDB.txt","rb")) == NULL)
    {
      printf("Khong the mo file %s\n","PhoneDB.txt");
      exit(0);
    }
  DT *DB;
  DB = (DT *)malloc(sizeof(DT));
  while(1)//lap vo han den khi thoa man break
    {
      fscanf(file,"%s %s %s %s", DB->model, DB->rom, DB->inch, DB->tien);
      //nhap tu file
      if(feof(file))
	break;
      insert_first(*DB);
      tong++;
    }
  free(DB);
  fclose(file);
}
void outPut()
{
  printf("%-15s %-15s %-15s %s\n",
	 "Model","Dungluongbonho","kichthuocmanhinh","giatien");
  int i=0;
  for(Node *P=head;P != NULL; P=P->next)
    {
      i++;
      printf("%-15s %-15s %-15s %s\n",
	     P->data.model,P->data.rom,P->data.inch,P->data.tien);
    }
}

void del_Node()
{
  Node *P= NULL;
  while(head != NULL)
    { P= head;
      head = head -> next;
      free(P);
    }
}
void insert_k(DT DB)
{ int tong=0;
  printf("Nhap vi tri can chen: ");
  int vtri;
  scanf("%d",&vtri);
  while(vtri < 1 || vtri >= tong)
    {
      printf("Nhap lai! : ");
      scanf("%d",&vtri);
    }
  int i=0;
  for(Node *P =head;P!=NULL;P->next)
    {
      i++;
      if(vtri ==1)
	{
	  Node *new = makeNode(DB);
	  new->next = P->next;
	  P->next = new;
	  tong++;
	}
    }
}
void nhap_Dulieu(int n)
{ int tong=0;
  printf("1.Chen dau \n"
	 "2.Chen cuoi\n"
	 "3.Chen tai vi tri k\n");
  printf("Ban chon : ");
  scanf("%d",&n);
  DT *DB = (DT * )malloc(sizeof(DT));
  __fpurge(stdin);
  printf("\nModel: ");
  gets(DB->model);
  printf("\ndung luong bo nho : ");
  gets(DB->rom);
  printf("\nkich thuoc man hinh : ");
  gets(DB->inch);
  printf("\ngia tien:");
  gets(DB->tien);
  if(n==1)
    {
      insert_first(*DB);
      tong++;
    }
  if(n==2)
    {
      insert_last(*DB);
      tong++;
    }
  if(n == 3)
    
      insert_k(*DB);
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
void outNode(DT s)
{
  printf("%-15s%-15s%-15s%s\n",s.model,s.rom,s.inch,s.tien);
}
//Tim theo model
void searchByModel()
{
  printf("Nhap model ");
  char name[20];
  __fpurge(stdin);
  gets(name);
  int check = 0;
  for(Node *P =head ;P!=NULL;P= P->next)
    {
      if(strcmp(name,P->data.model) == 0)
	{
	  check =1;
	  printf("%-15s %-15s %-15s %s\n",
		 P->data.model,P->data.rom,P->data.inch,P->data.tien);
	}
    }
  if(check == 0 )
    printf("Khong tim thay\n");
}
//Tim theo gia
void searchPrice()
{
	printf("Nhap so tien : ");
	int dem=0;
	char N[20];
	__fpurge(stdin);
	gets(N);
	Node *P=head;
        printf("%-15s %-15s %-15s %s\n",
	       "Model","dungluongbonho","kichthuocmanhinh","Giatien");
	while(P!=NULL)
	{
		int a=atoi(N);
		int b=atoi(P->data.tien);
		if(b<=a)
		{
			dem=1;
			outNode(P->data);
		}
		P=P->next;
	}
	if(dem==0) printf("Khong ton tai\n");
	free(P);
}
void exportToDat()
{
  FILE *fout;
  if((fout = fopen("PhoneDBnew.dat","wb")) == NULL)
    {
      printf("Khong the mo !\n");
      exit(0);
    }
  for(Node *P =head ; P!=NULL;P=P->next)
    {
      fwrite(P,sizeof(DT),1,fout);
    }
  printf("OK!\n");
  fclose(fout);
}


int main()
{
  int n;
  do
    {
      printf("1.Import from Text\n"
	     "2.Import from Dat\n"
	     "3.Manual Insertion\n"
             "4.DisplayList\n"
	     "5.Search phone by Model\n"
	     "6.Search phone by price (under the value)\n"
	     "7.Export to Dat\n"
	     "8.Quit\n");
      printf("Ban chon : ");
      scanf("%d",&n);

      switch(n)
	{
	case 1:
	  {
            del_Node();
	    inPut_Txt();
	    printf("OK!\n");
	    break;
	  }
	 case 2:
	  { del_Node();
	    inPut_Dat();
	    printf("OK!\n");
	    break;
	  }
	case 3:
	  nhap_Dulieu(n);
	  break;
	case 4 :
	  outPut();
	  break;
	case 5 :
	  searchByModel();
	  break;
	case 6 :
	  searchPrice();
          break;
	case 7 :
	  exportToDat();
	  break;
	case 8:
	  printf("---------QUIT---------\n");
	  break;
	default:
	  printf("nhap lai so ( tu 1 den 8) : ");
	}
    }while(n!=8);

  del_Node();
}
