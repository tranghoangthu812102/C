#include <stdio.h>
int dem=0;
void Chuyen(int N,char A, char B)
{
	printf("Chuyen dia thu %d tu coc %c sang coc %c \n",N,A,B);
	
}
void Hanoi(int N, char A, char B, char C)
{
	if(N==1) Chuyen(N,A,C);
	else
	{
		Hanoi(N-1,A,C,B);
		Chuyen(N,A,C);
		Hanoi(N-1,B,A,C);
	}
}
int main()
{
	int N;
	printf("Nhap so luong dia : ");
	scanf("%d",&N);
	Hanoi(N,'A','B','C');

}
