/*Chương trình C để nối thêm nội dung của tệp vào cuối tệp khác*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *f1,*f2,*f3;
  char ch, file1[20],file2[20],file3[20];
  printf("Nhap ten file 1 : ");
  gets(file1);
  printf("Nhap ten file 2 : ");
  gets(file2);
  printf("Nhap ten file 3 : ");
  gets(file3);
  f1 = fopen(file1,"r");
  f2 = fopen(file2,"r");
  if(f1 == NULL || f2 == NULL)
    {
      printf("ko the mo file\n");
      exit(0);
    }
  f3 = fopen(file3 , "w");
   if(f3 == NULL)
    {
      printf("ko the mo file\n");
      exit(0);
    }
   while((ch = fgetc(f1)) != EOF)
	 fputc(ch,file3);
   while((ch = fgetc(f2)) != EOF)
	 fputc(ch,file3);
   printf("Thanh cong \n");
	  fclose(f1);
	  fclose(f2);
	  fclose(f3);
  
}
