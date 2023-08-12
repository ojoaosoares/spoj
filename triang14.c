#include <stdio.h>

int main() {
    int varetas[4], teste;

    for (int i = 0; i < 4; i++)
        scanf("%d",&varetas[i]);
    
    for (int i = 0; i < 4; i++) {
        teste = 1;
        for (int j = 0; j < 4; j++) {
            if(j == i) continue;
            for (int k = 0; k < 4; k++) {
                if (k == i || k == j) continue;
                
                if (varetas[i] < varetas[j] + varetas[k] && varetas[j] < varetas[k] + varetas[i] && varetas[k] < varetas[j] + varetas[i]) {
                    printf("S\n");
                    teste = 0;
                    break;
                }
                
            }

            if(!teste) break;
        }

        if(!teste) break;
            
    }
    if (teste) printf("N\n");
    
}