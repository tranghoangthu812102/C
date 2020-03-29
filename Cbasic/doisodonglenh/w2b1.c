#include <stdio.h>
#include <stdlib.h>

int main (int argc , char* argv[])
{
  double dai, rong;
  if(argc != 3)
    {
      printf("khong thoa man!\n");
       printf("Cu phap dung la :  chieu dai chieu rong\n");
      return 1;
    }
  dai = atof(argv[1]);
  rong = atof(argv[2]);
  double dientich,chuvi;
  dientich=dai*rong;
  chuvi=2*(dai+rong);
  printf("\ndien tich hinh chu nhat la : %lf",dientich);
  printf("\nchu vi hinh chu nhat la : %lf\n",chuvi);
}
   
