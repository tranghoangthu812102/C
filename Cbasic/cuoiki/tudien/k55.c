#include "BST.h"
void InPut(LIST *T)
{
  FILE *file;
  DT x;
  if((file = fopen("data.txt","r+")) == NULL)
    {
      printf("Co loi xay ra !!!\n");
      exit(0);
    }
  while(1)
    {
      fscanf(file,"%s%*c %[^\n]",x.x,x.v);
      if(feof(file))
	break;
       Insert(T,x);
     }
  fclose(file);
}
int STT= 1;
void LNR(LIST *T)
{
  
  if(*T!=NULL)
    {
      LNR(&(*T)->Left);
      printf("%-20s%-20s\n",(*T)->x.x,(*T)->x.v);
      STT++;
      LNR(&(*T)->Right);      
    }
}
void dich(LIST *T,char *s)
{ DT x;
  NODE *dich = NULL;
  int len = strlen(s);
  for(int i=0;i<len;i++)
    s[i] = tolower(s[i]);
  char *t =(char *)malloc(sizeof(char));
  char *d = (char *)malloc(sizeof(char));
  d[0] = '\0';
  t =  strtok(s," ");
  while(t!= NULL)
    {
      printf("%s\n",t);
      strcpy(x.x,t);
       dich = Search(T,x);
       if(dich == NULL)
	 {
	   printf("Thieu tu :%s\n",x.x);
	   printf("Nhap nghia tieng Viet : ");
	   char tv[20];
	   gets(tv);
	   strcpy(x.v,tv);
	   Insert(T,x);
	   strcat(d,x.v);
	   strcat(d," ");
	 }
       else
	 {
	   strcat(d,dich->x.v);
	   strcat(d," ");
	 }
       t = strtok(NULL, " ");
       if(t == NULL)
	 {
	   printf("\n Sau khi dich : ");
	   printf("%s\n",d);
	 }
       
     }
}
void saveLNR(LIST *T,FILE *file)
{
  if((file = fopen("data.txt","w")) == NULL)
    {
      printf("Co loi xay ra !!!\n");
      exit(0);
    }
  if(*T!=NULL)
    {
      saveLNR(&(*T)->Left,file);
      fprintf(file,"%s\t%s\n",(*T)->x.x,(*T)->x.v);
      saveLNR(&(*T)->Right,file);      
    }
  fclose(file);
}

int main()
{
  LIST *T=(LIST*)malloc(sizeof(LIST));
  Empty(T);
  char *s= (char *)malloc(sizeof(char));
  char a[20];
  int lua_chon;
  FILE *file;
  
  do
    {
      printf("~~~~~~~~~~~~~MENU~~~~~~~~~~~~\n");
      printf("1.Doc file va tao cay\n"
	     "2.Hien thi theo thu tu tang dan\n"
	     "3.Dich Anh-Viet\n"
	     "4.Ghi lai vao cay\n"
	     "5.Thoat\n");
      printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~`\n");
      printf("Ban Chon : ");
      scanf("%d%*c",&lua_chon);
      switch(lua_chon)
	{
	case 1:
	  InPut(T);
	  printf("Doc va tao cay thanh cong !\n");
	  break;
	case 2:
	   printf("%-20s%-20s\n","Tieng Anh","Tieng Viet");
	  LNR(T);
	  break;
	case 3:
	  printf("Nhap chuoi can dich :");
          gets(s);
	  dich(T,s);
	  break;
	case 4:
	  saveLNR(T,file);
	    printf("Luu THanh Cong\n");
	  break;
	case 5:
	  printf("KET THUC CHUONG TRINH\n");
	  break;
	  }
	  
    }while(lua_chon!=5);
		
}
