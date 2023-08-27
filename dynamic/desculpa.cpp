#include <iostream>
#include <algorithm>


struct Obj {
    int peso, valor;
};


int knaspack(Obj *frases , int maximo, int n_objetos) {

    int matriz[n_objetos+1][maximo+1];

    for (int i = 0; i <= n_objetos; i++)
        for (int j = 0; j <= maximo; j++)
            matriz[i][j] = 0;
    

    
    for (int i = 1; i <= n_objetos; i++)
        for (int j = 1; j <= maximo; j++)
        {
            if(frases[i-1].peso > j) matriz[i][j] = matriz[i-1][j];
            else matriz[i][j] = std::max(frases[i-1].valor+ matriz[i-1][j - frases[i-1].peso], matriz[i-1][j]);
        }

    return matriz[n_objetos][maximo];
    
    
}

int main() {

    int c, cont = 1, f, caracteres_usados, desculpas;
    while (1)
    {
        
        std::cin >> c >> f;
        if(!c && !f) break;
        Obj *frases = new Obj[f];

        for (int i = 0; i < f; i++)
            std::cin >> frases[i].peso >> frases[i].valor;
        
        std::cout << "Teste " << cont++ << std::endl;
        std::cout << knaspack(frases,c,f) << std::endl << std::endl;
        delete[] frases;
        
    }
    
    
    
} 