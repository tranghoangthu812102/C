#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "jrb.h"
#include "fields.h"
#include "graph.h"
#define INFINITIVE 99999
JRB SanPham(char *filename, int *soluong)
{
	JRB sp = make_jrb();
	IS is = new_inputstruct(filename);
	if(is==NULL)
	{
		printf("kiem tra lai file %s\n",filename );
		exit(0);
	}
	fscanf(is->f,"%d%*c",soluong);
	while(get_line(is) >0)
	{
		jrb_insert_int(sp,atoi(is->fields[1]),new_jval_s(strdup(is->fields[0])));
	}
	jettison_inputstruct(is);
	return sp;
}
void hihi(JRB map, int d1, int d2,int weight)
{
	JRB tree,node;
	node = jrb_find_int(map,d1);
	if(node == NULL){
		tree = make_jrb();
		jrb_insert_int(map,d1,new_jval_v(tree));
	}
	else tree = (JRB) node->val.v;
	
	jrb_insert_int(tree,d2,new_jval_i(weight));
}
int KhoangCach(char *filename, int x1, int x2, JRB map)
{
	map = make_jrb();
	IS is = new_inputstruct(filename);
	int sokho;
	fscanf(is->f,"%d%*c",&sokho);
	while(1)
	{
		get_line(is);
		if(is->NF == 1) break;
	}
	int d1,d2, weight;
	while(get_line(is)>0)
	{
		d1 = atoi(is->fields[0]);
		d2 = atoi(is->fields[1]);
		weight = atoi(is->fields[2]);
		hihi(map,d1,d2,weight);
		hihi(map,d2,d1,weight);
	}
	jettison_inputstruct(is);

	JRB node = jrb_find_int(map,x1);
	if(node == NULL) return -1;
	JRB tree = (JRB) node->val.v;
	node = jrb_find_int(tree,x2);
	if(node == NULL) return -1;
	return node->val.i;
}
Graph KiemHang(char *filename1,int sosp)
{
	int sokh;
	IS is = new_inputstruct(filename1);
	Graph map = createGraph();
	fscanf(is->f,"%d%*c",&sokh);
	for(;sokh>0 ;sokh--)
	{
		get_line(is);
		int khoso = atoi(is->fields[1]);
		addVertex(map ,khoso ,strdup(is->fields[0]));
		for(int i=0 ;i<sosp ;i++ )
		{
			get_line(is);
			addEdge(map,khoso,atoi(is->fields[0]),atoi(is->fields[1]));
		}
	}
	jettison_inputstruct(is);
	return map;
}
int main(int argc, char const *argv[])
{
	int sosp;
	Graph map;
	JRB spham;
	JRB khohang;
	JRB node, tmp, tree, sp;
	int soluong, id,kho,kho2,kc;
	switch (argc)
	{

		case 2:
			printf("C-Advanced, HK20192\n");
			return 0;
		case 3:
			spham = SanPham(argv[2],&sosp);
			printf("%-20s%-20s\n","Ten san pham","ID" );
			jrb_traverse(tmp,spham)
			{
				printf("%-20s%-20d\n",tmp->val.s,tmp->key.i );
			}
			break;
		case 4:
			spham = SanPham(argv[3],&sosp);
			map = KiemHang(argv[2],sosp);
			jrb_traverse(node,map.edges)
			{
				jrb_traverse(tmp,map.vertices)
					if(tmp->key.i == node->key.i)
						printf("%s\n", tmp->val.s);
				tree = (JRB) node->val.v;
				jrb_traverse(tmp,tree)
				{
					jrb_traverse(sp,spham)
						if(sp->key.i == tmp->key.i)
							printf("%-20s%-10d\n",sp->val.s,tmp->val.i );
				}
				printf("----------\n");
			}
			break;
		case 5:
			kc = KhoangCach(argv[2],atoi(argv[3]), atoi(argv[4]), khohang);
			if(kc == -1 )printf("%d\n",kc );
			else printf("%d km\n", kc);
			jrb_free_tree(khohang);
			return 0;
		case 6:
			kho = atoi(argv[5]);
			id = atoi(argv[4]);
			spham = SanPham(argv[3],&sosp);
			map = KiemHang(argv[2],sosp);
			tmp = jrb_find_int(map.vertices,kho);
			printf("%s\n",tmp->val.s );
			tmp = jrb_find_int(spham,id);
			printf("%s   ",tmp->val.s );
			node = jrb_find_int(map.edges,kho);
			tree = (JRB) node->val.v;
			node = jrb_find_int(tree,id);
			printf("%d\n",node->val.i );
		
			printf("-----Cac kho ke: \n");
			jrb_traverse(node,map.edges)
			{
				if(node->key.i == kho ) continue;
				jrb_traverse(tmp,map.vertices)
					if(tmp->key.i == node->key.i)
						printf("%s\n", tmp->val.s);

				tree = (JRB) node->val.v;
				jrb_traverse(tmp,tree)
				{
					if(tmp->key.i != id) continue;
					jrb_traverse(sp,spham)
						if(sp->key.i == tmp->key.i)
							printf("%-20s%-10d\n",sp->val.s,tmp->val.i );
				}	
			}
			break;
		case 8:
			spham = SanPham(argv[3],&sosp); 
			map = KiemHang(argv[2],sosp);
			soluong = atoi(argv[5]);
			id = atoi(argv[4]);
			kho = atoi(argv[6]);
			kho2 = atoi(argv[7]);
			node = jrb_find_int(map.edges,kho);
			tree = (JRB) node->val.v;
			tmp = jrb_find_int(tree,id);
			int a = tmp->val.i;
			if(a >= soluong) 
				printf("Dang ky thanh cong @@ Xin quy khach cho 30ph\n");
			else
			{
				node = jrb_find_int(map.edges,kho2);
				tree = (JRB) node->val.v;
				tmp = jrb_find_int(tree,id);
				if(tmp->val.i + a >= soluong )
				{
					kc = KhoangCach(argv[2],kho2, kho, khohang);
					int phut = (kc*2+30)%60;
					int gio = (kc*2+30)/60;
					printf("Dang ky thanh cong @@ Xin quy khach cho %dgio%dph \n",gio, phut);
				}
				else printf("Dang ky khong thanh cong\n");
			}
			break;
		default : printf("Moi ban nhap dung cau truc \n");
	}
	dropGraph(map);
	jrb_free_tree(spham);
	return 0;
}