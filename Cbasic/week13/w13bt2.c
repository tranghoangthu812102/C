#include <stdlib.h>
#include <stdio.h> 

#define MAX 20
typedef int ElementType;
int BinarySearch(ElementType A[],int low, int high, int element)
{
   int middle;
    while (low <= high)
    {
        middle = low  +(high- low)/2;
        if (element > A[middle])
            low = middle + 1;
        else if (element < A[middle])
            high = middle - 1;
        else
            return middle;
    }
    return -1;
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
 
    p = BinarySearch(a,0,MAX,k);
 
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
