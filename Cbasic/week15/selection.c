#include <stdio.h>

void swap( int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

void selectionSort(int a[] , int n)
{
  int i , j , min;
  for(i = 0; i<n ;i++)
    {
      min = i;
      for(j=i+1;j<n;j++)
	if(a[j] <a[min])
	  min = j;
      swap(&a[min],&a[i]);
    }
}

void printArray(int a[],int n)
{
  int i;
  for(i=0 ; i<n ; i++)
    printf("%d  ",a[i]);
  printf("\n");
}

int main()
{
  int a[]= {64,25,12,22,11};
  int n = sizeof(a)/sizeof(a[0]);
  printf("Array : \n");
  for(int i=0 ; i<n ; i++)
    {
      printf("%d  ",a[i]);
    }
  selectionSort(a,n);
  printf("\nSorted array: \n");
  printArray(a,n);
  
}
