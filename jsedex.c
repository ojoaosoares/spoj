#include <stdio.h>

int main() {

    int d, a, l, p;
    scanf("%d %d %d %d",&d,&a,&l,&p);
    a -= d;
    l -= d;
    p -= d;
    if( a >= 0 && l >= 0 && p >= 0) printf("S\n");
    else printf("N\n");
}