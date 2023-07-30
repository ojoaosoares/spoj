#include <stdio.h>
#include <stdlib.h>

int main() {
    int x,n, qtd_testes = 0;
    int* vencedores;
    while(1)
    {
        scanf("%d",&n);

        if(n == 0) break;
        else if(n < 0) continue;

        qtd_testes++;
        if(qtd_testes == 1) vencedores = (int*) malloc(qtd_testes*sizeof(int));
        else vencedores = (int*) realloc(vencedores,qtd_testes*sizeof(int));

        
        for (int i = 0; i < n; i++)
        {
            scanf("%d",&x);
            if(x == (i+1)) vencedores[qtd_testes-1] = x;
        }
        
    };


    for (int i = 0; i < qtd_testes; i++)
    {
        printf("Teste %d\n",i+1);
        printf("%d\n",vencedores[i]);
        printf("\n");
    }
    
    
    



    free(vencedores);

}