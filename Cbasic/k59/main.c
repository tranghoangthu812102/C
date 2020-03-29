#include "graph.h"
#include "fields.h"

#define INFINITIVE_VALUE 9999

int checkArgc(int argc , char *argv[])
{
    if(argc == 2 && strcmp(argv[1] ,"-h") == 0 )
     return 1;
    if(argc == 3 && strcmp(argv[1] ,"-v") == 0 )
     return 2;
    if(argc == 5 && strcmp(argv[1] ,"-w") == 0 )
     return 3;
    if(argc == 5 && strcmp(argv[1] ,"-p") == 0 )
     return 4;
    if(argc == 4 && strcmp(argv[1] ,"-n") == 0 )
     return 5;
    if(argc == 5 && strcmp(argv[1] ,"-s") == 0 )
     return 6;
    return 0;
}

void readFile(Graph IP , char *filename )
{
    IS is = new_inputstruct(filename);
    if(is == NULL)
    {
        printf("ERROR!!!\n");
        exit(0);
    }
    get_line(is);
    int m = atoi(is->fields[0]);
    
    for(int i = 0; i < m ; i++)
    {
        get_line(is);
        addVertex(IP,atoi(is->fields[0]),is->fields[1]);
    } 
    
    get_line(is);
    int n = atoi(is->fields[0]);
    for(int i = 0; i < n ; i++)
    {
        get_line(is);
        addEdge(IP,atoi(is->fields[0]),atoi(is->fields[1]),atoi(is->fields[2])) ;
    } 
    jettison_inputstruct(is);
}

int main(int argc, char *argv[])
{
    int check_Argc = checkArgc(argc,argv);
    if(check_Argc == 0)
    {
        printf("ERROR \n");
        exit(2);
    }

    Graph IP = createGraph();
    JRB node,tree,tmp;

    readFile(IP, "demo.txt");
    int sl;
    switch(check_Argc)
    {
        case 1:
           printf("C-Advanced, HK20152\n");
           break;
        case 2:
           {
            jrb_traverse(node,IP.vertices)
            printf("%-3d %-10s\n",node->key.i,node->val.s);
           }
            break;
        case 3:
        {
          int ID1,ID2;
          ID1 = atoi(argv[3]);
          ID2 = atoi(argv[4]);

          double value = getEdgeValue(IP,ID1,ID2);
          if(value == INFINITIVE_VALUE)
             printf("-1\n");
          else
          {
              printf("Khoang cach giua %d va %d la :%.lf\n",ID1,ID2,value);
          }
          
        }
           break;
        case 4:
        {
            int ID1, ID2;
            ID1 = atoi(argv[3]);
            ID2 = atoi(argv[4]);

        int path[1000];
        int numVer;
        double value = shortestPath(IP, ID1, ID2, path, &numVer);

        if (value == INFINITIVE_VALUE)
            printf("-1\n");
        else
        {
            printf("\nKhoang cach: %.01f\n", value);
            for (int i = 0; i < numVer; i++)
            {
                printf("%s\n", getVertex(IP, path[i]));
            }
        }
        }
        break;
        case 5:
        { 
            int ID = atoi(argv[3]);
            int output[1000];
            int cnt = outdegree(IP,ID,output);
            if(cnt<= 0)
              printf("Khong co duong truyen di may nao ca!\n");
            else
            {
                printf("\n%d\n",cnt);
                for(int i= 0 ; i< cnt; i++)
                {
                    printf("%d %s %.0f\n", output[i],getVertex(IP,output[i]),getEdgeValue(IP,ID,output[i]));
                }
            }
        }
        break;
        default:
        break;
    }

    dropGraph(IP);
    return 0;
}

