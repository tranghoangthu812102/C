/*HÀNG ĐỢI VỚI MẢNG */
#include <stdio.h>
#include <stdlib.h>

#define Max 5 // số phần tử tối đa của Queue
typedef int item ; // kiểu dữ liệu

typedef struct
{
    int Front, Rear ;
    // Front : phần tử đầu hàng , rear : phần tử cuối
    item Data[Max];
    int count;//đếm số phần tử của Queue
}Queue;

#include "queue.h"

/*1.Khởi tạo Queue rỗng */
void Init(Queue *Q)
{
    Q->Front = 0 ;//Phần tử đầu
    Q->Rear = -1 ;//phần tử cuối (ko có ptu trg Ư)
    Q->count = 0;
}
/*2.Kiểm tra Queue rỗng , đầy*/
int Isempty(Queue *Q)
{
    if(Q->count == 0)
        return 1;
        return 0;
}

int Isfull(Queue *Q)
{
    if(Q->count == Max)
        return 1;
        return 0;
}

/*3.Them phần tử vào cuối Queue{Push)*/
//tăng vị trí Rear lên 1 và đưa data vào vị trí đó
void Push(Queue *Q,item x)
{
    if(Isfull(Q))
        printf("Hang doi day!");
    else
    {
        Q->Data[++Q->Rear]=x;//tăng Rear lên và gán x vào
        Q->count++;//tăng số phần tử lên

    }
}

/*4.Xóa phần tử đầu Queue(Pop)*/
//1.Kiểm tra Queue rỗng ko
//2.nếu ko rỗng , di chuyển các phần tử trong hàng về đầu hàng bằng vòng forr
//3.giảm Rear và Count xuống

int Pop(Queue *Q)
{
    if(Isempty(Q))
        printf("Hang doi rong!");
    else
    {   int i;
        item x ;
        x= Q->Data[Q->Front];
        for(i= Q->Front;i<Q->Rear;i++)//di chuyển các phần tử về đầu hàng
          Q->Data[i] = Q->Data[i+1];
        Q->Rear--;// giảm vị trí phần tử cuối xuống
        Q->count--;//giảm số phần tử xuống
        return x;//trả về phần tử lấy ra
    }
}

/*5.Xem thông tin phần tử đầu Queue*/
item Qfront (Queue *Q)
{
    if(Isempty(Q))
        printf("Hang doi rong !");
    else
        return Q->Data[Q->Front];
}
