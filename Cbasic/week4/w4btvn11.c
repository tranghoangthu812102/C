#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 6

int main(int argc , char *argv[])
{
  char c[MAX][MAX] = {"me","baka","crazy","lazy","dog","die"};
  FILE *file1;
  file1 = fopen(argv[1],"r");
  if(argc !=3 )
    {
      printf("nhap sai cu phap !\n"
	     "Cu phap dung la : ./a.out file kitunhaycam \n");
      return 1;
    }
  if (file1 == NULL)
    {
      printf("Khong the mo file %s " , file1);
      return 2;
    }
  char s[10];
  char *a;
   a=(char *)malloc(1);
 int dem = 0;
  while (1)
    {
      fscanf(file1,"%s%c" , s, a);
      if(feof(file1)!=0)
	{
	  printf("\n");
	  break;
	}
      for(int i=0;i<MAX;i++)
	if(strcmp(s,c[i]) == 0 )
	  {
	    for(int j=0;j<strlen(s);j++)
	      printf("%s",argv[2]);
	    dem++;
	  }
	  if(dem==0)
	    printf("%s",s);
	  else dem = 0;
	  printf("%s",a);
	  
    }
      fclose(file1);
      free(a);
}
