#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void insertionSort(char a[10][10],int n)
{
  int i,j;
  char key[10];
  for(i=1;i<n;i++)
    {
      strcpy(key,a[i]);
      j = i-1;
      while (j >= 0 && (strcmp(a[j],key) > 0))
	{
	  strcpy(a[j+1],a[j]);
	  j = j-1;
	}
      strcpy(a[j+1],key) ;
    }
}

void printArray(char a[10][10],int n)
{
  int i;
  for (i=0 ; i<n;i++)
    printf("%s  ",a[i]);
  printf("\n");
  }


int main()
{
  char a[10][10] =
    {"girl", "boy", "some","any","town","car","walked","over","the","from" };
  int n = sizeof(a) / sizeof(a[0]);
  printf("Array : \n ");
  for (int i=0 ; i< n ; i++)
    printf("%s  ",a[i]);
  
  insertionSort(a,n);
  printf("\n Sorted Array : \n");
  printArray(a,n);
  
}
