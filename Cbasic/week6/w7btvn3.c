#include <stdio.h>


#define N 5
int hau[N];
char cot[N],cheo1[2*N-1],cheo2[2*N-1];
int dem;

void inkq()
{
  int i,j;
  printf("Phuong an %d:\n",++dem);
  for(i=0;i<N;i++)
    {
      for(j=0;j<hau[i];j++)
	printf(" .");
        printf(" x");
      for(j=hau[i]+1;j<N;j++)
	printf(" .");
      printf("\n");
    }
  printf("\n");
}

void TRY(int i)
{
  for(int j=0;j<N;j++)
    if(cot[j] && cheo1[i+j] && cheo2[j-i+N])
      {
	hau[i]=j;
	cot[j] = 0;
	cheo1[i+j] = 0;
	cheo2[j-i+N] = 0;

	if(i== N-1)
	  inkq();
	else TRY(i+1);

	cot[j] = 1;
	cheo1[i+j] =1;
	cheo2[j-i+N] =1;
      }
}

int main()
{
  int i;
  for(i=0 ; i<N ; i++)
    cot[i]=1;
  for(i=0;i<2*N;i++)
    {
      cheo1[i] =1;
      cheo2[i] = 1;
      
    }
  dem =0;
  TRY(0);
  
}
