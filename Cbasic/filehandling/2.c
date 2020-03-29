 /*
 * Chương trình C để minh họa cách đọc tệp trên đĩa
 */
#include <stdio.h>
#include <stdlib.h>

void main()
{
  FILE *file;
  char filename[20];
  char ch;
  printf("Enter the filename to be opened\n");
  scanf("%s", filename);
  /* open the file for reading */
  if((file = fopen(filename,"r")) == NULL)
    {
      printf("khong the mo file \n");
      exit(0);
    }
  ch = fgetc(file);
  while( ch != EOF)
    {
      printf("%c",ch);
      ch = fgetc(file);
      }
  fclose(file);
}
