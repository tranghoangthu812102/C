
#include <stdio.h>

int doihe(int n )
{
  if( n == 0)
  return 0;
  else
    return n%2 +10 *  doihe(n/2);
}
int main()
{
  int n;
  printf("chuyen doi he co so \n");
  printf("Hay nhap mot so thap phan : ");
  scanf("%d",&n);
  while (n <= 0)
    {
      printf("Nhap lai gia tri duong!\n");
      printf("Gia tri: ");
      scanf("%d", &n);
     }
  printf("sau khi chuyen doi sang nhi phan :%d = %d \n ",n,doihe(n));
  
}
