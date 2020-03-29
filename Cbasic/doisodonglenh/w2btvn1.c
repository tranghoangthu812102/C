#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

double tinhe(double x, double n)
{ int m=1;
  double kq = 1, tu = x , mau = m;
  
  while(fabs(tu / mau) >= n)
    {
        kq += (double) tu/mau ;
        m++;
        tu *= x;
        mau*= m;
    }
    return kq;
}
int main(int argc , char* argv[])
{  double x,n;
   if(argc!=3 && argc!=4)
    {
        printf("Cu phap ma ban nhap khong hop le !\n");
        printf("Ban co the nhap <./a.out e  <so mu >  de tinh e^x\n");
	printf("Hoac ban co the nhap <./a.out e <so mu> <sai so > de tinh voi sai so\n");
        return 0;
    }
    char c = *argv[1];
    if(c != 'e' && c!= 'E' )
    {
      printf("Nhap lai tham so theo mau sau:\n");
      printf("./a.out e <so mu> (<sai so>)\n");
      return 2;}
      if(argc == 3)
      {
        x = atof(argv[2]);
        c = 0.00001;
      }
    else
      {
	x = atof(argv[2]);
	n = atof(argv[3]);
	if ( n <= 0 )
	  {
	    printf("Vui long nhap gia tri 'sai so' > 0\n");
	    return 4;
	  }
	if ( n > x)
	  {
	    printf("Vui long nhap gia tri 'sai so' < 'somu'\n");
	    return 5;
	  }
       }
    printf("Gia tri cua e^%lf la : %.9lf\n",x,tinhe(x,n));
}
