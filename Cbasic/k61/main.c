#include "graph.h"
#include "fields.h"

int checkArgc(int argc , char *argv[]);
int  readFileSanPham(char *filename , JRB sanpham);
void readFileKhoHang(Graph KhoHang , JRB sosanpham , char *filename , int m );

void kiemKe(Graph KhoHang , JRB sanpham , JRB sosanpham);
void kiemHang(Graph KhoHang , JRB sanpham , JRB sosanpham , int ID_SanPham , int ID_KhoHang);

int checkArgc(int argc,char *argv[])
{
    if(argc == 2 && strcmp(argv[1] ,"-t") == 0 )
     return 1;
    if(argc == 3 && strcmp(argv[1] ,"-s") == 0 )
     return 2;
    if(argc == 5 && strcmp(argv[1] ,"-w") == 0 )
     return 3;
    if(argc == 4 && strcmp(argv[1] ,"-a") == 0 )
     return 4;
    if(argc == 6 && strcmp(argv[1] ,"-h") == 0 )
     return 5;
    if(argc == 8 && strcmp(argv[1] ,"-g") == 0 )
     return 6;
    return 0;
}

int readFileSanPham(char *filename , JRB sanpham)
{
    IS is = new_inputstruct(filename);
    if(is == NULL)
    {
        printf("ERROR!!!\n");
        exit(0);
    }
    get_line(is);
    int m = atoi(is->fields[0]);

    while(get_line(is) > 0)
       jrb_insert_int(sanpham , atoi(is->fields[1]), new_jval_s(strdup(is->fields[0])));
    return m;
}

void readFileKhoHang(Graph KhoHang , JRB sosanpham , char *filename , int m )
{
    IS is = new_inputstruct(filename);
    if(is == NULL)
    {
        printf("ERROR!!!\n");
        exit(0);
    }
    get_line(is);
    int n = atoi(is->fields[0]);

    for(int i=1; i <=n ; i++)
    {
        get_line(is);
        JRB tp_sanpham = make_jrb();
        int ID_KhoHang = atoi(is->fields[1]);
        addVertex(KhoHang,ID_KhoHang,is->fields[0]);
        for(int j=1 ; j<= m ; j++)
        {
            get_line(is);
            jrb_insert_int(tp_sanpham,atoi(is->fields[0]),new_jval_i(atoi(is->fields[1])));
        }
        jrb_insert_int(sosanpham,ID_KhoHang,new_jval_v(tp_sanpham));
    }
    get_line(is);
    int k = atoi(is->fields[0]);
    while(get_line(is)>0)
      addEdge(KhoHang,atoi(is->fields[0]),atoi(is->fields[1]),atof(is->fields[2])); 
}

void kiemKe(Graph KhoHang , JRB sanpham , JRB sosanpham)
{
    JRB node , node1;
    jrb_traverse(node,KhoHang.vertices)
    {
        printf("-----------\n");
        int ID_KhoHang = jval_i(node->key);
        printf("%s\n",jval_s(node->val));

        JRB timSoSP  = jrb_find_int(sosanpham,ID_KhoHang);
        JRB tree = (JRB)jval_v(timSoSP->val);

        jrb_traverse(node1,tree)
        {
            JRB timSP = jrb_find_int(sanpham,jval_i(node1->key));
            printf("%s %d\n",jval_s(timSP->val),jval_i(node1->val));
        }

    }
}

void kiemHang(Graph KhoHang , JRB sanpham , JRB sosanpham , int ID_SanPham , int ID_KhoHang)
{
    JRB timKhoHang = jrb_find_int(KhoHang.vertices , ID_KhoHang );
    if(timKhoHang == NULL)
    {
        printf("Khong tim thay kho hang\n");
        exit(1);
    }
    JRB timSP = jrb_find_int(sanpham, ID_SanPham);
    if(timSP == NULL)
    {
        printf("Khong co san pham\n");
        exit(1);
    }

    printf("%s \n",jval_s(timKhoHang->val));
    JRB timSoSP = jrb_find_int(sosanpham,ID_KhoHang);
    JRB tree =  (JRB)jval_v(timSoSP->val);

    JRB timsoluong = jrb_find_int(tree, ID_SanPham);
    printf("%s %d\n",jval_s(timSP->val),jval_i(timsoluong->val));
    printf("------Cac Kho hang ke :\n");
    
    int luuKhoHang[1000];
    int SlKhoKe = outdegree(KhoHang,ID_KhoHang,luuKhoHang);
    printf("slkhoke = %d\n",SlKhoKe);
    for(int i = 0 ;i < SlKhoKe ; i++ )
    {  
        printf("%s\n",getVertex(KhoHang,luuKhoHang[i]));
        timSoSP = jrb_find_int(sosanpham , luuKhoHang[i]);
        tree =  (JRB)jval_v(timSoSP->val);
        timsoluong = jrb_find_int(tree, ID_SanPham);
        printf("%s %d\n",jval_s(timSP->val),jval_i(timsoluong->val));
    }
}

int main(int argc, char *argv[])
{
    int check_Argc = checkArgc(argc,argv);
    if(check_Argc == 0)
    {
        printf("ERROR \n");
        exit(2);
    }

    Graph KhoHang = createGraph();
    JRB sanPham = make_jrb();
    JRB soSanPham = make_jrb();
    JRB node;

    int m = readFileSanPham("sanpham.txt",sanPham);
    readFileKhoHang(KhoHang,soSanPham,"khohang.txt",m);

    switch(check_Argc)
    {
        case 1:
           printf("C-Advanced, HK20182\n");
           break;
        case 2:
           {
            jrb_traverse(node,sanPham)
            printf("%s %d\n",jval_s(node->val),jval_i(node->key));
           }
            break;
        case 3:
        {
          int ID1 = atoi(argv[3]);
          int ID2 = atoi(argv[4]);
          int value = (int) getEdgeValue(KhoHang,ID1 , ID2);
          if(value == INFINITIVE_VALUE)
            printf("-1\n");
          else
            printf("%d km\n",value);
          
        }
           break;
        case 4:
           kiemKe(KhoHang,sanPham,soSanPham);
           break;
        case 5:
            {
                int ID_sanPham = atoi(argv[4]);
                int ID_KhoHang = atoi(argv[5]);
                kiemHang(KhoHang,sanPham,soSanPham,ID_sanPham,ID_KhoHang);
            }
           break;
        case 6:
            {
                int ID_sanPham = atoi(argv[4]);
                int soluong = atoi(argv[5]);
                int ID_gannhat = atoi(argv[6]);
                int ID_ke = atoi(argv[7]);

                double time = 0;

                JRB timSoSP = jrb_find_int(soSanPham,ID_gannhat);
                JRB tree = (JRB)jval_v(timSoSP->val);
                JRB timSoluong = jrb_find_int(tree,ID_sanPham);

                int soluongKhogannhat = jval_i(timSoluong->val);
                if(soluongKhogannhat >= soluong)
                {
                    printf("Dat hang thanh cong, Thoi gian giao = %.0f\n",time = 30);
                }
                else 
                {
                     timSoSP = jrb_find_int(soSanPham,ID_ke);
                     tree = (JRB)jval_v(timSoSP->val);
                     timSoluong = jrb_find_int(tree,ID_sanPham);

                    int soluongKhoke = jval_i(timSoluong->val);
                    if(soluongKhogannhat + soluongKhoke < soluong)
                      printf("Dat hang that bai\n");
                    else 
                    {
                        time = 30 + 60* getEdgeValue(KhoHang,ID_gannhat,ID_ke) /30;
                        int gio = (int) time / 60;
                        int phut = (int) time % 60;
                        printf("Dat hang thanh cong!\n");
                        printf("Thoi gian giao hang la %d gio %d phut\n", gio, phut);
                    }
                }
              
            }
            break;
       default:
        break;
    }

    dropGraph(KhoHang);
    return 0;
}






