#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Vencedores {
    int partidas;
    char** nomes;
};

int main() {
    int n, cont = 0;
    Vencedores* vencedor;
    char nome1[11], nome2[11];

    int n1, n2;

    while(1) {
        scanf("%d",&n);

        if(n == 0) break;
        else if(n < 0) continue;

        if(cont == 0) vencedor = (Vencedores*) malloc(sizeof(Vencedores));
        else vencedor = (Vencedores*) realloc(vencedor,(cont+1)*sizeof(Vencedores));

        scanf("%s",nome1);
        scanf("%s",nome2);

        vencedor[cont].partidas = n;
        vencedor[cont].nomes = (char**) malloc(n*sizeof(char*));
        
        int i = 0;
        while (i < n) {
            scanf("%d %d",&n1,&n2);
            if(n1 < 0 || n1 > 5 || n2 < 0 || n2 > 5) continue;

            vencedor[cont].nomes[i] = (char*) malloc(11*sizeof(char));

            if((n1+n2) % 2) strcpy(vencedor[cont].nomes[i],nome2);
            else strcpy(vencedor[cont].nomes[i],nome1);
            
            i++;
        }

        cont ++;
    }


    for (int i = 0; i < cont; i++)
    {
        printf("Teste %d\n",i+1);
        for (int j = 0; j < vencedor[i].partidas; j++)
        {
            printf("%s\n",vencedor[i].nomes[j]);
            free(vencedor[i].nomes[j]);
        }
        free(vencedor[i].nomes);

        printf("\n");
        
    }

    free(vencedor);
    
    
}