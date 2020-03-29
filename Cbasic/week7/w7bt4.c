#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct
{
  char id[20];
  char name[20];
  int grade;
}elementype;
typedef struct node
{
  elementype elemen;
  struct node *next;
  struct node *prev;
}node;
node *head=NULL;
node *cur=NULL;
node *MakeNode()
{
  node *p;
  p=(node *)malloc(sizeof(node));
  if(p==NULL) {
    printf("khong du bo nho de cap phat cho bien");
    exit(0);
  }
  return p;
}
int inser(FILE *f)
{
  node *p=MakeNode();
  fscanf(f,"%s %s %d",p->elemen.name,p->elemen.id,&p->elemen.grade);
  if(feof(f)) return 0;
  if(head ==NULL) head = p;
  else{
    cur=head;
    while(cur!=NULL){
      if(p->elemen.grade >= cur->elemen.grade) break;
      cur=cur->next;
    }
    p->next=cur;
    if(cur->prev!=NULL) cur->prev->next=p;
    p->prev=cur->prev;
    cur->prev=p;
    while(cur->prev!=NULL) cur=cur->prev;
    head=cur;
  }
}
void Delete()
{
  char c[20];
  printf("Ten ban muon xoa: ");
  scanf("%s",c);
  cur=head;
  if(strcmp(cur->elemen.name,c)==0){
    head=head->next;
    free(cur);
    node *cur=NULL;
  }
  else{
    while(cur!=NULL){
      if(strcmp(cur->next->elemen.name,c) ==0) break;
      cur=cur->next;
    }
    if(cur !=NULL) cur->next=cur->next->next;
    else printf("Danh sach ko co ten %s\n",c);
  }
}
void add()
{
  int x;
  printf("Vi tri ban muon them vao: ");
  scanf("%d",&x);
}
void Print()
{
  cur=head;
  while(cur!=NULL){
    printf("%-15s %-20s %-2d\n",cur->elemen.id,cur->elemen.name,cur->elemen.grade);
    cur=cur->next;
  }
}
int main()
{
  FILE *f;
  if((f=fopen("danhsach.txt","r"))==NULL){
    printf("can't open file \n");
    exit(0);
  }
  while(!feof(f)) inser(f);
  Print();
  //Delete();
  //Print();
  //add();
  //Print();
  fclose(f);
}
