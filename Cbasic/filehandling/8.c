/*C Program to Find the Size of File using File Handling Function*/
#include <stdio.h>

int main(int argc , char **argv)
{
  FILE *file;
  char ch;
  int size = 0 ;

  file = fopen(argv[1],"r");
  if(file == NULL)
    printf("Khong the mo file \n");
  else
    printf("File da mo\n");
  fseek(file, 0 ,2);
  size = ftell(file);
  printf("Tong kich thuoc cua file = %d byte\n",size);
  fclose(file);
}
