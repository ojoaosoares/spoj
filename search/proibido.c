// Tabela Hash
// #include <stdio.h>
// #include <stdlib.h>

// #define MAX 279941

// int main() {
//     int n,x, index,j, teste;
//     int **proibidos = (int**)  malloc(sizeof(int*)*MAX);

//     for (int i = 0; i < MAX; i++) {
//         proibidos[i] = (int*)  malloc(sizeof(int));
//         proibidos[i][0] = -1;
//     }
        

    
//     scanf("%d",&n);
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d",&x);
//         index = x%MAX;
//         teste = 1;
//         for (j = 0; proibidos[index][j] != -1; j++)
//             if(proibidos[index][j] == x) {
//                 teste = 0;
//                 break;
//             } 


//         if(teste) {
//             proibidos[index][j] = x;
//             proibidos[index] = realloc(proibidos[index],sizeof(int)*(j+2));
//             proibidos[index][j+1] = -1;
//         }
        
        
//     }


//     while (scanf("%d", &x) != EOF)
//     {
//         teste = 1;
//         index = x%MAX;
//         for (j = 0; proibidos[index][j] != -1; j++)
//             if(proibidos[index][j] == x) {
//                 printf("sim\n");
//                 teste = 0;
//                 break;
//             }

//         if (teste) printf("nao\n");
        
//     }

//     for (int i = 0; i < MAX; i++) 
//         free(proibidos[i]);
//     free(proibidos);

// }



#include <stdio.h>
#include <stdlib.h>

// void intercala(int *resultado,int *xl,int *xr, int s1, int s2) {
//     int i, j, k;
//     i = j = k = 0;

//     while (i < s1 || j < s2) {
//         if( (xl[i] < xr[j] && i < s1) || j >= s2) resultado[k++] = xl[i++];
//         else if(j < s2) resultado[k++] = xr[j++];
//     }

//     free(xl);
//     free(xr);
// }

// void merge_sort(int *array, int *copia, int t) {
//     if (t == 1) {
//         copia[0] = array[0];
//         return;
//     } 

//     int *xl = (int*) malloc((t/2)*sizeof(int));
//     merge_sort(array,xl,t/2);
//     int *xr = (int*) malloc((t -t/2)*sizeof(int));
//     merge_sort(&(array[t/2]),xr,t-t/2);

//     intercala(copia,xl,xr,t/2,t -t/2);
    
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
            
        }


        for (int j = 0; j < tamanho; j++)
            array[j] = auxiliar[j];
        
    }


    free(auxiliar);
        
}

int binary_search(int *array,int alvo, int esquerda, int direita) {
    
    while (esquerda <= direita)
    {
        int meio = (esquerda + direita)/2;
        if(array[meio] == alvo) return 1;
        if(alvo > array[meio]) esquerda = meio+1;
        else direita = meio -1;
    }
    

    return 0;
}



int main() {
    int *proibidos,n,x;
    scanf("%d",&n);
    proibidos = (int*) malloc(sizeof(int)*n);


    for (int i = 0; i < n; i++)
        scanf("%d",&proibidos[i]);

    merge_sort(proibidos,n);

    while (scanf("%d", &x) != EOF)
    {
       if(binary_search(proibidos,x,0,n-1))
            printf("sim\n");

       else printf("nao\n");

   
    }

    free(proibidos);
}