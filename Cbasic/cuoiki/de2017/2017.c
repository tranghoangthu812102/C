#include "single.h"
int N;
void DNODE(DT x)
{
  printf("%-5d%-30s%-10d%-10d%d\n",x.id,x.ten,x.diem,x.thang,x.thua);
}
void DLIST(LIST *l)
{
  NODE *P= l->Head;
  printf("%-5s%-30s%-10s%-10s%s\n",
	 "id","Tendoibong","Diem","Sobanthang","Sobanthua");
  while(P!=NULL)
    {
      DNODE(P->x);
      P=P->next;
    }
  free(P);
}
void doibong(LIST *l,FILE*file)
{
  fscanf(file,"%d%*c",&N);
  for(int i=0;i<N;i++)
    {
      DT x;
      fscanf(file,"%d%*c",&x.id);
      fgets(x.ten,31,file);
      char  *ch = (char *) malloc(sizeof(char));
      ch = strtok(x.ten,"\n");
      strcpy(x.ten,ch);
      x.diem = x.thang = x.thua = 0;
      AddHead(l,x);
    }
  DLIST(l);
}
void Lichthidau(LIST *l,FILE *file)
{
  char a[15];
  DT x;
   
  for( int i=0; i< N-1; i++)
    {
      fgets(a,15,file);
      printf("%s",a);
      for(int j = 0 ; j < N/2 ; j++)
	{ int b;
	 
	  fscanf(file,"%d%*c",&b);
	    for(NODE  *P = l -> Head ; P!= NULL; P= P->next)
              {
                if(b == P->x.id)
	        {
	           printf("%s -  ",P->x.ten);
	           break;
	        }
	      }
	          fscanf(file,"%d%*c",&b);
	    for(NODE  *P = l -> Head ; P!= NULL; P= P->next)
             {
                 if(b == P->x.id)
              	{
	          printf("%s\n ",P->x.ten);
	          break;
	        }
	    }
        }
   }
}
void ketqua(LIST *l,FILE *file)
{
   for(int i=0 ; i< N-1 ; i++)
    {
       NODE *P;
       NODE *Q ;
      printf("CAP NHAT KET QUA VONG DAU\n");
      char a[30];
      fgets(a,31,file);
      printf("%s",a);
    
      for(int j = 0 ; j < N/2 ; j++)
	{   int b,c;
	    fscanf(file,"%d%*c",&b);
	    for(P = l -> Head ; P!= NULL; P= P->next)
              {
                if(b == P->x.id)
	        {
	           printf("%s -  ",P->x.ten);
	           break;
	        }
	      }
	     fscanf(file,"%d%*c",&c);
	    for(Q = l -> Head ; Q!= NULL; Q= Q->next)
             {
                 if(c == Q->x.id)
              	{
	          printf("%s\n ",Q->x.ten);
	          break;
	        }
	     }
	    int m,n;
	    scanf("%d%*c%d%*c",&m,&n);
	    P->x.thang += m;
            Q->x.thang += n;
	    P->x.thua += n;
	    Q->x.thua += m;
	    if(m>n)
	      {
		P->x.diem += 3;
		Q->x.diem += 0;
	      }
	   else if(m==n)
	      {
	        P->x.diem += 1;
		Q->x.diem += 1;
	      }
	    else
	      {
	        P->x.diem += 0;
		Q->x.diem += 3;
	      }
	    }
    
      DLIST(l);}
}
void Thongke(LIST *l)
{
  printf("Doi co diem thap nhat la : \n");
  NODE *P = l->Head;
  int min = 3*N;
  while(P!=NULL)
    {
      if(P->x.diem < min)
	min = P->x.diem;
      else
	P=P->next;
    }
  l->Cur = l->Head;
  printf("%-5s%-30s%-10s%-10s%s\n",
	 "id","Tendoibong","Diem","Sobanthang","Sobanthua");
  while(l->Cur !=NULL)
    {
      if(l->Cur ->x.diem == min)
	{
	  DNODE(l->Cur->x);
	  DeleteCur(l);
        }
      else l->Cur = l->Cur->next;}
      printf("Cac doi co diem cao nhat la:\n");
      DLIST(l);

}

int main()
{
  FILE *file;
  char filename[30];
  int lua_chon,vt;
  LIST  *l;
  l = (LIST *)malloc(sizeof(LIST));
  Empty(l);
  printf("Nhap file can thao tac :");
  scanf("%s",filename);
  if((file = fopen(filename,"r"))==NULL)
    {
     printf("Khong the mo file %s\n",filename);
     exit(0);
    }
  do
    {
  printf("\n~~~~~~~~~~~~~MENU~~~~~~~~~~~\n");
  printf("1.In thong tin cac doi bong\n"
	 "2.In thong tin lich thi dau\n"
	 "3.Cap nhat ket qua vong dau\n"
	 "4.Thong ke\n"
	 "5.Thoat\n");
  printf("Ban chon : ");
  scanf("%d",&lua_chon);
      switch(lua_chon)
	{
	case 1:
	  doibong(l,file);
	  break;
	case 2:
	  vt = ftell(file);
	  Lichthidau(l,file);
	  fseek(file,vt,SEEK_SET);
	  break;
	case 3 :
	  ketqua(l,file);
	  break;
	case 4:
	  Thongke(l);
	  break;
	case 5:
	  printf("KET THUC CHUONG TRINH \n");
	  break;
	}
    }while(lua_chon!=5);
  fclose(file);
  Free(l);
}
