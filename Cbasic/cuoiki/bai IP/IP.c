#include "BST.h"
void InPut(LIST *T)
{
  DT x;
  FILE *file;
   if((file = fopen("ip.txt","r+")) == NULL)
    {
      printf("Co loi xay ra \n");
      exit(0);
    }
  while(1)
    {
      fscanf(file,"%s%*c%s",x.x,x.dc);
      Insert(T,x);
      if(feof(file))
	break;
       
     }
   fclose(file);
}
int STT= 1;
void LNR(LIST *T)
{ 
  if(*T!=NULL)
    {
      LNR(&(*T)->Left);
      printf("%s %s;",(*T)->x.x,(*T)->x.dc);
      STT++;
      LNR(&(*T)->Right);      
    }
}
/*void Timkiem(LIST *l)
{
  DT s
  }*/

int main()
{
  LIST *T =(LIST *)malloc(sizeof(LIST));
  Empty(T);
  int lua_chon;
  FILE *file;
  InPut(T);
  DT x;
  do
    {
      printf("\n~~~~~~~~~~~~~~~MENU~~~~~~~~~~~~~~\n");
      printf("1.Doc Du Lieu \n"
	     "2.Tra cuu dia chi IP\n"
	     "3.Chan trang web \n"
	     "4.\n"
	     "5.Thoat\n");
      printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
      printf("Ban Chon :");
      scanf("%d%*c",&lua_chon);
      switch(lua_chon)
	{
      case 1:
	LNR(T);
	break;
      case 2:
	printf("Nhap ten mien ");
        scanf("%s",x.x);
       NODE *P = Search(T,x);
       if(P == NULL)
	 printf("This site can't be reached\n");
       else
	 printf("Redirecting to %s \n",P->x.dc);
	 break;
      case 3:
	break;
      case 4:
	break;
      case 5:
      	printf("Ket Thuc Chuong Trinh\n");
	break;
      default :
	  printf("Nhap lai gia tri!\n");
	}  
	  
	}while(lua_chon!=5);
 
}
