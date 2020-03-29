#include "Queue.h"
void DNODE(DT x)
{
  printf("%-20s%-10d%-10d%-10d%-10d\n",x.b,x.mau,x.tc,x.nn,x.pt);
}
void DLIST(LIST *l)
{
  NODE *P=l->Head;
  int i=1;
  printf("%-5s%-20s%-10s%-10s%-10s%-10s\n",
	 "STT","Biet_hieu","mau","tancong","nhanhnhen","phongthu");
  while(P!=NULL)
    {printf("%-5d",i++);
     DNODE(P->x);
      P=P->next;
    }
  free(P);
}
void Doc(LIST *l,FILE *f ,int *t)
{
  (*t) = 0;
  while(1)
    {
      DT x;
      fscanf(f,"%s%*c%d%*c%d%*c%d%*c%d",x.b,&x.mau,&x.tc,&x.nn,&x.pt);
      if(feof(f))
	break;
      EnQueue(l,x);
      (*t)++;
    }
  DLIST(l);
}
int main()
{
  LIST *l = (LIST *)malloc(sizeof(LIST));
  LIST *l1 = (LIST *)malloc(sizeof(LIST));
  int lua_chon;
  int t1,t2;
  FILE *f1,*f2;
  if((f1 = fopen("team1.txt","r"))==NULL)
    {
      printf("File du lieu team1.txt khong hop le\n");
      exit(0);
    }
  if((f2 = fopen("team2.txt","r"))==NULL)
    {
      printf("File du lieu team2.txt khong hop le\n");
      exit(0);
    }
  do
    {
      printf("~~~~~~~~~~~~~~~MENU~~~~~~~~~~~~~~\n");
      printf("1.Doc Du Lieu \n"
	     "2.Tien Hanh Thi Dau\n"
	     "3.Xep Hang Vo Si \n"
	     "4.Thoat\n");
      printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
      printf("Ban Chon :");
      scanf("%d%*c",&lua_chon);
      switch(lua_chon)
	{
      case 1:
	printf("Doc file 1 \n");
        Doc(l,f1,&t1);
	printf("Thanh cong !\n");
	printf("Doc file 2 \n");
        Doc(l1,f2,&t2);
	printf("Thanh cong !\n");
	if(t1 != t2)
	  {
	    printf("Luc Luong khong can bang ! Yeu cau sua lai so lieu !\n");
	    return 0;
	  }
	break;
      case 2:
	break;
      case 3:
	break;
      case 4:
	printf("Ket Thuc Chuong Trinh\n");
	break;
	  
	}  
	  
    }while(lua_chon!=4);
}
