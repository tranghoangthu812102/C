/*Dinh nghia cac ham API */
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int *matrix;
    int n;
}Graph;

/*1.Tao do thi voi so luong dinh = n
(cap phat bo nho cho mang matrix gom n^2 phan tu)*/

Graph createGraph(int n)
{
   Graph g;
   g.n = n;
   g.matrix = (int *)malloc(n*n*sizeof(int));
   return g;
}

/*2.Them 1 canh moi(v1,v2) vao do thi*/
//tao ra dia chi vo huong , neu tao ra dia chi co huong chi can dong 1
void addEdge(Graph graph,int v1,int v2)
{
    graph.matrix[v1*graph.n+v2] = 1;
    graph.matrix[v2*graph.n+v1] = 1;
}

/*3.Kiem tra xem do thi co canh (v1,v2) hay khong*/
int adjacent(Graph graph,int v1,int v2)
{
    return graph.matrix[v1*graph.n+v2] ;
}

/*4.Tra ve so luong cac dinh ke voi dinh v tren do thi ;
dong thoi mang output se chua danh sach cac dinh ke voi dinh v*/
int getAdjacentVertices(Graph graph,int v,int *output)
{
   int total = 0,i;
   for(i=0;i<graph.n;i++)
     if(adjacent(graph,v,i))
       output[total++] = i;
    return total;
}

/*5.Giai phong bo nho luu tru do thi*/
void dropGraph(Graph graph)
{
    free(graph.matrix);
    graph.matrix = NULL;
    graph.n = 0;
}

int main()
{
    int i,n,output[100];
    Graph g = createGraph(100);
    addEdge(g,0,1);
    addEdge(g,0,2);
    addEdge(g,1,2);
    addEdge(g,1,3);
    n = getAdjacentVertices(g,1,output);
    if(n == 0)
    printf("Dinh 1 khong ke voi dinh nao cua do thi!\n");
    else
    {
        printf("Danh sach cac dinh ke voi dinh 1:");
        for(i=0;i<n;i++)
        printf("%5d",output[i]);
    }
    printf("\n");
    dropGraph(g);
    
}



