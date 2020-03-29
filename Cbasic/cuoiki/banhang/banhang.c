#include "Queue.h"

void DNODE(DT x)
{
  printf("%-30s%-15s\n",x.ten,x.sdt);
}
void DLIST(LIST *l)
{ 
  NODE *P= l->Head;
  printf("%-30s%-15s\n","Ten Khach Hang","So dien thoai");
  while(P!=NULL)
    {
      DNODE(P->x);
      P=P->next;
    }
  free(P);
}

int tong = 0;
void fileds(LIST *l,FILE *file1)
{ 
  while(1) {
  DT x;
  fscanf(file1,"%s%*c",x.ten);
  fscanf(file1,"%s%*c",x.sdt);
  if(feof(file1))
    break;
  EnQueue(l,x);
  tong++;
  }
  DLIST(l);
}
void banhang(LIST *l,FILE * file2)
{
  printf("%-30s%-15s\n","Ten Khach Hang","So dien thoai");
  DNODE(DeQueue(l));
  int A,B,C;
  do
    {
       printf("Nhap so san pham A ");
       scanf("%d%*c",&A);
       printf("Nhap so san pham B ");
       scanf("%d%*c",&B);
       printf("Nhap so san pham C ");
       scanf("%d%*c",&C);
    }while(A < 0 || B < 0 || C <0);
  fprintf(file2,"%d\t%d\t%d\n",A,B,C);
 }
void tt(DT *x)
{
          printf("Nhap ten khach hang : ");
	  scanf("%s",x->ten);
	  printf("Nhap so dien thoai : ");
	  scanf("%s",x->sdt);
}
void ycdb(LIST *l,DT x)
{       NODE *p=CreatNODE(x);
	if(l->Head==NULL) l->Head=l->Tail=p;
	else
	{
		p->next=l->Head;
		l->Head->prew=p;
		l->Head=p;
	}
}

int main()
{
  LIST *l =(LIST*)malloc(sizeof(LIST));
  DT a;
  DT x;
  Empty(l);
  FILE *file1,*file2;
  if((file1 = fopen("danhsach.txt","r+"))== NULL)
    {
      printf("Co loi xay ra!!");
      exit(0);
    }
  if((file2 = fopen("banhang.txt","a+"))== NULL)
    {
      printf("Co loi xay ra!!");
      exit(0);
    }
  
  int lua_chon,vt;
  do
    {
      printf("~~~~~~~~~~~~~~~MENU~~~~~~~~~~~~~~~~\n");
      printf("1.Doc file danhsach.txt\n"
	     "2.Them nguoi mua vao hang doi\n"
	     "3.Ban hang\n"
	     "4.Ghi thong tin sau 1 ngay\n"
	     "5.Thong ke thong tin ban hang\n"
	     "6.Yeu cau dac biet\n"
	     "7.Thoat\n");
      printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
      printf("Ban chon : ");
      scanf("%d%*c",&lua_chon);
      switch(lua_chon)
	{
	case 1:
	  fileds(l,file1);
	  break;
	case 2 :
	  tt(&a);
	  EnQueue(l,a);
	  break;
	case 3:
	  banhang(l,file2);
	  break;
	case 4:
	  break;
	case 5:
	  break;
	case 6:
	  vt= ftell(file1);
	  tt(&a);
	  ycdb(l,a);
	  fseek(file1,vt,SEEK_SET);
	  break;
	case 7:
	  printf("KET THUC CHUONG TRINH\n");
	  break;
	  
	}
    }while(lua_chon!=7);
  fclose(file1);
  fclose(file2);
}

