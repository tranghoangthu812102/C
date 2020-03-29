#include <stdio.h>
#include <stdlib.h>

#define Max 100 //so phan tư toi da cua Stack

typedef int item; // kieu du lieu cua Stack
typedef struct
{
    int Top; //Đỉnh top
    item Data[Max]; // Mảng các phần tử
}Stack;
void Init(Stack *S);
int Isempty(Stack *S);
int Isfull(Stack *S);
void Push(Stack *S , item x);
int Peak(Stack S);
int Pop(Stack *S);
