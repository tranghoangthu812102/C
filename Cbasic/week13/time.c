#include <stdio.h>
#include <time.h>

#define MAX 500000

long linear_search(long a[],long n , long x)
{
  long i;
  for(i=0; i< n ; i++)
    {
      if(a[i] == x)
	return i;
    }
  return -1;
}

long sentinel_search(long a[],long n,long x)
{  
   long i=0;
   a[n] = x;
   while(a[i++] !=x)
     {
       if((a[i] == x) && (i < n))
	 return i;
     }
   
  return i-1;
 }

long binary_search(long a[],long x,int Low,int High )
{
   if (Low > High)
         return -1;
     int Mid = ( Low + High ) / 2;
     if (a[ Mid ] < x )
          return binary_search(a, x, Mid +1, High);
      if ( a[ Mid ] > x )
          return binary_search(a, x, Low, Mid - 1);
          return Mid;
}
int main()
{
  long a[MAX];
  long i,x,k;
  clock_t start,finish;
  double total;
  int lua_chon;
  for(i=0 ; i< MAX; i++)
    a[i]= 2*i+3;
   printf("Nhap so can tim : ");
   scanf("%ld",&x);
  do
    {
      printf("\n==========================\n");
      printf("\n~~~~~~~~~~MENU~~~~~~~~~~~~\n");
      printf("1.Tim kiem tuan tu thong thuong\n"
	     "2.Tim kiem su dung Sentinel\n"
	     "3.Tim kiem nhi phan\n"
	     "0.Thoat!\n");
      printf("Ban Chon : ");
      scanf("%d",&lua_chon);
      switch(lua_chon)
	{
	case 1:
	 start = clock();
	 k= linear_search( a,MAX,x);
	  if(k >= 0)
	    {
	      printf("Phan tu %ld o vi tri thu %ld(tinh tu vi tri 0)\n",x,k);
	    }
	  else
	    {
	    printf("Khong tim thay phan tu %ld\n",x);
	    }
	  finish = clock();
          total = (float)(finish - start)/CLOCKS_PER_SEC;
	  printf("thoi gian thuc thi chuong trinh : %lf \n",total);
	  break;
	case 2:
	  start = clock();
	  k= sentinel_search( a,MAX,x);
	  if(k >= 0)
	    {
	      printf("Phan tu %ld o vi tri thu %ld(tinh tu vi tri 0)\n",x,k);
	    }
	  else
	    {
	    printf("Khong tim thay phan tu %ld\n",x);
	    }
	  finish = clock();
          total = (float)(finish - start)/CLOCKS_PER_SEC;
	  printf("thoi gian thuc thi chuong trinh : %lf \n",total);
	  break;
	case 3 :
	  start = clock();
	  a[i]= 2*i+3;
	  k =binary_search( a,x,0,MAX);
	  if(k >= 0)
	    {
	      printf("Phan tu %ld o vi tri thu %ld(tinh tu vi tri 0)\n",x,k);
	    }
	  else
	    {
	    printf("Khong tim thay phan tu %ld\n",x);
	    }
	  finish = clock();
          total = (float)(finish - start)/CLOCKS_PER_SEC;
	  printf("thoi gian thuc thi chuong trinh : %lf \n",total);
	  break;
	case 0:
	  printf("KET THUC CHUONG TRINH!\n");
	  break;
       }
    }while(lua_chon!=0);
}
