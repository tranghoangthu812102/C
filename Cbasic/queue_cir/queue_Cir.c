#include "queue_Cir"
#define Max 5 // số phần tử tối đa của Queue
typedef int item ; // kiểu dữ liệu

typedef struct
{
    int Front, Rear ;
    // Front : phần tử đầu hàng , rear : phần tử cuối
    item Data[Max];
    int count;//đếm số phần tử của Queue
}Queue;

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
/*5.Xem thông tin phần tử đầu Queue*/
item Qfront (Queue *Q)
{
    if(Isempty(Q))
        printf("Hang doi rong !");
    else
        return Q->Data[Q->Front];
}

/*6.Hàng đợi vòng */
//Thêm phần tử vào hàng đợi vòng
void EnQueue_Circular(Queue *Q,item x)
{
    if(Isfull(Q))
        printf("Hang doi day !");
    else
    {
        Q->Data[(++Q->Rear) %Max] = x;
        //tăng Rear lên và gán phần tử vào,Nếu Rear đang ở vị trí Max-1 thì tăng về vị trí 0
        Q->count++;
        // tăng số phần tử lên
    }
}
//Loại bỏ phần tử đầu hàng đợi vòng
int DeQueue_Circular(Queue *Q)
{
    if(Isempty(Q))
        printf("Hnag doi rong !");
    item x = Q->Data[Q->Front];
    Q->Front = (Q->Front++) %Max ; //tăng vị trí phần đầu lên , nếu đang ở Max-1 thì về 0
    Q->count --; //giảm số phần tử xuống
    return x;//trả về phần tử lấy ra
}


