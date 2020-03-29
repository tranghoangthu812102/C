#include <stdio.h>
#define MAX 81
int In(FILE *file1)
{ int dem=0;
  char c;
  while(1)
    {
      c=fgetc(file1);
      if(feof(file1)) break;
      if(c=='\n')
	dem++;
    }
  
  return dem;
}
int main(int argc,char *argv[])
{
   if(argc!=2)
    {
      printf("Ban nhap sai cu phap.\n");
      printf("Cu phap dung: ./a.out 'ten file'\n");
      return 0;
    }
   FILE *file1;
  if((file1 = fopen(argv[1],"r")) == NULL)
    {
      printf("Khong the mo file1\n");
      return 1;
    }
 
  printf("So dong cua file '%s' la: %d\n",argv[1],In(file1));
 
  fclose(file1);
  
	 
}
