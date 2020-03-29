#include "graph.h"

/*1.Tạo đồ  thị*/
Graph createGraph()
{
    Graph g;
    g.edges = make_jrb();
    g.vertices = make_jrb();
    return g;
}

/*2.Thêm 1 đỉnh mới vào đồ thị */
void addVertex(Graph g,int id, char *name)
{
     //Kiem tra xem dinh da ton tai tren do thi hay chua 
     JRB node = jrb_find_int(g.vertices,id);
     if(node == NULL)
     jrb_insert_int(g.vertices,id,new_jval_s(strdup(name)));
}

/*3.Ham tra ve 1 dinh thuoc do thi*/
char *getVertex(Graph g , int id)
{
  JRB node = jrb_find_int(g.vertices,id);
  if(node == NULL)
    return NULL;
  else 
     return jval_s(node->val);
}

int getNumofVertex(Graph g)
{
    int count = 0;
    JRB node;
    jrb_traverse(node,g.vertices)
        count++;
    return count;
}

/*4.Ham tra ve gia tri 1 neu co canh (v1,v2), gia tri 0 neu khong co*/
int hasEdge(Graph g, int v1, int v2)
{
      JRB node = jrb_find_int(g.edges,v1); //Tim v1 trong cay do den edges
      if(node == NULL) return 0;
      //Kiem tra cay do den cua v1 co v2 khong
      JRB tree = (JRB)jval_v(node->val);//lay ra danh sach cac dinh ke voi v1
      if(jrb_find_int(tree,v2)== NULL)
            return 0;
      else 
            return 1;
      
}

/*5.Them canh (v1,v2) vao do thi*/
void addEdge(Graph graph, int v1, int v2, double weight)
{
     JRB node, tree;
     if (getEdgeValue(graph, v1, v2)==INFINITIVE_VALUE) //neu graph chua co canh (v1,v2)
     {
        node = jrb_find_int(graph.edges, v1); //tim dinh v1 tren tap canh graph.edges
        if (node==NULL) //neu graph.edges chua co dinh v1
		{
           tree = make_jrb();
           jrb_insert_int(graph.edges, v1, new_jval_v(tree)); //them v1 vao graph.edges
        }
		else //graph.edges da co dinh v1
            tree = (JRB) jval_v(node->val); //tree: caydoden cua dinh v1
        //them v2 vao caydoden tree cua dinh v1:
        jrb_insert_int(tree, v2, new_jval_d(weight));
     }
     //Neu 2 chieu!!
    //  if(getEdgeValue(graph , v2, v1) == INFINITIVE_VALUE)
    //      addEdge(graph,v2,v1,weight);

}

/*6.Hàm trả về trọng số của đồ thị */
double getEdgeValue(Graph graph, int v1, int v2)
{
    JRB node, tree;
    node = jrb_find_int(graph.edges, v1);
    if (node==NULL) //graph.edges chua co dinh v1==> graph ko co canh (v1, v2)
       return INFINITIVE_VALUE; //ko co canh (v1, v2) ==> trong so canh (v1, v2) = infinitive

	tree = (JRB) jval_v(node->val); //truy cap vao cay do den (chua danh sach ke) cua v1
    node = jrb_find_int(tree, v2); //tim v2 trong danh sach ke cua dinh v1
    if (node==NULL) //v2 khong ke voi v1
       return INFINITIVE_VALUE; //do do, graph ko co canh (v1, v2)
    else
       return jval_d(node->val); //truy cap vao truong val de lay trong so cua canh (v1, v2)
}

int getNumofEdge(Graph g)
{
    JRB node, node2;
    int cnt = 0;
    jrb_traverse(node,g.vertices)
    {
        jrb_traverse(node2,g.vertices)
        if(hasEdge(g,jval_i(node->key), jval_i(node2->key)))
          cnt++;
    }
    return cnt;
}
/*6.Ham tra ve ban bac vao cua dinh v*/
int indegree(Graph g,int v, int *output)
{
  JRB node, tree;
  int total =0;
  jrb_traverse(node,g.edges)
  {
      tree = (JRB)jval_v(node->val);
      if(jrb_find_int(tree,v) )
      {
          output[total] = jval_i(node->key);
          total++;
      }
  }
  return total;
}

/*7.Ham tra ve ban bac ra cua dinh v*/
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

/*8.Ham kiem tra do thi co chu trinh hay khong*/
/*Ham tra ve gia tri 1 neu khong phat hien ra chu trinh , gia tri 0 neu phat hien ra chu trinh*/
int DFS_DAG(Graph g ,int start )
{
    int visited[1000] ={};
    int out[100],i,u,v,n;
    Dllist node, stack;
    
    stack = new_dllist();
    dll_append(stack,new_jval_i(start));
    while(!dll_empty(stack))
    {
      node = dll_last(stack);
      u = jval_i(node->val);
      dll_delete_node(node);
      if(!visited[u])
      {
          visited[u]= 1;
          n= outdegree(g,u,out);
          for(i = 0; i<n; i++)//Xet lan luot cac domj ke voi dinh u
          { 
              v = out[i];
            if(v == start) return 0;
            if (!visited[v]) //thêm v vào queue nếu v chưa được thăm
                  dll_append(stack, new_jval_i(v));
          }
       }
    }
    return 1;
}
int DAG(Graph g)
{
    int start, notCycle;
    JRB vertex;
    jrb_traverse(vertex,g.vertices)
    {
        start = jval_i(vertex->key);
        //printf("Goi DFS xuat phat tu dinh %d \n",start);
        notCycle = DFS_DAG(g,start);
        if(notCycle == 0) return 0;
    }
    return 1;
}
/*12.Giai phong bo nho / xoa do thi*/
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

void swapArray(int arr[], int cnt)
{
    for (int i = 0; i < cnt / 2; i++)
    {
        int c = arr[i];
        arr[i] = arr[cnt - i - 1];
        arr[cnt - i - 1] = c;
    }
}

int topologicalSort(Graph graph, int *output)
{
    int indeg[1000], tmp[100];
    Dllist queue, node;
    queue = new_dllist();

    JRB vertex;
    jrb_traverse(vertex, graph.vertices)
    {
        int u = jval_i(vertex->key);
        indeg[u] = indegree(graph, u, tmp);
        if (indeg[u] == 0)
            dll_append(queue, new_jval_i(u));
    }

    int total = 0;
    while (!dll_empty(queue))
    {
        node = dll_first(queue);
        int u = jval_i(node->val);
        dll_delete_node(node);
        output[total++] = u;

        int m = outdegree(graph, u, tmp);
        for (int i = 0; i < m; i++)
        {
            int v = tmp[i];
            indeg[v]--;
            if (indeg[v] == 0)
                dll_append(queue, new_jval_i(v));
        }
    }
    swapArray(output , total);
    return total;
}

int DFS(Graph graph, int start, int stop, int *path)
{
    int visited[1000] = {};
    int output[100];
    int cnt = 0, u;
    int save[1000];
    Dllist stack = new_dllist();

    dll_append(stack, new_jval_i(start));

    while (!dll_empty(stack))
    {
        Dllist node = dll_last(stack);
        u = jval_i(node->val);
        dll_delete_node(node);

        if (!visited[u])
        {
            visited[u] = 1;
            if (u == stop)
                break;
            int n = outdegree(graph, u, output);
            for (int i = 0; i < n; i++)
            {
                int v = output[i];
                if (!visited[v])
                {
                    save[v] = u;
                    dll_append(stack, new_jval_i(v));
                }
            }
        }
    }
    if (u != stop)
        return 0;
    else
    {
        int i = stop;
        path[cnt++] = i;
        while (i != start)
        {
            i = save[i];
            path[cnt++] = i;
        }
        swapArray(path, cnt);
    }
    return cnt;
}

int shortest_noWeight_path(Graph graph, int start, int stop, int *path)
{
    JRB dist = make_jrb();
    Dllist node;

    Dllist queue = new_dllist();
    dll_append(queue, new_jval_i(start));

    Dllist trace = new_dllist();
    dll_append(trace, new_jval_i(start));
    jrb_insert_int(dist, start, new_jval_v(trace));

    int u;
    while (!dll_empty(queue))
    {
        node = dll_first(queue);
        u = jval_i(node->val);
        dll_delete_node(node);

        Dllist u_find_path = jval_v(jrb_find_int(dist, u)->val);
        if (u == stop)
        {
            int cnt = 0;
            Dllist tmp;
            dll_traverse(tmp, u_find_path)
            {
                cnt++;
                if (path != NULL)
                    path[cnt - 1] = jval_i(tmp->val);
            }
            return cnt;
        }

        int output[1000];
        int num = outdegree(graph, u, output);

        for (int i = 0; i < num; ++i)
        {
            JRB v_find = jrb_find_int(dist, output[i]);
            if (v_find == NULL)
            {
                Dllist current_path = new_dllist();
                Dllist node;
                dll_traverse(node, u_find_path)
                    dll_append(current_path, node->val);

                dll_append(current_path, new_jval_i(output[i]));
                jrb_insert_int(dist, output[i], new_jval_v(current_path));
                dll_append(queue, new_jval_i(output[i]));
            }
        }
    }
    if (u != stop)
        return 0;
}

double shortestPath(Graph graph, int start, int stop, int *path, int *numVertices)
{
    double distance[1000];
    int previous[1000], u, visit[1000];

    for (int i = 0; i < 1000; i++)
    {
        distance[i] = INFINITIVE_VALUE;
        visit[i] = 0;
        previous[i] = 0;
    }
    distance[start] = 0;
    previous[start] = start;
    visit[start] = 1;

    Dllist ptr, queue, node;
    queue = new_dllist();
    dll_append(queue, new_jval_i(start));

    while (!dll_empty(queue))
    {
        double min = INFINITIVE_VALUE;
        dll_traverse(ptr, queue)
        {
            u = jval_i(ptr->val);
            if (min > distance[u])
            {
                min = distance[u];
                node = ptr;
            }
        }

        u = jval_i(node->val);
        visit[u] = 1;
        dll_delete_node(node);
        if (u == stop)
            break;

        int output[1000];
        int n = outdegree(graph, u, output);

        for (int i = 0; i < n; i++)
        {
            int v = output[i];
            double w = getEdgeValue(graph, u, v);
            if (distance[v] > distance[u] + w)
            {
                distance[v] = distance[u] + w;
                previous[v] = u;
            }
            if (visit[v] == 0)
            {
                dll_append(queue, new_jval_i(v));
            }
        }
    }

    double distance_s_t = distance[stop];
    int count = 0;
    if (distance[stop] != INFINITIVE_VALUE)
    {
        path[count++] = stop;
        while (stop != start)
        {
            stop = previous[stop];
            path[count++] = stop;
        }
        *numVertices = count;
    }
    swapArray(path, count);
    return distance_s_t;
}
double shortestPath_s_To_t(Graph g, int s, int t, int* p)
{
   double d[1000], k[1000], min, w;
   int n, output[100], i, u, v;
   Dllist ptr, node_min, queue;
   JRB node;

   for (i=0; i<1000; i++)
   {
       d[i] = INFINITIVE_VALUE;
       k[i] = 0; //chua tim duoc duong di tu s den i
   }
   d[s] = 0; p[s] = s;

   //Bo sung tat ca cac dinh cua do thi vao hang doi Q:
   queue = new_dllist();
   jrb_traverse(node, g.vertices)
       dll_append(queue, new_jval_i(jval_i(node->key)));

   while ( !dll_empty(queue) )
   {
      /* get u from the priority queue:
      Tim u la dinh co d[u] nho nhat trong so cac dinh thuoc queue*/
      min = INFINITIVE_VALUE + 1;
      dll_traverse(ptr, queue) //duyet qua tung dinh v cua queue, tim u la dinh co gia tri d nho nhat
      {
          v = jval_i(ptr->val);
          if (min > d[v])
          {
             min = d[v];
             node_min = ptr;
             u = v;
          }
      }
      k[u] = 1; //da tim duoc ddnn tu s den u
      dll_delete_node(node_min); //xoa u khoi queue vi da tim duoc ddnn tu s den u

      if (u == t) break; // stop at t

      n = outdegree(g, u, output);
      for (i=0; i<n; i++)
      {
          v = output[i];
          if (k[v] == 0) //neu van chua tim duoc ddnn tu s den v
          {
              w = getEdgeValue(g, u, v);
              if ( d[v] > d[u] + w ) //kiem tra xem co giam duoc ddnn tu s den v bang cach di qua canh (u, v) hay ko
              {
                 d[v] = d[u] + w;
                 p[v] = u;
              }
          }//end if
      }//end for
   }//end while
   return d[t];
}
/*10.Đường đi ngắn nhất từ đỉnh S đến tất cả các đỉnh còn lại */
void shortestPath_s_To_All(Graph g, int s, int* p, double *d)
{
   double k[1000], min, w;
   int n, output[100], i, u, v;
   Dllist ptr, node_min, queue;
   JRB node;

   for (i=0; i<1000; i++)
   {
       d[i] = INFINITIVE_VALUE;
       k[i] = 0; //chua tim duoc duong di tu s den i
   }
   d[s] = 0; p[s] = s;

   //Bo sung tat ca cac dinh cua do thi vao hang doi Q:
   queue = new_dllist();
   jrb_traverse(node, g.vertices)
       dll_append(queue, new_jval_i(jval_i(node->key)));

   while ( !dll_empty(queue) )
   {
      /* get u from the priority queue:
      Tim u la dinh co d[u] nho nhat trong so cac dinh thuoc queue*/
      min = INFINITIVE_VALUE + 1;
      dll_traverse(ptr, queue) //duyet qua tung dinh v cua queue, tim u la dinh co gia tri d nho nhat
      {
          v = jval_i(ptr->val);
          if (min > d[v])
          {
             min = d[v];
             node_min = ptr;
             u = v;
          }
      }
      k[u] = 1; //da tim duoc ddnn tu s den u
      dll_delete_node(node_min); //xoa u khoi queue vi da tim duoc ddnn tu s den u

//      if (u == t) break; // stop at t

      n = outdegree(g, u, output);
      for (i=0; i<n; i++)
      {
          v = output[i];
          if (k[v] == 0) //neu van chua tim duoc ddnn tu s den v
          {
              w = getEdgeValue(g, u, v);
              if ( d[v] > d[u] + w ) //kiem tra xem co giam duoc ddnn tu s den v bang cach di qua canh (u, v) hay ko
              {
                 d[v] = d[u] + w;
                 p[v] = u;
              }
          }//end if
      }//end for
   }//end while
  // return d[t];
}