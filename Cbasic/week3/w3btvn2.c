#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{ char file[50];
  int count[26] = {0};
  FILE *file1,*file2;
  file2= fopen("ketqua2.txt","w");
  if(argc !=2)
    {
      printf("Ban nhap sai cu phap!\n"
	     "Cu phap dung la ./a.out <file> \n");
      return 1;
    }
  strcpy(file,argv[1]);
  if((file1 = fopen(argv[1],"r")) == NULL)
    printf("Khong the mo file %s \n " , file);
  int c;
  while(( c= fgetc(file1)) !=EOF)
    {
      if('a' <=c && c<= 'z' )
	count[c - 'a']++;
      if('A' <=c && c<= 'Z' )
	count[c - 'A']++;
     }
  fclose(file1);
  fputs("ket qua : \n",file2);
  
for (int i = 0; i < 26; i++)
  {
    if(count[i] !=0)
      fprintf(file2,"%c xuat hien %d lan \n ", 'a'+i,count[i]);
    
  }
  fclose(file2);
}
   
