#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree2search.h"
#include "fileSet.h"

int kiemTraDangNhap(elType *dangNhap, node *root)
{
  node *check = searchTree(root, *dangNhap);
  if (check == NULL)
    return 0;
  else
      if (strcmp(check->data.pass, dangNhap->pass) != 0)
	return 0;

  *dangNhap = check->data;
  return 1; 
}

int checkAdmin(char name[20])
{
  if (strcmp(name, "Admin") == 0)
    return 1;
  return 0;
}

void display_LNR(node *root)
{
  if (root == NULL)
    return;
  else
    {
      display_LNR(root->left);
      if (checkAdmin(root->data.name) == 0)
	printf("%s\t %s\t %d\n", root->data.name, root->data.pass, root->data.diem);
      display_LNR(root->right);
    }
}

elType nhapThongTin(elType data, node *root)
{
 LAPTEN:
  printf("Nhap ten: ");
  scanf("%s", data.name);
  node *check_name = searchTree(root, data);
  
  if (check_name != NULL)
    {
      printf("Ten bi lap! Nhap lai!\n");
      goto LAPTEN;
    }
  printf("Nhap pass: ");
  scanf("%s", data.pass);
  printf("Nhap diem: ");
  scanf("%d", &data.diem);
  return data;
}

void quanTriVien(node *root)
{
  int luachon;
  do
    {
      printf("\n***CHE DO QUAN TRI***\n"
	     "1. Them sinh vien\n"
	     "2. In danh sach\n"
	     "3. Xoa sinh vien\n"
	     "4. Luu File va thoat\n"
	     "---> Lua chon: ");
      scanf("%d", &luachon);
      switch(luachon)
	{
	case 1:
	  {
	    elType data;
	    data = nhapThongTin(data, root);
	    insertTree(&root, data);
	  }
	  break;
	case 2:
	  display_LNR(root);
	  break;
	case 3:
	  {
	    elType xoa_name;
	    printf("Nhap ten can xoa: ");
	    scanf("%s", xoa_name.name);
	    if (checkAdmin(xoa_name.name) == 0)
	      {
		node *xoa = searchTree(root, xoa_name);
		printf("\n%s\t %s\t %d\n", xoa->data.name,
		       xoa->data.pass, xoa->data.diem);
		root = removeNodeTree(root, xoa_name);
	      }
	    else
	      printf("Khong duoc phep xoa Admin!\n");
	  }
	  break;
	case 4:
	  saveFile(root);
	  break;
	}
    } while (luachon != 4);
}

void thanhVien(elType dangNhap, node *root)
{
  int luachon;
  do
    {
      printf("\n1. Xem diem\n"
	     "2. Doi mat khau\n"
	     "3. Ghi lai thong tin va thoat!\n"
	     "---> Chon: ");
      scanf("%d", &luachon);

      switch(luachon)
	{
	case 1:
	  printf("Diem: %d", dangNhap.diem);
	  break;
	case 2:
	  {
	    char mk1[20], mk2[20];
	    printf("Nhap mat khau moi: ");
	    scanf("%s", mk1);
	    printf("Nhap lai mat khau: ");
	    scanf("%s", mk2);
	    if (strcmp(mk1, mk2) != 0)
	      printf("Nhap sai!\n");
	    else
	      strcpy(dangNhap.pass, mk1);
	  }
	  break;
	case 3:
	  {
	    node *search = searchTree(root, dangNhap);
	    strcpy(search->data.pass, dangNhap.pass);
	    saveFile(root);
	  }
	  break;
	default:
	  printf("Nhap lai!\n");
	}
      
    } while (luachon != 3);
}
  
int main()
{
  node *root = NULL;
  inputDataFromTxt(&root);
  // display_LNR(root);

  int luachon;

  elType dangNhap;
  
  do
    {
      printf("\n--------------\n"
	     "1. Dang Nhap\n"
	     "2. Thoat\n"
	     "---> Chon: ");
      scanf("%d", &luachon);
      int demdangnhap = 0;
      switch(luachon)
	{
	case 1:
	BACK:
	  printf("Nhap tai khoan: ");
	  scanf("%s", dangNhap.name);
	  printf("Nhap mat khau: ");
	  scanf("%s", dangNhap.pass);
	  int check = kiemTraDangNhap(&dangNhap, root);
	  if (check == 1)
	    {
	      if (checkAdmin(dangNhap.name) == 1)
		quanTriVien(root);
	      else
		thanhVien(dangNhap, root);
	      demdangnhap = 0;
	    }
	  else
	    {
	      demdangnhap++;
	      if (demdangnhap > 2)
		exit(0);
	      printf("\nDang nhap lai!\n");
	      goto BACK;
	    }
	  break;
	case 2:
	  break;
	default:
	  printf("\nNhap lai!\n");
	}
      
    } while (luachon != 2);

  deleteTree(root);
  return 0;
}
