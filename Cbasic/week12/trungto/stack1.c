#include "stack1.h"

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
void Push(Stack *S , item x)
{
    if(!Isfull(S))
    {
        S->Data[S->Top]= x ; //gan du lieu
        S->Top ++; // Tang Top len 1
    }
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
