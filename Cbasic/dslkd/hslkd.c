#include "dslkd.h"
 int n=0 ;//so luong phan tu trong danh sach
Node *makeNode(item data)
{
  Node *P=(Node *)malloc(sizeof(Node));// tao vung nho cho node P
  if(P == NULL)
    {
      printf("Can't creat P\n");
      return NULL;
    }
  P->data = data; // truyen x vao data
  P->next = NULL;// dau tien khai bao thi node do chua lien ket den node nao het => con tro cua no tro den NULL
  return P;
}

void insert_first(item  data)
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
void insert_last(item data)
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
//Them node P vao sau node Q(nam trong danh sach lien ket don)
/* luc chay nhap gia tri node P thi sau khi nhap xong phai co lenh Node *P = makeNode(data);(ow ham main)*/
void insertP_sauQ(Node * P ,item data)
{
   printf("Nhap gia tri cua node Q: ");
   scanf("%d",&data);
   Node *Q = makeNode(data);
   // neu ds co 1 phan tu va no cung chinh la node Q-> THEM VAO CUOI
   if(Q->data == head->data && head -> next == NULL)
     {
            insert_last(data);
     }
    else 
     { 
        //duyet tu dau danh sach den cuoi danh sach de tim Q 
       for(Node *k = head ; k != NULL ; k = k->next)
       
      {      // neu Q ton tai thi ...
       if(Q->data == k->data)
         {  
            Node *H = makeNode(P->Data); // khoi tao node H de them vao sau node Q
            Node *G = k->next;
            H->next = G;// tao moi lien ket tu H den G (node nam sau node Q)
            k->next = H;//tao moi lien ket tu Q den H(chinh la node k den node H)
         }
       }
     } 
}

//Them node P vao truoc node Q trong danh sach
void insertP_truocQ(Node *P ,item data)
{ 
/* luc chay nhap gia tri node P thi sau khi nhap xong phai co lenh Node *P = makeNode(data);(ow ham main)*/
   printf("Nhap gia tri cua node Q: ");
   scanf("%d",&data);
   Node *Q = makeNode(data);
   //neu danh sach ton tai duy nhat node Q -> THEM VAO DAU
    if(Q->data == head->data && head -> next == NULL)
     {
            insert_first(data);
     }
    else 
     {       
       /*~~~~~~~~~~~~~~~cach 1 : trong ds co 1 node Q~~~~~~~~~~~~~~~~~~~~~~~~~~
       Node *G = (Node*)malloc(sizeof(Node));// node giu lien ket voi cai node nam truoc node Q trong ds
           //duyet tu dau danh sach den cuoi danh sach de tim Q 
       for(Node *k = head ; k != NULL ; k = k->next)
       
         {      // neu Q ton tai thi ...
              if(Q->data == k->data)
                {
                   //them node P vao sau node G <=> them node P vao truoc node Q
                   P->next = k;//b1 : cho node Q tro den node K <=> cung chinh la cho P tro den node Q
                   G->next = P;//b2 : cho node G tro den node P
                }
             G =k;//giu lien ket voi node nam truoc node Q trong ds
         }*/
        
    //  ~~~~~~~~~~~~~~~cach 2: trong ds co tu 2 node Q tro len ~~~~~~~~~~~~~~~~~~~~~~~~~~
        Node *G = (Node*)malloc(sizeof(Node));// node giu lien ket voi cai node nam truoc node Q trong ds
           //duyet tu dau danh sach den cuoi danh sach de tim Q 
       for(Node *k = head ; k != NULL ; k = k->next)
       
         {      // neu Q ton tai thi ...
              if(Q->data == k->data)
                {
                   //them node P vao sau node G <=> them node P vao truoc node Q
                   Node *H = makeNode(P->data); // moi lan phat hien 1 node Q thi tao motj node P moi
                   H->next = k;//b1 : cho node H tro den node K <=> cung chinh la cho H tro den node Q
                   G->next = H;//b2 : cho node H tro den node P
                }
             G = k;//giu lien ket voi node nam truoc node Q trong ds
         }
     }
}
//ham them node P vao vi tri bat ki
/* luc chay nhap gia tri node P thi sau khi nhap xong phai co lenh Node *P = makeNode(data);(ow ham main)*/
//CACH 1
/*void chenvitribatki(Node *P ,int vtri,int n)
{  
   //vong lap lay so luong node trong danh sach
   for (Node *k= head ; k!=NULL ; k=k->next)
      {  n++; }
   printf("Nhap gia tri cua node Q: ");
   scanf("%d",&data);
   Node *Q = makeNode(data);
   if(head == NULL || vtri ==1)
      insert_first(data);
   if (vtri == n+1)
      insert_last(data);
   else 
   {  int dem = 0; //xac dinh vi tri can them

      Node *G = (Node*)malloc(sizeof(Node));// node giu lien ket voi cai node nam truoc node Q trong ds
           //duyet tu dau danh sach den cuoi danh sach de tim Q 
       for(Node *k = head ; k != NULL ; k = k->next)
       {   
              dem ++;  
              // neu Q ton tai thi ...
              if(dem = vtri)
                {
                   //them node P vao sau node G <=> them node P vao truoc node Q
                   Node *H = makeNode(P->data); // moi lan phat hien 1 node Q thi tao motj node P moi
                   H->next = k;//b1 : cho node H tro den node K <=> cung chinh la cho H tro den node Q
                   G->next = H;//b2 : cho node H tro den node P
                   break;
                }
             G = k;//giu lien ket voi node nam truoc node Q trong ds
        }
   }
      
}*/

//CACH 2: DUNG BIEN TOAN CUC cho bien n

void chenvitribatki(Node *P ,int vtri)
{  
   //vong lap lay so luong node trong danh sach
   for (Node *k= head ; k!=NULL ; k=k->next)
      {  
        n++; 
      }
   printf("Nhap gia tri cua node Q: ");
   scanf("%d",&data);
   Node *Q = makeNode(data);
   if(head == NULL || vtri ==1)
      insert_first(data);
   if (vtri == n+1)
      insert_last(data);
   else 
   {  int dem = 0; //xac dinh vi tri can them

      Node *G = (Node*)malloc(sizeof(Node));// node giu lien ket voi cai node nam truoc node Q trong ds
           //duyet tu dau danh sach den cuoi danh sach de tim Q 
       for(Node *k = head ; k != NULL ; k = k->next)
       {   
              dem ++;  
              // neu Q ton tai thi ...
              if(dem = vtri)
                {
                   //them node P vao sau node G <=> them node P vao truoc node Q
                   Node *H = makeNode(P->data); // moi lan phat hien 1 node Q thi tao motj node P moi
                   H->next = k;//b1 : cho node H tro den node K <=> cung chinh la cho H tro den node Q
                   G->next = H;//b2 : cho node H tro den node P
                   break;
                }
             G = k;//giu lien ket voi node nam truoc node Q trong ds
        }
   }
      
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

// xoa 1 node nam sau node q trong danh sach
void xoasau(Node *Q)
{
   //duyet danh sach tu dau den cuoi de tim node Q 
   for(Node *k = head ; k != NULL ; k = k->next)
       
         {      
              if(k->data == Q->data)
                  {
                    Node *G =k->next;//G laf node nam sau node k (nam sau node Q)
                    k->next = Q->next;//cap nhat moi lien ket giua node k(node Q) voi node sau not G
                    free(G);
                    return ;
                          
                  }
        }
}

//xoa 1 node bat ki trong danh sach 
void xoabatki(int data)
{
  if(head->data = data)
    { 
     del_first();
     return;
    }
  if(tail->data = data)
    { 
     del_last();
     return;
    }
  else
    Node *G = (Node*)malloc(sizeof(Node)); // node tro den node nam truoc node can xoa
    for(Node *k = head ; k != NULL ; k = k->next)
       {
          if(k->data = data)
             {
                    
                    G->next = k->next;//cap nhat moi lien ket giua node k(node Q) voi node sau not H
                    free(k);
                    return ;
             }
         G =k ; // cho node G tro den node k
       }
    
}
void daoNguocDS()
{
  Node *P = NULL;
  Node *newHead = NULL, *newtail = NULL;

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

void searchMoveToFront(DB data)
{
  // TIM THEO TRUONG value
  for (Node *P = head; P != NULL; P= P->next)
    {
      if (P->data.value == data.value)
	{
	  Node new;
	  new = P->data;
	  P->data = head->data;
	  head->data = new;
	  break;
	}
    }
}

void searchTranspose(DB data)
{
  // TIM THEO TRUONG value !
  Node *prev = head;
  for (Node *P = head; P != NULL; P = P->next)
    {
      if (P->data.value == data.value)
	{
	  Node new;
	  new = P->data;
	  P->data = prev->data;
	  prev->data = new;
	  break;
	}
      prev = P;
    }
}

