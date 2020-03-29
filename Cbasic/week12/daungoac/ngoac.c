#include "stack.h"
#define MAX 100
int dem=0;
int is(char c)
{
	return (c=='['||c=='('||c=='{');
}
int is1(char c)
{
	return (c=='}'||c==')'||c==']');
}
char Chuyen(char c)
{
	if(c==']') return '[';
	if(c=='}') return '{';
	if(c==')') return '(';
	return 'a';
}
void Nhap(LIST *l,char c,int N)
{
	if(is(c))
	{
		DT a;
		a.x=c;
		a.N=N;
		Push(l,a);
	}
}
void KT(LIST *l,char c,int N)
{
	if(is1(c))
	{
		if(Chuyen(c)==l->Head->x.x) Pop(l);
		else
		{
			dem=1;
			printf("Ngoac '%c' o dong thu %d khong phu hop\n",c,N);
		}
	}
}
void DisPlay(DT x)
{
	printf("Thua ngoac '%c' o dong thu %d\n",x.x,x.N);
}
void Text(FILE *f)
{
	int N=1;
	LIST *l=(LIST *)malloc(sizeof(LIST));
	while(!feof(f))
	{
		char c=fgetc(f);
		if(c=='\n') N++;
		KT(l,c,N);
		Nhap(l,c,N);
	}
	while(!isEmpty(l)) 
	{
		DT b=Pop(l);
		DisPlay(b);
		dem=1;
	}
	Free(l);
}
int main()
{
	FILE *f=fopen("w9btvn1.c","r");
	Text(f);
	fclose(f);
	if(dem==0) printf("Khong co loi sai\n");
}
