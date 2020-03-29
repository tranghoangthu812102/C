#include "stack1.h"
#include <string.h>
#include <ctype.h>
#define MAX 100
/*1.Thứ tự ưu tiên */
int uutien(item x)
{
    if(x == '(')
        return 0;
    if(x == '+'|| x == '-')
        return 1;
    if(x == '*' || x == '/' || x == '%')
        return 2;
    return 3;
}

/*10.Chuyển từ trung tố sang hậu tố */
void chuyen(char in[], char post[])
{   Stack S ;                             
    item x, token ;
    int i , j=0; // i- chỉ số của infix , j- chỉ số của postfix
    Init(&S);
    for(i=0;in[i] != '\0';i++)
    {
        token = in[i];
        if(isalnum(token))
	  // isalnum :ký tự đã truyền có phải là ký tự - số hay không.
            post[j++] = token;
        else
            if(token == '(')
               Push(&S,'(');
            else
                if(token == ')')
                  while ((x = Pop(&S) )!= '(')
                         post[j++] = x;
                else
                {
         while (uutien(token)<= uutien(Peak(S)) && !Isempty(&S))
                    {
                        x = Pop(&S);
                        post[j++] = x;
                    }
                    Push(&S,token);
                }
    }
    while (!Isempty(&S))
    {
        x = Pop(&S);
        post[j++] = x;
    }
    post[j] = '\0';
}
int Tinh(char post[])
{
  Stack S;
  char  x;
  int i,op1, op2;
  i=0;
  int val ;
  Init(&S);
   while((x=post[i])!='\0')
    {
      if(isdigit(x))
	Push(&S,x-48);
      else
	{
	  op2=Pop(&S);
	  op1=Pop(&S);
          switch(x)
	    {
	    case '+' :
	      val = (op1+op2);
	      break;
	    case '-':
	      val = (op1-op2);
	      break;
	    case '*':
	      val = (op1*op2);
	      break;
	     case '/':
	      val = (op1/op2);
	      break;
	     case '%':
	      val = (op1%op2);
	      break;
	      
	    }
	  Push(&S,val);
	 }
       i++;
   }
   return val; 
}

int main()
{       
	char A[MAX], B[MAX];
	printf("Infix : ");
	gets(A);
	chuyen(A, B);

	printf("Postfix: %s\n", B);
	printf("Equals is %d\n", Tinh(B));
	gets(A);
	return 0;
}
