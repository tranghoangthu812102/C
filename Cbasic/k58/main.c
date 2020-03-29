#include "graph.h"
#include "fields.h"

void Readfile(Graph G,char *filename)
{
    IS is = new_inputstruct(filename);
    if(is == NULL)
    {
        printf("ERROR!!!\n");
        exit(0);
    }

    get_line(is);
    int n = atoi(is->fields[0]);
    int m = atoi(is->fields[1]);

    for(int i = 0 ; i< n;i++)
    {
        get_line(is);
        addVertex(G,atoi(is->fields[1]),strdup(is->fields[0]));
    }
    for(int i = 0; i< m;i++)
    {
        get_line(is);
        addEdge(G,atoi(is->fields[0]),atoi(is->fields[1]),1);
    }
    jettison_inputstruct(is);
}

int checkArgc(int argc,char *argv[])
{
    if(argc == 2 && strcmp(argv[1] ,"help") == 0 )
     return 1;
    if(argc == 2 && strcmp(argv[1] ,"about") == 0 )
     return 2;
    if(argc == 4 && strcmp(argv[1] ,"i2n") == 0 )
     return 3;
    if(argc == 4 && strcmp(argv[1] ,"n2i") == 0 )
     return 4;
    if(argc == 5 && strcmp(argv[1] ,"cc") == 0 )
     return 5;
    if(argc == 5 && strcmp(argv[1] ,"cr") == 0 )
     return 6;
    if(argc == 4 && strcmp(argv[1] ,"odg") == 0 )
     return 7;
    if(argc == 4 && strcmp(argv[1] ,"rel") == 0 )
     return 8;
    return 0;
}

int main(int argc,char const *argv[])
{
    int check_Argc = checkArgc(argc,argv);
    if(check_Argc == 0)
    {
        printf("ERROR \n");
        exit(1);
    }

    Graph G = createGraph();
    JRB node,tree,tmp;
    Readfile(G,"data.txt");

    switch (check_Argc)
    {
    case 1:
        printf("Support command : help,i2n,n2i,cc,cr,odg,rel.\n");
        break;
    case 2:
        printf("C advanced 20192 final exam.\n");
        break;
    case 3:
        {
            node = jrb_find_int(G.vertices,atoi(argv[3]));
            if(node == NULL)
              printf("Khong ton tai an pham co id la %d\n",atoi(argv[3]));
            else
                printf("%s\n",node->val.s);
        }
        break;
    case 4:
        {
            int x =0;
            jrb_traverse(node,G.vertices)
            if(strcmp(node->val.s,argv[3]) == 0)
                {
                     printf("%d\n",node->key.i);
                     x = 1;
                     break;
                }
             if(x == 0)
                printf("Khong ton tai an pham nay trong danh sach\n");
        }
        break;
    case 5:
        {
           int ID1 = atoi(argv[3]);
           int ID2 = atoi(argv[4]);
           int output[100],out;
           int input[100],in;
           out = outdegree(G,ID1,output);
           int save[100],cnt_save = 0;
           for(int i = 0; i < out ; i++)
           {
               in = indegree(G,output[i],input);
               for(int j=0; j < in; j++)
                 if(input[j] == ID2)
                   save[cnt_save++] = output[i];
           }
           for(int i = 0; i< cnt_save ; i++)
                printf("%s\n", getVertex(G,save[i]));
        }
        break;
    case 6:
        {
           int ID1 = atoi(argv[3]);
           int ID2 = atoi(argv[4]);
           int output[100],out;
           int input[100],in;
           out = indegree(G,ID1,output);
           int save[100],cnt_save = 0;
           for(int i = 0; i < out ; i++)
           {
               in = outdegree(G,output[i],input);
               for(int j=0; j < in; j++)
                 if(input[j] == ID2)
                   save[cnt_save++] = output[i];
           }
           for(int i = 0; i< cnt_save ; i++)
                printf("%s\n", getVertex(G,save[i]));
 
        }
    break;
    case 7:
        {
            int value = atoi(argv[3]);
            int output[100];
            jrb_traverse(node,G.vertices)
            {
                if(outdegree(G,jval_i(node->key),output) > value)
                 printf("%s\n",jval_s(node->val));
            }
        }
    break;
    case 8:
    {
        int ID = atoi(argv[3]);
        int output[100],output2[100];
        int out,out2;
        
        out = outdegree(G,ID,output);
        for(int i = 0; i < out ; i++)
        {
            printf("%s\n",getVertex(G,output[i]));
            out2 = outdegree(G,output[i],output2);
            for(int i = 0 ; i< out2 ; i++)
            {
                printf("%s\n",getVertex(G,output2[i]));
            }
        } 
    }
    break;
    default:
        break;
    }
    dropGraph(G);
    return 0;
}