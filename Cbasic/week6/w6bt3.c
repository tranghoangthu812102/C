#include <stdio.h>

int Tong(int n)
{
  if(n==0)
  return 0;
  else 
  return n + Tong(n-1);
}

int demso(int n)
{
  int dem = 0;
  if(n/10 == 0)
    return 1;
  else dem +=1 ;
  return dem + demso(n/10);
}
int Tongchuso(int n)
{
  int dem=0;
  if(n/10 == 0)
    return n;
  else dem += (n%10);
  return dem + Tongchuso(n/10);
  
}
int main()
{ int n;
  printf("Nhap n: ");
  scanf("%d",&n);
  printf("Tong tu 1 den n  la : %d\n ",Tong(n));
  printf("So chu so cua n la : %d\n",demso(n));
  printf("Tong cua cac chu so la :%d\n",Tongchuso(n));
}
