#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  char name[25];
  char sdt[11];
}PHONE;
int main(int argc , char * argv[])
{
  FILE *file1,*file2,*file3;
  if(argc !=4)
    {
      printf("Nhap sai cu phap!\n"
	     "Cu phap dung: ./mergefile <file1> <file2> <file3> \n");
      return 1;
      
    }
  if((file1 = fopen(argv[1] , "rb")) == NULL)
    {
      printf("khong the mo file %s\n",argv[1]);
      return 2;
    }
  if((file2 = fopen(argv[2] , "rb")) == NULL)
    {
      printf("khong the mo file %s\n",argv[2]);
      return 2;
    }
  if((file3 = fopen(argv[1] , "wb")) == NULL)
    {
      printf("khong the mo file %s\n",argv[3]);
      return 2;
    }
  PHONE *so;
  fseek(file1,0,SEEK_END);
  int m1 = ftell(file1) / sizeof(PHONE);
  rewind(file1);

  fseek(file2,0,SEEK_END);
  int m2 = ftell(file2) / sizeof(PHONE);
  rewind(file2);

  so = (PHONE *)malloc(sizeof(PHONE)*m1);
  int n,k;
  n=fread(so,sizeof(PHONE),m1,file1);
  fwrite(so,sizeof(PHONE),n,file1);
  free(so);

  so = (PHONE *)malloc(sizeof(PHONE)*m2);
  k=fread(so,sizeof(PHONE),m2,file2);
  fwrite(so,sizeof(PHONE),k,file3);
  free(so);
  fclose(file1);
  fclose(file2);
  fclose(file3);
  
}
