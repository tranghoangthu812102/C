#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#define MAX_ALP 26
void mahoa(FILE *file1,FILE *file2 , int dolech)
{
  char c;
  while ((c = fgetc(file1)) != EOF )
    {
     if('a' <= c && c <= 'z')
       {
	 if((c + dolech) > 'z' )
	   c = c - MAX_ALP + dolech;
	 else
	   c = c + dolech;
       }
     else if('A' <= c && c <= 'Z')
       {
	 if((c + dolech) > 'Z' )
	   c = c - MAX_ALP + dolech;
	 else
	   c = c + dolech;
       }
      fputc(c,file2);
    }     
}
void giaima(FILE *file1,FILE *file3 , int dolech)
{
  char c;
  while ((c = fgetc(file1)) != EOF )
    {
     if('a' <= c && c <= 'z')
       {
	 if((c - dolech) < 'a' )
	   c = c + MAX_ALP - dolech;
	 else
	   c = c - dolech;
       }
      if('A' <= c && c <= 'Z')
       {
	 if((c - dolech) < 'A' )
	   c = c + MAX_ALP - dolech;
	 else
	   c = c - dolech;
       }
      fputc(c,file3);
    }
}
  int main(int argv , char *argc[])
  {
    int dolech;
    FILE *file1,*file2,*file3;
    file2=fopen("ketqua1.txt","w");
    file3=fopen("giaima1.txt","w");
    char filename[MAX];
  
    if(argv != 4)
      {
	printf("Ban da nhap sai tham so dong lenh!\n"
	       "Cu phap nhap dung la:\n"
	       "Ma hoa:./a.out mahoa filename dolech\n"
	       "Giai ma:./a.out giaima filename dolech\n");
	return 1;
      }
    strcpy(filename,argc[2]);
    if((file1= fopen(filename,"r")) == NULL)
      {
	printf("Khong the mo file\n");
	return 2;
      }
  
    dolech = atoi(argc[3]);
    dolech %= MAX_ALP;
    if(dolech <0)
      {
	printf("hay nhap do lech >=0 \n");
	return 4;
      }
    //MA HOA FILE
    if(strcmp(argc[1],"mahoa") == 0)
      {
  	mahoa(file1,file2,dolech);
	fclose(file2);
      }
    //GIAI MA FILE
    if(strcmp(argc[1],"giaima") == 0)
      {
	giaima(file1,file3,dolech);
	fclose(file3);
      }
      fclose(file1);
       
  }
