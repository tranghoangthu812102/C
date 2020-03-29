#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  char name[25];
  char sdt[11];
}PHONE;

int main(int argc , char * argv[])
{
  FILE *file1;
  if(argc !=2)
    {
      printf("Nhap sai cu phap !\n"
	     "Cu phap dung la : ./fileread <file1>\n");
      return 1;
    }
  if((file1 = fopen(argv[1],"r+b")) == NULL)
    {
      printf("Khong the mo file %s\n",argv[1]);
      return 2;
    }
  PHONE *so;

  fseek(file1,0,SEEK_END);
  int m = ftell(file1) / sizeof(PHONE);
  rewind(file1);

  so = (PHONE * )malloc(sizeof(PHONE)*m);

  fread(so,sizeof(PHONE),m,file1);
  for(int i=0 ; i < m ; i++)
    {
      printf("%d. %s\t %s\t\n",i+1,so[i].name,so[i].sdt);
    }
  free(so);
  fclose(file1);
}
