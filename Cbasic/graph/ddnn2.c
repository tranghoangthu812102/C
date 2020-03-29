#include <stdio.h>
#include <stdlib.h>
#include "jrb.h"
#include "dllist.h"
#define INFINITIVE_VALUE 10000000
typedef struct
{
    JRB edges;
    JRB vertices;
}Graph;

Graph createGraph()
{
    Graph g;
    g.edges = make_jrb();
    g.vertices = make_jrb();
    return g;
}
void addVertex(Graph g,int id, char *name)
{
     //Kiem tra xem dinh da ton tai tren do thi hay chua 
     JRB node = jrb_find_int(g.vertices,id);
     if(node == NULL)
     jrb_insert_int(g.vertices,id,new_jval_s(strdup(name)));
}
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
char *getVertex(Graph g , int id)
{
  JRB node = jrb_find_int(g.vertices,id);
  if(node == NULL)
    return NULL;
  else 
     return jval_s(node->val);
}
double getEdgeValue(Graph g, int v1, int v2)
{
    JRB node, tree;
    node = jrb_find_int(g.edges,v1);
    if(node == NULL)
      return INFINITIVE_VALUE;
    tree = (JRB)jval_v(node->val);
    node = jrb_find_int(tree,v2);
    if(node == NULL)
       return INFINITIVE_VALUE;
    else 
       return jval_d(node->val);
}

void addEdge(Graph g, int v1, int v2 , double weight)
{
    JRB node, tree;
    if(getEdgeValue(g,v1,v2)== INFINITIVE_VALUE)
    {
        node = jrb_find_int(g.edges,v1);
        if(node == NULL)
        {
            tree = make_jrb();
            jrb_insert_int(g.edges,v1,new_jval_v(tree));
        }
        else
           tree = (JRB)jval_v(node->val);
           jrb_insert_int(tree,v2,new_jval_d(weight));
    }
}

void shortestPath_s_To_All(Graph g, int s, int t , int *p[1000],double *d)
{
    double k[1000],min, w;
    int n, output[100],i, u, v;
    Dllist ptr, queue;
    JRB node;
    for(i = 0 ; i<1000 ; i++)
    {
        d[i] = INFINITIVE_VALUE;
        k[i] = 0;
    }
    d[s] = 0 ; *p[s] = s;
    queue = new_dllist();
    jrb_traverse(node,g.vertices)
      dll_append(queue,new_jval_i(jval_i(node->key)));
    while(!dll_empty(queue))
    {
        min = INFINITIVE_VALUE + 1;
        dll_traverse(ptr,queue)
        {
            v = jval_i(ptr->val);
            if(min>d[v])
            {
                min = d[v];
                node = ptr;
                u = v;
            }            
        }
        k[u] =1 ;
        dll_delete_node(node);
        n = outdegree(g,u,output);
        for(i = 0 ; i <n ; i++)
        {
            v = output[i];
            if(k[v] == 0)
            {
                w = getEdgeValue(g,u,v);
                if(d[v] > d[u] +w)
                {
                    d[v] = d[u] + w;
                    p[v] = u;
                }
            }
        }       
    }
}
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
    int i, previous[100],s,t;
    double w ;
    Graph g = createGraph();
    addVertex(g, 0,"V0"); addVertex(g,1,"V1");
    addVertex(g, 2,"V2"); addVertex(g,3,"V3");
    addVertex(g, 4,"V4"); 
    addEdge(g,0,1,1);addEdge(g,1,2,3);
    addEdge(g,2,0,3);addEdge(g,1,3,1);
    addEdge(g,3,2,1);addEdge(g,4,3,5);
    s =0 ; t = 2;
    w = shortestPath_s_To_All(g,s,t,previous,);
    if(w == INFINITIVE_VALUE)
      printf("Khong ton tai duong di tu %s den %s\n",getVertex(g,s),getVertex(g,t));
    else
    {
        printf("Duong di ngan nhat tu %s den %s la : \n",getVertex(g,s),getVertex(g,t));
        printf("-Do dai = %.3f\n",w);
        printf("-Duong di : ",w);
        i = t;
        do
        {
            printf("%s <== ",getVertex(g,i));
            i = previous[i];
            
        } while (i != s);
        printf("%s ",getVertex(g,s));
    }
    printf("\n");
    dropGraph(g);

    
}