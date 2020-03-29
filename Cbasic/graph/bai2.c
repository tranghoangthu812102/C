/*Danh sach ke*/
/*Dinh nghia lai cac ham API cho do thi su dung thu vien libfdr*/

#include <stdio.h>
#include <stdlib.h>
#include "jrb.h"

typedef JRB Graph;

/*1.Ham tao do thi*/
Graph createGraph()
{
   return make_jrb();
}

/*2.Neu dinh v1 ke voi v2 trong do thi g, ham tra ve gia tri 1,
neu khong tra ve gia tri 0*/
int adjacent(Graph g, int v1,int v2)
{
    JRB node, tree;
    //Kiem tra xem do thi g co chua dinh v1 hay khong?
    node = jrb_find_int(g,v1);
    if(node == NULL) return 0; //g khong co dinh v1
    /*do thi g co v1 : tiep tuc lay truong value(chua ds ke)cua 
    dinh v1 de kiem tra xem v1 co ke voi v2 hay ko*/
    tree = (JRB) jval_v(node->val);
    if(jrb_find_int(tree, v2)== NULL)
      return 0;
    else return 1;

}

/*3.Them canh(v1,v2) vao do thi g*/
/*Do thi vo huong , neu co huong chi can 1 lan!!!*/
void addEdge(Graph g, int v1, int v2)
{
    JRB node,tree;
    //1.Them canh(v1,v2)
    if(!adjacent(g,v1,v2)) //(v1,v2) chua co tren do thi
    {
        node = jrb_find_int(g,v1);//tim v1 tren g
        if(node == NULL) //g chua co v1
        {
            tree = make_jrb();//tao cay do den de luu tru danh sach ke cua dinh v1
            jrb_insert_int(g,v1,new_jval_v(tree));//them v1 vao g:truong key = v1,truong value = tree
            jrb_insert_int(tree,v2,new_jval_i(1));//them v2 vao danh sach cac dinh ke voi v1
        } 
        else
        {
            tree = (JRB) jval_v(node->val);//truy cap vao truong value cua dinh v1
            jrb_insert_int(tree,v2,new_jval_i(1));//de them v2 vao danh sach cac dinh ke voi v1
        }
    }
    //2.Them canh (v2,v1) 
    if(!adjacent(g,v2,v1)) //(v1,v2) chua co tren do thi
    {
        node = jrb_find_int(g,v2);//tim v1 tren g
        if(node == NULL) //g chua co v1
        {
            tree = make_jrb();
            jrb_insert_int(g,v2,new_jval_v(tree));
            jrb_insert_int(tree,v1,new_jval_v(1));
        } 
        else
        {
            tree = (JRB) jval_v(node->val);
            jrb_insert_int(tree,v1,new_jval_i(1));
        }
    }
}

/*4.Dua danh sach cac dinh ke voi dinh v vao mang output,
ham tra ve so luong dinh ke voi dinh v*/
int getAdjacentVertices(Graph g, int v, int* output)
{
    JRB node,tree;
    node = jrb_find_int(g,v);
    if(node == NULL) return 0;
      tree = (JRB) jval_v(node->val);
      //truy cap vao truong value cua dinh v~1 cay do den
    int total =0;
    //duyet cay do den cua dinh v,de dua ra cac dinh ke voi dinh v vao mang output
    jrb_traverse(node,tree)
       output[total++] = jval_i(node->key);
    return total;
}

/*5.Giai phong bo nho , xoa do thi g*/
void dropGraph(Graph g)
{
    JRB node,tree;
    //1.Xoa cay do den tung dinh
    jrb_traverse(node,g)
    {
       tree  = (JRB) jval_v(node->val);
       jrb_free_tree(tree);
    }
    //2.Xoa do thi
    jrb_free_tree(g);
}
int main()
{
    int i,n,output[100];
    Graph g = createGraph();
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