#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    int h1,m1,h2,m2, cont =0;
    int *minutos = (int*) malloc(sizeof(int));

    while (1)
    {
        scanf("%d %d %d %d",&h1,&m1,&h2,&m2);
        if(h1 == 0 && m1 == 0 && h2 == 0 && m2 == 0 ) break;
        if(cont > 0) minutos = (int*) realloc(minutos,(cont+1)*sizeof(int));

        if(m2 < m1) {
            if (h2 > 0) h2--;
            else h2 = 23;
            
            minutos[cont] = (60 + m2) - m1;
        }
        else minutos[cont] = m2 - m1;

        if(h2 < h1) minutos[cont] += ((24 + h2) - h1)*60;
        else minutos[cont] += (h2 - h1)*60;;
    
        cont++;
    }

    for (int i = 0; i < cont; i++)
        printf("%d\n",minutos[i]);
        
    free(minutos);
    
    
    
}