#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char Name[20];
  char Tel[11];
  char email[25];
}phoneadd;

int main()
{
  FILE *file;
  phoneadd add[100];
  int i,n,m;
  printf("Ban muon nhap bao nhieu so (n < 20) : ");
  scanf("%d%*c",&n);
  for (i=1; i<=n; i++)
    {
     printf("     Nguoi thu %d\n",i);
     printf("Nhap ten:");
     gets(add[i].Name);
     printf("Nhap SDT:");
     gets(add[i].Tel);
     printf("Nhap email:");
     gets(add[i].email);
   }
  if((file = fopen("thongtin.txt","w+b")) == NULL )
    {
      printf("Khong the mo file %s",file);
      return 1;
    }
   m = fwrite(add , sizeof(phoneadd), n, file);
   printf(" so luong viet ra =  %d\n", m); 
   fclose(file);
  if ((file = fopen("thongtin.txt","rb")) == NULL)
    {
        printf("Khong the mo file %s.\n", file);
        return 1;
    } 
   m = fread(add , sizeof(phoneadd), n, file);
   printf(" so luong doc duoc  = %d\n", m);
   for (i=1; i<=n; i++)
     {
     printf("Thong tin cua nguoi thu %d\n",i);
     printf("%s---",add[i].Name);
     printf("%s---",add[i].Tel);
     printf("%s\n",add[i].email);
     }
   fclose(file);
}

 

