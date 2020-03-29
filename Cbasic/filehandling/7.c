/*C Program that Merges Lines Alternatively from 2 Files & Print Result*/
#include <stdio.h>

int main()
{
  char file1[20], file2[20];
  printf("Nhap ten file 1 ");
  scanf("%s",file1);
  printf("Nhap ten file 2 ");
  scanf("%s",file2);
  FILE *f1, *f2,*f3;
  f1 = fopen(file1 , "r");
  f2 = fopen(file2 , "r");
  f3 = fopen("merge.txt" , "w+");
  char str[200];
  char ch1, ch2;
  int n =0 , w =0;
  while(((ch1 = fgetc(f1) )!= EOF) && (( ch2 = fgetc(f2)) !=EOF))
    {
      if(ch1 !=EOF )
	{
	  ungetc(ch1 , f1);
	  fgets(str,199,f1);
	  fputs(str,f3);
	  if(str[0] != '\n')
	    n++;
	}
      if(ch2 !=EOF )
	{
	  ungetc(ch2 , f2);
	  fgets(str,199,f2);
	  fputs(str,f3);
	  if(str[0] != '\n')
	    n++;
	}
    }
      rewind(f3);
      while((ch1 = fgetc(f3)) != EOF)
	{
	  ungetc(ch1,f3);
	  fscanf(f3,"%s",str);
	  if(str[0] != ' ' || str[0] != '\n' )
	    w++;
	}
	fprintf(f3,"\n \n so dong = %d \n so chu la = %d\n",n,w-1);
	fclose(f1);
	fclose(f2);
	fclose(f3);
}
