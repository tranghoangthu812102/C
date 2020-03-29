#include "queue2.h"

/*2.Khởi tạo*/
void Init(Queue *Q)
{
    Q->Front = Q->Rear = NULL;
    Q->Cur = NUll;
}

/*3.Kiểm tra rỗng */
int Isempty(Queue *Q)
{
    Q->Front=Q->Cur=Q->Rear=NULL;

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
    Q->Cur = P;
}

/*6.Xóa phần tử đầu Queue*/

int DeQueue(Queue *Q)
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
