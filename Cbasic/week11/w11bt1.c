#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

typedef struct
{
  char model[20];
  char rom  [8];
  char inch [15];
  char tien [15];
}elem;

typedef struct Node
{
  elem  data;
  struct Node *next;
  struct Node *prev;
}Node;

Node *head = NULL;
Node *tail = NULL;
Node *cur  = NULL;

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
//Chen vao cuoi 
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
elem *nhapTuBanPhim(elem *data)
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
void addNewPhone()
{
  int n;
  printf("\n1.Chen dau \n"
	 "2.Chen cuoi\n"
	 "3.Thoat\n");
  do
    {
      printf("Ban chon : ");
      scanf("%d",&n);
  
      if(n==3)
        return ;
      if(n<=0 || n>=3)
	printf("Hay nhap lai !\n");
    }while(n<=0 || n>=3);
  DB *data = (DB*) malloc(sizeof(DB));
  nhapTuBanPhim(data);

  if(n==1)
    insert_first(*data);
  if(n==2)
    insert_last(*data);

  free(data);
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

}
/*void insert_Position()
{
   printf("chon vi tri : \n");
   scanf("%d%*c",&n);
   DB *data = (DB*) malloc(sizeof(DB));
   nhapTuBanPhim(data);
    int i = 0;
    for (Node *P = head; P != NULL; P = P->next)
    {
      if (n == 0)
	{
	  insert_first(*data);
	  break;
	}
      else if (n == i)
	{
	  Node *new = makeNode(*data);
	  P->prev->next = new;
	  new->next = P;
	  new->prev= P->prev;
	  P->prev= new;
	  break;
	}
      i++; 
     
    }

    free(data);
    }*/
void inPut_Dat()
{ 
  FILE *file;
  if((file = fopen("PhoneDB.dat","rb")) == NULL)
    {
      printf("Khong the mo file %s\n","PhoneDB.dat");
      exit(0);
    }
  DB *data = (DB *)malloc(sizeof(DB));
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
/*void del_Node()
{
  Node *P= NULL;
  while(head != NULL)
    {
      P= head;
      head = head -> next;
      free(P);
    }
    }*/
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

/*void Del_Position(int n)
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
}*/
void del_Position()
{  
   if(len(head) <= 0)
    {
      printf("Danh sach rong !\n");
      return;
    }
  int n;
  do
    {
      printf("============================\n");
      printf("Danh sach co do dai tu 0 den %d!\n",len(head)-1);
      printf("chon vi tri : \n");
      scanf("%d",&n);
      if(n<0 || n > len(head)-1)
	printf("so ban nhap khong thoa man , hay nhap lai !\n");
    }while(n<0 || n > len(head)-1);
  int i=0;
  Node *prev = NULL;
  for (Node *P = head; P != NULL; P = P->next)
    {
      if (n == 0)
	{
	  del_first();
	  return;
	}
      else if (n == len(head)-1)
	{
	  del_last();
	  return;
	}
      else if(n == i)
	{
	  prev->next = P->next;
	  free(P);
	  return;
	}
     prev = P;
     i++;
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

void printDat(FILE *f1)
{ 
  fseek(f1, 0, SEEK_END);
  int so = ftell(f1) / sizeof(DB);
  rewind(f1);
  
  DB *dt = (DB*) malloc(sizeof(DB)*so);
  fread(dt, sizeof(DB), so, f1);
  for (int j = 0; j < so; j++)
    {
      printf("%-4d %-15s %-15s %-15s %s\n", j+1, dt[j].model,
	     dt[j].rom, dt[j].inch, dt[j].tien);
    }
}
void saveAndPrint(int vitri, int n)
{
  FILE *file1, *file2;
  if ((file1 = fopen("phone1.dat", "w+b")) == NULL)
    {
      printf("Khong the mo %s\n", "phone1.dat");
      return;
    }

  if ((file2 = fopen("phone2.dat", "w+b")) == NULL)
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
  printf("\n1. Luu va In file 1\n"
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
void findAndUpdate()
{
  if (len(head) <= 0)
    {
      printf("Danh sach rong!\n");
      return;
    }

  char name[20];
  printf("Nhap Model tim kiem: ");
  scanf("%s", name);

  int check = 0,sua = 0;
  for(Node *P =head ;P!=NULL;P= P->next)
    {
      if(strcmp(P->data.model,name) == 0)
	{
	  check =1;
	  sua =1 ;
	  printf("%-15s %-15s %-15s %s\n",
		 P->data.model,P->data.rom,P->data.inch,P->data.tien);
	}
    if (sua == 1)
	{
	  printf("\n Ban co muon chinh sua khong!\n");
	  printf("1 - Chinh sua "
		 "\n0 - Bo qua\n");
	  printf("Ban Chon: ");
	  int chinh;
	  sua = 0;
	  scanf("%d", &chinh);
	  if (chinh == 0)  
	      continue;
	  
	  DB *data=(DB*) malloc(sizeof(DB));
	  nhapTuBanPhim(data);
	  P->data = *data;
	  free(data);
	}
    }
  if(check == 0 )
        printf("Khong tim thay\n");
 }
void daoNguocDS()
{
  Node *P = NULL;
  Node *newHead = NULL, *newtail = NULL;

  while(head != NULL)
    {
      P = head;
      head = head->next;

      if (newHead == NULL)
	{
	  P->next = NULL;
	  newHead = newtail = P;
	}
      else
	{
	  P->next = newHead;
	  newHead = P;
	}
    }

  head = newHead;
  tail  = newtail;

}
void saveFileDat()
{
  FILE *f1;
 if ((f1 = fopen("phoneDB.dat", "w +b ")) == NULL)
    {
      printf("Khong the mo %s\n", "phoneDB.dat");
      return; 
    }
 for (Node *P = head; P != NULL; P = P->next)
    {
      fwrite(P, sizeof(DB), 1, f1);
    }
 fclose(f1);
}
int main()
{
  int lua_chon;
  do
    {
       printf("\n~~~~~~~~~~~~~~~~~MENU~~~~~~~~~~~~~~~~~\n");
       printf("1.Import from NokiaDB.dat (insertafter)\n"
              "2. Display (traverse)\n"
              "3. Add new phone (insertbefore/after)\n"
              "4. Insert at Position\n"
              "5. Delete at Position\n"
	      "6. Delete current\n"
              "7. Delete first\n"
              "8. Search and Update\n"
              "9. Divide and Extract\n"
              "10. Reverse List\n"
              "11. Save to File\n"
              "12. Quit(Free)\n");
 
      printf("Ban chon : ");
      scanf("%d",&lua_chon);
      switch(lua_chon)
	{
	case 1:
	  del_Node();
	  inPut_Dat();
	  printf("Thanh cong\n");
	  break;
	case 2:
	  outPut();
	  break;
	case 3:
	  addNewPhone();
	  break;
	case 4:
	  insert_Position();
	  break;
	case 5 :
	  del_Position();
	  break;
	case 6:
	  del_last();
	  break;
	case 7:
	  del_first();
	  break;
	case 8:
	  findAndUpdate();
	  break;
	case 9:
	  slipFile();
	  break;
	case 10:
	  daoNguocDS();
	  printf("Thanh cong !\n");
	case 11 :
	  saveFileDat();
	  break;
	case 12:
	  printf("KET THUC CHUONG TRINH\n");
	  break;
	}
    }while(lua_chon!=12);
  del_Node();
}

  
