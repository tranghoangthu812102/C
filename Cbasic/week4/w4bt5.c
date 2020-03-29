#include <stdio.h>
#define MAX_LEN 81
void block(FILE *f1 , FILE *f2)
{
  int n;
  char c[81];
  while(!feof(f1))
   {
     n= fread(c, sizeof(char),MAX_LEN, f1);

     c[n * sizeof(char)] = '\0';

     printf("%s", c);

    fwrite(c, sizeof(char), n, f2);
   }
}
int main()
{
  FILE *fptr1, *fptr2;
  char filename1[]= "ketqua.txt";
  char filename2[]= "bai3.txt";
  if ((fptr2 = fopen(filename2, "r")) == NULL)
    {
     printf("Khong the mo %s.\n", filename2);
     return 1;
    }
  else
    {
  block(fptr2, fptr1);
  fclose(fptr1);
  fclose(fptr2);
    }
}
