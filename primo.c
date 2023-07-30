#include <stdio.h>
#include <math.h>

int main() {
    int n, p = 1;
    scanf("%d",&n);

    for (int i = (int) floor(sqrt(n)); i > 1; i--)
        if(!(n%i)){
            p = 0;
            break;
        } 

    if(p) printf("sim\n");
    else printf("nao\n");

    return 0;
        
}