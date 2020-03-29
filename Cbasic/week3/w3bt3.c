#include <stdio.h>
#include <string.h>
void chep(char str[])
{ char s[80];
  for(int i=0 ; i<strlen(str);i++)
    {
      if(str[i] == '\n' )
	{
	  strncpy(s,str,1);
	  printf("%s",s[i]);
        }
    }
}

int main(int argc , char *argv[])
{
  FILE *file1 ;
  if(argc !=3 )
    {
      printf("Nhap sai cu phap \n "
	     "Cu phap dung la : ./a.out <file> \n");
      return 1;
    }
  if((file1 = fopen(argv[1],"r")) == NULL)
    {
      printf("Khong the mo file %s \n ", file1);
    }
  char s[80];
    chep
  
}
