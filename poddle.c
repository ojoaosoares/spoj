#include <stdio.h>

int main() {
    int n, p, pag;

    while (1)
    {
        pag = -6;
        scanf("%d %d",&n,&p);
        if(!n && !p) break;
        pag += n/p;
        if(n%p > 0) pag++;
        if(pag > 14) pag = 14;

        printf("Poo");
        for (int i = 0; i < pag; i++)
            printf("o");
        
        printf("dle\n");

        

    }   
    
}