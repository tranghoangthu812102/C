#include <stdio.h>
#include <math.h>

int x,y;
int Tich(int x, int y)
{ int T=0;

  if(y == 0 )
    return 0;
  else T=T+x;
    return (T + Tich(x,y-1));
}
int main()
{
  printf("Nhap x :");
  scanf("%d",&x);
  printf("Nhap y:");
  scanf("%d",&y);
  printf("Ket qua la :%d ",Tich(x,y));
}
