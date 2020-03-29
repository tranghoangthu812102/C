#include <stdio.h>
#include <stdlib.h>
#include "jrb.h"
#include "dllist.h"

typedef struct
{
    JRB edges;
    JRB vertices;
}Graph;
/*Trong cây đỏ đen vertices mỗi node tương đương với một đỉnh thuộc đồ thị 
  Mỗi nút gồm 2 trường : key - 1 số nguyên id
                         value - 1 xâu kí tự name*/


/*Trong cây đỏ đen edges: mỗi nút tương đương với 1 đỉnh thuộc đồ thị có tập các đỉnh
kề với nó khác rỗng. Mỗi nút gồm 2 trường:
• Key: 1 số nguyên id
• Value: 1 cây đỏ đen lưu trữ danh sách các đỉnh kề với nó*/

/*1.Tạo đồ  thị*/
Graph createGraph()
{
    Graph g;
    g.edges = make_jrb();
    g.vertices = make_jrb();
    return g;
}

/*2.Thêm 1 đỉnh mới vào đồ thị */
void addVertex(Graph g,int id, char *name)
{
     //Kiem tra xem dinh da ton tai tren do thi hay chua 
     JRB node = jrb_find_int(g.vertices,id);
     if(node == NULL)
     jrb_insert_int(g.vertices,id,new_jval_s(strdup(name)));
}

/*3.Ham tra ve 1 dinh thuoc do thi*/
char *getVertex(Graph g , int id)
{
  JRB node = jrb_find_int(g.vertices,id);
  if(node == NULL)
    return NULL;
  else 
     return jval_s(node->val);
}

/*4.Them canh (v1,v2) vao do thi*/
void addEdge(Graph g, int v1, int v2)
{
     JRB node = jrb_find_int(g.edges,v1);
     if(node == NULL)
     {
         JRB treev1 = make_jrb();//tao cay do den cua v1 de luu tru dinh ke cua v1 tren do thi
         jrb_insert_int(g.edges,v1,new_jval_v(treev1));
         jrb_insert_int(treev1, v2, new_jval_i(1));
     }
     else
     {
         JRB treev1 = (JRB)jval_v(node->val); // truy cap vao cay do den cua dinh v1
         jrb_insert_int(treev1, v2, new_jval_i(1));//them v2 vao danh sach ke cua dinh v1 trong cay do den
     }
     
}

/*5.Ham tra ve gia tri 1 neu co canh (v1,v2), gia tri 0 neu khong co*/
int hasEdge(Graph g, int v1, int v2)
{
      JRB node = jrb_find_int(g.edges,v1); //Tim v1 trong cay do den edges
      if(node == NULL) return 0;
      //Kiem tra cay do den cua v1 co v2 khong
      else
      {
          JRB tree = (JRB)jval_v(node->val);//lay ra danh sach cac dinh ke voi v1
          if(jrb_find_int(tree,v2)== NULL)
             return 0;
        else return 1;
      }
      
}

/*6.Ham tra ve ban bac vao cua dinh v*/
int indegree(Graph g,int v, int *output)
{
  JRB node, tree;
  int total =0;
  jrb_traverse(node,g.edges)
  {
      tree = (JRB)jval_v(node->val);
      if(jrb_find_int(tree,v) )
      {
          output[total] = jval_i(node->key);
          total++;
      }
  }
  return total;
}

/*7.Ham tra ve ban bac ra cua dinh v*/
int outdegree(Graph g,int v, int *output)
{
   int total = 0;
   JRB node = jrb_find_int(g.edges,v);
   if(node == NULL) return 0;
   JRB tree = (JRB) jval_v(node->val);
   jrb_traverse(node, tree)
   {
          output[total] = jval_i(node->key);
          total++;

   }
   return total;

}

/*8.Ham kiem tra do thi co chu trinh hay khong*/
/*Ham tra ve gia tri 1 neu khong phat hien ra chu trinh , gia tri 0 neu phat hien ra chu trinh*/
int DFS_DAG(Graph g ,int start )
{
    int visited[1000] ={};
    int out[100],i,u,v,n;
    Dllist node, stack;
    
    stack = new_dllist();
    dll_append(stack,new_jval_i(start));
    while(!dll_empty(stack))
    {
      node = dll_last(stack);
      u = jval_i(node->val);
      dll_delete_node(node);
      if(!visited[u])
      {
          visited[u]= 1;
          n= outdegree(g,u,out);
          for(i = 0 ; i<n;i++)//Xet lan luot cac domj ke voi dinh u
          { 
              v = out[i];
            if(v == start) return 0;
            if (!visited[v]) //thêm v vào queue nếu v chưa được thăm
                  dll_append(stack, new_jval_i(v));
          }
       }
    }
    return 1;
}
int DAG(Graph g)
{
    int start, notCycle;
    JRB vertex;
    jrb_traverse(vertex,g.vertices)
    {
        start = jval_i(vertex->key);
        printf("Goi DFS xuat phat tu dinh %d \n",start);
        notCycle = DFS_DAG(g,start);
        if(notCycle == 0) return 0;
    }
    return 1;
}


/*9.Giai phong bo nho / xoa do thi*/
void dropGraph(Graph g)
{
       JRB node, tree;
       jrb_traverse(node , g.edges)
       {
           tree = (JRB)jval_v(node->val);
           jrb_free_tree(tree);
       }
       jrb_free_tree(g.edges);
       jrb_free_tree(g.vertices);
}
int main()
{
    int out[100];
    Graph g = createGraph();
    addVertex(g,0,"V0");addVertex(g,1,"V1");
    addVertex(g,2,"V2");addVertex(g,3,"V3");
    addVertex(g,4,"V4");addVertex(g,5,"V5");
    addEdge(g,0,1);addEdge(g,1,2);
    addEdge(g,2,3);addEdge(g,1,3);
    addEdge(g,2,4);addEdge(g,4,5);addEdge(g,5,1);
    if(DAG(g)) printf("Do thi khong co chu trinh\n");
    else printf("Do thi co chu trinh\n");
     
    printf("Ban bac vao cua dinh 2 = %d\n",indegree(g,2,out));
    printf("Ban bac ra cua dinh 2 = %d\n",outdegree(g,2,out));
    dropGraph(g);
}
