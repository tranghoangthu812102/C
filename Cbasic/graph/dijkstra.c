#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "jrb.h"
#include "dllist.h"

#define INFINITIVE_VALUE  10000000

typedef struct {
   JRB edges;
   JRB vertices;
} Graph;

Graph createGraph();
void addVertex(Graph graph, int id, char* name);
char *getVertex(Graph graph, int id);
void addEdge(Graph graph, int v1, int v2, double weight);
double getEdgeValue(Graph graph, int v1, int v2);
int indegree(Graph graph, int v, int* output);
int outdegree(Graph graph, int v, int* output);
void dropGraph(Graph graph);
double shortestPath_s_To_t(Graph g, int s, int t, int* previous);
void shortestPath_s_To_All(Graph g, int s, int* previous, double *d);



int main()
{
    int i, previous[100], s, t;
    double w;
    Graph g = createGraph();
    addVertex(g, 0, "V0"); addVertex(g, 1, "V1");
    addVertex(g, 2, "V2");addVertex(g, 3, "V3");
    addVertex(g, 4, "V4");
    addEdge(g, 0, 1, 1);addEdge(g, 1, 2, 3);
    addEdge(g, 2, 0, 3);addEdge(g, 1, 3, 1);
    addEdge(g, 3, 2, 1);addEdge(g, 4, 3, 5);
    s = 0; t =  2;
    w = shortestPath_s_To_t(g,s,t,previous);
    if (w == INFINITIVE_VALUE)
         printf("Khong ton tai duong di tu %s den %s\n", getVertex(g, s), getVertex(g, t));
    else
    {
         printf("Duong di ngan nhat tu %s den %s : \n",getVertex(g, s), getVertex(g, t));
         printf("- Do dai = %f \n",  w);
         printf("- Duong di: ",  w);i = t;
         do
         {
             printf(" %s  <== ", getVertex(g, i));
             i = previous[i];
         }while (i != s);
         printf(" %s  ", getVertex(g, s));
    }
//    Chan(g);

   double d[1000];
   int v;
   JRB node;
   printf("\nDuong di ngan nhat tu dinh %s den tat ca cac dinh con lai cua do thi la: \n",getVertex(g,s));
   shortestPath_s_To_All(g, s, previous, d);
   jrb_traverse(node, g.vertices)
   {
       v = jval_i(node->key);
       if (v != s)
       {
          if (d[v] == INFINITIVE_VALUE)
             printf("Khong ton tai duong di tu %s den %s\n", getVertex(g, s), getVertex(g, v));
          else
          {
             printf("Duong di ngan nhat tu %s den %s : \n",getVertex(g, s), getVertex(g, v));
             printf("- Do dai = %f \n",  w);
             printf("- Duong di: ",  w);i = t;
             do
             {
                  printf(" %s  <== ", getVertex(g, i));
                  i = previous[i];
             }while (i != s);
             printf(" %s  ", getVertex(g, s));
             printf("\n");
          }

       }//end if (v != s)
    }
	dropGraph(g);
    getch();
}

Graph createGraph()
{
   Graph g;
   g.edges = make_jrb();
   g.vertices = make_jrb();
   return g;
}

void addVertex(Graph g, int id, char* name)
{
     JRB node = jrb_find_int(g.vertices, id);
     if (node==NULL) // only add new vertex
         jrb_insert_int(g.vertices, id, new_jval_s(strdup(name)));
}

char *getVertex(Graph g, int id)
{
     JRB node = jrb_find_int(g.vertices, id);
     if (node==NULL)
        return NULL;
     else
        return jval_s(node->val);
}

void addEdge(Graph graph, int v1, int v2, double weight)
{
     JRB node, tree;
     if (getEdgeValue(graph, v1, v2)==INFINITIVE_VALUE) //neu graph chua co canh (v1,v2)
     {
        node = jrb_find_int(graph.edges, v1); //tim dinh v1 tren tap canh graph.edges
        if (node==NULL) //neu graph.edges chua co dinh v1
		{
           tree = make_jrb();
           jrb_insert_int(graph.edges, v1, new_jval_v(tree)); //them v1 vao graph.edges
        }
		else //graph.edges da co dinh v1
            tree = (JRB) jval_v(node->val); //tree: caydoden cua dinh v1
        //them v2 vao caydoden tree cua dinh v1:
        jrb_insert_int(tree, v2, new_jval_d(weight));
     }
}

void PrintDSKe(Graph graph)
{
    JRB node, node1, tree;
    int v;
    jrb_traverse(node, graph.edges)
    {
        v = jval_i(node->key);
        tree = (JRB) jval_v(node->val);
        printf("Nhung dinh ke voi dinh %d: ",v);
        jrb_traverse(node1, tree)
           printf("%4d  ",jval_i(node1->key));
        printf("\n");

    }
}


double getEdgeValue(Graph graph, int v1, int v2)
{
    JRB node, tree;
    node = jrb_find_int(graph.edges, v1);
    if (node==NULL) //graph.edges chua co dinh v1==> graph ko co canh (v1, v2)
       return INFINITIVE_VALUE; //ko co canh (v1, v2) ==> trong so canh (v1, v2) = infinitive

	tree = (JRB) jval_v(node->val); //truy cap vao cay do den (chua danh sach ke) cua v1
    node = jrb_find_int(tree, v2); //tim v2 trong danh sach ke cua dinh v1
    if (node==NULL) //v2 khong ke voi v1
       return INFINITIVE_VALUE; //do do, graph ko co canh (v1, v2)
    else
       return jval_d(node->val); //truy cap vao truong val de lay trong so cua canh (v1, v2)
}


int indegree (Graph graph, int v, int* output)
{
    JRB tree, node;
    int total = 0;
    jrb_traverse(node, graph.edges)
    {
       tree = (JRB) jval_v(node->val);
       if (jrb_find_int(tree, v))
       {
          output[total] = jval_i(node->key);
          total++;
       }
    }
    return total;
}

int outdegree (Graph graph, int v, int* output)
{
    JRB tree, node;
    int total;
    node = jrb_find_int(graph.edges, v);
    if (node==NULL)
       return 0;
    tree = (JRB) jval_v(node->val);
    total = 0;
    jrb_traverse(node, tree)
    {
       output[total] = jval_i(node->key);
       total++;
    }
    return total;
}


double shortestPath_s_To_t(Graph g, int s, int t, int* p)
{
   double d[1000], k[1000], min, w;
   int n, output[100], i, u, v;
   Dllist ptr, node_min, queue;
   JRB node;

   for (i=0; i<1000; i++)
   {
       d[i] = INFINITIVE_VALUE;
       k[i] = 0; //chua tim duoc duong di tu s den i
   }
   d[s] = 0; p[s] = s;

   //Bo sung tat ca cac dinh cua do thi vao hang doi Q:
   queue = new_dllist();
   jrb_traverse(node, g.vertices)
       dll_append(queue, new_jval_i(jval_i(node->key)));

   while ( !dll_empty(queue) )
   {
      /* get u from the priority queue:
      Tim u la dinh co d[u] nho nhat trong so cac dinh thuoc queue*/
      min = INFINITIVE_VALUE + 1;
      dll_traverse(ptr, queue) //duyet qua tung dinh v cua queue, tim u la dinh co gia tri d nho nhat
      {
          v = jval_i(ptr->val);
          if (min > d[v])
          {
             min = d[v];
             node_min = ptr;
             u = v;
          }
      }
      k[u] = 1; //da tim duoc ddnn tu s den u
      dll_delete_node(node_min); //xoa u khoi queue vi da tim duoc ddnn tu s den u

      if (u == t) break; // stop at t

      n = outdegree(g, u, output);
      for (i=0; i<n; i++)
      {
          v = output[i];
          if (k[v] == 0) //neu van chua tim duoc ddnn tu s den v
          {
              w = getEdgeValue(g, u, v);
              if ( d[v] > d[u] + w ) //kiem tra xem co giam duoc ddnn tu s den v bang cach di qua canh (u, v) hay ko
              {
                 d[v] = d[u] + w;
                 p[v] = u;
              }
          }//end if
      }//end for
   }//end while
   return d[t];
}


void shortestPath_s_To_All(Graph g, int s, int* p, double *d)
{
   double k[1000], min, w;
   int n, output[100], i, u, v;
   Dllist ptr, node_min, queue;
   JRB node;

   for (i=0; i<1000; i++)
   {
       d[i] = INFINITIVE_VALUE;
       k[i] = 0; //chua tim duoc duong di tu s den i
   }
   d[s] = 0; p[s] = s;

   //Bo sung tat ca cac dinh cua do thi vao hang doi Q:
   queue = new_dllist();
   jrb_traverse(node, g.vertices)
       dll_append(queue, new_jval_i(jval_i(node->key)));

   while ( !dll_empty(queue) )
   {
      /* get u from the priority queue:
      Tim u la dinh co d[u] nho nhat trong so cac dinh thuoc queue*/
      min = INFINITIVE_VALUE + 1;
      dll_traverse(ptr, queue) //duyet qua tung dinh v cua queue, tim u la dinh co gia tri d nho nhat
      {
          v = jval_i(ptr->val);
          if (min > d[v])
          {
             min = d[v];
             node_min = ptr;
             u = v;
          }
      }
      k[u] = 1; //da tim duoc ddnn tu s den u
      dll_delete_node(node_min); //xoa u khoi queue vi da tim duoc ddnn tu s den u

//      if (u == t) break; // stop at t

      n = outdegree(g, u, output);
      for (i=0; i<n; i++)
      {
          v = output[i];
          if (k[v] == 0) //neu van chua tim duoc ddnn tu s den v
          {
              w = getEdgeValue(g, u, v);
              if ( d[v] > d[u] + w ) //kiem tra xem co giam duoc ddnn tu s den v bang cach di qua canh (u, v) hay ko
              {
                 d[v] = d[u] + w;
                 p[v] = u;
              }
          }//end if
      }//end for
   }//end while
  // return d[t];
}

void dropGraph(Graph graph)
{
    JRB node, tree;
    jrb_traverse(node, graph.edges)
    {
        tree = (JRB) jval_v(node->val);
        jrb_free_tree(tree);
    }
    jrb_free_tree(graph.edges);
    jrb_free_tree(graph.vertices);
}

