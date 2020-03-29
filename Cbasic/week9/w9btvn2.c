#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  char name[30];
  char tel[11];
  char mail[50];
}DB;

typedef struct Node
{
  DB data;
  struct Node *next;
}Node;

Node *head = NULL;
Node *tail = NULL;
//Tao 1 Node moi 
Node *makeNode(DB data)
{
  Node *P=(Node *)malloc(sizeof(Node));
  if(P == NULL)
    {
      printf("Can't creat P\n");
      return NULL;
    }
  P->data = data;
  P->next = NULL;
  return P;
}

void insert_last(DB data)
{
  Node *P = makeNode(data);
  if(head == NULL)
    head = tail =P;
  else
    {
      tail -> next = P;
      tail = P;
    }
}
void inPut_Dat()
{ 
  FILE *file;
  if((file = fopen("phone.dat","rb")) == NULL)
    {
      printf("Khong the mo file %s\n","phone.dat");
      exit(0);
    }
  DB *data;
  data = (DB *)malloc(sizeof(DB));
  while(1)
    {
      fread(data,sizeof(DB),1,file);
      if(feof(file))
	break;
      insert_last(*data);
     }
  free(data);
  fclose(file);
}
int len(Node *head)
{
  Node *p=head;
  int dem=0;
  while(p!=NULL)
    {
      dem++;
      p=p->next;
    }
  free(p);
  return dem;
}

void outPut()
{
  printf("%-15s %-15s %s\n",
	 "HO VA TEN","SDT","EMAIL");
  int i=0;
  for(Node *P=head;P != NULL; P=P->next)
    {
      i++;
      printf("%-15s %-15s %s \n",
	     P->data.name,P->data.tel,P->data.mail);
    }
}
void saveDat(FILE *file1, FILE *file2, int vitri)
{
  int i = 0;
  for (Node *P = head; P != NULL; P = P->next)
    {
      if (i <= vitri)
	fwrite(P, sizeof(DB), 1, file1);
      else if (i > vitri)
	fwrite(P, sizeof(DB), 1, file2);
      i++;
    }
  
}

void printDat(FILE *f)
{ 
  fseek(f, 0, SEEK_END);
  int so = ftell(f) / sizeof(DB);
  rewind(f);
  
  DB *dt = (DB*) malloc(sizeof(DB)*so);
  fread(dt, sizeof(DB), so, f);
  for (int j = 0; j < so; j++)
    {
      printf("%d %-15s %-15s %s\n", j+1, dt[j].name,
	     dt[j].tel, dt[j].mail);
    }
}
void saveAndPrint(int vitri, int n)
{
  FILE *file1, *file2;
  if ((file1 = fopen("Phone1.dat", "w+b")) == NULL)
    {
      printf("Khong the mo %s\n", "phone1.dat");
      return;
    }

  if ((file2 = fopen("Phone2.dat", "w+b")) == NULL)
    {
      printf("Khong the mo %s\n", "phone2.dat");
      return;
    }
  
  saveDat(file1, file2, vitri);

  if (n == 1)
    printDat(file1);
  else
    printDat(file2);

  fclose(file1);
  fclose(file2);
}

void slipFile()
{
  printf("Nhap vi tri tach trong khoang 0 -> %d\n", len(head) - 1);
  printf("hay nhap: ");
  int vitri;
  scanf("%d", &vitri);
  while (vitri < 0 || vitri >= len(head))
    {
      printf("Nhap lai gia tri! : ");
      scanf("%d", &vitri);
    }
 int n;
  printf("\n 1. Luu va In file 1\n"
	     "2. Luu va In file 2\n"
	     "3. Thoat!\n");
 do
    {
      printf("Ban Chon: ");
      scanf("%d", &n);
      if(n ==1)
	  saveAndPrint(vitri, n);
      if(n ==2)
	  saveAndPrint(vitri, n);
      if(n==3)
	printf("Thoat!\n");
   
     } while (n != 3);
}
void del_Node()
{
  Node *P= NULL;
  while(head != NULL)
    {
      P= head;
      head = head -> next;
      free(P);
    }
}
int main()
{
  int lua_chon;
  do
    {
      printf("\n----------menu---------\n"
  	     "1. Nhap du lieu tu file Dat\n"
  	     "2. Hien thi du lieu\n"
  	     "3. Tach du lieu\n"
  	     "4. Thoat!\n"
  	     "Ban Chon: ");
      scanf("%d", &lua_chon);
      switch(lua_chon)
  	{
  	case 1:
  	  inPut_Dat();
	  printf("Nhap du lieu thanh cong !\n ");
  	  break;
  	case 2:
  	  outPut();
  	  break;
  	case 3:
	  slipFile();
	  break;
	case 4 :
	  printf("KET THUC CHUONG TRINH\n");
	  break;
  	default:
  	  printf("Nhap lai!\n");
	  break;
  	}
	
    } while (lua_chon!= 4);
  del_Node;

}
