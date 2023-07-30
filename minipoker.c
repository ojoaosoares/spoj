#include <stdio.h>


int pontuacao(int mao[5]) {
    int teste = 1;
    

    for (int j = 1; j < 5; j++)
            if (mao[0] + j != mao[j]) {
                teste = 0;
                break;
            }

    if (teste) return 200 + mao[0];
    
    int cont = 0, repeticao[2][2] = {{-1,1},{-1,1}};
    for (int i = 0; i < 4; i++)
        if (mao[i] == mao[i+1])
        {
            if(repeticao[cont][0] != -1 && repeticao[cont][0] != mao[i]) cont++;
            repeticao[cont][0] = mao[i];
            repeticao[cont][1]++;
        }


    if(repeticao[0][0] != -1 && repeticao[1][0] != -1) {
        if (repeticao[0][1] == 2 && repeticao[1][1] == 2) return 3* repeticao[1][0] + 2*repeticao[0][0] + 20;
        else if(repeticao[0][1] == 3) return 160 +repeticao[0][0];
        return 160 +repeticao[1][0];
    }

    if (repeticao[0][0] != -1 && repeticao[0][1] == 4)
        return repeticao[0][0] + 180;

    if (repeticao[0][0] != -1 && repeticao[0][1] == 3)
        return repeticao[0][0] + 140;

    if (repeticao[0][0] != -1 && repeticao[0][1] == 2)
        return repeticao[0][0];
                
    return 0;
}

int main() {

    int n, mao[5], mediador =0;

    scanf("%d",&n);
    int pontos[n];

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < 5; j++)
        {
            scanf("%d",&mao[j]);
            for (int x = j; x > 0; x--)
            {
                if(mao[x] < mao[x-1]) {
                    mediador = mao[x-1];
                    mao[x-1] = mao[x];
                    mao[x] = mediador;
                }

                else break;
            }
            
        }

        pontos[i] = pontuacao(mao);
    }


    for (int i = 0; i < n; i++)
    {
        printf("Teste %d\n",i+1);
        printf("%d\n",pontos[i]);
        printf("\n");
    }
        

}