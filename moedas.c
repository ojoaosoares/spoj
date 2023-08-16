#include <stdio.h>
#include <stdlib.h>

// int contar_moedas(int total, int *moedas, int n, int *memoria) {
//     if(total == 0) return 0;
//     if(n < 0 || total < 0) return -1;

//     if(memoria[total] == -1) {
//         int pego = contar_moedas(total - moedas[n], moedas, n, memoria);
//         int troco = contar_moedas(total, moedas, n -1, memoria);

//         if(pego++ != -1)  {
//             if(pego < troco || troco == -1) memoria[total] = pego;
//             else memoria[total] = troco;
//         }
//         else {
//             memoria[total] = troco;
//         }
//     }
//     return memoria[total];
    

// }


int contar_moedas(int total, int *moedas, int n) {
    int min, *memoria = (int*) malloc(sizeof(int)*(total+1));
    
    memoria[0] = 0;
    for (int i = 1; i < (total+1); i++) {
            memoria[i] = -1;
            min = -1;
        
        for (int j = n; j >= 0; j--)        
            if((i - moedas[j] >= 0 && memoria[i-moedas[j]] != -1) &&  (min == -1 || 1 + memoria[i-moedas[j]] < min)) min = 1+ memoria[i-moedas[j]];

        memoria[i] = min;
        
    }


    min = memoria[total];
    free(memoria);
    return min;
    

    
}


int main() {
    int m, n, *moedas, x;
    
    while (1)
    {
        scanf("%d %d",&m,&n);
        if(!m) break;
        moedas = (int*) malloc(sizeof(int)*n);
    

        for (int i = 0; i < n; i++)
            scanf("%d",&moedas[i]);
        

        x = contar_moedas(m,moedas,n-1);
        if(x == -1) printf("Impossivel\n");
        else printf ("%d\n",x);
        free(moedas);
        
    }
    
}