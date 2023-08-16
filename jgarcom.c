#include <stdio.h>


int main() {
    int n, l,c ,t = 0;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d",&l,&c);
        if(l > c) t += c;
    }
    printf("%d\n",t);
    
}