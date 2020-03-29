#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
typedef struct node
{
  char name[10];
  struct node *left;
  struct node *right;
  struct node *next;
}tree;
tree *cur=NULL;
tree *Make(char a[])
{
  tree *new=(tree *)malloc(sizeof(tree));
  strcpy(new->name,a);
  new->next=NULL;
  return new;
}
void push(tree **root, char a[])
{
  tree *new=Make(a);
  if(*root==NULL) *root=cur=new;
  else{
    cur->next=new;
    cur=cur->next;
  }
}
tree *thang(tree *N1, tree *N2,int a)
{
  tree *new;
  if(a==1)
    new=Make(N1->name);
  else 
    new=Make(N2->name);
  new->left=N1;
  new->right=N2;
  return new;
}
void TranDau(tree **root)
{
  tree *p=*root;
  *root=NULL;
  while(p!=NULL){
    int a= 1+ rand()% 2;
    tree *N= thang(p,p->next,a);
    if(*root==NULL){
      *root=N;
      cur=*root;
    }
    else{
      cur->next=N;
      cur=cur->next;
    }
    p=p->next->next;
  }
  if((*root)->next!=NULL) TranDau(root);
}
void Print(tree *root, FILE *f1, int a)
{
  if(root!=NULL){
    Print(root->left,f1,a/2);
    //rewind(f1);
  int i;
  tree *p=root;
  while(p!=NULL){
    for(i=a;i>0;i--) fprintf(f1," ");
    fprintf(f1,"%s",p->name);
    for(i=a;i>0;i--) fprintf(f1," ");
    p=p->next;
  }
  fprintf(f1,"\n");
  free(p);
  }
}
void freetree(tree **root)
{
  if(*root!=NULL){
    freetree(&(*root)->left);
    freetree(&(*root)->right);
    free(*root);
  }
}
int main()
{
  FILE *f=fopen("USopen.txt","r");
  FILE *f1=fopen("treegame.txt","w");
  tree *root=NULL;
  time_t t;
  char a[10];
  srand((unsigned) time(&t));
  char x;
  int i=0;
  while(1){
    x=fgetc(f);
    if(feof(f)) break;
    if(x!=' ') a[i++]=x;
    else {
      a[i++]='\0';
      push(&root,a);
      i=0;
    }
  }
  TranDau(&root);
  Print(root,f1,25);
  
  printf("Nguoi thang : %s \n",root->name);
  fclose(f);
  fclose(f1);
  freetree(&root);
}
