#include<stdio.h>
void HanoiTower(int n, int i, int j)
    {
        int k;
     
        if(n==1)
            printf("chuyen tu dia %d sang dia %d\n",i,j);
        else
        {
            k = 6-i-j;
            HanoiTower(n-1,i,k);
            HanoiTower(1,i,j);
            HanoiTower(n-1,k,j);
        }
    }
int main()
{
  
  int N,i,j;
	printf("Nhap so luong dia : ");
	scanf("%d",&N);
	HanoiTower(N,i,j);
        


}
