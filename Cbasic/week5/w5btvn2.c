#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

typedef struct
{
  int stt;
  int mssv;
  char ten[30];
  double diem;
}SINHVIEN;

void Text2Dat(FILE *file1,FILE * file2)
{
   int sv = 0;
  char str[MAX_LEN];
  while(fgets(str,MAX_LEN,file1) != NULL)
    sv++;
    sv = sv - 1 ;
    fseek(file1,0,SEEK_SET);

    SINHVIEN *svien;
    svien = (SINHVIEN *)malloc(sizeof(SINHVIEN)*1);
    int i=0;
    fgets(str,MAX_LEN,file1);
    while(!feof(file1))
      {
	fscanf(file1,"%d %d %s %lf ",&svien[0].stt, &svien[0].mssv , svien[0].ten,&svien[0].diem);
    fwrite(svien, sizeof(SINHVIEN),1,file2);
	printf("%s\n",svien[0].ten);
	if(i==sv) break;
	i++;
      }

    free(svien);    
}

void Display(FILE *file2)
{
   SINHVIEN *svien;

  fseek(file2,0,SEEK_END);
  int m = ftell(file2) / sizeof(SINHVIEN);
  rewind(file2);

  svien = (SINHVIEN *)malloc(sizeof(SINHVIEN)*m);

  fread(svien,sizeof(SINHVIEN),m,file2);
  printf("%-4s %-10s %-20s %s\n","STT","MSSV","HO VA TEN" , "DIEM");
  for(int i=0 ; i<m ; i++)
    {
      printf("%-4d %-10d %-20s  %.2lf\n",svien[i].stt,svien[i].mssv,svien[i].ten,svien[i].diem);
    }
  free(svien);
  
}
void nhapdiem(SINHVIEN *svien , int i , FILE *file2)
{
  do
    {
      printf("Nhap diem : ");
      scanf("%lf",&svien[i].diem);
      if(svien[i].diem > 10 || svien[i].diem <0)
	printf("Nhap lai voi dieu kien 0 <= diem <= 10 !\n");
      
    }while(svien[i].diem > 10 ||svien[i].diem <0 );
  SINHVIEN  *doi;
  doi = &svien[i];
  fseek(file2,sizeof(SINHVIEN)*i,SEEK_SET);
  fwrite(doi,sizeof(SINHVIEN),1,file2);
}

void SearchandUpdate(FILE *file2)
{
  SINHVIEN *svien;

  fseek(file2,0,SEEK_END);
  int m = ftell(file2) / sizeof(SINHVIEN);
  rewind(file2);

  svien = (SINHVIEN *)malloc(sizeof(SINHVIEN)*m);

  fread(svien,sizeof(SINHVIEN),m,file2);
  int ktra=0;
  do{
    int mssv;
    printf("Nhap MSSV : ");
    scanf("%d",&mssv);
    for(int i=0;i<m;i++)
      {
	if(mssv== svien[i].mssv)
	  {
	    ktra =1;
	    printf("%-4d %-10d %-20s %.2lf \n",svien[i].stt,svien[i].mssv,svien[i].ten,svien[i].diem);
	    nhapdiem(svien,i,file2);
	    printf("diem sau khi thay doi!\n");
	    printf("%-4d %-10d %-20s %0.2lf \n " ,svien[i].stt,svien[i].mssv,svien[i].ten,svien[i].diem);
	    break;
	  }
      }
    if(ktra == 0)
      {
	printf("Khong co sinh vien mang mssv %d\n",mssv);
	printf("hay nhap lai!\n");
	printf("Nhap lai :");
	scanf("%d",&mssv);
      }}while(ktra == 0);
    free(svien);
 }

int main()
{ 
  FILE *file1 , *file2;
   if((file1 = fopen("grade.txt","r")) == NULL)
    {
      printf("Khong the mo %s\n","grade.txt");
      exit(0);
    }
  if((file2 = fopen("grade.dat","w+b")) == NULL)
    {
      printf("Khong the mo file %s\n","grade.dat");
      exit(0);
    }
  int n;
  do
    {
      printf("\n-----------MENU----------\n"
	     "1.Text2Dat\n"
	     "2.Display Dat file \n"
	     "3.Search and Update\n"
	     "4.Quit\n");
      printf("ban muon thuc hien : ");
      scanf("%d",&n);

      switch(n)
	{
	case 1:
	  Text2Dat(file1,file2);
	  break;
	case 2:
	  Display(file2);
	  break;
	case 3:
	  SearchandUpdate(file2);
	  break;
	case 4:
	  printf("\n KET THUC CHUONG TRINH \n ");	 
	}
    }while(n!=4);
  fclose(file1);
  fclose(file2);
}
