#include <stdio.h>
#include <stdlib.h>

int main() {

    int** matriz;
    int n,m;
    scanf("%d %d",&n,&m);

    matriz = (int**) malloc(n*sizeof(int*));
    for (int i = 0; i < n; i++)
        matriz[i] = (int*) malloc(m*sizeof(int));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            scanf("%d",&matriz[i][j]);
        
        
    }

    int teste,maior;

    for (int i = 0; i < n; i++)
    {
        teste = 0;
        for (int j = 0; j < m; j++)
            teste += matriz[i][j];

        if(i == 0) maior = teste;
        else if(teste > maior) maior = teste;
    }
    

    for (int j = 0; j < m; j++)
    {
        teste = 0;
        for (int i = 0; i < n; i++)
            teste += matriz[i][j];

        if(teste > maior) maior = teste;
    }

    printf("%d\n",maior);
    for (int i = 0; i < n; i++)
        free(matriz[i]);
    free(matriz);
}