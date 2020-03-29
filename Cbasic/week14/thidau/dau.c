#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct node
{
  char name[10];
  struct node *Left;
  struct node *Right;
  struct node *Next;
}Node;
Node *Cur=NULL;
Node *makeNode(char a[])
{
  Node *P = (Node *)malloc(sizeof(Node));
  strcpy(P->name,a);
  P->Next=NULL;
  return P;
}
void Push(Node **T, char a[])
{
  Node *P = makeNode(a);
  if(*T == NULL)
    *T = Cur= P;
  else
    {
    Cur->Next = P;
    Cur = Cur->Next;
    Cur->Next=NULL;
    }
}
Node *thang(Node *N1, Node *N2,int a)
{
  Node *P;
  if(a==1) P = makeNode(N1->name);
  else P = makeNode(N2->name);
  P->Left=N1;
  P->Right=N2;
  return P;
}
void TranDau(Node **T)
{
  Node *P = *T;
  *T=NULL;
  while(P!=NULL)
  {
    int a= 1+ rand()% 2;
    Node *N= thang(P,P->Next,a);
    if(*T == NULL)
     {
      *T=N;
      Cur=*T;
     }
    else
     {
      Cur->Next=N;
      Cur=Cur->Next;
     }
    P=P->Next;
    P=P->Next;
  }
  if((*T)->Next!=NULL)
    TranDau(T);
}
void Print(Node *T, FILE *f1, int a)
{
  if(T!=NULL){
    Print(T->Left,f1,a/2);
    //rewind(f1);
  int i;
  Node *P = T;
  while(P!=NULL){
    for(i=a;i>0;i--)
      fprintf(f1," ");
    fprintf(f1,"%s",P->name);
    for(i=a;i>0;i--)
      fprintf(f1," ");
    P = P->Next;
  }
  fprintf(f1,"\n");
  free(P);
  }
}
void freeTree(Node **T)
{
  if(*T!= NULL)
    {
      freeTree(&(*T)->Left);
      freeTree(&(*T)->Right);
      free(*T);
    }
}
int main()
{
  FILE *f;
  if((f=fopen("USopen.txt","r")) == NULL)
    {
      printf("Khong the mo file %s\n","USopen.txt");
      exit(0);
    }
   FILE *f1=fopen("treegame.txt","w");
  Node *T = NULL;
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
      Push(&T,a);
      i=0;
    }
  }
  TranDau(&T);
  Print(T,f1,25);
  
  printf("Nguoi thang : %s \n",T->name);
  fclose(f);
  fclose(f1);
  freeTree(&T);
}
