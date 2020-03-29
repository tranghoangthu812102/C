#include <stdio.h>
#include <string.h>
#define MAX_LEN 100
void demkitu(FILE *file1 , FILE *file2)
{
  char c[100];
    int len;
  while (fgets(c,MAX_LEN,file1) != NULL )
    {
      len = strlen(c)-1;
      fprintf(file2,"%d %s",len,c);
      printf("%s",c);
    }
}
int main(int argc , char *argv[])
{
  if(argc!=2)
    {
      printf("Nhap sai cu phap !\n"
	     "cu phap dung la : ./a.out <file> \n");
      return 1;
    }
  char file[MAX_LEN];
  FILE *file1,*file2;
  file2 = fopen("kq1.txt","w");
  strcpy(file,argv[1]);
  if( (file1=fopen(argv[1],"r")) == NULL)
    {
      printf("Khong the mo file %s\n",argv[1]);
      return 2;
    }
  demkitu(file1,file2);
  fclose(file1);
  fclose(file2);
  
  
  
  
  
}
