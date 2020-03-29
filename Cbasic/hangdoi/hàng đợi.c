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

/*6.Hàng đợi vòng */
//Thêm phần tử vào hàng đợi vòng
void Push_Circular(Queue *Q,item x)
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
int Pop_Circular(Queue *Q)
{
    if(Isempty(Q))
        printf("Hnag doi rong !");
    item x = Q->Data[Q->Front];
    Q->Front = (Q->Front++) %Max ; //tăng vị trí phần đầu lên , nếu đang ở Max-1 thì về 0
    Q->count --; //giảm số phần tử xuống
    return x;//trả về phần tử lấy ra
}

/*Nhập Hàng đợi*/
void Input(Queue *Q)
{
    int n,i;
    item x;
    do
    {
        printf("Nhap so phan tu cua Queue(<%d) : ",Max);
        scanf("%d",&n);
    }while(n>Max || n<1);
    for(i = 0;i<n;i++)
    {
        printf("Nhap phan tu thu %d: ",i+1);
        scanf("%d",&x);
        Push(Q,x);
        //Push_Circular(Q,x);//hàng vòng
    }
}

void Output(Queue *Q)
{   int i;
    if(Isempty(Q))
        printf("Hang doi rong !");
    else
    {
        for(i= Q->Front;i<= Q->Rear;i++)
//for (int i=Q.Front, j=0; j<Q.count; j++, i = (i++) % Max) //hang vong
         printf("%d  ",Q->Data[i]);
         printf("\n");
    }
}

int main()
{
    Queue *Q;
    Q = (Queue *)malloc(sizeof(Queue));
    Init(Q);
    Input(Q);
    Output(Q);

    int lua_chon;
    printf("Moi ban chon phep toan voi DS LKD:");
    printf("\n1: Kiem tra Queue rong");
    printf("\n2: Kiem tra Queue day");
    printf("\n3: Them phan tu vao Queue");
    printf("\n4: Xoa phan tu trong Queue");
    printf("\n5: Xuat Queue");
    printf("\n6: Thoat");
    do
    {
        printf("\nBan chon: ");
        scanf("%d",&lua_chon);
        switch (lua_chon)
        {
            case 1:
            {
                if(Isempty(Q))
                    printf("Queue rong !");
                else
                    printf("Queue khong rong !");
                break;
            }
            case 2:
            {
                  if (Isfull(Q)) printf("Queue day !");
                else printf ("Queue chua day !");
                break;
            }
            case 3:
            {  item x;
                printf ("Nhap phan tu can chen vao Queue: ");
                scanf("%d",&x);
                Push(Q,x);
                //Push_Circular(Q,x); hang vong
                break;
            }
            case 4:
            {
                Pop(Q);
                //Pop_Circular(Q); hang vong
                break;
            }
            case 5:
            {
                Output(Q);
                break;
            }
            case 6: break;
        }
    }while (lua_chon !=6);
    return 0;

}
