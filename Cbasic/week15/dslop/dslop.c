#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

typedef struct 
{ char fullName[MAX];
  char cutName[5][MAX];
  int cut;
  //int  mssv;
}elm;
void fileOpen(FILE **file, char filename[])
{
    if ((*file = fopen(filename, "r")) == NULL)
    {
        printf("Khong the mo %s\n", filename);
        exit(0);
    }
}
int sv = 0;
void inputDataFromTxt(elm  s[])
{
    FILE *file;
    fileOpen(&file, "danhsachlop.txt");
    char cp[MAX];
    int i = 0;
    while (1)
    {
        fgets(cp, MAX, file);
        if (feof(file))
            break;
        strcpy(s[i].fullName, cp);
        i++;
    }
    sv= i;
    fclose(file);
}
void cutName(elm s[])
{
    const char a[2] = " ";
    char *token;
    elm  new;

    for (int i = 0; i < sv; i++)
    {
        new = s[i];
        int j = 0;
        token = strtok(new.fullName, a);

        /* duyet qua cac token con lai */
        while (token != NULL)
        {
            strcpy(s[i].cutName[j], token);
            j++;
            token = strtok(NULL, a);
        }
        s[i].cut = j;
    }
}
int soSanh(elm s1, elm s2)
{
    int i = s1.cut - 2;
    int j = s2.cut - 2;

    while (i != 0 && j != 0)
    {
        if (strcmp(s1.cutName[i], s2.cutName[j]) > 0)
            return 1;
    	else if (strcmp(s1.cutName[i], s2.cutName[j]) < 0)
            return 0;
        i--;
        j--;
    }
}
void swap(elm *a,elm  *b)
{
  elm  c = *a;
  *a = *b;
  *b = c;
}

void heapify(elm a[] ,int n ,int i)
{
  int largest = i;
  int left = 2*i + 1;
  int right = 2*i + 2;
      if(left < n && soSanh(a[largest],a[left]) == 0 )
	largest = left;
      if(right < n && soSanh(a[largest],a[right]) == 0 )
	largest = right;
      if(largest != i)
	{
	   swap(&a[i],&a[largest]);
           heapify(a,n,largest);
	}
}
void heapSort(elm a[])
{
      for(int i = sv/2 ; i>= 0 ; i--)
	heapify(a,sv,i);
      for(int i = sv-1 ; i>0 ; i-- )
	{
	  swap(&a[0],&a[i]);
           heapify(a,i,0);
	} 
 }

int main()
{
  elm a[26];
  
  inputDataFromTxt(a);

  /*for (int i = 0; i <sv; i++)
    printf("%-10d %-15s",a[i].mssv, a[i].fullName);*/

    cutName(a);

    printf("\n");
    heapSort(a);
  for(int i = 0; i <sv ; i++ )
    printf(" %-15s\n",a[i].fullName);
  return 0;
}
