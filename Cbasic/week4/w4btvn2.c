#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100
void substr(char *str ,int offset , int number)
{
  printf("Xau ki tu loc ra duoc  la : " );
  for ( int i=offset ; i < offset + number ; i++)
    {
      printf("%c",*(str+i));
      if(*(str + i +1) == '\0')
	break;
    }
  printf("\n");
}
int main()
{
  char xau[MAX+1];
  char *str;
  int num , off ;
  printf("Hay nhap xau : ");
  gets(xau);
 
  do
  {
     printf("Vi tri ki tu muon lay la : ");
     scanf("%d",&off);
     if(off > strlen(xau) ||   off < 0)
       {
          printf("so ban nhap khong thoa man! \n"
	    "Hay nhap so thoa man : 0 < ' so muon nhap ' <= %d \n",strlen(xau));
          printf("Nhap lai : ");
          scanf("%d",&off);
        }
  }while(off > strlen(xau) ||   off < 0);
  do{
      printf("ki tu ban muon loc ra la :" );
      scanf("%d",&num);
      if(num <=0 )
        {
         printf("so ki tu muon lay thoa man > 0 \n");
         printf("ket thuc chuong trinh !!!\n ");
	 return 1;
         }
  }while(num <= 0);

   str = (char *)malloc(MAX);
   strcpy(str,xau);
   substr(str,off,num);
 
  free(str);
}
