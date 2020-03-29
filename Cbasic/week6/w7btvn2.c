#include <stdio.h>
#include <string.h>
#include <ctype.h>

int dem = 0;
char inhoa(char *str)
{
  static int i=0;
  if(i<strlen(str))
    {
      if(isupper(str[i]))
	{
	  return str[i]; 
        }
	else
	  {
	    i = i + 1;
	    return inhoa(str);
	  }
    }
      return 0;
}
int vitri(char str[], int dai)
{
  if (dem == dai)
    return dem;

  if ('A' <= str[dem] && str[dem] <= 'Z')
    return dem;
  dem++;
  
  return vitri(str, dai);
}

int main()
{
  char str[50];
  printf("Nhap xau: ");
  gets(str);
  int dodai = strlen(str);
  int m = vitri(str,dodai);
  char chu = inhoa(str);

  if (m  == dodai)
    printf("Khong co chu in hoa xuat hien!\n");
  else
    printf("Chu in hoa dau tien trong '%s' la :%c\n",str,chu);
    printf("Vi tri chu in hoa dau tien la: %d\n", m);

  return 0;
}
