#include "queue2.h"
#define MAX 1000

void makePro(elem *Data)
{
  printf("ID : ");
  gets(Data->ID);
  printf("Memory : ");
  scanf("%d",&Data->Memory);
}

void DisplayNode(elem Data)
{
  printf("%-20s%d\n",Data.ID,Data.Memory);
}

void DisplayQueue(Queue *Q)
{
  Node *P = Q->Front;
  while(P!= NULL)
    {
      DisplayNode(P->Data);
      P = P->Next;
    }
 }

void PushRun( Queue *Q,Queue *Q2,elem  b)
{
	EnQueue(Q2,b);
	if(Q2->Front->Data.Memory <= Q->Sum)
	{
		elem a=DeQueue(Q2);
		EnQueue(Q,a);
		Q->Sum=Q->Sum-a.Memory;
	}
}

void Kill(Queue *Q, Queue *Q2)
{
	if(!Isempty(Q))
	{
		elem x= DeQueue(Q);
		Q->Sum=Q->Sum+x.Memory;
		if(!Isempty(Q2))
		while(Q->Sum>=Q2->Front->Data.Memory)
		{
			elem a=DeQueue(Q2);
			EnQueue(Q,a);
			Q->Sum=Q->Sum-a.Memory;
			if(Isempty(Q2)) break;
		}
	}
	else if (!Isempty(Q2)) 
	{
		while(Q->Sum>=Q2->Front->Data.Memory)
		{
			elem a=DeQueue(Q2);
			EnQueue(Q,a);
			Q->Sum=Q->Sum-a.Memory;
			if(Isempty(Q2)) break;
		}
	}
	else printf("Het chuong trinh dang chay va cho\n");
}

void Empty(Queue *Q,int Data)
{
  Q->Front = Q->Rear = NULL;
  Q->Sum = Data;
}

int main()
{
        Queue *Q=(Queue *)malloc(sizeof(Queue));
	Queue *Q2=(Queue *)malloc(sizeof(Queue));
	Init(Q);
	Init(Q2);
	     
	Empty(Q,MAX);
	int lua_chon;
	elem Data;
	Empty(Q2,0);
	do
	 {      printf("============================\n");	
	        printf("~~~~~~~~~~~MENU~~~~~~~~~~\n");
		printf("1. Creat program\n");
		printf("2. Kill program\n");
		printf("3. Display\n");
		printf("0. Exit\n");
		printf("Ban chon: ");
		scanf("%d%*c",&lua_chon);
		switch(lua_chon)
		{
			case 1:
				makePro(&Data);
				PushRun(Q,Q2,Data);
				break;
			case 2:
			  Kill(Q,Q2);
				break;
			case 3:
				printf("Running: \n");
				printf("%-20s%s\n","ID","Memory");
				DisplayQueue(Q);
				printf("Waiting: \n");
				printf("%-20s%s\n","ID","Memory");
				DisplayQueue(Q2);
				break;
		}		
	}while(lua_chon!=0);
	Free(Q);
	Free(Q2);
	return 0;

}
