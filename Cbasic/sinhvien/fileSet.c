#include <stdio.h>
#include <stdlib.h>
#include "fileSet.h"

#define MAX_NAME 50

void fileOpenRead(FILE **f, char filename[])
{
  if ((*f = fopen(filename, "r")) == NULL)
    {
      printf("Khong the mo %s\n", filename);
      exit(0);
    }
}

void fileOpenWrite(FILE **f, char filename[])
{
  if ((*f = fopen(filename, "w")) == NULL)
    {
      printf("Khong the mo %s\n", filename);
      exit(0);
    }
}

void inputDataFromTxt(node **root)
{
  FILE *fin;
  fileOpenRead(&fin, "sinhvien.txt");

  elType *data = (elType*) malloc(sizeof(elType));

  while(1)
    {
      fscanf(fin, "%s %s %d", data->name, data->pass, &data->diem);
      if (feof(fin))
	break;
      insertTree(root, *data);
    }

  free(data);
  fclose(fin);
}

void save_LNR(FILE **fin, node *root)
{
  if (root != NULL)
    {
      save_LNR(fin, root->left);
      fprintf(*fin, "%s\t %s\t %d\n",
	     root->data.name, root->data.pass,
	     root->data.diem);
      save_LNR(fin, root->right);
    }
}

void saveFile(node *root)
{
   FILE *fin;
  fileOpenWrite(&fin, "sinhvien.txt");

  save_LNR(&fin, root);
   
  fclose(fin);
}
