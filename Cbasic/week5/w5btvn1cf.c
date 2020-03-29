#include <stdio.h>

#define MAX_LEN 81

typedef struct
{
  char name[30];
  char tel[11];
  char mail[50];
}PHONE;

int main()
{
  FILE *file1 , *file2;
  if((file1 = fopen ("thongtin.txt","r")) == NULL)
    {
      printf("Khong the mo file %s\n","thongtin.txt");
      return 1;
    }
  if((file2 = fopen("phone.dat","wb")) == NULL)
    {
      printf("Khong the mo %s\n","Phone.dat");
      return 1;
    }

  int dem = 0;
  char s[MAX_LEN];
  while(fgets(s,MAX_LEN,file1) != NULL)
    dem++;
  rewind(file1);
  PHONE so[dem];
  int i=0;
  while(!feof(file1))
    {
      fscanf(file1,"%s %s %s",so[i].name, so[i].tel, so[i].mail);
      i++;
    }
  fwrite(so,sizeof(PHONE),dem,file2);
  fclose(file1);
  fclose(file2);
  
}

  
