#include <stdlib.h>
#include <stdio.h> 

#define MAX 20
typedef int ElementType;

int BinarySearch(ElementType A[ ], ElementType X, int Low,int High )
{

     if (Low > High)
         return -1;
     int Mid = ( Low + High ) / 2;
     if (A[ Mid ] < X )
          return BinarySearch(A, X, Mid +1, High);
      if ( A[ Mid ] > X )
          return BinarySearch(A, X, Low, Mid - 1);
          return Mid;
    
}
int main()
{
    int a[10] = {5, 7, 8, 9 , 20, 21, 54, 67, 89, 93};
    int i, e, k, p;
 
    printf("Array: ");
    for(i = 0; i < 10; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
 
    printf("\nNhap phan tu tim kiem :");
    scanf("%d",&k);
 
    p = BinarySearch(a,k,0,MAX);
 
    if(p >= 0)
    {
        printf("phan tu %d o vi tri %d (tinh tu vi tri 0)\n",k,p);
    }
    else
    {
        printf("khong tim thay phan tu %d\n",k);
    }
    return 0;
}

