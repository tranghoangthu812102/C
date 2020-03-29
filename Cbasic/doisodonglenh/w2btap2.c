#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main(int argc , char* argv[])
{
    double a,b,c;
    double denta;
    char str[] = "sde";
    if(argc!=5)
    {
        printf("Ban da nhap sai cu phap!\n");
        printf("Cu phap dung la ./a.out sde a b c\n");
        return 1;
    }
    for (int i = 0; i < strlen(argv[1]); i++)
    {
      argv[1][i] = tolower(argv[1][i]);
    }
  
  if (strcmp(str, argv[1]) != 0)
    {
      printf("Nhap sai tham so dieu khien! Tham so dung la: sde\n"
	     "Vi du: ./bai2 sde 1 2 1\n");
      return 2;
    }
  
    a = atof(argv[2]);
    b = atof(argv[3]);
    c = atof(argv[4]);
    denta=b*b-4*a*c;
    
    if(denta<0)
        printf("Phuong trinh vo nghiem !");
    else if ( denta == 0)
        printf("phuong trinh co nghiem kep x1=x2=%f\n",-b/(2*a));
    else if (denta > 0)
    {
        printf("Phuong trinh co hai nghiem phan biet :\n");
        printf("Nghiem thu nhat la x1=%f\n",(-b+sqrt(denta))/(2*a));
        printf("Nghiem thu hai la x2=%f\n",(-b-sqrt(denta))/(2*a));
    }

}
