#include <stdio.h>
#include <stdlib.h>

int main() {
    int n,x, maior;
    int votos[100];

    while (1) {

        scanf("%d",&n);
        if(n< 1) break;
        
        for (int i = 0; i < n; i++)
            votos[i] = 0;

        maior = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d",&x);
                votos[j] += x;
                if(votos[j] > maior) maior = votos[j];
            }
                
        }        
        printf("%d\n",maior);

    }
    
}