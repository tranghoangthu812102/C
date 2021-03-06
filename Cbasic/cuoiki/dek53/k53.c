#include "single.h"
int N=0;
void DNODE(DT x)
{
  printf("%-10d%-10d%-10d%s\n",x.maSP,x.gia,x.sl,x.ten);
}
void Nhap(FILE *file)
{ int a;
  while(1)
    {
      DT x;
      printf("Nhap Ma San Pham :");
      scanf("%d%*c",&x.maSP);
     if(x.maSP == 0) break;
     if(N== 0) a = x.maSP-1;
	  while(x.maSP <a)
	    {
	      printf("Nhap lai\n");
	      printf("Nhap Ma San Pham :");
              scanf("%d%*c",&x.maSP);
	       if(x.maSP == 0) break;
	    }
	   if(x.maSP == 0) break;
	   else
	     {
          printf("Nhap gia san pham ");
	  scanf("%d%*c",&x.gia);
	  while(x.gia <= 0 )
	    {
	      printf("Gia sp phai > 0 \n");
	       printf("Nhap gia san pham ");
	      scanf("%d%*c",&x.gia);
	    }
	  printf("Nhap so luong san pham : ");
	  scanf("%d%*c",&x.sl);
	  while(x.sl < 0 )
	    {
	      printf("so luong sp phai >= 0 \n");
	       printf("Nhap so luong san pham ");
	      scanf("%d%*c",&x.sl);
	    }
	  printf("Nhap ten : ");
	  gets(x.ten);      
          a = x.maSP;
	  fprintf(file,"%d\t%d\t%d\t%s\n",x.maSP,x.gia,x.sl,x.ten);
	  N++;
	}
      }
}

void DLIST(LIST *l)
{
  int i = 1;
  NODE *P= l->Head;
  printf("%-5s%-10s%-10s%-10s%s\n",
	 "STT","MaSP","gia","So luong","Ten san pham");
  while(P!=NULL)
    {
      printf("%-5d",i++);
      DNODE(P->x);
      P=P->next;
    }
  free(P);
}
void doc(LIST *l,FILE *file)
{  DT x;
  rewind(file);
  while(1)
    {
      fscanf(file,"%d%d%d%*c",&x.maSP,&x.gia,&x.sl);
      fgets(x.ten,82,file);
      char *s =strtok(x.ten,"\n");
      strcpy(x.ten,s);
      if(feof(file))	break;
      AddTail(l,x);
    }
  DLIST(l);
  }
void swap(DT *a, DT *b)
{
	DT  c =*a;
	*a = *b;
	*b = c;
}
void sapxep(LIST *l)
{
  NODE *p=l->Head;
  while(p!=NULL)
    {
      NODE *q=p;
      while(q!=NULL)
	{
	  if(p->x.gia>q->x.gia) swap(&p->x,&q->x);
	  q=q->next;
	}
      free(q);
      p=p->next;
    }
  free(p);
}
void Tongtien(LIST *l)
{
  DT x;
  NODE *P=l->Head;
  int Tong = 0;
  while(P!=NULL)
    {
      Tong += P->x.gia * P->x.sl;
      P = P->next;
    }
  printf("Tong tien san pham la : %d\n",Tong);
}
int main()
{
  LIST *l = (LIST*)malloc(sizeof(LIST));
  Empty(l);
  DT a[10];
  FILE *file;
  if((file = fopen("sanpham.txt","w+")) == NULL)
    {
      printf("Co Loi xay ra\n");
      return 0;
    }
  Nhap(file);
  doc(l,file);
  sapxep(l);
  DLIST(l);
  Tongtien(l);
  Free(l);
  fclose(file);
}
