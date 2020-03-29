#include <stdio.h>
#include <string.h>
#define MAX 200
typedef struct
{
    char hoten[50];
    char ten[15];
}SinhVien;
void nhapdulieu(SinhVien sv[], int n);
void tachten(SinhVien sv[], int n);
void daomang(char a[]);
void sapxep(SinhVien sv[], int n);
void xuatdulieu(SinhVien sv[],int n);
void svtrungten(SinhVien sv[],int n);

void nhapdulieu(SinhVien sv[],int n)
{   int i;
    printf("\nNhap ho ten sinh vien .\n");
    for(i=0;i< n;i++)
    {
        printf("%d.",i+1);
		gets(sv[i].hoten);
    }
}

void tachten(SinhVien sv[],int n)
{
 int i,j;
 for (i=0;i<n;i++)
  {
    int m=strlen(sv[i].hoten);
    for(j=0;j<m;j++)
    {
        if(sv[i].hoten[m-j-1]== ' ')
            break;
        sv[i].ten[j]=sv[i].hoten[m-j-1];
    }
    daomang(sv[i].ten);
  }
}
void daomang(char a[])
{   int i;
    int m=strlen(a);
    for(i=0;i<m/2;i++)
    {   char dao;
        dao =a[i];
        a[i]=a[m-i-1];
        a[m-i-1]=dao;
    }
}
void sapxep(SinhVien sv[],int n)
{
 int i,j;
 for(i=0;i<n -1;i++)
     for (j=i+1;j<n;j++)
     if(strcmp(sv[i].ten,sv[j].ten)>=0)
       { SinhVien dao;
         dao=sv[i];
         sv[i]=sv[j];
         sv[j]=dao;
       }
}
void xuatdulieu(SinhVien sv[],int n)
{   int i;
    printf("danh sach sap xep ten !\n");
    for (i=0;i<n;i++)
    {
        printf("%d. ",i+1);
        puts(sv[i].hoten);
    }
}
void svtrungten(SinhVien sv[],int n)
{   int i,j;
    int demtrung=0;
    char tentrung[MAX];
    for (i=0;i<n-1;i++)
    {
        int dem =1;
        for (j=i+1;j<n;j++)
        if(strcmp(sv[i].ten,sv[j].ten)==0)
         {
             dem++;
         }
        if(dem>demtrung)
         {
             demtrung = dem;
             strcpy(tentrung,sv[i].ten);
         }
     }
    if(demtrung  > 1)
        printf("\n Co %d sinh vien co ten '%s' trung nhau  \n",demtrung,tentrung);
    else
        printf("\nKhong co sinh vien nao trung ten!\n");
}
int main()
{
    SinhVien sv[MAX];
    int n ;
    printf ("Nhap so luong sinh vien: ");
    scanf("%d%*c",&n);
    nhapdulieu( sv, n);
    tachten(sv, n);
    sapxep(sv,n);
    xuatdulieu(sv, n);
    svtrungten(sv, n);
    return 0;
}
