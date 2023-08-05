#include <stdio.h>
#include <stdlib.h>


struct Aresta {
    int v1, v2, peso;
};

struct Arvore {
    int pai;
};


int find(Arvore *v, int x) {
    if(v[x].pai != x) {
        v[x].pai = find(v,v[x].pai);
    }
    return v[x].pai;
}

void juntar(Arvore *v, int x1, int x2) {
    int pai1 = find(v,x1);
    int pai2 = find(v,x2);

    if( pai1 < pai2) v[pai2].pai = pai1;
    else v[pai1].pai = pai2;
}


int main() {
    int cont = 1,n,m, x,y;
    Aresta *arestas;
    Aresta troca;
    Arvore *vertices;
    while (1)
    {
        scanf("%d %d",&n,&m);
        if(n < 1) break;
        arestas = (Aresta*) malloc(sizeof(Aresta)*m);
        
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d %d",&x,&y,&arestas[i].peso);
            
            arestas[i].v1 = x;
            arestas[i].v2 = y;
            
            if(x > y) {
                arestas[i].v1 = y;
                arestas[i].v2 = x;
            }
        }


        for (int i = 0; i < (m-1); i++)
            for (int j = 0; j < (m-1); j++) 
                if(arestas[j].peso > arestas[j+1].peso) {
                    troca = arestas[j+1];
                    arestas[j+1] = arestas[j];
                    arestas[j] = troca;
                }

        vertices = (Arvore*) malloc(sizeof(Arvore)*n);
        for (int i = 0; i < n; i++)
            vertices[i].pai = i;

        printf("Teste %d\n",cont++);
        for (int i = 0; i < m; i++)
        {
            if(find(vertices,(arestas[i].v1 -1)) != find(vertices,(arestas[i].v2-1))) {
                printf("%d %d\n",arestas[i].v1,arestas[i].v2);
                juntar(vertices,(arestas[i].v1-1),(arestas[i].v2-1));
            }
        }
        printf("\n");


        free(arestas);
        free(vertices);
    }

}