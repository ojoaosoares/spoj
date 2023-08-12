#include <stdio.h>
#include <stdlib.h>

struct Aresta {
    int v1, v2, peso;
};

int find(int *v, int x) {
    while(v[x] != x) {
        x = v[x];
    }
    return v[x];
}


void join(int *v, int x1, int x2) {
    int pai1 = find(v,x1);
    int pai2 = find(v,x2);

    if( pai1 < pai2) v[pai2] = pai1;
    else v[pai1] = pai2;
}


int kruskal(int *vertices, Aresta *arestas, int n, Aresta *copia) {

    int t = 0;
    for (int i = 0; i < n; i++)
    {
        if(find(vertices,arestas[i].v1) != find(vertices,arestas[i].v2)) {
            join(vertices,arestas[i].v1,arestas[i].v2);
            copia[(t++)] = arestas[i];
        }
    }
    copia = (Aresta*) realloc(copia,t*sizeof(Aresta));
    return t;
    
}

void merge_sort(Aresta *array, int tamanho) {

    Aresta *auxiliar = (Aresta*) malloc(tamanho*sizeof(Aresta));

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

                if((array[x].peso < array[y].peso || y >= direita) &&  (x < meio)) auxiliar[esquerda++] = array[x++];
                else if((array[y].peso <= array[x].peso || x>= meio) && y < direita) auxiliar[esquerda++] = array[y++];
            }
            
            for (int k = j; k < direita; k++) {
                array[k] = auxiliar[k];
     
            }
        }
    }
        
}


int main() {
    int x,y,n,m, *vertices, cont = 1;
    Aresta *arestas, *copia;
    while (1) {
        scanf("%d %d",&n,&m);
        if(n < 1) break;
        arestas = (Aresta*) malloc(sizeof(Aresta)*m);
        copia = (Aresta*) malloc(sizeof(Aresta)*m);

        for (int i = 0; i < m; i++)
        {
            scanf("%d %d %d",&x,&y,&arestas[i].peso);
            
            
            
            if(x > y) {
                arestas[i].v1 = y-1;
                arestas[i].v2 = x-1;
            }

            else {
                arestas[i].v1 = x-1;
                arestas[i].v2 = y-1;
            }
        }

        merge_sort(arestas,m);
        
        vertices = (int*) malloc(sizeof(int)*n);
        for (int i = 0; i < n; i++)
            vertices[i] = i;
        
        int size = kruskal(vertices,arestas,m,copia);
        printf("Teste %d\n",cont++);
        for (int i = 0; i < size; i++)
            printf("%d %d\n",copia[i].v1 +1,copia[i].v2 +1);
        
        printf("\n");

        free(vertices);
        free(arestas);
        free(copia);
    }
}