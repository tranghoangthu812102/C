#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void insertionSort( int  a[],int n)
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
void swap(int*a , int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int a[] , int low , int high)
{
  int pivot = a[high];
  int i = low -1;

  for(int j = low ; j<= high -1 ; j++ )
    {
      if(a[j] <= pivot)
	{
	  i++;
	  swap(&a[i],&a[j]);
	}
    }

  swap(&a[i+1] , &a[high]);
  return (i+1);
}

void quickSort(int a[], int low , int high)
{
  if(low < high)
    {
      int pi = partition(a,low,high);
      quickSort(a,low , pi -1);
      quickSort(a,pi + 1,high);
    }
}
void printArray(int  a[],int n)
{
  int i;
  for (i=0 ; i< n;i++)
    printf("%d ",a[i]);
  printf("\n");
}

int main()
{
  int lua_chon;
  clock_t start , end;
  double total;
  time_t t;
  int *a= (int * )malloc(MAX*sizeof(int));
  int *b= (int * )malloc(MAX*sizeof(int));
  srand((unsigned)time(&t));
  for(int i = 0;i<MAX;i++)
    {
      a[i] = rand()%MAX;
      b[i] = a[i];
        printf("%d ",b[i]);
    }

  printf("\n==========================\n");
  printf("1.Insertion Sort \n");
  printf("2.Quick  Sort \n");
  printf("Ban chon : ");
  scanf("%d",&lua_chon);
  if(lua_chon == 1)
    {
      start = clock();
      insertionSort(a, MAX);
      printf("Sorted Array : \n");
      printArray(a,MAX);

      end = clock();
      total = (double)(end - start)/ CLOCKS_PER_SEC;
      printf("Thoi gian su dung boi CPU : %lf\n" , total);
      }
  if(lua_chon == 2)
    {
      start = clock();
      quickSort(a ,0, MAX);
      printf("Sorted Array : \n");
      printArray(a,MAX);

      end = clock();
      total = (double)(end - start)/ CLOCKS_PER_SEC;
      printf("Thoi gian su dung boi CPU : %lf\n" , total);
      }
  
}
