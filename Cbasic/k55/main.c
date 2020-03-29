#include "graph.h"
#include "fields.h"

void readFile(Graph g, char *filename);
int vertexToNum(char *str);
int cvPre(Graph g, int CV_pre[], int ID);

int cvPre(Graph g, int CV_pre[], int ID)
{
    int visited[1000] = {};
    int output[100], save[1000], u, cnt = 0;
    Dllist queue = new_dllist();
    dll_append(queue,new_jval_i(ID));
    while(!dll_empty(queue))
    {
        Dllist node = dll_first(queue);
        u = jval_i(node->val);
        dll_delete_node(node);

        if(!visited[u])
           CV_pre[cnt++] = u;
        visited[u] = 1;
        int n = indegree(g, u,output);
        for(int i = 0; i < n; i++)
        {
            int v = output[i];
            dll_append(queue,new_jval_i(v));
        }
    }
    return cnt;
}
int vertexToNum(char *str)
{
    int number = strlen(str);
    char *num = (char *)malloc(sizeof(char) * number);
    for (int i = 0; i < number - 1; i++)
    {
        num[i] = str[i + 1];
    }
    num[number - 1] = '\0';
    return number = atoi(num);
}

void readFile(Graph g, char *filename)
{
    IS is = new_inputstruct(filename);
    if(is == NULL)
    {
        printf("ERROR!!!\n");
        exit(1);
    }

    while(get_line(is) > 0)
    {
        int time;
        const char s[2] = "-";
        char *Vertex = (char *)malloc(sizeof(char) * strlen(is->fields[0]));
        strcpy(Vertex , is->fields[0]);
        int ID = vertexToNum(Vertex);
        addVertex(g,ID,Vertex);

        for(int i =2; i< is->NF ; i++)
        {
            char *first = strtok(is->fields[i],s);
            int ID2 = vertexToNum(first);
            time = atoi(strtok(NULL,s));
            addEdge(g,ID2,ID,time);
        }
    }
}


int main()
{
    Graph g = createGraph();
    JRB node;
    int choice;
    
    do
    {
        printf("\n======================\n");
        printf("1.Doc du lieu\n");
        printf("Ban chon : ");
        scanf("%d",choice);
        switch(choice)
        {
            case 1:
            {
              readFile(g,"data.txt");
              printf("So dinh: %d\n",getNumofVertex(g));
              printf("So canh: %d\n",getNumofEdge(g));
            }
            break;
            case 2:
            {
                printf("Nhap cong viec: ");
                char CV[100];
                scanf("%s",CV);
                int ID = vertexToNum(CV);

                JRB find = jrb_find_int(g.vertices,ID);
                if(find == NULL)
                   printf("Khong co cong viec!\n");
                else
                {
                    int output[1000],CV_pre[1000];
                    int value = indegree(g,ID, output);
                    printf("So luong cong viec ngay truoc: %d\n",value);
                    printf("Danh sach cong viec: ");
                    for(int i = 0; i< value ; i++)
                       printf("%s ",getVertex(g,output[i]));
                    printf("\n");

                    int CVnum = cvPre(g, CV_pre, ID);
                printf("So cong viec truoc la: %d\n", CVnum - value);
                printf("Danh sach cong viec: ");
                for (int i = value; i < CVnum; i++)
                    printf("%s ", getVertex(g, CV_pre[i]));
                }
            }
            break;
            case 4:
            {
                int output[100];
                int cnt = topologicalSort(g,output);
                for(int i = 0; i < cnt ; i++)
                 printf("%s", getVertex(g, output[i]));
            }
            break;
        }
        
    } while (choice!=0);
    

}