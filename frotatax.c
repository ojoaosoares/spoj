#include <stdio.h>

int main() {
    float a,g,ra,rg;
    scanf("%f %f %f %f",&a,&g,&ra,&rg);

    if(g/rg <= a/ra) printf("G\n");
    else printf("A\n");
}