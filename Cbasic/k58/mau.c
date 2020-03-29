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
void readFile(FILE *taptin, Graph graph, int table[]);
Graph createGraph();
void addVertex(Graph graph, int id, char* name);
void addEdge(Graph graph, int v1, int v2, int trongSo);
void In(Graph graph, int table[]);
char *getVertex(Graph graph, int id);
int indegree(Graph graph, int v, int* output);
int outdegree(Graph graph, int v, int* output);
void addEgdeConLai(Graph graph);
int convertKeyToID(int key, int table[]);//key la chua convert, id la de nhet vao graph
int convertIDToKey(int id, int table[]);
void dijkstra(Graph graph, int v1, int v2, void (* func)(Graph, int , int , int *, int *, int *));
int getTrongSo(Graph graph, int v1, int v2);
void updateD(Graph graph, Dllist Qmin, JRB node2, int *d, int *parents);
Dllist findQmin(Dllist queue, int *d);
void InCase4(Graph graph, int v1, int v2, int *d, int *parents, int *soPT);//khogn can dung v2


int main(int argc, char *argv[])
{
    int luaChon;
    int *output1 = malloc(100*sizeof(int));
    int *output2 = malloc(100*sizeof(int)), dinh[size][size];
    int table[20] = {};
    int i1, j1, tmp, n1, n2;
    Graph graph = createGraph();
    FILE *taptin;
    //taptin = fopen("input.txt", "r+");
    if(argc > 2)
    {
    
   		taptin = fopen(argv[2], "r+");
	}
    JRB node1 = NULL, node2 = NULL;
    if(taptin != NULL)
    {
    	luaChon = readLenh(argc, argv);
        readFile(taptin, graph, table);
        switch(luaChon)
        {
            case 1:
            {
                printf("Supported command: help, i2n, n2i, cc, cr, odg, rel.\n");
                break;
            }
            case 2:
            {
				printf("C advanced 20142 final exam.\n");
                break;
            }
            case 3:
            {
            	tmp = convertKeyToID(atoi(argv[3]), table);
				printf("%s\n", getVertex(graph, tmp));
                break;
            }
            case 4:
            {
            	dijkstra(graph, convertKeyToID(atoi(argv[3]), table), -1, InCase4);
				
                break;
            }
            case 5:
            {
				jrb_traverse(node1, graph.Vertex)
				{
					if(strcmp(jval_s(node1->val), argv[3]) == 0)
					{
					
						printf("%d\n", convertIDToKey(jval_i(node1->key), table));
					}
				}
                break;
            }
            case 6:
            {
            	jrb_traverse(node1, graph.Vertex)
				{
					if(outdegree(graph, jval_i(node1->key), output1) > atoi(argv[3]))
					{
						printf("%s\n", jval_s(node1->val));
					}
				}
				
                break;
            }
            case 7:
            {
				n1 = outdegree(graph, convertKeyToID(atoi(argv[3]), table), output1);
				n2 = outdegree(graph, convertKeyToID(atoi(argv[4]), table), output2);
				for(i1 = 0; i1 < n1; i1++)
				{
					for(j1 = 0; j1 < n2; j1++)
					{
						if(output1[i1] == output2[j1])
						{
							printf("%s\n", getVertex(graph, output1[i1]));
						}
				
					}
				}
                break;
            }
            case 8:
            {
				n1 = indegree(graph, convertKeyToID(atoi(argv[3]), table), output1);
				n2 = indegree(graph, convertKeyToID(atoi(argv[4]), table), output2);
				for(i1 = 0; i1 < n1; i1++)
				{
					for(j1 = 0; j1 < n2; j1++)
					{
						if(output1[i1] == output2[j1])
						{
							printf("%s\n", getVertex(graph, output1[i1]));
						}
					}
				}
                break;
            }
        }
        //printf("\n");
       	//In(graph, table);
        fclose(taptin);
    }
    else
    {
        printf("ERROR\n");
    }
    return 0;
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
	if(strcmp(argv[0], "./main") != 0)
	{
		printf("Ten file bi sai\n");
		exit(1);
	}
	if(argc == 2)
	{
		if(strcmp(argv[1], "help") == 0)// ./pr help
		{
			return 1;
		}
		else if(strcmp(argv[1], "about") == 0)// ./pr about
		{
			return 2;
		}
	}
	else if(argc == 4)
	{
		if(strcmp(argv[1], "i2n") == 0)// ./pr i2n file_name id
		{
			return 3;
		}
		else if(strcmp(argv[1], "rel") == 0)// ./pr rel file_name u
		{
			return 4;
		}
		else if(strcmp(argv[1], "n2i") == 0)// ./pr n2i file_name item_name
		{
			return 5;
		}
		else if(strcmp(argv[1], "odg") == 0)// ./pr odg file_name k
		{
			return 6;
		}
	}
	else if(argc == 5)
	{
		if(strcmp(argv[1], "cc") == 0)// ./pr cc file_name i j
		{
			return 7;
		}
		else if(strcmp(argv[1], "cr") == 0)// 	./pr cr file_name i j
		{
			return 8;
		}
	
	}
}


void readFile(FILE *taptin, Graph graph, int table[])
{
	int Vertex, Egde;
	char tmp;
	fscanf(taptin, "%d", &Vertex);
	
	fscanf(taptin, "%c", &tmp);
	
	fscanf(taptin, "%d", &Egde);
	
	int i1;
	char ten[100];
	int key1, key2;//key nay la truoc khi convert
	for(i1 = 0; i1 < Vertex; i1++)//doc Vertex
	{
		fscanf(taptin, "%s", ten);
		//printf("'%s'  ", ten);
		
		fscanf(taptin, "%c", &tmp);
		
		fscanf(taptin, "%d", &key1);
		//printf("'%d'\n", key1);
		addVertex(graph, convertKeyToID(key1, table), strdup(ten));
		//printf("Da add dinh %d\n", convertKeyToID(key1, table));
	}
	for(i1 = 0; i1 < Egde; i1++)//doc Egde
	{
		fscanf(taptin, "%d", &key1);
		//printf("'%d'->", key1);
		
		fscanf(taptin, "%c", &tmp);
		
		fscanf(taptin, "%d", &key2);
		//printf("'%d'\n", key2);
		addEdge(graph, convertKeyToID(key1, table), convertKeyToID(key2, table), 1);
	}
	addEgdeConLai(graph);
}

void addVertex(Graph graph, int id, char* name)
{
    JRB node = jrb_find_int(graph.Vertex, id);
    //printf("---'%s'\n", name);
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
            //printf("Khong co dinh %d\n", v1);
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
            jrb_insert_int((JRB)jval_v(node->val), v2, new_jval_i(trongSo));
        }
    }
}

void In(Graph graph, int table[])
{
    JRB node1 = NULL, node2 = NULL;
    jrb_traverse(node1, graph.Egde)
    {
        printf("Dinh %d:", convertIDToKey(jval_i(node1->key), table));
        jrb_traverse(node2, ((JRB)jval_v(node1->val)))
        {
            printf(" %d", convertIDToKey(jval_i(node2->key), table));
        }
        printf("\n");
    }
    printf("\n");
    jrb_traverse(node2, graph.Vertex)
    {
        printf("Dinh %d (%s)\n", convertIDToKey(jval_i(node2->key), table), jval_s(node2->val));
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


int convertKeyToID(int key, int table[])//key la chua convert, id la de nhet vao graph
{
    int i = 0;
    static int n = 0;
    for(i=0; i < n; i++)
    {
        if(table[i] == key)
        {
            return i;
        }
    }
    table[n] = key;
    n++;
    //printf("n:%d; %d\n\n", n, table[n-1]);
    return n-1;
}

int convertIDToKey(int id, int table[])
{
    if(id >= 0)//tranh coredumped
    {
        return table[id];
    }
}

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

int outdegree(Graph graph, int v, int* output)
{
    JRB node = jrb_find_int(graph.Egde, v);
    int n = 0;
    if(node == NULL)
    {
        printf("O-Khong co dinh %d\n", v);
    }
    else
    {
        JRB node1 = NULL;
        jrb_traverse(node1, ((JRB)jval_v(node->val)))
        {
            output[n] = jval_i(node1->key);
            n++;
        }
    }
    return n;
}


void InCase4(Graph graph, int v1, int v2, int *d, int *parents, int *soPT)//khogn can dung v2
{
    int i1;
    for(i1=0; i1 < *soPT; i1++)
    {
    	if(d[i1] <= 2 && d[i1] != 0)
    	{
    		printf("%s\n", getVertex(graph, i1));
    	}
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

void updateD(Graph graph, Dllist Qmin, JRB node2, int *d, int *parents)
{
    //printf("Xet %d: d: %d; new: %d\n", jval_i(node2->key), d[jval_i(node2->key)], (d[jval_i(Qmin->val)] + getTrongSo(graph, jval_i(Qmin->val), jval_i(node2->key))));
    if(d[jval_i(node2->key)] > (d[jval_i(Qmin->val)] + getTrongSo(graph, jval_i(Qmin->val), jval_i(node2->key))))
    {
        d[jval_i(node2->key)] = d[jval_i(Qmin->val)] + getTrongSo(graph, jval_i(Qmin->val), jval_i(node2->key));
        parents[jval_i(node2->key)] = jval_i(Qmin->val);
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
            printf("Dinh %d khong ton tai\n", v2);
            return 0;
        }
    }
    else
    {
        printf("Dinh %d khong ton tai\n", v1);
        return 0;
    }


}

void dijkstra(Graph graph, int v1, int v2, void (* func)(Graph, int , int , int *, int *, int *))
{
    int soPT = 0, i;
    int d[20] = {};
    int parents[20] = {};
    for(i=0; i<20; i++)
    {
        d[i] = VOCUC;
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
            updateD(graph, Qmin, node2, d, parents);
        }
        dll_delete_node(Qmin);
    }
    func(graph, v1, v2, d, parents, &soPT);
}


