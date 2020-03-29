#ifndef FILE_SET
#define FILE_SET

#include "tree2search.h"

void fileOpenRead(FILE **f, char filename[]);
void fileOpenWrite(FILE **f, char filename[]);
void inputDataFromTxt(node **root);
void saveFile(node *root);

#endif
