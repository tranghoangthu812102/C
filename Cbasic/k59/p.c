#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jrb.h"
#include "dllist.h"

#define VOCUC 999
#define size 6

typedef struct Graph
{
    JRB Egde;
    JRB Vertex;
}Graph;

Graph createGraph();
int readLenh(int argc, char *argv[]);
void readFile(FILE *taptin, Graph graph);
void addVertex(Graph graph, int id, char* name);
char *getVertex(Graph graph, int id);
void addEdge(Graph graph, int v1, int v2, int trongSo);
int hasEdge(Graph graph, int v1, int v2);
int getTrongSo(Graph graph, int v1, int v2);
void addEgdeConLai(Graph graph);
void In(Graph graph);
void InCase6(Graph graph);
void InCase2(Graph graph);
void updateD(Graph graph, int v1, int v2, int *d, int *parents);
void dijkstra(Graph graph, int v1, int v2, void (* func)(Graph, int , int , int *, int *, int *));
Dllist findQmin(Dllist queue, int *d);
void InDuongDi(Graph, int v1, int v2, int *d, int *parents, int *soPT);
int indegree(Graph graph, int v, int* output);

int indegree(Graph graph, int v, int* output)
{
    JRB node1 = NULL, node2 = NULL;
    int n = 0;
    jrb_traverse(node1, graph.Egde)
    {
        jrb_traverse(node2, ((JRB)jval_v(node1->val)))
        {
            if(jval_i(node2->key) == v)
            {
                output[n] = jval_i(node1->key);
                n++;
                break;
            }
        }
    }
    return n;
}


int main(int argc, char *argv[])
{
    int luaChon;
    int *output1 = malloc(100*sizeof(int));
    int *input1 = malloc(100*sizeof(int));
    int *output2 = malloc(100*sizeof(int)), dinh[size][size];
    int table[20] = {};
    int i1, j1, tmp, n1, n2, soDinh, soCanh, a1, b1;
    Graph graph = createGraph();
    Graph graph5 = createGraph();
    FILE *taptin;
    if(argc > 2)
    {
   		taptin = fopen(argv[2], "r+");
	}
	else
	{
        printf("C-Advanced, HK20152\n");
		exit(1);
	}
    JRB node1 = NULL, node2 = NULL;
    if(taptin != NULL)
    {
    	luaChon = readLenh(argc, argv);
        readFile(taptin, graph);
        switch(luaChon)
        {
            
            case 2:
            {
				//printf("Case 2\n");
				InCase2(graph);
                break;
            }
            case 3:
            {
            	//printf("Case 3\n");
            	if(hasEdge(graph, atoi(argv[3]), atoi(argv[4])))
            	{
            		printf("%d\n", getTrongSo(graph, atoi(argv[3]), atoi(argv[4])));
            	}
            	else
            	{
            		printf("-1\n");
            	}
                break;
            }
            case 4:
            {
            	//printf("Case 4\n");
				dijkstra(graph, atoi(argv[3]), atoi(argv[4]), InDuongDi);
                break;
            }
            case 5:
            {
				//printf("Case 5\n");
				n1 = indegree(graph, atoi(argv[3]), output1);
				printf("%d\n", n1);
				for(i1 = 0; i1 < n1; i1++)
				{
					printf("%d %s %d\n", output1[i1], getVertex(graph, output1[i1]), getTrongSo(graph, atoi(argv[3]), output1[i1]));	
				}
                break;
            }
            case 6:
            {
            	//printf("Case 6\n");
            	for(i1 = 0, soDinh = 0; i1 < argc-3; i1++, soDinh++)
            	{
            		input1[i1] = atoi(argv[i1+3]);
            	}
            	printf("%d\n", soDinh);
            	for(a1 = 0; a1 < soDinh; a1++)
				{
				    jrb_insert_int(graph5.Vertex, input1[a1], new_jval_s(getVertex(graph, input1[a1])));

				}
				addEgdeConLai(graph5);
				for(a1 = 0, soCanh = 0; a1 < soDinh; a1++)
				{
				    for(b1 = a1; b1 < soDinh; b1++)
				    {

				        if(input1[a1] != input1[b1])
				        {
				            if(hasEdge(graph, input1[a1], input1[b1]))
				            {
				                addEdge(graph5, input1[b1], input1[a1] , getTrongSo(graph, input1[a1], input1[b1]));
				                addEdge(graph5, input1[a1], input1[b1] , getTrongSo(graph, input1[b1], input1[a1]));
				                soCanh++;
				            }
				            
				        }

				    }
				}
				
				
          		InCase2(graph5);
          		printf("%d\n", soCanh);
          		InCase6(graph5);
                break;
            }
     
        }
        fclose(taptin);
    }
    else
    {
        printf("ERROR\n");
    }
    return 0;
}
/*
JRB find_egde(Graph graph, int v1, int v2)
{
	JRB node1 = NULL, node2 = NULL;
	jrb_traverse(node1, graph.Egde)
    {
        jrb_traverse(node2, ((JRB)jval_v(node1->val)))
        {
        	if(jval_i(node1->key) == v1 && jval_i(node2->key) == v2)
        	{
        		return node2;
        	}
            	
            
        }
    }


}
*/
void InCase6(Graph graph)
{
    JRB node1 = NULL, node2 = NULL, node3;
  
    /*jrb_traverse(node1, graph.Egde)//Cach 1
    {
        jrb_traverse(node2, ((JRB)jval_v(node1->val)))
        {
        	if(getTrongSo(graph, jval_i(node1->key), jval_i(node2->key)) < 99999)
        	{
        		printf("%d %d %d\n", jval_i(node1->key), jval_i(node2->key), getTrongSo(graph, jval_i(node1->key), jval_i(node2->key)));
            	addEdge(graph, jval_i(node2->key), jval_i(node1->key), (getTrongSo(graph, jval_i(node1->key), jval_i(node2->key))+99999));
        	}
        	else
        	{
        		addEdge(graph, jval_i(node1->key), jval_i(node2->key), (getTrongSo(graph, jval_i(node1->key), jval_i(node2->key))-99999));
        	}
        }
    }*/
	
	int daXet[30]={};//chi dung khi key be
	jrb_traverse(node1, graph.Egde)
    {
        jrb_traverse(node2, ((JRB)jval_v(node1->val)))
        {
        	if(daXet[jval_i(node2->key)] == 0)
        	{
        		printf("%d %d %d\n", jval_i(node1->key), jval_i(node2->key), getTrongSo(graph, jval_i(node1->key), jval_i(node2->key)));
        	}
        }
        daXet[jval_i(node1->key)] = 1;
    }
	
}


Graph createGraph()
{
	Graph graph;
    graph.Egde = make_jrb();
    graph.Vertex = make_jrb();
    return graph;
}

int readLenh(int argc, char *argv[])
{
	int i;
	if(strcmp(argv[0], "./p") != 0)
	{
		printf("Ten file bi sai\n");
		exit(1);
	}
	if(argc == 3)
	{
		return 2;
	}
	else if(argc == 4)
	{
		return 5;
	}
	else if(argc >= 5)
	{
		if(strcmp(argv[1], "-w") == 0)
		{
			return 3;
		}
		else if(strcmp(argv[1], "-p") == 0)
		{
			return 4;
		}
		if(strcmp(argv[1], "-s") == 0)
		{
			return 6;
		}
	}
}

void readFile(FILE *taptin, Graph graph)
{
	int i1;
	char str[100], tmp;
	int a, b, key, key1, key2, trongSo;
	fscanf(taptin, "%d", &a);
	for(i1 = 0; i1 < a; i1++)
	{
		fscanf(taptin, "%d", &key);
		fscanf(taptin, "%c", &tmp);
		fgets(str, 98, taptin);
		str[strlen(str) - 1] = '\0';
		addVertex(graph, key, strdup(str));
	}
	fscanf(taptin, "%d", &b);
	for(i1 = 0; i1 < b; i1++)
	{
		fscanf(taptin, "%d", &key1);
		fscanf(taptin, "%c", &tmp);
		fscanf(taptin, "%d", &key2);
		fscanf(taptin, "%d", &trongSo);
		addEdge(graph, key1, key2, trongSo);
		addEdge(graph, key2, key1, trongSo);
	}
	addEgdeConLai(graph);
}

void InDuongDi(Graph graph, int v1, int v2, int *d, int *parents, int *soPT)
{
    int v = v2, bienChay, dekiru = 1;
    int duongDi[20] = {}, n=0;
    duongDi[0] = v2;n++;
    while(v != v1)
    {
        //printf("%d ", parents[v]);
        v = parents[v];
        if(v == -1 ||parents[v] == -1)
        {
            printf("Tu %d khong the den duoc %d\n", v1, v2);
            dekiru = 0;
            break;
        }
        duongDi[n] = v;
        n++;
    }
    if(dekiru == 0) return;
    //printf("\nDuong di ngan nhat tu %d->%d: ", v1, v2);
    /*int doDai = 0;
    for(bienChay = n-1; 0 < bienChay; bienChay--)
    {

        doDai += getTrongSo(graph, duongDi[bienChay], duongDi[bienChay-1]);

    }
    printf("%d\n", doDai);*/
    printf("%d\n", d[v2]);
    for(bienChay = n-1; 0 <= bienChay; bienChay--)
    {

        printf("%s\n", getVertex(graph, duongDi[bienChay]));

    }
}

Dllist findQmin(Dllist queue, int *d)
{
    Dllist Qnode = NULL, Qmin = NULL;
    Qnode = dll_first(queue);
    Qmin = Qnode;
    for(; Qnode != dll_last(queue); )
    {
        if(d[jval_i(Qnode->val)] < d[jval_i(Qmin->val)])
        {
            Qmin = Qnode;
        }
        Qnode = dll_next(Qnode);
    }
    Qnode = dll_next(Qnode);
    Qnode = dll_last(queue);//vong while khong den duoc node cuoi
    if(d[jval_i(Qnode->val)] < d[jval_i(Qmin->val)])
    {
        Qmin = Qnode;
    }
    return Qmin;
}


void dijkstra(Graph graph, int v1, int v2, void (* func)(Graph, int , int , int *, int *, int *))
{
    int soPT = 0, i;
    int d[20] = {};
    int parents[20] = {};
    for(i=0; i<20; i++)
    {
        d[i] = VOCUC;
        parents[i] = -1;
    }
    d[v1] = 0;
    parents[v1] = v1;
    Dllist queue = new_dllist(), Qnode = NULL, Qmin = NULL;
    JRB node1 = NULL, node2 = NULL;
    jrb_traverse(node1, graph.Vertex)
    {
        dll_append(queue, node1->key);
        soPT++;
    }
    while(!dll_empty(queue))
    {
        Qmin = findQmin(queue, d);
        node1 = jrb_find_int(graph.Egde, jval_i(Qmin->val));
        jrb_traverse(node2, ((JRB)jval_v(node1->val)))
        {
            updateD(graph, jval_i(Qmin->val), jval_i(node2->key), d, parents);
        }
        dll_delete_node(Qmin);
    }
    func(graph, v1, v2, d, parents, &soPT);
}



void updateD(Graph graph, int v1, int v2, int *d, int *parents)
{

    if(d[v2] > (d[v1] + getTrongSo(graph, v1, v2)))
    {
        //int old = d[v2];
        d[v2] = d[v1] + getTrongSo(graph, v1, v2);
        //printf("%d->%d; old: %d; new: %d\n", v1, v2, old, d[v2]);
        parents[v2] = v1;
    }

}


void addVertex(Graph graph, int id, char* name)
{
    JRB node = jrb_find_int(graph.Vertex, id);
    if(node == NULL)
    {
        jrb_insert_int(graph.Vertex, id, new_jval_s(name));
    }
    else
    {
        strcpy(jval_s(node->val), name);
    }
}

void addEdge(Graph graph, int v1, int v2, int trongSo)
{
    JRB node = jrb_find_int(graph.Egde, v1), node2 = NULL;
    if(node == NULL)
    {
        JRB node2 = jrb_find_int(graph.Vertex, v1);
        if(node2 == NULL)
        {
            printf("Khong co dinh %d\n", v1);
            return ;
        }
        JRB dsKe = make_jrb();
        jrb_insert_int(dsKe, v2, new_jval_i(trongSo));
        jrb_insert_int(graph.Egde, v1, new_jval_v(dsKe));
    }
    else
    {
        node2 = jrb_find_int((JRB)jval_v(node->val), v2);
        if(node2 == NULL)//neu co canh v1 v2 roi thi khong them nua
        {
            jrb_insert_int((JRB)jval_v(node->val), v2, new_jval_i(trongSo));//printf("aaaaaaa\n");
        }
        else
        {
        	node2->val = new_jval_i(trongSo);
        }
    }
}

int getTrongSo(Graph graph, int v1, int v2)
{
    JRB node1 = NULL, node2 = NULL;
    node1 = jrb_find_int(graph.Egde, v1);
    if(node1 != NULL)
    {
        node2 = jrb_find_int((JRB)jval_v(node1->val), v2);
        if(node2 != NULL)
        {
            return jval_i(node2->val);
        }
        else
        {
            //printf("Dinh %d khong ton tai\n", v2);
            return 0;
        }
    }
    else
    {
        //printf("Dinh %d khong ton tai\n", v1);
        return 0;
    }


}

int hasEdge(Graph graph, int v1, int v2)
{
    JRB node = jrb_find_int(graph.Egde, v1);
    if(node == NULL)
    {
        //printf("Khong co canh %d -> %d\n", v1, v2);
        return 0;
    }
    else
    {
        JRB node2 = jrb_find_int((JRB)jval_v(node->val), v2);
        if(node2 == NULL)
        {
            //printf("Khong co canh %d -> %d\n", v1, v2);
            return 0;
        }
        else
        {
            //printf("Co canh %d -> %d\n", v1, v2);
            return 1;
        }
    }
}

char *getVertex(Graph graph, int id)
{
    JRB node = jrb_find_int(graph.Vertex, id);
    if(node == NULL)
    {
        return NULL;
    }
    else
    {
        return jval_s(node->val);
    }
}

void addEgdeConLai(Graph graph)
{
    JRB node1 = NULL, node2 = NULL;
    jrb_traverse(node1, graph.Vertex)
    {
        if(jrb_find_int(graph.Egde, jval_i(node1->key)) == NULL)
        {
            JRB dsKe = make_jrb();
            jrb_insert_int(graph.Egde, jval_i(node1->key), new_jval_v(dsKe));
        }
    }
}

void InCase2(Graph graph)
{
    JRB node1 = NULL, node2 = NULL;
    jrb_traverse(node1, graph.Egde)
    {
        printf("%d %s\n", jval_i(node1->key), getVertex(graph, jval_i(node1->key)));
        
    }
}


void In(Graph graph)
{
    JRB node1 = NULL, node2 = NULL;
    jrb_traverse(node1, graph.Egde)
    {
        printf("Dinh %d(%s):", jval_i(node1->key), getVertex(graph, jval_i(node1->key)));
        jrb_traverse(node2, ((JRB)jval_v(node1->val)))
        {
            printf("  %d(%d)", jval_i(node2->key), jval_i(node2->val));
        }
        printf("\n");
    }
}


