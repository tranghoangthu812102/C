#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char model[20];
  char rom  [8];
  char inch [15];
  char tien [15];
}DB;

typedef struct Node
{
  DB  data;
  struct Node *next;
  struct Node *prev;
}Node;

Node *head = NULL;
Node *cur = NULL;

void swap(Node *a, Node *b)
{
  DB c =a->data;
  a->data = b->data;
  b->data = c;
}
Node *makeNode(DB data)
{
  Node *P=(Node *)malloc(sizeof(Node));
  if(P == NULL)
    {
      printf("Can't creat P\n");
      return NULL;
    }
  P->data = data;
 
  return P;
}

void inser(DB a)
{
  if(head == NULL)
    head = cur = makeNode(a);
  else
    {
      Node *n = makeNode(a);
      cur->next =n;
      n->prev = cur ;
       cur = cur->next;
    }
}

void insertionSort()
{
  cur = head -> next;
  for(cur = head -> next ; cur != NULL ; cur = cur->next)
    {  if(strcmp(cur->data.model,cur-> prev->data.model) >0)
      swap(cur,cur->prev);
   cur = cur->prev;
    if(cur -> prev !=NULL)
      cur = cur->prev;
    }
}

int main()
{
  DB *A=(DB *)malloc(sizeof(DB));
  FILE *f=fopen("phoneDB.dat","rb");
  int i=0;
  while(1){
    fread(A,sizeof(DB),1,f);
    if(i==9 || feof(f)) break;
    inser(*A);
    i++;
  }
  insertionSort();
  for(cur=head;cur!=NULL;cur=cur->next)
    printf("%-20s %-5s %-5s %-10s\n",
	   cur->data.model, cur->data.rom,cur->data.inch, cur->data.tien);
  //printf("\n");
}
