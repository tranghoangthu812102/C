/*NGĂN XẾP VỚI MẢNG */
#include <stdio.h>
#include <stdlib.h>

#define Max 100 //so phan tư toi da cua Stack

typedef int item; // kieu du lieu cua Stack
typedef struct
{
    int Top; //Đỉnh top
    item Data[Max]; // Mảng các phần tử
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
/*NHAP PHAN TU VAO*/
void Input (Stack *S)
{
    int n,i;
    item x;
    do
    {
        printf("Nhap so phan tu cua Stack (<%d): ",Max );
        scanf("%d",&n);
    }while(n>Max || n<1);
    for(i=0;i<n;i++)
    {
        printf("Nhap phan tu thu %d: ",i+1);
        scanf("%d",&x);
        Push(S,x);
    }
}

void Output(Stack *S)
{   int i;
    for(i=S->Top-1;i>=0;i--)
        printf("%d ",S->Data[i]);
    printf("\n");
}

int main()
{
    Stack *S;
    S=(Stack *)malloc(sizeof(Stack));
    Init(S);
    Input (S);
    Output(S);

    int lua_chon;
    do
      {
     printf("\n=========MENU============\n");
     printf("1.Kiem tra Stack rong\n"
           "2.Kiem tra Stack day\n"
           "3.Them phan tu vao Stack\n"
           "4.Xoa phan tu trong Stack\n"
           "5.Xuat Stack\n"
           "6.Thoat\n");
      printf("======================");
      printf("\nBan chon: ");
      scanf("%d",&lua_chon);
        switch(lua_chon)
        {
        case 1:
            {
                if(Isempty(S))
                    printf("Stack rong !\n");
                else
                    printf("Stack khong rong!\n");
                break;

            }
        case 2:
            {
                if(Isfull(S))
                    printf("Stack day !\n");
                else
                    printf("Stack chua day!\n");
                break;

            }
        case 3:
            {
                item x;
                printf("Nhap ptu chen vao:");
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
                printf("Ket thuc chuong trinh \n");
                break;
            }
        }
    }while(lua_chon !=6);
}
