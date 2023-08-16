#include <stdio.h>

int main() {
    char c;
    int n, x1,x2;
    
    scanf("%d %d %c %d",&n,&x1,&c,&x2);
    if (c == '+')
    {
        if(n >= x1 + x2) printf("OK\n");
        else printf("OVERFLOW\n");
    }
    
    else
    {
        if(n >= x1 * x2) printf("OK\n");
        else printf("OVERFLOW\n");
    }

}