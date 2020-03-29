#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> 

#define MAX 81
typedef struct
{
  char model[20];
  char rom[20];
  char inch[20];
  char tien[20];
}phone;

void swap(phone *a,phone *b)
{
  phone c = *a;
  *a = *b;
  *b = c;
}

void heapify(phone a[] ,int n ,int i)
{
  int largest = i;
  int left = 2*i + 1;
  int right = 2*i + 2;

 

      if(left < n && strcmp(a[largest].model,a[left].model) < 0 )
	largest = left;
      if(right < n && strcmp(a[largest].model,a[right].model) < 0 )
	largest = right;
      if(largest != i)
	{
	   swap(&a[i],&a[largest]);
           heapify(a,n,largest);
	}
}
void heapSort(phone a[],int n)
{
      for(int i = n/2 -1 ; i>= 0 ; i--)
	heapify(a,n,i);
      for(int i = n-1 ; i>= 0 ; i-- )
	{
	  swap(&a[0],&a[i]);
           heapify(a,i,0);
	}
 }

int main()
{
  phone a[27];
  FILE *file;
  file = fopen("phoneDB.dat","rb");
  fread(a,sizeof(phone),27,file);
  heapSort(a,27);
  for(int i = 0; i <27; i++ )
    printf("%-20s %-5s %-5s %-10s\n",a[i].model,a[i].rom,a[i].inch,a[i].tien);
    
}
