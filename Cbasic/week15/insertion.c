#include <stdio.h>
#include <math.h>

void insertionSort(int a[],int n)
{
  int i,key,j;
  for(i=1;i<n;i++)
    {
      key = a[i];
      j = i-1;
      while (j >= 0 && a[j] > key)
	{
	  a[j+1] = a[j];
	  j = j-1;
	}
      a[j+1] = key ;
    }
}

void printArray(int a[],int n)
{
  int i;
  for (i=0 ; i<n;i++)
    printf("%d  ",a[i]);
  printf("\n");
}

int main()
{
  int a[] = { 12,11,13,5,6};
  int n = sizeof(a) / sizeof(a[0]);
  printf("Array : \n ");
  for (int i=0 ; i< n ; i++)
    
  printf("%d  ",a[i]);
  
  insertionSort(a,n);
  printf("\n Sorted Array : \n");
  printArray(a,n);
}
