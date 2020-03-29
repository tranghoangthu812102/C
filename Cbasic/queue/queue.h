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

void Init(Queue *Q);
int Isempty(Queue *Q);
int Isfull(Queue *Q);
void Push(Queue *Q,item x);
int Pop(Queue *Q);
item Qfront (Queue *Q);
