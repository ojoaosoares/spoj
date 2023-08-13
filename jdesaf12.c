#include <stdio.h>
#include <stdlib.h>

int main() {
    int x;
    int maior, teste = 1;
    
    while (1)
    {
        scanf("%d",&x);
        if(!x) break;
        if(teste || x > maior) {
            maior = x;
            teste = 0;
        } 

    }
    
    printf("%d\n", maior);
    
}