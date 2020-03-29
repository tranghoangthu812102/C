#include "queue2.h"

/*2.Khởi tạo*/
void Init(Queue *Q)
{
    Q->Front = Q->Rear = NULL;
}

/*3.Kiểm tra rỗng */
int Isempty(Queue *Q)
{
    return Q->Front==NULL;
}

/*4.Tạo 1 Node P*/
Node *MakeNode(elem x)
{
    Node *P= (Node *)malloc(sizeof(Node));
    P->Next = NULL;
    P->prev=NULL;
    P->Data =x;
    return P;
}

/*5.Thêm phần tử vào cuối Queue */

void EnQueue(Queue *Q,elem x)
{
    Node *P = MakeNode(x);
    if(Isempty(Q)) //nếu Q rỗng
      Q->Front = Q->Rear = P;
    else
    {   
	P->prev = Q->Rear;
        Q->Rear->Next = P;
        Q->Rear = P;
    }
}
void Free(Queue *Q)
{
	Node *P=Q->Front;
	while(P!=NULL)
	{
		Q->Front=Q->Front->Next;
		free(P);
		P=Q->Front;
	}
	free(P);
}

/*6.Xóa phần tử đầu Queue*/

elem DeQueue(Queue *Q)
{
	Node *p=Q->Front;
	elem a=p->Data;
	if (!Isempty(Q)){
	if(Q->Front->Next==NULL) Q->Front=Q->Rear=NULL;
	else
	{
		Q->Front=Q->Front->Next;
		Q->Front->prev=NULL;
	}
	free(p);
	return a;
        }
}
