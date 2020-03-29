/*QUEUE CÀI ĐẶT BẰNG CON TRỎ */
#include <stdio.h>
#include <stdlib.h>

/*1. Xây dựng cấu trúc */
typedef int item ;
typedef struct
{
    item Data;
    struct Node * Next;
    struct Node * prev;
}Node;

typedef struct
{
    Node *Front,*Rear;//Node đầu , node cuối
    int count;
}Queue;

/*2.Khởi tạo*/
void Init(Queue *Q)
{
    Q->Front = Q->Rear = NULL;
    Q->count = NUll;
}

/*3.Kiểm tra rỗng */
int Isempty(Queue *Q)
{
    Q->Front=Q->Count=Q->Rear=NULL;

}

/*4.Tạo 1 Node P*/
Node *MakeNode(item x)
{
    Node *P= (Node *)malloc(sizeof(Node));
    P->Next = NULL;
    p->prev=NULL;
    P->Data =x;
    return P;
}

/*5.Thêm phần tử vào cuối Queue */
//1.Kiểm tra rỗng hay ko
//2.Nếu rỗng cho Front và Rear trỏ về Node P mới chứa x cần thêm
//3.Nếu ko trỏ Rear->Next và Rear trỏ về P
//4.Tăng count lên 1
void EnQueue(Queue *Q, item x)
{
    Node *P = MakeNode(x);
    if(Isempty(Q)) //nếu Q rỗng
      Q->Front = Q->Rear = P;
    else
    {   P->Next = Q->Rear;
        Q->Rear->Next = P;
        Q->Rear = P;
    }
    Q->count = P;
}

/*6.Xóa phần tử đầu Queue*/
//1.Kiểm tra có rỗng ko
//kiểm tra xem có 1 hay nhiều hơn 1 ptu
//nếu có 1 phần tử thì khởi tạo lại Queue
//nếu > 1 ptu cho Front trỏ đến tiếp theo , giảm count xuống 1
int Pop(Queue *Q)
{
    if(Isempty(Q))
    {
        printf("Hang doi rong !");
        return 0;
    }
    else
    {
            item x = Q->Front->Data;
            Q->Front = Q->Front->Next;
            Q->Front->prev = NULL;
            return Q;//trả về phần tử lấy ra
    }
}
int Input(Queue *Q)
{
    int i=0;
    item x;
    do
    {
        i++;
        printf("Nhap phan tu thu %d (nhap 0 de ket thuc) : ",i);
        scanf("%d",&x);
        if(x!=0)
            EnQueue(Q,x);

    }while(x!=0);//Nhap 0 để kết thúc
}

void Output(Queue *Q)
{
    Node *P = Q->Front;
    while (P!=NULL)
    {
        printf("%d ",P->Data);
        P = P->Next;
    }
    printf("\n");
}

int main()
{
    Queue *Q;
    Q=(Queue *)malloc(sizeof(Queue));
    Init(Q);
    Input(Q);
    Output(Q);
    int lua_chon;

    printf("Moi ban chon phep toan voi DS LKD:");
    printf("\n1: Kiem tra Queue rong");
    printf("\n2: Them phan tu vao Queue");
    printf("\n3: Xoa phan tu trong Queue");
    printf("\n4: Xuat Queue");
    printf("\n5: Thoat");
    do
    {
        printf("\nBan chon: ");
        scanf("%d",&lua_chon);
        switch (lua_chon)
        {
            case 1:
            {
                if (Isempty(Q)) printf("Queue rong !");
                else printf ("Queue khong rong !");
                break;
            }
            case 2:
            {
                item x;
                printf ("Nhap phan tu can chen vao Queue: ");
                scanf("%d",&x);
                EnQueue(Q,x);
                break;
            }
            case 3:
            {
                DeQueue(Q);
                break;
            }
            case 4:
            {
                Output(Q);
                break;
            }
            case 5: break;
        }
    }while (lua_chon !=5);
    return 0;
}
