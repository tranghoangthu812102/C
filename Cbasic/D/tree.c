#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "tree.h"
int sl=0;
node *MakeNode(char p[],int a)
{
  node *new=(node *)malloc(sizeof(node));
  strcpy(new->team.name,p);
  if(a>0) new->team.diem=3;
  else if(a==0) new->team.diem=1;
  else new->team.diem=0;
  printf("Not moi thu %d\t%p\n",++sl,new);
  new->left=NULL;
  new->right=NULL;
  return new;
}
int sosanh(node *root, char p[])
{
  int a=strcmp(root->team.name,p);
  if(a==0) return 0;
  if(a>0) return 1;
  return -1;
}
node *Insert(node *root, char p[],int a)
{
  if(root==NULL) root=MakeNode(p,a);
  else {
    if(sosanh(root,p)<0) root->right=Insert(root->right,p, a);
    else if(sosanh(root,p)>0) root->left=Insert(root->left,p,a);
    else {
      if(a==1) root->team.diem+=3;
      else if(a==0) root->team.diem++;
    }
  }
  return root;
}
node *search(node *root, char p[])
{
  if(root==NULL) return NULL;
  if(sosanh(root,p)<0) return search(root->right,p);
  else if(sosanh(root,p)==0) return root;
  else return search(root->left,p);
}
node *Delete(node *root)
{
  node *cur;
  if(root->right==NULL){
    cur=root;
    root=root->left;
  }
  else if(root->left==NULL){
    cur=root;
    root=root->right;
  }
  else{
    cur=root->right;
    node *p=NULL;
    while(cur->left!=NULL){
      p=cur;
      cur=cur->left;
    }
    root->team=cur->team;
    if(p==NULL) root->right=NULL;
    else p->left=Delete(cur);
  }
  free(cur);
  return root;
}
void Display(node *root)
{
  if(root==NULL) return;
  Display(root->left);
  printf("%s\t%d\n",root->team.name,root->team.diem);
  Display(root->right);
}
void FreeTree(node **root)
{
  if(*root!=NULL) {
    FreeTree(&(*root)->left);
    FreeTree(&(*root)->right);
    free(*root);
  }
}
