#include "dslkd.h"
int n=0;
DB *nhapTuBanPhim(DB *data)
{
  printf("Ten dien thoai: ");
  scanf("%s", data->model);
  printf("Dung luong: ");
  scanf("%s", data->rom);
  printf("Kich co man hinh: ");
  scanf("%s", data->inch);
  printf("Gia tien: ");
  scanf("%s", data->tien);
  return data;
}
Node *makeNode(DB data)
{
  Node *P=(Node *)malloc(sizeof(Node));
  if(P == NULL)
    {
      printf("Can't creat P\n");
      return NULL;
    }
  P->data = data;
  P->next = NULL;
  return P;
}

void insert_first(DB data)
{
  Node *P = makeNode(data);
  if(head == NULL)
    head = tail = P;
  else
    {
      P->next = head;
      head = P;
    }
}
//Chen vao cuoi 
void insert_last(DB data)
{
  Node *P = makeNode(data);
  if(head == NULL)
    head = tail =P;
  else
    {
      tail -> next = P;
      tail = P;
    }
}


int len(Node *k)
{
  Node *p = k;
  int dem=0;
  while(p!=NULL)
    {
      dem++;
      p=p->next;
    }
  free(p);
  return dem;
}

 void insert_Position(int n)
{
  int a= len(head);
  if(a <= 0)
    {
      printf("Danh sach rong !\n");
      return;
    }
    DB *data = (DB*) malloc(sizeof(DB));
    nhapTuBanPhim(data);
    int i = 0;
    Node *prev = NULL;
    for (Node *P = head; P != NULL; P = P->next)
    {
      if (n == 0)
	{
	  insert_first(*data);
	  break;
	}
      else if (n == i)
	{
	  Node *new = makeNode(*data);
	  prev->next = new;
	  new->next = P;
	  break;
	}
      i++; 
      prev = P;
    }

    free(data);
}
  
void del_Node()
{
  Node *P= NULL;
  while(head != NULL)
    {
      P= head;
      head = head -> next;
      free(P);
    }
}
void del_first()
{
  if(head == NULL)
    return;
  Node *P=head;
  head = head->next;
  free(P);
  printf("Xoa thanh cong\n ");
}

void del_last()
{
  if(head == NULL)
    return;
  else if(head == tail)
	del_first();
  else
    for(Node *P = head;P!=NULL; P= P->next)
    {
      if(P->next == tail)
	{
	  free(tail);
	  P->next = NULL;
	  tail = P;
	}
    }
  printf("Xoa thanh cong\n ");
}
void del_Position(int n)
{  
int a=len(head);
   if(a <= 0)
    {
      printf("Danh sach rong !\n");
      return;
    }
  int i=0;
  Node *prev = NULL;
  for (Node *P = head; P != NULL; P = P->next)
    {
      if (n == 0)
	{
	  del_first();
	  return;
	}
      else if (n == a-1)
	{
	  del_last();
	  return;
	}
      else if(n == i)
	{
	  prev->next = P->next;
	  free(P);
	  return;
	}
     prev = P;
     i++;
    }
}
void daoNguocDS()
{
  Node *P = NULL;
  Node *newHead = NULL;
Node *newtail = NULL;

  while(head != NULL)
    {
      P = head;
      head = head->next;

      if (newHead == NULL)
	{
	  P->next = NULL;
	  newHead = newtail = P;
	}
      else
	{
	  P->next = newHead;
	  newHead = P;
	}
    }

  head = newHead;
  tail  = newtail;
}

int searchMoveToFront(DB data)
{
  // TIM THEO TRUONG model
int i=0;
 for (Node *P = head; P != NULL; P= P->next)
    {
      if (strcmp(P->data.model,data.model) == 0)
	{
	  DB new;
	  new = P->data;
del_Position(i);
	  insert_first(new);
	  return 1;
	}
i++;
    }
  return 0;
}

int searchTranspose(DB data)
{
   Node *P = head;
int i=0;
  for (Node *P = head; P != NULL; P = P->next)
    {
      if (strcmp(P->data.model,data.model) == 0)
	{
	DB new=P->data;	  
	if(P==head) return 1;
	else if(P==tail) 
	{
	del_last();
	insert_Position(i-1);
	}
	else 
	{
	del_Position(i);
	insert_Position(i-1);
	}
return 1;
}

      i++;
    }
    return 0;
}

