#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
  char model[20];
  char rom[20];
  char inc[20];
  char rate[20];
}element;
typedef struct node
{
  element data;
  struct node *next;
  struct node *prev;
}node;
void swap(node *a, node *b)
{
  element c=a->data;
  a->data=b->data;
  b->data=c;
}
node *head=NULL;
node *cur=NULL;
node *Make(element a)
{
  node *new=(node *)malloc(sizeof(node));
  new->data=a;
  return new;
}
void inser(element a)
{
  if(head==NULL) head=cur=Make(a);
  else {
    node *n=Make(a);
    cur->next=n;
    n->prev=cur;
    cur=cur->next;
  }
}
void insertion_sort()
{
  cur=head->next;
  for(cur=head->next;cur!=NULL;cur=cur->next)
      if(strcmp(cur->data.model,cur->prev->data.model)>0){
	swap(cur,cur->prev);
	cur=cur->prev;
	if(cur->prev!=NULL) cur=cur->prev;
      }
}

int main()
{
  element *A=(element *)malloc(sizeof(element));
  FILE *f=fopen("phoneDB.dat","rb");
  int i=0;
  while(1){
    fread(A,sizeof(element),1,f);
    if(i==9 || feof(f)) break;
    inser(*A);
    i++;
  }
  insertion_sort();
  for(cur=head;cur!=NULL;cur=cur->next)
    printf("%-20s %-5s %-5s %-10s\n",cur->data.model, cur->data.rom,cur->data.inc, cur->data.rate);
  //printf("\n");
}
