#include <stdio.h>

#define MAX 199999

struct Candidato
{
    int id;
    int votos;
};



int main() {

    Candidato votos[MAX], vencedor = {0,0};

    for (int i = 0; i < MAX; i++)
    {
        votos[i].id = 0;
        votos[i].votos = 0;
    }

    int n,x;
    scanf("%d",&n);

    for (int i = 0; i < n; i++) {
        scanf("%d",&x);
        int index = x%MAX;
        while (1)
        {
            
            if(votos[index].id == 0 || votos[index].id == x) {
                votos[index].id = x;
                votos[index].votos++;

                if(vencedor.votos == 0 || votos[index].votos > vencedor.votos)
                    vencedor = votos[index];
                break;
            }

            index++;
        }
    }



    printf("%d\n",vencedor.id);
    
    
    
    
    
    
}