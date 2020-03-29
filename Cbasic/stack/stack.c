#include "stack.h"
/*2.Khoi tao danh sach rong */
void Init(Stack *S)
{
    S->Top = NULL;
}

/*3.kiem tra danh sach rong */
int Isempty(Stack *S)
{
    return(S->Top == NULL);
}
/*4.Tao 1 node */
Node *MakeNode(item x)
{
    Node *P=(Node *)malloc (sizeof(Node));
    P->Next = NULL;
    P->Data = x;
    return P;
}
/*5.Chen phan tu vao Stack(Push)*/
void Push(Stack *S,item x)
{
    Node *P = MakeNode(x);
    P->Next = S->Top;
    S->Top = P;
}
/*6.Lay du lieu tai Top nhung khong xoa (Peak)*/
int Peak(Stack S)
{
    return S.Top->Data;
}

/*7.Xoa va lay du lieu tai Top(Pop)*/
int Pop(Stack *S) // Loai bo phan tu khoi Stack
{
    if(!Isempty(S))
    {
        item x = S->Top->Data;//Luu lai gia tri
        S->Top = S->Top->Next;//Xoa phan tu Top
        return x;
    }
}
