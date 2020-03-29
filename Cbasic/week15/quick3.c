#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

typedef struct 
{ 
  char fullName[MAX];
  char cutName[5][MAX];
  int cut;
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

void swap(elm *a , elm *b)
{
  elm t = *a;
  *a = *b;
  *b = t;
}

int partition(elm  a[] , int low , int high)
{
  elm  pivot = a[high];
  int i = low -1;

  for(int j = low ; j <= high -1 ; j++ )
    {
      if(soSanh(a[j],pivot) == 0)
	{
	  i++;
	  swap(&a[i],&a[j]);
	}
    }

  swap(&a[i+1] , &a[high]);
  return (i+1);
}

void quickSort(elm a[], int low , int high)
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
  elm a[26];
  
  inputDataFromTxt(a);

    cutName(a);

    printf("\n");
    quickSort(a,0,25);
  for(int i = 0; i <sv ; i++ )
    printf(" %-15s\n",a[i].fullName);
  return 0;
}
