#include <stdio.h>
#include <stdlib.h>
/*1.Xay dung cau truc */
typedef int item; //kieu du lieu
typedef struct Node
{
    item Data;
     struct Node *Next;//link
}Node;

typedef struct
{
   struct Node *Top;
}Stack;

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

/*4. Do dai danh sach */
int Len(Stack *S)
{
    Node *P = S->Top;
    int i=0;
    while(P!= NULL)
    {
        i++;
        P = P->Next;
    }
    return i;
}

/*5.Tao 1 node */
Node *MakeNode(item x)
{
    Node *P=(Node *)malloc (sizeof(Node));
    P->Next = NULL;
    P->Data = x;
    return P;
}
/*6.Chen phan tu vao Stack(Push)*/
void Push(Stack *S,item x)
{
    Node *P = MakeNode(x);
    P->Next = S->Top;
    S->Top = P;
}
/*7.Lay du lieu tai Top nhung khong xoa (Pesk)*/
int Peak(Stack S)
{
    return S.Top->Data;
}

/*8.Xoa va lay du lieu tai Top(Pop)*/
int Pop(Stack *S) // Loai bo phan tu khoi Stack
{
    if(!Isempty(S))
    {
        item x = S->Top->Data;//Luu lai gia tri
        S->Top = S-> Top ->Next;//Xoa phan tu Top
        return x;
    }
}

void Input(Stack *S)//nhap danh sach
{
    int i=0;
    item x;
    do
    {
        i++;
        printf("Nhap phan tu thu %d : ",i);
        scanf("%d",&x);
        if(x!= 0)
            Push(S,x);
    }while(x!=0);//Nhap khong de ket thuc
}

void Output(Stack *S)
{
    Node *P= S-> Top;
    while(P!= NULL)
    {
        printf("%d  ",P->Data);
        P = P->Next;
    }
    printf("\n");
}

int main()
{
     Stack *S; //   Stack S : sai vì chỗ này phải khai báo con trỏ và cấp phát bộ nhớ cho nó
     S = (Stack *)malloc(sizeof(Stack));
     Init(S);
     Input(S);
     Output(S);int lua_chon;
    do
    {
     
    printf("Moi ban chon phep toan voi DS LKD:");
    printf("\n1: Kiem tra Stack rong");
    printf("\n2: Do dai Stack");
    printf("\n3: Them phan tu vao Stack");
    printf("\n4: Xoa phan tu trong Stack");
    printf("\n5: Xuat Stack");
    printf("\n6: Thoat");
    
        printf("\nBan chon: ");
        scanf("%d",&lua_chon);
        switch (lua_chon)
        {
        case 1:
            {
                if(Isempty(S))
                    printf("Stack rong!");
                else
                    printf("Stack khong rong !");
                break;
            }
        case 2:
            {
                printf("Do dai Stack :%d",Len(S));
                break;
            }
        case 3:
            {
                item x;
                printf("Nhap phan tu chen vao danh sach: ");
                scanf("%d",&x);
                Push(S,x);
                break;
            }
        case 4:
            {
                Pop(S);
                break;
            }
        case 5:
            {
                Output(S);
                break;
            }
        case 6:
            {
                printf("Thoat\n");
                break;
            }
        }
    }while(lua_chon !=6);
}
