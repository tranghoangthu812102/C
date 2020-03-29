#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jrb.h"
#include "dllist.h"

typedef struct
{
    JRB edges;//JRB ke
    JRB vertices;//Khoa nut
}GRAPH;
GRAPH make_graph()
{
    GRAPH graph;
    graph.edges=make_jrb();
    graph.vertices=make_jrb();
    return graph;
}
void addVertex(GRAPH graph,int id,char *name)
{
    if(!jrb_find_int(graph.vertices,id))
        jrb_insert_int(graph.vertices,id,new_jval_s(strdup(name)));
}
char *getVertex(GRAPH graph,int id)
{
    JRB g=jrb_find_int(graph.vertices,id);
    if(!g) return NULL;
    return jval_s(g->val);
}
int hasEdge(GRAPH graph,int v1,int v2)
{
    JRB a=jrb_find_int(graph.edges,v1);
    if(!a) return 0;
    a=jrb_find_int((JRB)jval_v(a->val),v2);
    if(!a) return 0;
    return 1;
}
void addEdge(GRAPH graph,int v1,int v2)
{
    if(hasEdge(graph,v1,v2)) return;
    JRB tree1;
    JRB a=jrb_find_int(graph.edges,v1);
    if(!a)
    {
        tree1=make_jrb();
        jrb_insert_int(graph.edges,v1,new_jval_v(tree1));
    }
    else
        tree1 = (JRB)jval_v(a->val);
    jrb_insert_int(tree1,v2,new_jval_i(1));
    a=jrb_find_int(graph.edges,v2);
    if(!a)
    {
        tree1=make_jrb();
        jrb_insert_int(graph.edges,v2,new_jval_v(tree1));
    }
}
int indegree(GRAPH graph,int v1,int *output)
{
    int total=0;
    JRB b,a=jrb_find_int(graph.edges,v1);
    if(a)
        jrb_traverse(a,graph.edges)
        {
           b=jrb_find_int((JRB)jval_v(a->val),v1);
           if(b)
               output[total++]=jval_i(a->key);
        }
    return total;
}
int outdegree(GRAPH graph,int v1,int *output)
{
    int total=0;
    JRB a,b=jrb_find_int(graph.edges,v1);
    if(b)
    {
        b=(JRB)jval_v(b->val);
        jrb_traverse(a,b)
            output[total++]=jval_i(a->key);
    }
    return total;
}
int DFS_DAG(GRAPH graph,int start)
{
   int visited[1000]={};
   int n,output[100],i,u,v;
   Dllist node,stack;
   stack=new_dllist();
   dll_append(stack,new_jval_i(start));
   while(!dll_empty(stack))
   {
       node=dll_last(stack);
       u=jval_i(node->val);
       dll_delete_node(node);
       if(!visited[u])
       {
           visited[u]=1;
           n=outdegree(graph,u,output);
           for(i=0;i<n;i++)
           {
               v=output[i];
               if(v==start) return 0;
               if(!visited[v])
                dll_append(stack,new_jval_i(v));
           }
       }
   }
   return 1;
}
int DAG(GRAPH graph)
{
    int start, notCycle;
    JRB vertex;
    jrb_traverse(vertex,graph.vertices)
    {
        start=jval_i(vertex->key);
        printf("Goi DFS xuat phat tu dinh %d \n",start);
        notCycle=DFS_DAG(graph,start);
        if(notCycle==0) return 0;
    }
    return 1;
}
void dropGraph(GRAPH graph)
{
    JRB node,tree;
    jrb_traverse(node,graph.edges)
    {
        tree=(JRB) jval_v(node->val);
        jrb_free_tree(tree);
    }
    jrb_free_tree(graph.edges);
    jrb_free_tree(graph.vertices);
}
void topologicSort(GRAPH graph,int *output,int *n)
{
    Dllist node,queue=new_dllist();
    int total=0;
    int i,j=0,m;
    int output1[100];
    int output3[1000]={};
    JRB a;
    jrb_traverse(a,graph.edges)
    {
        i=indegree(graph,jval_i(a->key),output1);
        if(i==0) dll_append(queue,a->key);
        output3[jval_i(a->key)]=i;
    }
    while(!dll_empty(queue))
    {
        node=dll_first(queue);
        i=jval_i(node->val);
        output[total++]=i;
        dll_delete_node(node);
        j=outdegree(graph,i,output1);
        for(m=0;m<j;m++)
        {
            output3[output1[m]]-=1;
            if(output3[output1[m]]==0)
                dll_append(queue,new_jval_i(output1[m]));
        }
    }
    *n=total;
}
int main()
{
   int output[100],n,output2[100];
   GRAPH graph=make_graph();
   addVertex(graph,0,"S0");
   addVertex(graph,1,"S1");
   addVertex(graph,2,"S2");
   addVertex(graph,3,"S3");
   addVertex(graph,4,"S4");
   addVertex(graph,5,"S5");
   addVertex(graph,6,"S6");
   addVertex(graph,7,"S7");
   addVertex(graph,8,"S8");
   addVertex(graph,9,"S9");
   addEdge(graph,0,1);
   addEdge(graph,0,4);
   addEdge(graph,0,6);
   addEdge(graph,1,2);
   addEdge(graph,2,5);
   addEdge(graph,2,7);
   addEdge(graph,3,4);
   addEdge(graph,3,8);
   addEdge(graph,4,5);
   addEdge(graph,6,2);
   addEdge(graph,6,3);
   addEdge(graph,7,8);
   addEdge(graph,9,6);
   if(DAG(graph)) printf("Do thi khong co chu trinh\n");
   else printf("Do thi co chu trinh\n");
   printf("Ban bac vao cua dinh 2 = %d \n",indegree(graph,2,output2));
   printf("Ban bac ra cua dinh 2 = %d \n",outdegree(graph,2,output2));
   topologicSort(graph,output,&n);
   for(int i=0;i<n;i++) printf("%d\t",output[i]);
   printf("\n");
   dropGraph(graph);
   return 0;
}