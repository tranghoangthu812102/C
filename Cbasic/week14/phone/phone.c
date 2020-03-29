#include "BST.h"

void inPut_Dat(Node **T)
{ 
  FILE *file;
  if((file = fopen("phoneDB.dat","rb")) == NULL)
    {
      printf("Khong the mo file %s\n","PhoneDB.dat");
      exit(0);
    }
  elmType *data = (elmType *)malloc(sizeof(elmType));
  while(1)
    {
      fread(data,sizeof(elmType),1,file);
      if(feof(file))
	break;
      insertNode(T,*data);
     }
  free(data);
  fclose(file);
}
int main()
{
     Node *T;
     Init(&T);
     int lua_chon;
     elmType  x;
     char name[30];
     elmType *data=(elmType*) malloc(sizeof(elmType));
	 
     do
       {
	 printf("\n=============================");
	 printf("\n~~~~~~~~~~~~MENU~~~~~~~~~~~~~");
	 printf("\n1.Import from NokiaDB.dat\n"
		"2.Them\n"
		"3.Xoa\n"
		"4.Cap nhat\n"
		"5.Tim kiem\n"
		"6.Hien thi danh sach\n"
		"0.Thoat\n");
	 printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	 printf("Ban chon: ");
	 scanf("%d",&lua_chon);
	 switch(lua_chon)
	   {
	   case 1:
	     freeTree(T);
	     inPut_Dat(&T);
	     printf("Thanh cong!\n");
	     break;
	   case 2:
	     printf("Nhap du lieu can them\n");
	     nhapTuBanPhim(data);
	     insertNode(&T,*data);
	     break;
	   case 3:
	     printf("Nhap model can xoa: ");
	     scanf("%s",data->model);
	     Del_Node(T,*data);
	     break;
	   case 4:
	     break;
	   case 5:
	     printf("Nhap model can tim kiem " );
	     scanf("%s",data->model);
	     Node *P=Search(T,*data);
             if(P == NULL)
	       printf(" %s khong ton tai\n",data->model);
	     else
                printf("%-15s %-15s %-15s %s\n",
	    "Model","dungluongbonho","kichthuocmanhinh","giatien");
	       printf("%-15s %-15s %-15s %s\n",
	      P->data.model,P->data.rom,P->data.inch,P->data.tien);
	     break;
	   case 6:
             printf("%-15s %-15s %-15s %s\n",
	    "Model","dungluongbonho","kichthuocmanhinh","giatien");
	     NLR(T);
	     break;
	   case 0:
	     printf("Ket thuc chuong trinh!\n");
	     break;
	    }
       }while(lua_chon !=0);
     freeTree(T);
}
