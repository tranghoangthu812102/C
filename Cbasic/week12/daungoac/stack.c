#include "stack.h"
int isEmpty(LIST *l)
{
  return (l->Head==NULL);
}
NODE *CreatNODE(DT x)
{
	NODE *p=(NODE *)malloc(sizeof(NODE));
	if(p==NULL) return NULL;
	p->x=x;
	p->next=NULL;
	return p;
}
void Push(LIST *l,DT x)
{
	NODE *p=CreatNODE(x);
	if(l->Head==NULL) l->Head=p;
	else
	{
		p->next=l->Head;
		l->Head=p;
	}
}
DT Pop(LIST *l)
{
	NODE *p=l->Head;
	if(p==NULL) return ;
	l->Head=l->Head->next;
	DT a=p->x;
	free(p);
	return a;
}
void Free(LIST *l)
{
	while(l->Head!=NULL) Pop(l);
}
LIST *SeverseLIST(LIST *l)
{
	LIST *p=(LIST *)malloc(sizeof(LIST));
	NODE *a=l->Head;
	while(a!=NULL)
	{
		Push(p,a->x);
		a=a->next;
	}
	return p;
}
