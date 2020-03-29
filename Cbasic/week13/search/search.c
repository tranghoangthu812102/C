#include  "dslkd.h"

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
void inPut_Dat()
{ 
  FILE *file;
  if((file = fopen("phoneDB.dat","rb")) == NULL)
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
int a=len(head);
  printf("Nhap vi tri tach trong khoang 0 -> %d\n", a - 1);
  printf("hay nhap: ");
  int vitri;
  scanf("%d", &vitri);
  while (vitri < 0 || vitri >= a)
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
void saveFileDat()
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
}
int main()
{
  int lua_chon;
  DB x;
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
	      "12.Search Move To Front\n"
	      "13.Search Transpose\n"
              "14. Quit(Free)\n");
 
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
	  
          printf("Model ban muon tim : ");
          scanf("%s",x.model);
	  searchMoveToFront(x);
	  break;
	case 13:
	  
          printf("Model ban muon tim : ");
          scanf("%s",x.model);
	  searchTranspose(x);
	  break;
	case 14:
	  printf("KET THUC CHUONG TRINH\n");
	  break;
	}
    }while(lua_chon!=14);
  del_Node();
}
