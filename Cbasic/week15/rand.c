#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

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

void heapify(int  a[] , int n , int i)
{
  int largest = i;
  int l = 2*i;
  int r = 2*i+1;

  if(l < n && a[l] > a[largest])
    largest = l;

  if(r < n && a[r] > a[largest])
    largest = r;
  if(largest != i)
    {
      int temp = a[i];
      a[i] = a[largest];
      a[largest] = temp;
      heapify(a,n,largest);
    }
}

void heapSort(int  a[] ,int n)
{
  for(int i = n/2 -1 ; i>=0 ; i-- )
    heapify(a,n,i);
  for(int i = n-1; i >=0 ; i--)
    {
      int temp = a[0];
      a[0] = a[i];
      a[i] = temp;
      heapify(a,i,0);
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
  printf("2.Heap Sort \n");
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
      heapSort(a , MAX);
      printf("Sorted Array : \n");
      printArray(a,MAX);

      end = clock();
      total = (double)(end - start)/ CLOCKS_PER_SEC;
      printf("Thoi gian su dung boi CPU : %lf\n" , total);
      }
  
}
