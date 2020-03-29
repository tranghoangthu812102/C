#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 100
#define MAX_DS 100

char tunhaycam[MAX_DS][MAX_DS];
int sotunhaycam;

void dsnhaycam(char *file)
{
  FILE *file1;
  if((file1 = fopen(file, "r")) == NULL)
    {
      printf("Khong the mo %s\n",file);
    }
  fscanf(file1,"%d",&sotunhaycam);
  for(int i=0 ; i < sotunhaycam ; i++)
    {
      fscanf(file1,"%s" ,tunhaycam[i]);
    }
  fclose(file1);
}
void check (char a[] , char kitu[])
{
  int check = 0;
  for(int i=0 ; i< sotunhaycam;i++)
    {
      if(strcmp(a,tunhaycam[i]) == 0)	{
	  check = 1;
	  int m = strlen(a);
	  for(int j=0;j<m;j++)
	    printf("%s",kitu);
	}
    }
      if(check == 0)
	printf("%s",a);
}
  int main(int argv , char *argc[])
  {
    FILE *file1;
    char filename[MAX_LEN];
    char file2[] = "dsnhaycam.txt";
    if(argv != 3 )
      {
	printf("Nhap sai cu phap ! \n "
	       "cu phap dung la : ./a.out <file> <kitudacbiet> \n");
	return 1;
      }
    strcpy(filename,argc[1]);
    if((file1 = fopen(filename , "r")) == NULL )
      {
	printf("Khong the mo %s\n",filename);
	return 2;
      }
    dsnhaycam(file2);

    char str[MAX_LEN];
    char c;
    while(!feof(file1))
      {
	c=fgetc(file1);
	if(c < '!' || c > 'z')
	  printf("%c",c);
	else
	  {
	    fseek(file1,-1,SEEK_CUR);
	    fscanf(file1,"%s",str);
	    check(str,argc[2]);
	  }
	
      }
    fclose(file1);
    return 0;
      }
