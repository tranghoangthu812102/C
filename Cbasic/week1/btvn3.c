#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include <time.h>

#define MAX 200
int main()
{   int i,j;
    int max=10;
    char maotu[5][10]={"a","an","the","some","any"};
    char danhtu[5][10]={"boy","girl","dog","town","car"};
    char dongtu[5][10]={"drove", "jumped", "ran", "walked","skipped"};
    char gioitu[5][10]={"to", "from", "over", "under","on"};

    srand(time(NULL));
    printf("cac cau duoc tao thanh ngay nhien la :\n");
    for(i=1;i<=max;i++)
    {
    char Up[max];
    strcpy(Up, maotu[rand()%5]);
    Up[0] = toupper(Up[0]);
    printf("%d.%s %s %s %s %s %s. \n",i, Up, danhtu[rand()%5], dongtu[rand()%5],gioitu[rand()%5], maotu[rand()%5],danhtu[rand()%5]);
    }
}
