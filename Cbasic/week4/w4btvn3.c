#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

void chepkitu(FILE *file1,FILE *file2)
{
  clock_t start = clock();
  char a;
  while(!feof(file1))
    {
      a=fgetc(file1);
      fputc(a,file2);
    }
  clock_t end = clock();
  printf(" Thoi gian thuc hien = %f\n ", (double)(end -start ) / CLOCKS_PER_SEC);
}

void chepdong(FILE *file1,FILE *file2)
{
  clock_t start = clock();
  char a[MAX];
  
  while(!feof(file1))
    {
      fgets(a,MAX,file1);
      fputs(a,file2);
    }
   clock_t end = clock();
   printf(" Thoi gian thuc hien = %f\n ", (double)(end -start ) / CLOCKS_PER_SEC); 
}

void chepblock(FILE *file1,FILE *file2)
{ int m;
  clock_t start = clock();
  char a[MAX + MAX ] ;
  while ( !feof(file1))
    { printf("co bao nhieu ky tu ban muon chep : ");
      scanf("%d",&m);
      int  n= fread(a,sizeof(char), m, file1);
             fwrite(a,sizeof(char), n,  file2);
    }
  clock_t end = clock();
  printf(" Thoi gian thuc hien = %lf\n ", (double)(end -start ) / CLOCKS_PER_SEC);
  
}


  int main()
  {
    int b;
    FILE *file1,*file2 = fopen("inra.txt","w");
    if((file1 = fopen("danhsach.txt","r")) == NULL )
      {
	printf("Khong the mo file %s \n" , file1);
	return 0;
      }
    while(b!=0)
      {
	printf("-----------MENU-----------\n");
	printf("1.Sao chep theo ki tu\n"
	       "2.Sao chep theo dong \n"
	       "3.Sao chep tuy chon \n"
	       "4.Thoat chuong trinh\n");
	printf("Chon so ban muon : ");
	scanf("%d",&b);
	switch(b)
	  {
	  case 1 : chepkitu(file1,file2);
	    break;
	  case 2 : chepdong(file1,file2);
	    break;
	  case 3 : chepblock(file1,file2);
	    break;
	  case 4 : printf("ket thuc chuong trinh !\n");
	    return 1;
	    break;
	  }
	fseek(file1,0,SEEK_SET);
        
      }
    fclose (file1);
    fclose(file2);
  }
