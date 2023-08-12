#include <stdio.h>


int main() {
    int n,s,x, menor;
    scanf("%d %d",&n,&s);
    menor = s;
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&x);
        s += x;
        if(s < menor) menor = s;
        
    }

    printf("%d\n",menor)   ;
}