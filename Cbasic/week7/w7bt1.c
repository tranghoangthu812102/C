
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct ADD
{
  char name[20];
  char tel[11];
  char email[25];
  struct ADD *next;
}ADD;
typedef struct LIST
{
  ADD *Heal;
  ADD *Tail;
}LIST;
void NhapNODE(ADD *a)
{
  printf("Nhap ten: ");
  gets(a->name);
  printf("Nhap tel: ");
  gets(a->tel);
  printf("Nhap email: ");
  gets(a->email);
}
ADD *inNODE(ADD *a)
{
  ADD *s=(ADD *)malloc(sizeof(ADD));
  strcpy(s->name,a->name);
  strcpy(s->tel,a->tel);
  strcpy(s->email,a->email);
  s->next=NULL;
  return s;
}
void Empty(LIST *l)
{
  l->Heal=l->Tail=NULL;
}
void AddHeal(LIST *l,ADD *a)
{
  ADD *s=inNODE(a);
  if(l->Heal==NULL) l->Heal=l->Tail=s;
  else
    {
      s->next=l->Heal;
      l->Heal=s;
    }
}
void AddTail(LIST *l,ADD *a)
{
  ADD *s=inNODE(a);
  if(l->Heal==NULL) l->Heal=l->Tail=s;
  else
    {
      l->Tail->next=s;
      l->Tail=s;
    }
}
void InNODE(ADD *a)
{
  if(a==NULL) printf("Loi con tro NULL\n");
  else printf("%-25s%-15s%s\n",a->name,a->tel,a->email);
}
void In(LIST *l)
{
  ADD *s=l->Heal;
  printf("------------- DANH SACH --------------\n");
  printf("%-25s%-15s%s\n","Ho va ten","Tel","Email");
  while(s!=NULL)
    {
      InNODE(s);
      s=s->next;
    }
}
int main()
{
  LIST *l=(LIST *)malloc(sizeof(LIST));
  Empty(l);
  ADD *s=(ADD *)malloc(sizeof(ADD));;
  int N;
  printf("Nhap so phan tu : ");
  scanf("%d%*c",&N);
  for(int i=0;i<N;i++)
    {
      NhapNODE(s);
      AddHeal(l,s);
    }
  In(l);
  return 0;
}
  
