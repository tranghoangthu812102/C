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
void swap(phone *a , phone *b)
{
  phone t = *a;
  *a = *b;
  *b = t;
}

int partition(phone  a[] , int low , int high)
{
  phone  pivot = a[high];
  int i = low -1;

  for(int j = low ; j<= high -1 ; j++ )
    {
      if(strcmp(a[j].model,pivot.model) < 0)
	{
	  i++;
	  swap(&a[i],&a[j]);
	}
    }

  swap(&a[i+1] , &a[high]);
  return (i+1);
}

void quickSort(phone a[], int low , int high)
{
  if(low < high)
    {
      int pi = partition(a,low,high);
      quickSort(a,low , pi -1);
      quickSort(a,pi + 1,high);
    }
}
int main()
{
  phone a[27];
  FILE *file;
  file = fopen("phoneDB.dat","rb");
  fread(a,sizeof(phone),27,file);
  quickSort(a,0,26);
  for(int i = 0; i <27; i++ )
    printf("%-20s %-5s %-5s %-10s\n",a[i].model,a[i].rom,a[i].inch,a[i].tien);
    
}
