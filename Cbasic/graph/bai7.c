#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jrb.h"
#include "fields.h"
#include "dllist.h"


typedef JRB Graph;
JRB stations;

/*1.Ham tao do thi*/
Graph createGraph()
{
   return make_jrb();
}

/*2.Neu dinh v1 ke voi v2 trong do thi g, ham tra ve gia tri 1,
neu khong tra ve gia tri 0*/
int adjacent(Graph g, char *v1,char *v2)
{
    JRB node, tree;
    //Kiem tra xem do thi g co chua dinh v1 hay khong?
    node = jrb_find_int(g,v1);
    if(node == NULL) return 0; //g khong co dinh v1
    /*do thi g co v1 : tiep tuc lay truong value(chua ds ke)cua 
    dinh v1 de kiem tra xem v1 co ke voi v2 hay ko*/
    tree = (JRB) jval_v(node->val);
    if(jrb_find_str(tree, v2)== NULL)
      return 0;
    return 1;

}

/*3.Them canh(v1,v2) vao do thi g*/
/*Do thi vo huong , neu co huong chi can 1 lan!!!*/
void addEdge(Graph g, char *v1, char *v2)
{
    JRB node,tree;
    //1.Them canh(v1,v2)
    if(!adjacent(g,v1,v2)) //(v1,v2) chua co tren do thi
    {
        node = jrb_find_str(g,v1);//tim v1 tren g
        if(node == NULL) //g chua co v1
        {
            tree = make_jrb();//tao cay do den de luu tru danh sach ke cua dinh v1
            jrb_insert_str(g,v1,new_jval_v(tree));//them v1 vao g:truong key = v1,truong value = tree
            
        } 
        else
        
            tree = (JRB) jval_v(node->val);//truy cap vao truong value cua dinh v1
            jrb_insert_str(tree,v2,new_jval_i(1));//de them v2 vao danh sach cac dinh ke voi v1
        
    }
    //2.Them canh(v2,v1)
    if(!adjacent(g,v2,v1)) //(v2,v1) chua co tren do thi
    {
        node = jrb_find_str(g,v2);//tim v2 tren g
        if(node == NULL) //g chua co v2
        {
            tree = make_jrb();//tao cay do den de luu tru danh sach ke cua dinh v1
            jrb_insert_str(g,v2,new_jval_v(tree));//them v2 vao g:truong key = v2,truong value = tree
            
        } 
        else
        
            tree = (JRB) jval_v(node->val);//truy cap vao truong value cua dinh v2
            jrb_insert_str(tree,v1,new_jval_i(1));//de them v1 vao danh sach cac dinh ke voi v2
        
    }

  
}

/*4.Dua danh sach cac dinh ke voi dinh v vao mang output,
ham tra ve so luong dinh ke voi dinh v*/
int getAdjacentVertices(Graph g, char *v, char * output[])
{
    JRB find_v,tree;
    find_v = jrb_find_str(g,v);
    if(find_v == NULL) return 0;
      tree = (JRB) jval_v(find_v->val);
      //truy cap vao truong value cua dinh v~1 cay do den
    int total =0;
    JRB node;
    //duyet cay do den cua dinh v,de dua ra cac dinh ke voi dinh v vao mang output
    jrb_traverse(node,tree)
    {
       output[total] = malloc(sizeof(char)*strlen(jval_s(node->key)));
       strcpy(output[total],jval_s(node->key));
       total++;
    }
    return total;
}

/*5.Giai phong bo nho , xoa do thi g*/
void dropGraph(Graph g)
{
    JRB node,tree;
    //1.Xoa cay do den tung dinh
    jrb_traverse(node,g)
    {
       tree  = (JRB) jval_v(node->val);
       jrb_free_tree(tree);
    }
    //2.Xoa do thi
    jrb_free_tree(g);
}
void fileOpenRead(FILE **f, char filename[])
{
  if ((*f = fopen(filename, "r")) == NULL)
  {
    printf("Can't open file: %s\n", filename);
    exit(0);
  }
}
void inputDataFromTxt(Graph g, char filename[])
{
    int stations_input = 0, line_input = 0;
    IS is = new_inputstruct(filename);
    if(is == NULL)
    {
        exit(1);
    }
    while(get_line(is) > 0)
    {
        if(strcmp(is->fields[0],"[STATIONS]") == 0)
        {
            stations_input = 1;
            line_input = 0;
            continue;
        }
        if(strcmp(is->fields[0],"[LINES]") == 0)
        {
            stations_input = 0;
            line_input =1;
            continue;
        }
        if(stations_input == 1)
        {
            char stations_name[100];
            strcpy(stations_name,is->fields[2]);
            for(int i =3;i<is->NF;i++)
            {
                strcat(stations_name, " ");
                strcat(stations_name,is->fields[i]);
            }
            (void)jrb_insert_str(stations,strdup(is->fields[0]),
            new_jval_s(strdup(stations_name)));
        }
        if(line_input == 1)
        {
            JRB find_i, find_j;
            for(int i = 2;i < is->NF -1 ;i++)
            {
                find_i = jrb_find_str(stations,is->fields[i]);
                find_j = jrb_find_str(stations,is->fields[i+1]);
                addEdge(g,jval_s(find_i->val),jval_s(find_j->val));

            }
        }
    }
}
void printVetex(char  v)
{
    printf("%4s",v);
}
void BFS_Shortest(Graph g,char start, char stop , char *truoc)
{
  char *visited ;
  char n,output[100],i,u,v;
  Dllist node,queue;
  queue = new_dllist();//tao 1 queue
  dll_append(queue,new_jval_s(start));//them phan tu start vao queue
  while (!dll_empty(queue))
  {
      node = dll_first(queue);
      u = jval_s(node->val);
      dll_delete_node(node);
      if(!())//neu u chua duoc tham
      {
      
          visited[u] = 1;
          if(u == stop) return ;
          n = getAdjacentVertices(g,u,output);
          for(i = 0 ; i<n;i++)//Xet lan luot cac domj ke voi dinh u
          {
              v = output[i];
            if (!visited[v]) //thêm v vào queue nếu v chưa được thăm
            {
                  truoc[v] = u;
                  dll_append(queue, new_jval_i(v));
            }
          }
      }
   }
}
int main()
{
    char *output[20];
    FILE *f;
    stations = make_jrb();
    Graph g = createGraph();
    char filename[]= "data.txt";
    fileOpenRead(&f,filename);
    inputDataFromTxt(g,filename);
    char ten_ga_tim_kiem[20];
    printf("Nhap ten ga :");
    gets(ten_ga_tim_kiem);
  
    int adjacent_station_number = getAdjacentVertices(g,ten_ga_tim_kiem,output);
    
    printf("So ga lien ke voi ga %s la : %d\n",ten_ga_tim_kiem,adjacent_station_number);
    for(int i = 0; i<adjacent_station_number;i++)
    {
        printf("%s\n",output[i]);
    }
    dropGraph(g);
}