#include <stdio.h>

int dayso(int n)
{
  if(n==0)
    return 0;
  if(n == 1)
    return 1;
  else
    return dayso(n-1) + dayso(n-2);
}
int main()
{
  int k;
  printf("Nhap k:");
  scanf("%d",&k);
  printf("Day so Fib la : ");
  for (int i=0 ; i<k;i++)
    {
  printf("%d  ",dayso(i));
    }
}
