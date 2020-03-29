#include <stdio.h>
#include <stdlib.h>
int  IN(int i)
{
  printf("%d  ",i);
  if(i==50)
    {
      printf("\n");
      return 0;
    }
  else IN(i+1);
}
int main()
{
  
  IN(1);
}
