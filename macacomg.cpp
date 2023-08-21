#include <iostream>

void merge_sort(int *array, int tamanho) {

    int *auxiliar = new int[tamanho];

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

    delete[] auxiliar;     
}

int main() {

    int n;
    while (1)
    {    
        std::cin >> n;
        if(!n) break;
        

        int *p = new int[n];
        for (int cont = 0; cont < n; cont++)
            std::cin >> p[cont];

        merge_sort(p,n);
        int i = 0, j = n-1, k = 0;

        int maior;
        while (i < j) {
            if(k == 0 || p[i] + p[j] > maior) maior = p[i] + p[j];
            k++;
            i++;
            j--;   
        }


        
        
        std::cout << maior << std::endl;


        delete[] p;
        

    }
    
}