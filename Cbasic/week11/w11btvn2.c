#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define Max 100 //so phan tư toi da cua Stack

typedef int item; // kieu du lieu cua Stack
typedef struct
{
    int Top;
    item Data[Max];
}Stack;
/*1. Khởi tạo Stack rỗng */
void Init(Stack *S)
{
    S->Top = 0 ; //Stack rỗng khi Top là 0
}
/*2.Kiểm tra Stack rỗng */
int Isempty(Stack *S)
{
    return (S->Top == 0);
}

/*3.Kiem tra Stack đầy */
int Isfull(Stack *S)
{
    return (S->Top == Max);
}
/*4. Them pha tu vao Stack */
Stack *Push(Stack *S , item x)
{
    if(!Isfull(S))
    {
        S->Data[S->Top]= x ; //gan du lieu
        S->Top ++; // Tang Top len 1
    }
    return S;
}

/*5.Lay phan tu o dau Stack nhung khong xoa */
int Peak(Stack S)
{
    return S.Data[S.Top-1];//Lay du lieu tai Top
}

/*6.Loai bo phan tu khoi Stack*/
int Pop(Stack *S)
{
    if(!Isempty(S))
    {
        S->Top -- ;//Giam Top
        return S->Data[S->Top];//Lay du lieu tai Top
    }
}
/*9.So sánh*/
int sosanh(Stack *S1, Stack *S2)
{
    int n=0;
  int x=0;
  int x1,x2;
  while(!Isempty(S1))
    {
    if(Isempty(S2)){
            S1->Top+=n;
            S2->Top+=n;
    return 0;}
    x1=Pop(S1);
    x2=Pop(S2);
    n++;
    if(x2>x1)
     x=1;
    else
     x=0;
  }
  S1->Top=n;
  if(!Isempty(S2)){
      S2->Top+=n;
        return 1;}
  S2->Top+=n;
  return x;
}
/*10.Tính hiệu */
void Hieu(Stack *S1, Stack *S2, int dau)
{
  int x1,x2;
  int du = 0;
  Stack *KQ= (Stack *)malloc(sizeof(Stack));
  Init(KQ);
  int kqr =0 ;
  while(!Isempty(S2))
{   x2=Pop(S2);
    x1=Pop(S1);
    x1=x1-du;
    if(x1<x2)
        {   du=1;
            KQ=Push(KQ,10*x1-x2);
        }
    else
        {   du=0;
            KQ=Push(KQ,x1-x2);
        }
}
  while(!Isempty(S1))
    {
    x1=Pop(S1);
    x1=x1-du;
    du=0;
    KQ=Push(KQ,x1);
    }
  KQ->Data[KQ->Top-1] = dau*KQ->Data[KQ->Top-1];
  while(!Isempty(KQ))
  {
    kqr=Pop(KQ);
    printf("%d",kqr);
  }
  printf("\n");
  }
int main()
{
    Stack *S1 = (Stack *)malloc(sizeof(Stack));
    Stack *S2 = (Stack *)malloc(sizeof(Stack));
    char c;
    int x;
    Init(S1);
    Init(S2);
    printf("Nhap so dau tien: ");
    c= getchar();
    while(c >= '0' && c<= '9')
    {
        x = (int)(c-'0');
        S1=Push(S1,x);
        c=getchar();
    }
    printf("Nhap so thu hai: ");
    c= getchar();
    while(c >= '0' && c<= '9')
    {
        x = (int)(c-'0');
        S2=Push(S2,x);
        c=getchar();
    }
   if(sosanh(S1,S2)== 0){

        Hieu(S1,S2,1);}
    else{
        Hieu(S2,S1,-1);
        }
}
