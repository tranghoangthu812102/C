#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 200

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
void bubbleSort(int  a[],int n)
{
  int i,j;
  for(i=0 ; i<n ; i++)
    for(j= 0; j<n-i-1;j++)
      if(a[j]>a[j+1])
	swap(&a[j],&a[j+1]);
}
void heapify(int a[] , int n , int i)
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

int main()
{
  int lua_chon;
  int  *a = (int * )malloc(MAX*sizeof(int));
  clock_t start , end;
  double total;
  time_t t;
  srand((unsigned)time(&t));
  do
    {
  printf("==========================\n");
  printf("1.Tao lai du lieu\n"
         "2.Insertion Sort \n"
	 "3.Selection Sort\n"
	 "4.Bubble sort\n"
         "5.Heap Sort \n"
	 "0.Thoat\n");
  printf("==========================\n");
  printf("Ban chon : ");
  scanf("%d",&lua_chon);
  switch(lua_chon)
    {
    case 1 :
      for(int i = 0 ; i<MAX ; i++)
	  a[i] = rand() %MAX;
      break;
    case 2:
      start = clock();
      insertionSort(a, MAX);
      end = clock();
      printf("Thoi gian su dung boi CPU : %f\n" , (double)(end - start)/ CLOCKS_PER_SEC);
      break;
    case 3 :
      start = clock();
      selectionSort(a, MAX);
      end = clock();
      total = (double)(end - start)/ CLOCKS_PER_SEC;
      printf("Thoi gian su dung boi CPU : %lf\n" , total);
      break;
    case 4 :
      start = clock();
      bubbleSort(a, MAX);
      end = clock();
      total = (double)(end - start)/ CLOCKS_PER_SEC;
      printf("Thoi gian su dung boi CPU : %lf\n" , total);
      break;
    case 5:
      start = clock();
      heapSort(a ,MAX);
      end = clock();
      total = (double)(end - start)/ CLOCKS_PER_SEC;
      printf("Thoi gian su dung boi CPU : %lf\n" , total);
      break;
    case 0 :
      printf("Ket thuc chuong trinh\n");
      break;
    }
    }while(lua_chon!=0);
  free(a);
}
