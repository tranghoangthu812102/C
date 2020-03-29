#include "double.h"
#define MAX 100
void Empty(LIST *l)
{
	l->Head=l->Cur=l->Tail=NULL;
}
void DisplayNODE(DT s)
{
  printf("%-15s%-10s%-10s%s\n",s.Model,s.Mem,s.Sign,s.Gia);
}
void FiletoLISTAddTail(LIST *l,FILE *f)
{
	DT *a=(DT *)malloc(sizeof(DT));
	while(!feof(f))
	{
		int n=fread(a,sizeof(DT),1,f);
		if(n==1) AddTail(l,*a);
	}
	printf("Complete\n");
	free(a);
}
void DisplayLIST(LIST *l)
{
	NODE *p=l->Head;
	int i=0;
	printf("-------------DANH SACH------------\n");
  	printf("%-5s%-15s%-10s%-10s%-10s\n","STT","Model","Memory","Sign","Gia");
	while(p!=NULL)		
	{
		printf("%-5d",i++);
		DisplayNODE(p->x);
		p=p->next;
	}
	free(p);
}
void LISTtoDAT(LIST *l,FILE *f)
{
	NODE *p=l->Head;
	while(p!=NULL)		
	{
		fwrite(&(p->x),sizeof(DT),1,f);
		p=p->next;
	}
	printf("Complete\n");
	free(p);
}
void AddNODE(LIST *l,DT p)
{
	printf("Moi ban chon che do \n");
	printf("1. AddBefor\n");
	printf("2. AddAfter\n");
	printf("Ban chon: ");
	int N;
	scanf("%d%*c",&N);
	switch(N)
	{
		case 1:			
			AddBefor(l,p);
			break;
		case 2:				
			AddAfter(l,p);
			break;
	}
}
void Find_Update(LIST *l,char s[])
{
    int e,dem=0;
    DT x;
    do
    {
        printf("Moi ban chon che do: \n");
        printf("1. MoveToFront\n");
        printf("2. Transpose\n");
        strcpy(x.Model,s);
        printf("Ban chon: ");
        scanf("%d%*c",&e);
        switch(e)
        {
            case 1:
                dem=MoveToFront(l,x);
                break;
            case 2:
                dem=Transpose(l,x);
                break;
        }
    }while(!(e==1 || e== 2));
    if(dem==1)
    {
        printf("Thong tin san pham: \n");
        DisplayNODE(l->Cur->x);
        printf("Ban muon Update: ");
        printf("\n1.Yes\nPhim khac.No\n");
        printf("Ban chon: ");
        int a;
        scanf("%d%*c",&a);
        if(a==1)
        {
            printf("Update: \n");
            DT a;
            printf("Ten Model: ");
            gets(a.Model);
            printf("Memory: ");
            gets(a.Mem);
            printf("Sign: ");
            gets(a.Sign);
            printf("Gia : ");
            gets(a.Gia);
            l->Cur->x=a;
        }
    }
}
void Split(LIST *l,FILE *f,FILE *f1)
{
	printf("Nhap so phan tu chia: ");
	int n;
	scanf("%d%*c",&n);
	NODE *p=l->Head;
	LIST *l1=(LIST *)malloc(sizeof(LIST));
	LIST *l2=(LIST *)malloc(sizeof(LIST));
	for(int i=0;i<n;i++)
	{
		AddTail(l1,p->x);
		p=p->next;
		if(p==NULL) break;
	}
	while(p!=NULL)
	{
		AddTail(l2,p->x);
		p=p->next;
	}
	LISTtoDAT(l1,f);
	LISTtoDAT(l2,f1);
	printf("File 1: \n");
	DisplayLIST(l1);
	printf("File 2: \n");
	DisplayLIST(l2);
	free(p);
	Free(l1);
	Free(l2);
}
int main()
{
	LIST *l=(LIST *)malloc(sizeof(LIST));
	Empty(l);
	int a,n;
	DT p;
	FILE *f=fopen("NokiaDB.dat","rb");
	FILE *f1=fopen("NokiaDB.txt","r");
	FILE *f2=fopen("NODE.dat","wb");
	FILE *f3=fopen("phone1.dat","wb");
	FILE *f4=fopen("phone2.dat","wb");
	if(!f||!f1)
	{
		printf("Khong tim thay file du lieu\n");
		return 0;
	}
	do{
	printf("------------------MENU----------------\n");
	printf("1. Import form DAT\n");
	printf("2. Display LIST\n");
	printf("3. Add new phone\n");
	printf("4. Insert at Position\n");
	printf("5. Delete at Position\n");
	printf("6. Delete Cur\n");
	printf("7. Delete First\n");
	printf("8. Search and Update\n");
    printf("9. Divide and Extract\n");
	printf("10. Reverse LIST\n");
	printf("11. Save to FILE\n");
    printf("12. Quit\n");
	printf("Moi ban chon: ");
	scanf("%d%*c",&a);
	switch(a)
	{
		case 1:
			Empty(l);
			rewind(f);
			Free(l);
			FiletoLISTAddTail(l,f);
			break;
		case 2:
			DisplayLIST(l);
			break;
		case 3:
			printf("Moi ban nhap TT\n");
			printf("Ten Model: ");
			gets(p.Model);
			printf("Memory: ");
			gets(p.Mem);
			printf("Sign: ");
			gets(p.Sign);
			printf("Gia : ");
			gets(p.Gia);
			AddNODE(l,p);
			break;
		case 4:
			printf("Moi ban nhap TT\n");
			printf("Ten Model: ");
			gets(p.Model);
			printf("Memory: ");
			gets(p.Mem);
			printf("Sign: ");
			gets(p.Sign);
			printf("Gia : ");
			gets(p.Gia);
			printf("Nhap vi tri can Insert: ");
			scanf("%d%*c",&n);
			InsertPos(l,p,n);
			break;
		case 5:
			printf("Nhap vi tri can delete: ");
			scanf("%d%*c",&n);
			DeletePos(l,n);
			break;
        case 6:
			DeleteCur(l);
			break;
        case 7:
			DeleteHeal(l);
			break;
		case 8:
			printf("Nhap ten Model: ");
            char s[30];
            gets(s);
            Find_Update(l,s);
			break;
		case 9:
			Split(l,f3,f4);
			break;
        case 10:
			l=SeverseLIST(l);
			break;
		case 11:
			LISTtoDAT(l,f2);
			break;
        case 12:
            Free(l);
            break;
	}}while(a!=12);
	fclose(f);
	fclose(f1);
	fclose(f2);
	fclose(f3);
	fclose(f4);
	return 0;
}
