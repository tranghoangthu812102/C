#include<stdio.h>

int UCLN(int x,int y)
{
  if(x ==y)
    return x;
  if(x>y)
    return UCLN(x-y,y);
  return UCLN(x,y-x);
  
}

int main()
{
  int x,y;
  printf("Nhap so x : ");
  scanf("%d",&x);
  printf("Nhap so y : ");
  scanf("%d",&y);
  int T=x*y;
  printf("UCLN= %d\n",UCLN(x,y));
  printf("BCNN= %d\n",T/UCLN(x,y));
}
