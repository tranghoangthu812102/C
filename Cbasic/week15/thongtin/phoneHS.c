#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> 

#define MAX_LEN 81

typedef struct
{
  char name[30];
  char tel[11];
  char mail[50];
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

 

      if(left < n && strcmp(a[largest].name,a[left].name) < 0 )
	largest = left;
      if(right < n && strcmp(a[largest].name,a[right].name) < 0 )
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
  phone a[10];
  FILE *file;
  file = fopen("phone.dat","rb");
  fread(a,sizeof(phone),10,file);
  heapSort(a,10);
  for(int i = 0; i <10 ; i++ )
    printf("%-15s %-10s %s\n",a[i].name,a[i].tel,a[i].mail);
    
}
