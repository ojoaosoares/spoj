#include <stdio.h>
#include <stdlib.h>

struct Caminhos {
    int *distancias;
};

int main() {
    int n,x1,x2, cont = 1, menor[2], maior_linha;
    Caminhos *pais;

    while (1) {
        scanf("%d",&n);        
        if(n == 0) break;

        pais = (Caminhos*) malloc(sizeof(Caminhos)*n);

        for (int i = 0; i < n; i++) {
            pais[i].distancias = (int*) malloc(sizeof(int)*n);
            for (int j = 0; j < n; j++)
            {
                pais[i].distancias[j] = -1;
                if(i == j) pais[i].distancias[j] = 0;
            }
            
        }
            
        for (int i = 0; i < n-1; i++) {
            scanf("%d %d",&x1,&x2);
            pais[x1-1].distancias[x2-1] = 1;
            pais[x2-1].distancias[x1-1] = 1;
            
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (pais[j].distancias[i] == -1) continue;

                for (int k = 0; k < n; k++) {
                    if(j == k  || j == i || k == i || pais[i].distancias[k] == -1) continue; 
                    if(pais[j].distancias[k] == -1 || pais[j].distancias[k] > pais[j].distancias[i] + pais[i].distancias[k]) pais[j].distancias[k] = pais[j].distancias[i] + pais[i].distancias[k];
                    
                }
            }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(i != 0 && pais[i].distancias[j] >= menor[1]) {
                    maior_linha = -1;
                    break;
                }
                if(j == 0 || pais[i].distancias[j] > maior_linha) maior_linha = pais[i].distancias[j];
                
            }
                
            if(i == 0 || maior_linha != -1) {
                menor[0] = i;
                menor[1] = maior_linha;
            }
        }

        printf("Teste %d\n",cont++);
        printf("%d\n",menor[0]+1);
        printf("\n");

        for (int i = 0; i < n; i++) 
            free(pais[i].distancias);

        free(pais);
        
    }
    
}