#include <stdio.h>
#define MAX_DS 50
#define MAX_TEN 50
#define MAX_LEN 90

typedef struct
{
  int STT;
  int MSSV;
  char ten[MAX_TEN];
  char SDT[15];
  double diem;
}SINHVIEN;
int soluong = 0;
void nhapDS(FILE *file1, SINHVIEN sv[])
{
  char str[MAX_LEN];
  int i = 0;
  while (fgets(str,MAX_LEN,file1)!= NULL)
    {
     fscanf(file1 , "%d %d %s %s",&sv[i].STT,&sv[i].MSSV,sv[i].ten,sv[i].SDT);
      i++;
      soluong++;
    }
}
void nhapdiem(SINHVIEN sv[])
{
  printf("%-4s %-10s %-20s %s\n","STT","MSSV","HO TEN","DIEM");
  for(int i=0 ; i<soluong - 1 ;i++)
    {
      printf("%-4d %-10d %-20s ",sv[i].STT,sv[i].MSSV,sv[i].ten);
      scanf("%lf",&sv[i].diem);
      if(sv[i].diem < 0 || sv[i].diem > 10 )
      {
	printf("nhap lai diem voi dieu kien : 0 <= diem <=10!\n");
        i--;
      }
    }
}
void inDS(FILE *file2,SINHVIEN sv[])
{
  fprintf(file2 , "%-4s %-10s %-20s %-15s %s\n","STT","MSSV","HO TEN","SDT","DIEM");
  for(int i=0 ; i < soluong -1 ; i++ )
    {
      fprintf(file2,"%-4d %-10d %-20s %-15s %.2lf\n",sv[i].STT,sv[i].MSSV,sv[i].ten,sv[i].SDT,sv[i].diem);
    }
  
}
int main()
{
  SINHVIEN sv[MAX_DS];
  FILE *file1,*file2=fopen("bangdiem.txt","w");
  if((file1=fopen("danhsach.txt","r")) == NULL)
    {
      printf("Khong the mo file !\n");
      return 1 ;
    }
    nhapDS(file1,sv);
    nhapdiem(sv);
    inDS(file2,sv);
    fclose(file1);
    fclose(file2);
}
