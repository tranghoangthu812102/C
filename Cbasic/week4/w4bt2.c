//bai tap hoa tron dong
#include <stdio.h>
#include <string.h>
#define MAX_LEN 100
void hoatron(FILE *file1 ,FILE *file2 , FILE *file3)
{
  char c1[MAX_LEN],c2[MAX_LEN];
  int len;
  while ((fgets(c1,MAX_LEN,file1) !=NULL) && (fgets(c2,MAX_LEN,file2) !=NULL))
    {
      fputs(c1,file3);
      printf("%s",c1);
     fputs(c2,file3);
     printf("%s",c2);
   
    }
  /* if(c1 != NULL )
    fputs(c1,file3);
  while (fgets(c1,MAX_LEN,file1) !=NULL)
    {
      fputs(c1,file3);
    }
  while(fgets(c2,MAX_LEN,file2) != NULL )
    {
      fputs(c2,file3);
      }*/
}
int main(int argc , char *argv[])
{ 
  if(argc !=4)
    {
      printf("Nhap sai cu phap\n"
	     "Cu phap dung la : ./merge file1 file2 file3 \n");
      return 1;
    }
  
  FILE *file1,*file2,*file3;
  file3 = fopen("Ketqua3.txt","w");
  if((file1 = fopen(argv[1],"r")) == NULL )
    {
      printf("Khong the mo %s \n ",argv[1]);
      return 1;
     }
  if((file2 = fopen(argv[2],"r")) == NULL )
    {
      printf("Khong the mo %s\n",argv[2]);
      return 2;
    }
  else
    {
  hoatron(file1,file2,file3);
  fclose(file1);
  fclose(file2);
  fclose(file3);
    }
  
  
}
