#include <stdio.h>

#define MAX 199999

struct Candidato
{
    int id;
    int votos;
};



int main() {

    Candidato votos[MAX];

    for (int i = 0; i < MAX; i++)
    {
        votos[i].id = 0;
        votos[i].votos = 0;
    }

    int n,x;
    scanf("%d",&n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d",&x);
        int index = x%MAX;
        while (1)
        {
            
            if(votos[index].id == 0 || votos[index].id == x) {
                votos[index].id = x;
                votos[index].votos++;
                break;
            }

            index++;
        }

        
        
    }

    Candidato maior;
    maior.votos = 0;

    for (int i = 0; i < MAX; i++)
    {
        if(votos[i].votos > maior.votos) {
            maior.id = votos[i].id;
            maior.votos = votos[i].votos;
            
        }
    }

    printf("%d\n",maior.id);
    
    
    
    
    
    
}