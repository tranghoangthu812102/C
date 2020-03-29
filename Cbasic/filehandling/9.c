/* Chương trình C để sao chép một tập tin vào một tập tin khác */
#include <stdio.h>

int main(int argc, char **argv)
{
  FILE *f1, *f2;
  char ch;
  int pos;
  if((f1 = fopen(argv[1],"r")) == NULL)
    {
      printf("Khong the mo file");
      return ;
    }
  else
    printf("Da mo file can sao chep\n");

  f2= fopen(argv[2],"w");
  fseek(f1, 0L, SEEK_END);
  pos = ftell(f1);

  fseek(f1, 0L,SEEK_END);
  while(pos -- )
    {
      ch = fgetc(f1);
      fputc(ch,f2);
    }
  
  fclose(f1);
  fclose(f2);
  
}
