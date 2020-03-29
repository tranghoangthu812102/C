#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 81

typedef struct
{
  char name[25];
  char sdt[11];
}PHONE;

int main(int argc , char *argv[])
{
  FILE *file1 , *file2 , *file3;
  if(argc !=5)
    {
      printf("Ban nhap sai cu phap !\n"
	     "cu phap dung la :./fileslip <file1> <somuontach> <file2> <file3>\n");
      return 1;
    }
  if((file1 = fopen(argv[1],"rb")) == NULL)
    {
      printf("Khong the mo %s\n",argv[1]);
      return 2;
    }
  if((file2 = fopen(argv[3],"wb")) == NULL)
    {
      printf("Khong the mo %s\n",argv[3]);
      return 2;
    }
  if((file3 = fopen(argv[4],"wb")) == NULL)
    {
      printf("Khong the mo %s\n",argv[4]);
      return 2;
    }
  PHONE *so;
  int num,n,k;
  num = atoi(argv[2]);

  fseek(file1,0,SEEK_END);
  int m = ftell(file1) / sizeof(PHONE);
  rewind(file1);
  if (num <0 || num > m)
    {
      printf("So ban nhap vuot qua so cac so dien thoai hien co !\n");
      printf("Hien tai chi co %d so dien thoai\n " , m);
      return 0;
    }
  so = (PHONE * )malloc(sizeof(PHONE)*num);
  n=fread(so,sizeof(PHONE),num,file1);
    fwrite(so,sizeof(PHONE),n,file2);
  free(so);

  so = (PHONE * )malloc(sizeof(PHONE)*(m-num));
  k=fread(so,sizeof(PHONE),m-num,file1);
  fwrite(so,sizeof(PHONE),k,file3);
  free(so);
  fclose(file1);
  fclose(file2);
  fclose(file3);
}
