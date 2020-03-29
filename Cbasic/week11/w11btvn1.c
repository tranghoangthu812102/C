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
/*8.Tính tổng */
void Sum(Stack *S1, Stack *S2)
{
    item n =0;
    item x1,x2;
    double kq = 0;
    while(!Isempty(S1))
    {
        x1 = Pop(S1);
        x2 = Pop(S2);
        kq +=(x1+x2)*pow(10,n);
        n++;
    }
    printf("KQ : %lf\n",kq);
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
    Sum(S1,S2);
}
