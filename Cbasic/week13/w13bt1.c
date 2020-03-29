#include <stdio.h>

int LinearSentinelSearch( long s[] , long N , long X)
{ 
  int k=0;
  s[N]=X;
  while(s[k]!=X) k++;
  return k;
}

int main()
{
   long a[100], search, i, n, position;
 
   printf("Nhap so phan tu cua mang\n");
   scanf("%ld", &n);
 
   printf("hay nhap %ld phan tu\n", n);
 
   for (i = 0; i < n; i++)
      scanf("%ld", &a[i]);
 
   printf("Nhap phan tu tim kiem \n");
   scanf("%ld", &search);
 
   position = LinearSentinelSearch(a, n, search);
 
   if (position == -1)
      printf("Khong tim thay %ld trong mang\n", search);
   else
      printf("phan tu %ld o vi tri %ld trong mang \n", search, position+1);
 
   return 0;

}
