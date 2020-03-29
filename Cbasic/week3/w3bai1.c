#include<stdio.h>
#include <ctype.h> 
int main()
{
  FILE *f1=fopen("bai3.txt","r");
  FILE *f2=fopen("Kq.txt","w");
  if(!f1)
    {
      printf("Khong mo duoc file\n");
      return 0;
    }
  if(!f2)
    {
      printf("Khong mo duoc file\n");
      return 0;
    }
  char c;
  while(1)
    {
      c=fgetc(f1);
      if(feof(f1)) break;
      if(c=='\n') fputc('\n',f2);
      fputc(c,f2);
    }
  printf("Copy thanh cong\n");
  fclose(f1);
  fclose(f2);
  return 0;
}



