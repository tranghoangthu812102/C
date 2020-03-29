#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"jrb.h"
#include"jval.h"
#include"dllist.h"
#include"fields.h"
#include"graph.h"

void addEdgenoW(Graph map, int a1, int a2)
{
	JRB node, tree;
	node = jrb_find_int(map.edges,a1);
	if(node == NULL)
	{
		tree = make_jrb();
		jrb_insert_int(map.edges,a1,new_jval_v(tree));
	}
	else  tree = (JRB) (node->val.v);
	node = jrb_find_int(tree,a2);
	if(node == NULL)
		jrb_insert_int(tree,a2,new_jval_d(1));
	else
	{
		node->val.d++;
	} 
}
void Read_File(Graph map)
{
	FILE *f;
	int id;
	char name[100];
	if((f=fopen("products.txt","r+")) == NULL) exit(0);
	while(1)
	{
		if(feof(f)) break;
		fscanf(f,"%d%*c%s",&id,name);
		addVertex(map,id,strdup(name));
	}
	IS is = new_inputstruct("orderhistory.txt");
	if(is == NULL) exit(0);
	while(get_line(is) > 0)
	{
		for(int i=0 ; i<is->NF; i++)
			for(int j=i+1; j< is->NF; j++)
			{
				addEdgenoW(map,atoi(is->fields[i]),atoi(is->fields[j]));
				addEdgenoW(map,atoi(is->fields[j]),atoi(is->fields[i]));
			}
	}
	fclose(f);
	jettison_inputstruct(is);
}
void TimDuong(Graph map, int a1, int a2)
{
	JRB node;
	int output[100],p[100],visited[100] ={0};
	int n,i,v, u = 0;
	Dllist queue, tmp;
 	p[a1] = a1;
 	visited[a1] = 1;
   //Bo sung tat ca cac dinh cua do thi vao hang doi Q:
   queue = new_dllist();
	node = jrb_find_int(map.edges,a1);
    dll_append(queue, new_jval_i(jval_i(node->key)));
    while(!dll_empty(queue))
    {
    	tmp = dll_first(queue);
    	u = jval_i(tmp->val);
    	dll_delete_node(tmp);
    	if(u==a2) break;
    	n = outdegree(map, u, output);
    	for(i=0;i<n;i++)
    	{
    		v = output[i];
    		if(visited[v] == 0)
    		{
    			dll_append(queue, new_jval_i(v));
    			visited[v] = 1;
    			p[v] = u;
    		}
    	}
    }
    if(u!= a2) printf("Hai san pham nay khong co lien he voi nhau\n");
    else 
    {
    	while(1)
    	{
    		node = jrb_find_int(map.vertices,u);
    		printf("%s - ",node->val.s );
    		if(u == p[u]) break;
    		u = p[u];
    	}
    }
    free_dllist(queue);
}
void Lich_su_giao_dich(Graph map)
{
	JRB node;
	int a;
	IS is = new_inputstruct("orderhistory.txt");
	while(get_line(is)>0)
	{
		for(int i=0; i<is->NF; i++)
		{
			node = jrb_find_int(map.vertices,atoi(is->fields[i]));
			printf("%s  ",node->val.s );
		}
		printf("\n");
	}
	jettison_inputstruct(is);
}
int main(int argc, char const *argv[])
{
	Graph map = createGraph();
	JRB node, tree, tmp, n;
	int output[100] = {0};
	int dem = 0;
	int id1,id2;
	Read_File(map);
	int menu;
	do
	{
		printf("\n********HELLO MASTER**********\n\n");
		printf(" 1/In danh sach san pham\n "
              "2/in danh sach giao dich\n 3/hien thi muc do lien quan cua 2 san pham\n 4/in danh sach cac san pham lien quan\n 5/Hien thi moi quan he giua cac san pham\n 6/exit\n");
		scanf("%d",&menu);
		switch(menu)
		{
			case 1:
				jrb_traverse(node,map.vertices)
				{
					printf("Ma san pham: %d\n",node->key.i );
					printf("Ten san pham: %s\n",node->val.s );
					printf("\n");
				}
				break;
			case 2:
				Lich_su_giao_dich(map);
				break;
			case 3:
				printf("Nhap ma san pham 1: \n");
				scanf("%d",&id1);
				printf("Nhap ma san pham 2: \n" );
				scanf("%d",&id2);
				node = jrb_find_int(map.edges,id1);
				if(node == NULL) printf("-1\n");
				else 
				{
					tree = (JRB) node->val.v;
					tmp = jrb_find_int(tree,id2);
					if(tmp == NULL) printf("-1\n");
					else printf("Do lien quan giua 2 san pham: %.0lf\n",tmp->val.d );
				}
				break;
			case 4:
				printf("Nhap ma san pham : \n");
				scanf("%d",&id1);
				node = jrb_find_int(map.edges,id1);
				if(node == NULL) 
				{
					printf("Khong co san pham nao lien quan\n");
					break;
				}
				tree = (JRB) node->val.v;
				printf("Cac san pham lien quan:  ");
				jrb_rtraverse(tmp,tree)
				{
					node = jrb_find_int(map.vertices,tmp->key.i);
					printf("%s , ",node->val.s );
				}
				printf("\n");
				break;
			case 5:
				printf("Nhap ma san pham 1: \n");
				scanf("%d",&id1);
				printf("Nhap ma san pham 2: \n");
				scanf("%d",&id2);
				TimDuong(map,id2,id1);
		}
	}while(menu!=6);
	dropGraph(map);
	return 0;
}