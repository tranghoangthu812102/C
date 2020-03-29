#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void dem(char s[])
{
  char str[26];
  strcpy(str,"abcdefghijklmnpqorstuvxyz");
  int a[26]={0};
  for(int i=0;i<strlen(s);i++)
    {
      for(int j=0;j<26;j++)
	{
	  s[i]= tolower(s[i]);
	  if(s[i]==str[j])
	    {
	      a[j]++;
	     }
	}
    }
  FILE *file2;
  file2=fopen("stats.txt","w");
  for(int i=0;i<strlen(str);i++)
    if(a[i]>0)
     fprintf(file2,"%c xuat hien %d lan\n",str[i],a[i]);
  fclose(file2);
}
int main(int argc , char* argv[])
{
  char str[]="statsfile";
  if(strcmp(str,argv[1]) !=0)
    {
      printf("Nhap sai tham so ! tham so dung la : statsfile\n");
      printf("Cu phap dung la : ./a.out statsfile file \n");
      return 1;
    }
    if(argc !=3)
      {
	printf("Cu phap ban nhap da sai !\n"
	       "Cu phap dung la : ./a.out statsfile file \n");
      return 2;
       }
    FILE *file1=fopen(argv[2],"r");
    if(file1 == NULL)
    {
      printf("khong the mo file %s\n",argv[1]);
      exit(0);
    }
    else
    { char c;
      int n=0;
      while((c=fgetc(file1))!=EOF)
        n++;
      fseek(file1,0,SEEK_SET);
      char s[n+1];
      fgets(s,n,file1);
      
      fclose(file1);
      dem(s);
    }
    
  
  
}
