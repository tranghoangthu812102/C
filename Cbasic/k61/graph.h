#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jrb.h"
#include "dllist.h"

#define true 1
#define false 0
#define UNDIRECTED 0
#define DIRECTED 
#define INT_MAX 1000000000
#define INFINITIVE_VALUE 10000000

typedef struct
{
    JRB edges;
    JRB vertices;
}Graph;

/*1.Tạo đồ  thị*/
Graph createGraph();

/*2.Thêm 1 đỉnh mới vào đồ thị */
void addVertex(Graph g,int id, char *name);

/*3.Ham tra ve 1 dinh thuoc do thi*/
char *getVertex(Graph g , int id);

/*dem so dinh*/
int getNumofVetex(Graph g);

/*4.Ham tra ve gia tri 1 neu co canh (v1,v2), gia tri 0 neu khong co*/
int hasEdge(Graph g, int v1, int v2);

/*5.Them canh (v1,v2) vao do thi*/
void addEdge(Graph graph, int v1, int v2, double weight);

/*6.Hàm trả về trọng số của đồ thị */
double getEdgeValue(Graph graph, int v1, int v2);

/*6.Ham tra ve ban bac vao cua dinh v*/
int indegree(Graph g,int v, int *output);

/*7.Ham tra ve ban bac ra cua dinh v*/
int outdegree(Graph g,int v, int *output);

/*8.Ham kiem tra do thi co chu trinh hay khong*/
/*Ham tra ve gia tri 1 neu khong phat hien ra chu trinh , gia tri 0 neu phat hien ra chu trinh*/
int DFS_DAG(Graph g ,int start );
int DAG(Graph g);

/*9.Đường đi ngắn nhất từ đỉnh S đến đỉnh T*/
double shortestPath_s_To_t(Graph g, int s, int t, int* p);
void swapArray(int arr[], int cnt);
double shortestPath(Graph g, int s , int t, int *p , int *numVertices);

/*10.Đường đi ngắn nhất từ đỉnh S đến tất cả các đỉnh còn lại */
void shortestPath_s_To_All(Graph g, int s, int* p, double *d);

/*11 . Sắp xếp topo*/
void topologicalSort(Graph g, int *output,int *n);
void topoSort(Graph g, int* output, int* n);

/*11.Giai phong bo nho / xoa do thi*/
void dropGraph(Graph g);
