#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main(int argc,char* argv[])
{
  char str[]= "mycp";
  if(argc !=4)
    {
      printf("moi ban nhap lai theo dung cu phap :./a.out mycp file1 file2\n");
      return 1;
     }
    if (strcmp(str, argv[1]) != 0)
    {
      printf("Nhap sai tham so dieu khien! Tham so dung la: mycpy\n"
	     "Vi du: ./a.out mycpy file1 file2 \n");
      return 2;
    }
  FILE *file1,*file2;
  if((f1=fopen(argv[2],"r"))==NULL)
    {
      printf("khong the mo file %s\n",argv[1]);
      exit(0);
    }
  if((f2=fopen(argv[3],"r"))==NULL)
    {
      printf("khong the mo file %s\n",argv[2]);
      exit(0);
    }
for (int i = 0; i < strlen(argv[1]); i++)
    {
      argv[1][i] = tolower(argv[1][i]);
    }
 char c;
 while ((c=fgetc(f1)!=EOF))
       fputc(c,f2);
       fclose(f1);
       fclose(f2);

 }


  
       
  
