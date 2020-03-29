#ifndef TREE
#define TREE
typedef struct 
{
  char name[10];
  int diem;
}elementype;
typedef struct node
{
  elementype team;
  struct node *left;
  struct node *right;
}node;
node *MakeNode(char p[], int a);
int sosanh(node *root, char p[]);
node *Insert(node *root, char p[],int a);
node *search(node *root, char p[]);
void Display(node *root);
node *Delete(node *root);
void FreeTree(node **root);

#endif
