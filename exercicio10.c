#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void exemplo(){
    int soma = 0;
    for (int i = 0; i < 1000000000; i++) {
        soma += i;
    }
}

int main() {
    clock_t inicio, fim;
    double tempo_decorrido;

    inicio = clock();

    exemplo();

    fim = clock();

    tempo_decorrido = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("Tempo decorrido: %.6f segundos\n", tempo_decorrido);

    return 0;
}