#include <stdio.h>
#include <string.h>

int main() {
    char nome[21], reprovado[21];
    int cont = 1,n,nota, nota_reprovado;

    while (scanf("%d", &n) != EOF) {
        nota_reprovado = 11;
        for (int i = 0; i < n; i++) {   
            scanf("%s %d",nome,&nota);
            if (nota < nota_reprovado || (nota == nota_reprovado && strcmp(nome,reprovado) > 0))
            {
                nota_reprovado = nota;
                strcpy(reprovado,nome);
            }
        }
        
        printf("Instancia %d\n%s\n\n",(cont++),reprovado);
    }
}