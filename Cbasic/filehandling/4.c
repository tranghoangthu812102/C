/* C Program to Replace a specified Line in a Text File */
#include <stdio.h>

int main()
{
  FILE *file1 , *file2;
  char filename[40];
  int del, temp = 1;
  char ch;
  printf("Enter file name : ");
  scanf("%s",filename);
  // open file in read mode
  file1 = fopen(filename , "r");
  ch = getc(file1);
  while(ch != EOF)
    {
      printf("%c",ch);
      ch = getc(file1);
    }
  //Rewind
  rewind(file1);
  printf("\n Enter line number to be deleted and replaced : ");
  scanf("%d",&del);
  //open new file in write mode
  file2 = fopen("tt1.txt","w");
  ch = getc(file1);
  while(ch != EOF)
    {
      ch = getc(file1);
      if(ch == 'n')
	temp++;
      // loai tru dong bi xoa
      if(temp != del)
	{
	  // copy all lines in file tt.txt
	  putc(ch,file2);
	}
      else
	{
	  while ((c = getc(file1) != 'n')
	    {
	      printf("Enter new text");
	      fflush(stdin);
	      putc('n',file2);
	      while((c = getchar()) != 'n')
		{putc(ch,file2);
	      fputs("n",file2);
	      temp++;}
	     
	    }
	    c = getc(file1);
	}
	  fclose(file1);
  fclose(file2);
  remove(filename);
  // dat lai ten file ban dau
  rename("tt1.txt",filename);
  printf("\n Noi dung file sau khi duoc doi la : \n");
  file1 = fopen(filename,"r");
  ch = getc(file1);
  while(ch != EOF)
    {
      printf("%c",ch);
      ch = getc(file1);
    }
  fclose(file1);
    }
