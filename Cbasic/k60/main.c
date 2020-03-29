#include "graph.h"
#include "fields.h"
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
void Read_File(Graph g)
{
	FILE *file;
	int ID;
	char name[100];
	if((file=fopen("products.txt","r+")) == NULL) exit(0);
	while(1)
	{
		if(feof(file)) break;
		fscanf(file,"%d%*c%s",&ID,name);
		addVertex(g,ID,strdup(name));
	}
	IS is = new_inputstruct("orderhistory.txt");
	if(is == NULL) exit(0);
	while(get_line(is) > 0)
	{
		for(int i=0 ; i<is->NF; i++)
			for(int j=i+1; j< is->NF; j++)
			{
				addEdgenoW(g,atoi(is->fields[i]),atoi(is->fields[j]));
				addEdgenoW(g,atoi(is->fields[j]),atoi(is->fields[i]));
			}
	}
	fclose(file);
	jettison_inputstruct(is);
}

void Lich_su_giao_dich(Graph g)
{
	JRB node;
	int a;
	IS is = new_inputstruct("orderhistory.txt");
	while(get_line(is)>0)
	{
		for(int i=0; i<is->NF; i++)
		{
			node = jrb_find_int(g.vertices,atoi(is->fields[i]));
			printf("%s  ",node->val.s );
		}
		printf("\n");
	}
	jettison_inputstruct(is);
}

int main()
{
    Graph g = createGraph();
    JRB node;
    Read_File(g);
    int choice;
    do
    {
        printf("\n------------MENU-------------\n");
        printf("1.In danh sach san pham\n"
               "2.In sanh sach giao dich\n"
               "3.Hien thi muc do lien quan giua 2 san pham\n"
               "4.In danh sach cac san pham lien quan\n"
               "5.Hien thi moi lien he giua hai san pham\n"
               "6.Ket thuc chuong trinh\n");
        printf("Ban chon :");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                jrb_traverse(node,g.vertices)
                {
                    printf("Ma san pham :%d\n",node->key.i);
                    printf("Ten san pham :%s\n",jval_s(node->val));
                    printf("\n");
                }
                break;
            case 2:
                Lich_su_giao_dich(g);
                break;
            case 3:
            {    
            int ID1, ID2;
            printf("Nhap ID1: ");
            scanf("%d", &ID1);
            printf("Nhap ID2: ");
            scanf("%d", &ID2);
            node = jrb_find_int(g.edges,ID1);
				if(node == NULL) printf("-1\n");
				else 
				{
					JRB tree = (JRB) node->val.v;
					JRB tmp = jrb_find_int(tree,ID2);
					if(tmp == NULL) printf("-1\n");
					else printf("Do lien quan giua 2 san pham: %.0lf\n",tmp->val.d );
				}
            }
                break;
            case 4:
            {   
                int ID1;
                printf("Nhap ma san pham : ");
				scanf("%d",&ID1);
				node = jrb_find_int(g.edges,ID1);
				if(node == NULL) 
				{
					printf("Khong co san pham nao lien quan\n");
					break;
				}
				JRB tree = (JRB) jval_v(node->val);
                JRB tmp;
				printf("Cac san pham lien quan:  ");
				jrb_rtraverse(tmp,tree)
				{
					node = jrb_find_int(g.vertices,tmp->key.i);
					printf("%s  ",node->val.s );
				}
				printf("\n");
				
            }
               break;
            case 5:
            {
            int ID1, ID2;
            printf("Nhap id1: ");
            scanf("%d", &ID1);
            printf("Nhap id2: ");
            scanf("%d", &ID2);
            int path[1000];
            int cnt = shortestPath_s_To_t(g, ID1, ID2, path);
            if (cnt == 0)
                printf("Hai san pham khong co lien he voi nhau!\n");
            else
            {
                for (int i = 0; i < cnt; i++)
                {
                    printf("%s ", getVertex(g, path[i]));
                }
            }
            printf("\n");
            cnt = DFS(g, ID1, ID2, path);
            if (cnt == 0)
                printf("Hai san pham khong lien he voi nhau!\n");
            else
                for (int i = 0; i < cnt; i++)
                {
                    printf("%s ", getVertex(g, path[i]));
                }
            }
            break;
            case 6:
               printf("Ket thuc chuong trinh\n");
               break;
            default:
            printf("Nhap lai!");
            break;
        }
    } while (choice!=6);
    dropGraph(g);
    return 0;
}