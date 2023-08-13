#include <stdio.h>

int main() {

    int v, t, x;
    scanf("%d %d",&v,&t);
    for (int i = 0; i < t; i++) {
        scanf("%d",&x);
        v += x;
        if(v < 0) v = 0;
        else if(v  > 100) v = 100;
    }

    printf("%d\n",v);
    
}