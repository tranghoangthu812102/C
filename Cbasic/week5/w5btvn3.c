
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct
{
  char model[20];
  char rom  [8];
  char inch [15];
  char tien [15];
}DT;

int chuyen(FILE *file1 , FILE *file2,DT *t)
{
  int m = 0;
  char str[100];
  while(fgets(str, 100, file1) != NULL)
      m++;
  m = m - 1;
  
  rewind(file1);
  int i = 0;
  fgets(str, 100, file1);
  while(!feof(file1))
    {
      fscanf(file1, "%s %s %s %s", t->model, t->rom,t->inch, t->tien);
      
      fwrite(t, sizeof(DT), 1 , file2);
    }
  free(t);
  rewind(file2);
  printf("Chuyen thanh cong!\n");  
}

void in(DT *t,int m)
{
  printf("\n%-15s %-15s %-20s %s\n", "Model", "dungluongbonho", "kichthuocmanhinh", "gia Tien");
  for (int i= 0; i< m; i++)
    {
      printf("%-15s %-15s %-20s %s\n", t[i].model, t[i].rom, t[i].inch, t[i].tien); 
    }
}
void doc(FILE *file2,DT *t)
{ 
  int n,h=0,i;
  printf("\n-----------MENU----------\n"
	 "1.Doc toan phan tu dau \n"
	 "2.doc toan phan tu cuoi\n"
	 "3.Doc mot phan tu hai vi tri dau\n"
	 "4.Doc mot phan tu hai vi tri cuoi\n");
  printf("Ban chon : ");
  scanf("%d",&n);
  if(n<1 || n>4)
    {
      printf("so ban nhap khong thoa man !\n");
      printf("Nhap lai : ");
      scanf("%d",&n);
    }
  fseek(file2, 0, SEEK_END);
  int m= ftell(file2) / sizeof(DT);
  rewind(file2);
  if(n==3 || n== 4 )
    {
     do
     {
      printf("Nhap so luong dien thoai ban muon xem : ");
      scanf("%d",&h);
      if(h<=0 || h>20 )
	printf("so ban nhap khong thoa man!\n"
	       "nhap voi dieu kien sau : 1 <= h <= %d\n",m);
     } while(h <= 0 || h > m);
    }
  else h=m;
  switch(n)
    { case 1:
      case 3:
      rewind(file2);
      t = (DT *)malloc(sizeof(DT)*h);
      fread(t,sizeof(DT),h,file2);
      in(t,h);
      free(t);
      break;
    case 2:
    case 4:
      rewind(file2);
      t = (DT *)malloc(sizeof(DT)*h);
      printf("\n%-15s %-15s %-20s %s\n","Model","dungluongbonho","kichthuocmanhinh","gia tien");
      int i=0;
    while(i!=h)
    {
    fseek(file2,-sizeof(DT)*(i+1),SEEK_END);
    fread(t,sizeof(DT),1,file2);
    printf("%-15s %-15s %-20s %s\n",t[0].model,t[0].rom,t[0].inch,t[0].tien);
    i++;
    }
    free(t);
    break ;
    default :
      printf("So ban nhap khong thoa man !");
    }   
}
void tim(FILE *file2,DT *t)
{
  fseek(file2, 0, SEEK_END);
  int m;
  m= ftell(file2)/sizeof(DT);
  rewind(file2);
  
  t = (DT*)malloc(sizeof(DT)*m);
  fread(t,sizeof(DT),m,file2);
  char str[20];
  printf("Model can tim la : ");
  scanf("%s",str);
  int ktra =0,ktra2=0;
  for(int i=0 ; i<m ;i++)
    {
      
      if(strcmp(str,t[i].model) == 0)
	{
	  ktra = 1 ;
	  if((ktra+ktra2) == 1)
	    {
   printf("\n%-15s %-10s %-20s %s\n", "Model", "dungluongbonho", "kichthuocmanhinh", "giatien");
            ktra2=1;
	    }  
  printf("%-15s %-10s %-20s %s\n", t[i].model, t[i].rom, t[i].inch, t[i].tien);
             
	 }
    }
  if(ktra == 0)
    { printf("\nKhong tim thay model ban nhap !\n");}
  free(t);
}
int main()
{
  FILE *file1,*file2;
  if((file1 = fopen("PhoneDB.txt","rb")) == NULL)
    {
      printf("Khong the mo file!\n");
      exit(0);
    }
   if((file2 = fopen("PhoneDB.dat","w+b")) == NULL)
    {
      printf("Khong the mo file!\n");
      exit(0);
    }
   int a,m;
   DT *t;
   t = (DT*)malloc(sizeof(DT));
   do
     {
       printf("\n-------------MENU------------\n"
	      "1.Import DB from Text\n"
	      "2.Import from DB\n"
	      "3.Print All Database\n"
	      "4.Tim kiem theo Model\n"
	      "5.Thoat\n");
       printf("Ban chon: ");
       scanf("%d",&a);
       switch(a)
	 {
	 case 1 : chuyen (file1 ,file2,t);
	   break;
	 case 2 : doc(file2,t);
	   break;
	 case 3 : in(t,m);
	   break;
	 case 4 : tim(file2,t);
	   break;
	 case 5 :
	   printf("Ket thuc chuong trinh \n");
	   break;
	 default :
	   printf("yeu cau ban nhap khong hop le \n");
	   printf("Ban nhap so thoa man : 1<= a <=5 \n");
           break;
	 }
     }while(a!=5);
   fclose(file1);
   fclose(file2);
}
