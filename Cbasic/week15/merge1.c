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

void merge(phone  a[], int l, int m , int r)
{
  int i,j,k;
  int n1 = m - l +1 ;
  int n2 = r -m ;
  phone L[n1] , R[n2];
  for (i = 0 ; i< n1 ; i++)
    strcpy(L[i].model ,a[l+i].model);
  for(j = 0 ; j <n2 ; j++)
    strcpy(R[j].model,a [m+1+j].model);
  j  = 0;
  i = 0 ;
  k = l;
  while(i < n1 && j <n2)
    {
      if(strcmp(L[i].model,R[j].model) < 0)
	{
	  strcpy(a[k].model, L[i].model);
	  i++;
	}
      else
	{
	  strcpy(a[k].model, R[j].model);
	  j++;
	}
      k++;
    }
  while(i<n1)
    {
      strcpy(a[k].model, L[i].model);
      i++;
      k++;
    }
  while (j<n2)
    {
      strcpy(a[k].model, R[j].model);
      j++;
      k++;
    }
}

void mergeSort(phone a[] , int l , int r)
{
  if(l<r)
    {
      int m = l + (r-l)/2;
      mergeSort(a,l,m);
      mergeSort(a,m+1,r);
      merge(a,l,m,r);
      
    }
}
int main()
{
  phone a[10];
  FILE *file;
  file = fopen("phoneDB.dat","rb");
  fread(a,sizeof(phone),10,file);
  mergeSort(a,0,9);
  for(int i = 0; i <10; i++ )
    printf("%-20s %-5s %-5s %-10s\n",a[i].model,a[i].rom,a[i].inch,a[i].tien);
    
}
