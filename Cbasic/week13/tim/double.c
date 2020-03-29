#include "double.h"
int isEmpty(LIST *l)
{
	return (l->Head==NULL);
}
NODE *CreatNODE(DT a)
{
	NODE *p=(NODE *)malloc(sizeof(NODE));
	if(p==NULL) return NULL;
	p->x=a;
	p->next=NULL;
	p->prew=NULL;
	return p;
}
void AddHead(LIST *l,DT a)
{
	NODE *p=CreatNODE(a);
	if(l->Head==NULL) l->Head=l->Tail=p;
	else
	{
		p->next=l->Head;
		l->Head->prew=p;
		l->Head=p;
	}
	l->Cur=p;
}
void AddTail(LIST *l,DT a)
{
	NODE *p=CreatNODE(a);
	if(l->Head==NULL) l->Head=l->Tail=p;
	else
	{
		l->Tail->next=p;
		p->prew=l->Tail;
		l->Tail=p;
	}
	l->Cur=p;
}
void AddAfter(LIST *l,DT a)
{
	NODE *p=CreatNODE(a);
	if(l->Head==NULL) l->Head=l->Tail=p;
	else if(l->Cur->next==NULL) AddTail(l,a);
	else
	{
		p->prew=l->Cur;
		p->next=l->Cur->next;
		l->Cur->next->prew=p;
		l->Cur->next=p;
	}
	l->Cur=p;
}
void AddBefor(LIST *l,DT a)
{
	NODE *p=CreatNODE(a);
	if(l->Head==NULL) l->Head=l->Tail=p;
	else if(l->Cur->prew==NULL) AddHead(l,a);
	else
	{
		p->next=l->Cur;
		p->prew=l->Cur->prew;
		l->Cur->prew->next=p;
		l->Cur->prew=p;
	}
	l->Cur=p;
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
void DeleteHeal(LIST *l)
{
    if(l->Head==NULL) printf("LIST rong\n");
	else if(l->Tail==l->Head) Free(l);
    else
    {
        NODE *p=l->Head;
        l->Head=l->Head->next;
		l->Head->prew=NULL;
		l->Cur=l->Head;
        free(p);
	    }
}
void DeleteTail(LIST *l)
{
	if(l->Head==NULL) printf("LIST rong\n");
	else if(l->Tail==l->Head) Free(l);
	else
	  {
	    NODE *a=l->Tail;
	    l->Tail=a->prew;
	    l->Tail->next=NULL;
		l->Cur=l->Tail;
	    free(a);	    
	  }
}
void DeleteCur(LIST *l)
{
	if(l->Head==NULL) printf("LIST rong\n");
	else if(l->Tail==l->Head) Free(l);
	else if(l->Cur==l->Head) DeleteHeal(l);
	else if(l->Cur==l->Tail) DeleteTail(l);
	else
	  {
	    NODE *a=l->Cur;
		l->Cur->prew->next=l->Cur->next;
		l->Cur->next->prew=l->Cur->prew;
		l->Cur=l->Cur->next;
		free(a);	    
	  }
}
void DeletePos(LIST *l,int n)
{
    NODE *p=l->Head;
    for(int i=0;i<n;i++) 
    {
        if(p==NULL) break;
        p=p->next;
    }
	l->Cur=p;
    if(p==NULL) printf("Khong ton tai vi tri\n");
    else DeleteCur(l);
}

void InsertPos(LIST *l, DT p,int n)
{
    NODE *q=l->Head;
    for(int i=0;i<n;i++) 
    {
        if(q==NULL) break;
        q=q->next;
    }
    if(q==NULL) printf("Khong ton tai vi tri\n");
    else 
    {
        if(n==0) AddHead(l,p);
        else if(q==l->Tail) AddTail(l,p);
        else AddBefor(l,p);
    }
}
LIST *SeverseLIST(LIST *l)
{
	LIST *p=(LIST *)malloc(sizeof(LIST));
	NODE *a=l->Head;
	while(a!=NULL)
	{
		AddHead(p,a->x);
		a=a->next;
	}
	return p;
}
int MoveToFront(LIST *l,DT x)
{
  NODE *p=l->Head;
  while(p!=NULL)
    {
	if(strcmp(p->x.Model,x.Model)==0) break;
	p=p->next;
	}
  if(p==NULL) printf("Khong ton tai\n");
  else
    {
      l->Cur=p;
	DT a=p->x;
      DeleteCur(l);
      AddHead(l,a);
    }
	return (p!=NULL);
}
int Transpose(LIST *l,DT x)
{
  NODE *p=l->Head;
  DT a;
  while(p!=NULL)
    {
	if(strcmp(p->x.Model,x.Model)==0) break;
	p=p->next;
	}
  	if(p==NULL) printf("Khong ton tai\n");
  	else if (p==l->Tail||p==l->Head) 
	{
		l->Cur=p;
		a=p->x;
		DeleteCur(l);
		AddBefor(l,a);
	}
	else
	{
	  a=p->x;
	  l->Cur=p;
	  DeleteCur(l);
	  l->Cur=l->Cur->prew;
	  AddBefor(l,a);
	}
	return (p!=NULL);
}
