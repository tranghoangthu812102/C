#include "stack.h"
#include <string.h>
#define MAX 50

typedef struct 
{
  char c[MAX];
  struct elem *next;
}elem;

elem *ph(elem *kt , char s[])
{
  elem *P;
  P = (elem *)malloc(sizeof(elem));
  strcpy(P->c,s);
  P->next = kt;
  kt = P;
  return kt;
}

elem *pp(elem *kt,char s[])
{
  elem *tmp=kt;
  strcpy(s,kt->c);
  kt =kt->next;
  free(tmp);
  return kt;
}

elem *nhap(elem *kt,int x, double n)
{
  char s[MAX];
  sprintf(s,"%d%lf",x,n);
  kt = ph(kt,s);
  return kt;
}

elem *xuat(elem *kt,double *x)
{
  char s[MAX];
  kt = pp(kt,s);
  *x = atof(s);
  return kt;
}
int main()
{ Stack *S;
  S = (Stack *)malloc(sizeof(Stack));
  Init(S);
  elem *kt =NULL;
  int lua_chon;
  double i,n;
  for(i=0;i<10;i++)
    Push(S,i);
  do{
    printf("\n------------MENU--------------\n");
    printf("1.Them 1 so nguyen\n"
	   "2.xem dinh\n"
	   "3.Lay khoi ngan xep 1 phan tu\n"
	   "4.undo\n"
	   "5.Thoat\n");
    printf("Ban chon : ");
    scanf("%d",&lua_chon);
    switch(lua_chon)
      {
      case 1:
	printf("So muon them vao :");
	scanf("%lf",&n);
	Push(S,n);
	kt = nhap(kt,1,n);
	break;
      case 2:
	printf("%d\n",S->Top->Data);
	break;
      case 3:
	kt = nhap(kt,2,S->Top->Data);
	Pop(S);
	break;
      case 4:
	if(kt->c[0] == '1')
	  {
	    kt->c[0] = '0';
	    kt = xuat(kt,&n);
	    Pop(S);
	  }
	else
	  {
	  kt->c[0]='0';
	  kt=xuat(kt,&n);
	  Push(S,n);
	  }
	break;
       }
	
  }while(lua_chon!=5);
}
