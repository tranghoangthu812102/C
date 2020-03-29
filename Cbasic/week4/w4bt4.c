#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
int main()
{
  int a1 , a2 ;
  char *result;
  char s[MAX],a[MAX];
  printf("Nhap xau 1 : ");
  gets(s);
  printf("Nhap xau 2 : ");
  gets(a);
  a1 = strlen(s);
  a2 = strlen(a); 
  result = (char *)malloc((a1 + a2 +1)* sizeof(char));
  if(!result)
    {
      printf("Khong cap phat duoc\n");
      return 0;
    }
  strcpy(result,s);
  strcat(result,a);
  printf("Xau moi la: ");
  puts(result);
  free(result);
  return 0;
  
}
