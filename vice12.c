#include <stdio.h>

// void bubble_sort(int *array, int size) {
//     int troca;
//     for (int i = 0; i < (size-1); i++)
//             for (int j = 0; j < (size-1-i); j++) 
//                 if(array[j] > array[j+1]) {
//                     troca = array[j+1];
//                     array[j+1] = array[j];
//                     array[j] = troca;
//                 }
// }

void merge_sort(int *array, int tamanho) {

    int *auxiliar = (int*) malloc(tamanho*sizeof(int));

    int esquerda,meio, direita, x, y;
    for (int i = 1; i < tamanho; i*=2) {
        for (int j = 0; j + i < tamanho; j+= i*2)
        {
            esquerda = j;
            meio = esquerda + i;
            direita = esquerda + 2*i;
            if (direita > tamanho) direita = tamanho;
            
            x = esquerda;
            y  = meio;
            
            while (esquerda < direita)
            {
                if((array[x] < array[y] || y >= direita) &&  (x < meio)) auxiliar[esquerda++] = array[x++];
                else if((array[y] <= array[x] || x>= meio) && y < direita) auxiliar[esquerda++] = array[y++];
            }
            
            for (int k = j; k <  direita; k++)
                array[k] = auxiliar[k];
        } 
    }     
}



int main() {
    int a[3];
    scanf("%d %d %d",&a[0],&a[1],&a[2]);
    merge_sort(a,3);
    printf("%d\n",a[1]);
}