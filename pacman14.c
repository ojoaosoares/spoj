#include <stdio.h>
#include <stdlib.h>

int main() {

    int n, t = 0, maior= 0;
    scanf("%d",&n);
    char **matriz  = (char**) malloc(sizeof(char*)*n);
    for (int i = 0; i < n; i++) {
        setbuf(stdin,NULL);
        matriz[i] = (char*) malloc(sizeof(char)*n+1);
        scanf("%s",matriz[i]);
    }


    for (int i = 0; i < n; i++) {
        if(i % 2)
            for (int j = n-1; j >= 0; j--) {
                if(matriz[i][j] == 'o') t++;
                if(matriz[i][j] == 'A') {
                    if(t > maior) maior = t;
                    t = 0;
                }

            }
        else
            for (int j = 0; j < n; j++) {
                if(matriz[i][j] == 'o') t++;
                if(matriz[i][j] == 'A') {
                    if(t > maior) maior = t;
                    t = 0;
                }
            }
            
    }
    if(t > maior) maior = t;

    printf("%d\n",maior);
    
}