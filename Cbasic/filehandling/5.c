/* Chương trình C để tìm số lượng dòng trong tệp văn bản*/

#include <stdio.h>

int main()
{
  FILE *file;
  int count = 0;
  char filename[40],ch;

  printf("ENter file name : ");
  scanf("%s",filename);

  file = fopen(filename , "r");

  ch = getc(file);
  while(ch!= EOF)
    {
      if(ch == 'n')
	{
	  count = count +1;
	}
      ch = getc(file);
      
    }
  fclose(file);
  printf("co %d dong trong file '%s'\n",count,filename);
}
