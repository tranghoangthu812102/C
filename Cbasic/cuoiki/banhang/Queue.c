#include "Queue.h"
int isEmpty(LIST *l)
{
	return(l->Head==NULL);
}
void Empty(LIST *l)
{
	l->Head=l->Tail=NULL;
	l->Sum=0;
}
NODE *CreatNODE(DT a)
{
	NODE *p=(NODE *)malloc(sizeof(NODE));
	if(p==NULL)	return NULL;
	p->x=a;
	p->next=NULL;
	p->prew=NULL;
	return p;
}
void EnQueue(LIST *l,DT a)
{
	NODE *p=CreatNODE(a);
	if(l->Head==NULL) l->Head=l->Tail=p;
	else
	{
		l->Tail->next=p;
		p->prew=l->Tail;
		l->Tail=p;
	}
	l->Sum++;
}
void Free(LIST *l)
{
	NODE *p=l->Head;
	while(p!=NULL)
	{
		l->Head=l->Head->next;
		free(p);
		p=l->Head;
	}
	free(p);
}
DT DeQueue(LIST *l)
{
	if(!isEmpty(l))
	{
		NODE *p=l->Head;
		DT a=p->x;
		if(l->Head->next==NULL) l->Head=l->Tail=NULL;
		else
		{
			l->Head=l->Head->next;
			l->Head->prew=NULL;
		}
		l->Sum--;
		free(p);
		return a;
	}
}