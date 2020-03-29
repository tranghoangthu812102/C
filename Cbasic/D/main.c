#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "tree.h"
void push(node **root, char t1[], char t2[], int a, int b)
{
  if(a>b){
    *root=Insert(*root,t1,1);
    *root=Insert(*root,t2,-1);
  }
  else if(a<b) {
    *root=Insert(*root,t2,1);
    *root=Insert(*root,t1,-1);
  }
  else {
    *root=Insert(*root,t1,0);
    *root=Insert(*root,t2,0);
  }
}
void ReadFile(node **root, FILE *f)
{
  char t1[10],t2[10];
  int a,b;
  while(1){
    fscanf(f,"%s%*c%s%*c%d%*c%d",t1,t2,&a,&b);
    if(feof(f)) break;
    push(root,t1,t2,a,b);
  }
}
node *Xuonghang(node *root,int x)
{
  if(root!=NULL){
  if(root->team.diem<x) root= Delete(root);
  if(root!=NULL){
  root->left=Xuonghang(root->left,x);
  root->right=Xuonghang(root->right,x);
  }
  return root;
  }
}
void Xuatfile(node *root, FILE *f)
{
  if(root==NULL) return;
  Xuatfile(root->left,f);
  fprintf(f,"%s\t%d\n",root->team.name,root->team.diem);
  Xuatfile(root->right,f);
}
int main()
{
  FILE *f,*f1;
  if((f=fopen("BongDa.txt","r+"))==NULL){
    printf("khong the mo file BongDa.txt\n");
    exit(0);
  }
  if((f1=fopen("KetQua.txt","w"))==NULL){
    printf("khong the mo file KetQua.txt\n");
    exit(0);
  }
  int a,x;
  node *root=NULL;
  node *cur;
  char p[10];
  do{
    printf("\n~~~~MENU~~~~\n");
    printf(" 1.Tao cay\n 2.Ket qua\n 3.Tim kiem\n 4.Xuong hang\n 5.Xuat file\n 0.exit\n");
    scanf("%d",&a);
    switch(a)
      {
      case 1: ReadFile(&root,f);
	break;
      case 2: Display(root);
	break;
      case 3:
	printf("Nhap ma doi bong : ");
	scanf("%s",p);
	if((cur=search(root,p))==NULL)
	  printf("khong co doi bong nay\n");
	else printf("diem cua doi bong: %d \n",cur->team.diem);
	break;
      case 4:
	printf("X=");
	scanf("%d",&x);
	root=Xuonghang(root,x);
	break;
      case 5: Xuatfile(root,f1);
	break;
      }
  }while(a!=0);
  fclose(f);
  fclose(f1);
  FreeTree(&root);
}
