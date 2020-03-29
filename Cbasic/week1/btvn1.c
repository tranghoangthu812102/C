#include <stdio.h>
#include <stdlib.h>
#define MAX_1000
int n;
void nhapmang(int a[100])
{
    int i;
    printf("nhap so phan tu cua mang : ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("pt[%d]=",i);
        scanf("%d",&a[i]);
    }
}
int sosanh(int a[100],int b[100])
{   int i;
    int dem1=0,dem2=0;
    for(i=1;i<=n;i++)
    {
        if(a[i]==b[i])
          dem1++;
        if(a[i]==b[n-i+1])
          dem2++;
    }
    if(dem1==n)
        return 1;
    if(dem2==n)
        return -1;
     return 0;
}
int main()
{
    int a[100],b[100];
    int n;
    printf("Nhap mang A !!!\n");
    nhapmang(a);
    printf("\nNhap mang B !!\n");
    nhapmang(b);
    if(sosanh(a,b)==1)
        printf("hai mang bang nhau !!\n");
    if(sosanh(a,b)==0)
        printf("hai mang khong bang nhau!!\n");
    if(sosanh(a,b)==-1)
        printf("hai mang doi xung nhau !!\n");
}
