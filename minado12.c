#include <stdio.h>
#include <stdlib.h>

int main() {

    int n, *tabuleiro, minas;
    scanf("%d",&n);
    tabuleiro = (int*) malloc(sizeof(int)*n);

    
    for (int i = 0; i < n; i++)
        scanf("%d",&tabuleiro[i]);

    
    for (int i = 0; i < n; i++) {
        minas = 0;
        if(i - 1 >= 0 && tabuleiro[i-1]) minas++;
        if(i + 1 < n && tabuleiro[i+1]) minas++;
        if(tabuleiro[i]) minas++;

        printf("%d\n",minas);
    }

    free(tabuleiro);
}