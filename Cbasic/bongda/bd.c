#include "BST.h"
void Tinh(LIST *T)
{
  NODE *P,*Q;
  int m,n;
  
  
}
void InPut(LIST *T)
{ 
  DT x;
  FILE *file;
  int a,b;
   while(1)
    {
      fscanf(file,"%s%*c%d%*c",x.x,&x.t);
      if(feof(file))
	break;
       Insert(T,x);
     }
}
int STT= 1;
void LNR(LIST *T)
{
  if(*T!=NULL)
    {
      LNR(&(*T)->Left);
      printf("%-20s\t%d\n",(*T)->x.x,(*T)->x.t);
      STT++;
      LNR(&(*T)->Right);      
    }
}
int main()
{ LIST *T = (LIST *)malloc(sizeof(LIST));
  FILE *file;
  int lua_chon;
   if((file = fopen("BongDa.txt","r+")) == NULL)
    {
      printf("Co loi xay ra !!!\n");
      exit(0);
    }
  do
    {
      printf("~~~~~~~~~~~~~MENU~~~~~~~~~~~~\n");
      printf("1.Tao Cay\n"
	     "2.Hien thi ket qua\n"
	     "3.Tim kiem doi bong\n"
	     "4.Doi bong bi xuong hang\n"
	     "5.Ket qua\n"
	     "6.Thoat\n");
      printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
      printf("Ban chon :" );
      scanf("%d%*c",&lua_chon);
      switch(lua_chon)
	{
	case 1 :
	  InPut(T);
	  printf("Doc va tao cay thanh cong !\n");
	  break;
	case 2:
	  printf("%-20s\t%-20s\n","Ten Doi Bong","Ti So");
	  LNR(T);
	  break;
	case 3:
	  break;
	case 4:
	  break;
	case 5 :
	  break;
	case 6:
	  printf("KET THUC CHUONG TRINH\n");
	  break;
	}


    }while(lua_chon!=6);
  fclose(file);
}
