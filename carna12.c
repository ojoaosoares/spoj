#include <stdio.h>

int main() {
    float nota = 0,x, maior, menor;

    for (int i = 0; i < 5; i++)
    {
        scanf("%f",&x);
        nota += x;
        if(i == 0 || x > maior) maior = x;
        if(i == 0 || x < menor) menor = x;
    }

    printf("%.1f\n",nota-maior-menor);
    
}