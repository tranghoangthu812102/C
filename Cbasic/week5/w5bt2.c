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
  phoneadd *add;
  int i,n,m;
  /*  printf("Nhap tu du lieu 2 den du lieu 3: ");
  for (i=1; i<=n; i++)
    {
     printf("     Nguoi thu %d\n",i);
     printf("Nhap ten:");
     gets(add[i].Name);
     printf("Nhap SDT:");
     gets(add[i].Tel);
     printf("Nhap email:");
     gets(add[i].email);
     }*/
  if((file = fopen("thongtin.txt","r+b")) == NULL )
    {
      printf("Khong the mo file %s","thongtin.txt");
      return 1;
    }
  phoneadd *s=(phoneadd *)malloc(sizeof(phoneadd));
  while(!feof(file))
    {
      fread(s,sizeof(phoneadd),1,file);
      printf("%s---",s->Name);
     printf("%s---",s->Tel);
     printf("%s\n",s->email);
    }
  free(s);
  add = (phoneadd *)malloc(2 * sizeof(phoneadd));
 if(add == NULL)
   {
     printf("Memory allcation failed !\n");
     return 1;
     
   }
			     
if (fseek(file,1*sizeof(phoneadd),SEEK_SET) != 0)
    {
        printf("Fseek failed!\n");
        return 1;
    }
   strcpy(add[1].Name,"Lan Hoa");
   strcpy(add[1].Tel,"0923456");
   strcpy(add[1].email,"lovelybuffalo@hut.edu.vn");
   rewind(file);
   fseek(file,1*sizeof(phoneadd),SEEK_SET);
   m= fwrite(add , sizeof(phoneadd), 2, file);
   printf(" so luong viet ra =  %d\n", m); 
   fclose(file);
   free(add);
   
  if ((file = fopen("thongtin.txt","rb")) == NULL)
    {
        printf("Khong the mo file %s.\n", "thongtin.txt");
        return 1;
    } 
   m = fread(add , sizeof(phoneadd), n, file);
   printf(" so luong doc duoc  = %d\n", n);
   for (i=1; i<=m; i++)
     {
     printf("Thong tin cua nguoi thu %d\n",i);
     printf("%s---",add[i].Name);
     printf("%s---",add[i].Tel);
     printf("%s\n",add[i].email);
     }
   fclose(file);
}
