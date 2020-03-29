#include <stdio.h>
#include<stdlib.h>

enum{SUCCESS,FAIL};

void docviet( FILE *fin , FILE *fout)
{
  int k;
  while((k=fgetc(fin))!= EOF)
    {
      fputc(k,fout);
      putchar(k);
    }
}

    
int main()
{
  FILE *fptr1, *fptr2;
  char tenfile1[]="lab1a.txt";
  char tenfile2[]="lab1.txt";
  int reval = SUCCESS;
  if((fptr1= fopen(tenfile1 , "w"))== NULL)
    {
      printf("khong the mo %s.\n",tenfile1);
      reval=FAIL;
     }
    if((fptr2= fopen(tenfile2 , "r"))== NULL)
    {
      printf("khong the mo %s.\n",tenfile2);
      reval=FAIL;
    }
    else
     {
       docviet(fptr2,fptr1);
       fclose(fptr1);
       fclose(fptr2);
     }
    return reval;
}
