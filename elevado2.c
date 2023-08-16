#include <stdio.h>

int main() {
    int n, c, e,s,t = 0;
    char u =  'N';;
    scanf("%d %d",&n,&c);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d",&s,&e);
        t -= s;
        t += e;
        if(t > c) u = 'S';
    }

    printf("%c\n",u);
    
}