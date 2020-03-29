#include <stdio.h>
#include <string.h>

void kiemtra ( char so[], int i)
{
  int len = strlen(so) - (i+1);
  if (so[i]==so[len])
   {
    if (i+1 == len || i == len)
       {
         printf("day so ban vua nhap doi xung nhau \n");
         return;
        }

        kiemtra(so, i+ 1);
   }
   else
    {
      printf("Day so ban vua nhap khong doi xung\n");
    }

}
int main()
{
  char so[10];
  printf("Nhap day so ban muon :");
  scanf("%s",so);
  kiemtra(so,0);
}
