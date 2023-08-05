#include <stdio.h>

int main() {

    int n, cont = 1, notas[] = {50,10,5,1};

    while (1) {
        scanf("%d",&n);
        if(!n) break;

        printf("Teste %d\n",cont++);
        for (int i = 0; i<4 ; i++)
        {
            printf("%d ",n/notas[i]);
            n%= notas[i];
        }
        
        printf("\n\n");
    }
}